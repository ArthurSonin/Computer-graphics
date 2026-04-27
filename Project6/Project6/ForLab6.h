#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

// Структура для збереження 3D координат у системі однорідних координат
public value struct Point3D {
    double x, y, z, w;
};

// Структура для збереження 2D координат екрана після проектування
public value struct Point2D {
    float x, y;
};

public ref class ConvexPolyhedron {
private:
    int vertexCount;
    List<Point3D>^ vertices;        // Поточні координати
    List<Point3D>^ initialVertices; // Копія для скидання змін
    cli::array<int, 2>^ adjacencyMatrix; // Матриця суміжності

    Point3D ApplyMatrix(Point3D p, cli::array<double, 2>^ M) {
        Point3D res;
        res.x = p.x * M[0, 0] + p.y * M[0, 1] + p.z * M[0, 2] + p.w * M[0, 3];
        res.y = p.x * M[1, 0] + p.y * M[1, 1] + p.z * M[1, 2] + p.w * M[1, 3];
        res.z = p.x * M[2, 0] + p.y * M[2, 1] + p.z * M[2, 2] + p.w * M[2, 3];
        res.w = p.x * M[3, 0] + p.y * M[3, 1] + p.z * M[3, 2] + p.w * M[3, 3];
        return res;
    }

    Point2D ProjectAxonometric(Point3D p, float ox, float oy) {
        double alpha = 45 * 3.14159 / 180.0;
        double kx = 0.5;
        Point2D res;
        res.x = ox + (float)(p.y + kx * p.x * cos(alpha));
        res.y = oy - (float)(p.z - kx * p.x * sin(alpha));
        return res;
    }

    Point2D ProjectPerspective(Point3D p, float ox, float oy, double d) {
        Point2D res;
        double factor = 1.0 + (p.z / d);
        if (Math::Abs(factor) < 0.001) factor = 0.001;
        res.x = ox + (float)(p.x / factor);
        res.y = oy + (float)(p.y / factor);
        return res;
    }

    Point2D ProjectPerspectiveTwoFocus(Point3D p, float ox, float oy, double d) {
        Point2D res;
        double factor = d + p.z;
        if (Math::Abs(factor) < 0.1) factor = 0.1;
        res.x = ox + (float)((d * p.x) / factor);
        res.y = oy + (float)((d * p.y) / factor);
        return res;
    }

public:
    ConvexPolyhedron() {
        vertexCount = 0;
        vertices = gcnew List<Point3D>();
        initialVertices = gcnew List<Point3D>();
    }

    bool LoadFromFile(String^ fileName) {
        std::string stdFileName = msclr::interop::marshal_as<std::string>(fileName);
        std::ifstream file(stdFileName);
        if (!file.is_open()) return false;

        vertices->Clear();
        initialVertices->Clear();

        int count;
        file >> count;
        vertexCount = count;
        for (int i = 0; i < vertexCount; i++) {
            Point3D p;
            file >> p.x >> p.y >> p.z;
            p.w = 1.0;
            vertices->Add(p);
            initialVertices->Add(p);
        }

        adjacencyMatrix = gcnew cli::array<int, 2>(vertexCount, vertexCount);
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                int val;
                file >> val;           
                adjacencyMatrix[i, j] = val;
            }
        }
        file.close();
        return true;
    }

    Point3D GetCenter() {
        Point3D c; c.x = 0; c.y = 0; c.z = 0; c.w = 1;
        if (vertices->Count == 0) return c;
        for each (Point3D v in vertices) {
            c.x += v.x; c.y += v.y; c.z += v.z;
        }
        c.x /= vertices->Count; c.y /= vertices->Count; c.z /= vertices->Count;
        return c;
    }

    void Scale(double sx, double sy, double sz) {
        Point3D c = GetCenter();
        cli::array<double, 2>^ M = gcnew cli::array<double, 2>(4, 4);
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) M[i, j] = 0;
        M[0, 0] = sx; M[1, 1] = sy; M[2, 2] = sz; M[3, 3] = 1;

        for (int i = 0; i < vertices->Count; i++) {
            Point3D v = vertices[i];
            v.x -= c.x; v.y -= c.y; v.z -= c.z;
            v = ApplyMatrix(v, M);
            v.x += c.x; v.y += c.y; v.z += c.z;
            vertices[i] = v;
        }
    }

    void Rotate(double angle, char axis) {
        Point3D c = GetCenter();
        double rad = angle * 3.14159265 / 180.0;
        cli::array<double, 2>^ M = gcnew cli::array<double, 2>(4, 4);
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) M[i, j] = 0;

        if (axis == 'x') {
            M[0, 0] = 1; M[3, 3] = 1;
            M[1, 1] = cos(rad); M[1, 2] = -sin(rad);
            M[2, 1] = sin(rad); M[2, 2] = cos(rad);
        }
        else if (axis == 'y') {
            M[1, 1] = 1; M[3, 3] = 1;
            M[0, 0] = cos(rad); M[0, 2] = sin(rad);
            M[2, 0] = -sin(rad); M[2, 2] = cos(rad);
        }
        else {
            M[2, 2] = 1; M[3, 3] = 1;
            M[0, 0] = cos(rad); M[0, 1] = -sin(rad);
            M[1, 0] = sin(rad); M[1, 1] = cos(rad);
        }

        for (int i = 0; i < vertices->Count; i++) {
            Point3D v = vertices[i];
            v.x -= c.x; v.y -= c.y; v.z -= c.z;
            v = ApplyMatrix(v, M);
            v.x += c.x; v.y += c.y; v.z += c.z;
            vertices[i] = v;
        }
    }

    void ResetToOriginal() {
        for (int i = 0; i < vertices->Count; i++) vertices[i] = initialVertices[i];
    }

    Bitmap^ Redraw(int width, int height, String^ mode, double d) {
        Bitmap^ bmp = gcnew Bitmap(width, height);
        Graphics^ g = Graphics::FromImage(bmp);
        g->Clear(Color::White);
        g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

        if (vertexCount == 0) return bmp;

        Pen^ pen = gcnew Pen(Color::DarkBlue, 2);
        float ox = width / 2.0f, oy = height / 2.0f;

        List<Point2D>^ projected = gcnew List<Point2D>();
        for each(Point3D v in vertices) {
            if (mode == "Perspective")
                projected->Add(ProjectPerspective(v, ox, oy, d));
            else if (mode == "Perspective2") // Наша нова модель
                projected->Add(ProjectPerspectiveTwoFocus(v, ox, oy, d));
            else
                projected->Add(ProjectAxonometric(v, ox, oy));
        }

        for (int i = 0; i < vertexCount; i++) {
            for (int j = i + 1; j < vertexCount; j++) {
                if (adjacencyMatrix[i, j] == 1) {
                    g->DrawLine(pen, projected[i].x, projected[i].y,
                        projected[j].x, projected[j].y);
                }
            }
        }

        delete pen; // Звільняємо ресурси
        delete g;
        return bmp;
    }
};
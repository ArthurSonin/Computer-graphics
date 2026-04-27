#pragma once
#include <fstream>
#include <string>
#include <cmath>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

public value struct Point3D {
    double x, y, z, w;
};

public ref class ConvexPolyhedron {
private:
    int vertexCount;
    List<Point3D>^ vertices;
    List<Point3D>^ initialVertices;
    cli::array<int, 2>^ adjacencyMatrix;

    Point3D ApplyMatrix(Point3D p, cli::array<double, 2>^ M) {
        Point3D res;
        res.x = p.x * M[0, 0] + p.y * M[0, 1] + p.z * M[0, 2] + p.w * M[0, 3];
        res.y = p.x * M[1, 0] + p.y * M[1, 1] + p.z * M[1, 2] + p.w * M[1, 3];
        res.z = p.x * M[2, 0] + p.y * M[2, 1] + p.z * M[2, 2] + p.w * M[2, 3];
        res.w = p.x * M[3, 0] + p.y * M[3, 1] + p.z * M[3, 2] + p.w * M[3, 3];
        return res;
    }

public:
    ConvexPolyhedron() {
        vertexCount = 0;
        vertices = gcnew List<Point3D>();
        initialVertices = gcnew List<Point3D>();
        adjacencyMatrix = gcnew cli::array<int, 2>(0, 0);
    }

    Point3D GetCenter() {
        Point3D c; c.x = 0; c.y = 0; c.z = 0; c.w = 1;
        if (vertices->Count == 0) return c;
        for each (Point3D v in vertices) {
            c.x += v.x; 
            c.y += v.y; 
            c.z += v.z;
        }
        c.x /= vertices->Count; 
        c.y /= vertices->Count; 
        c.z /= vertices->Count;
        return c;
    }

    bool LoadFromFile(String^ filePath) {
        std::string stdPath = msclr::interop::marshal_as<std::string>(filePath);
        std::ifstream file(stdPath);
        if (!file.is_open()) return false;
        int tempCount;
        if (!(file >> tempCount)) return false;
        this->vertexCount = tempCount;
        vertices->Clear(); initialVertices->Clear();
        for (int i = 0; i < vertexCount; i++) {
            double tx, ty, tz;
            file >> tx >> ty >> tz;
            Point3D p; p.x = tx; p.y = ty; p.z = tz; p.w = 1.0;
            vertices->Add(p); initialVertices->Add(p);
        }
        adjacencyMatrix = gcnew cli::array<int, 2>(vertexCount, vertexCount);
        for (int i = 0; i < vertexCount; i++)
            for (int j = 0; j < vertexCount; j++) {
                int val; file >> val; adjacencyMatrix[i, j] = val;
            }
        file.close();
        return true;
    }

    void Scale(double sx, double sy, double sz) {
        Point3D c = GetCenter();
        cli::array<double, 2>^ M = gcnew cli::array<double, 2>(4, 4);
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) M[i, j] = 0;

        M[0, 0] = sx; M[1, 1] = sy; M[2, 2] = sz; M[3, 3] = 1;

        for (int i = 0; i < vertices->Count; i++) {
            Point3D v = vertices[i];
            v.x -= c.x; 
            v.y -= c.y; 
            v.z -= c.z;
            v = ApplyMatrix(v, M);
            v.x += c.x; 
            v.y += c.y; 
            v.z += c.z;
            vertices[i] = v;
        }
    }

    void Rotate(double angle, char axis) {
        Point3D c = GetCenter();
        double rad = angle * 3.14159265 / 180.0;
        cli::array<double, 2>^ M = gcnew cli::array<double, 2>(4, 4);
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) M[i, j] = (i == j) ? 1.0 : 0.0;

        if (axis == 'x') {
            M[1, 1] = cos(rad); M[1, 2] = -sin(rad);
            M[2, 1] = sin(rad); M[2, 2] = cos(rad);
        }
        else if (axis == 'y') {
            M[0, 0] = cos(rad); M[0, 2] = sin(rad);
            M[2, 0] = -sin(rad); M[2, 2] = cos(rad);
        }
        else if (axis == 'z') {
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

    void Draw(Graphics^ g, int w, int h) {
        if (vertexCount == 0) return;
        Pen^ pen = gcnew Pen(Color::Blue, 2);
        float ox = w / 2.0f, oy = h / 2.0f;
        for (int i = 0; i < vertexCount; i++)
            for (int j = i + 1; j < vertexCount; j++)
                if (adjacencyMatrix[i, j] == 1)
                    g->DrawLine(pen, (float)vertices[i].x + ox, (float)vertices[i].y + oy,
                        (float)vertices[j].x + ox, (float)vertices[j].y + oy);
    }

    void ResetToOriginal() {
        for (int i = 0; i < vertices->Count; i++) vertices[i] = initialVertices[i];
    }
};
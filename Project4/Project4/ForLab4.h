#pragma once
#include <fstream>
#include <string>
#include <cmath>
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

public value struct Point3D {
    double x, y, z;
};

public ref class ConvexPolyhedron {
private:
    int vertexCount;
    List<Point3D>^ vertices;
    List<Point3D>^ initialVertices;
    cli::array<int, 2>^ adjacencyMatrix;

public:
    ConvexPolyhedron() {
        vertexCount = 0;
        vertices = gcnew List<Point3D>();
        initialVertices = gcnew List<Point3D>();
        adjacencyMatrix = gcnew cli::array<int, 2>(0, 0); 
    }

    Point3D GetCenter() {
        Point3D c; c.x = 0; c.y = 0; c.z = 0;
        if (vertices->Count == 0) return c;
        for each (Point3D v in vertices) {
            c.x += v.x; c.y += v.y; c.z += v.z;
        }
        c.x /= vertices->Count; c.y /= vertices->Count; c.z /= vertices->Count;
        return c;
    }

    bool LoadFromFile(String^ filePath) {
        std::string stdPath = msclr::interop::marshal_as<std::string>(filePath);
        std::ifstream file(stdPath);
        if (!file.is_open()) return false;

        int tempCount;
        if (!(file >> tempCount)) return false;
        this->vertexCount = tempCount;          

        vertices->Clear();
        initialVertices->Clear();

        for (int i = 0; i < vertexCount; i++) {
            double tx, ty, tz;
            if (file >> tx >> ty >> tz) { 
                Point3D p;
                p.x = tx; p.y = ty; p.z = tz;
                vertices->Add(p);
                initialVertices->Add(p);
            }
        }

        adjacencyMatrix = gcnew cli::array<int, 2>(vertexCount, vertexCount);
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                int tempVal;
                file >> tempVal;
                adjacencyMatrix[i, j] = tempVal;
            }
        }
        file.close();
        return true;
    }

    void ResetToOriginal() {
        for (int i = 0; i < vertices->Count; i++) {
            vertices[i] = initialVertices[i];
        }
    }

    void Scale(double sx, double sy, double sz) {
        Point3D c = GetCenter();
        for (int i = 0; i < vertices->Count; i++) {
            Point3D v = vertices[i];
            v.x = c.x + (v.x - c.x) * sx;
            v.y = c.y + (v.y - c.y) * sy;
            v.z = c.z + (v.z - c.z) * sz;
            vertices[i] = v;
        }
    }

    void Rotate(double angle, char axis) {
        Point3D c = GetCenter();
        double rad = angle * 3.141592653589793 / 180.0;

        for (int i = 0; i < vertices->Count; i++) {
            Point3D v = vertices[i];
            double x1 = v.x - c.x;
            double y1 = v.y - c.y;
            double z1 = v.z - c.z;

            double x2, y2, z2;

            if (axis == 'x') {
                x2 = x1;
                y2 = y1 * cos(rad) - z1 * sin(rad);
                z2 = y1 * sin(rad) + z1 * cos(rad);
            }
            else if (axis == 'y') {
                x2 = x1 * cos(rad) + z1 * sin(rad);
                y2 = y1;
                z2 = -x1 * sin(rad) + z1 * cos(rad);
            }
            else if (axis == 'z') {
                x2 = x1 * cos(rad) - y1 * sin(rad);
                y2 = x1 * sin(rad) + y1 * cos(rad);
                z2 = z1;
            }
            else continue;

            v.x = x2 + c.x;
            v.y = y2 + c.y;
            v.z = z2 + c.z;
            vertices[i] = v;
        }
    }

    void Draw(Graphics^ g, int w, int h) {
        if (vertexCount == 0 || adjacencyMatrix->GetLength(0) == 0) return;
        Pen^ pen = gcnew Pen(Color::Blue, 2);
        float ox = w / 2.0f, oy = h / 2.0f;
        for (int i = 0; i < vertexCount; i++) {
            for (int j = i + 1; j < vertexCount; j++) {
                if (adjacencyMatrix[i, j] == 1) {
                    g->DrawLine(pen, (float)vertices[i].x + ox, (float)vertices[i].y + oy,
                        (float)vertices[j].x + ox, (float)vertices[j].y + oy);
                }
            }
        }
    }
};
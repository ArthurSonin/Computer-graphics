#pragma once

// 1. ЗАХИСТ ВІД КОНФЛІКТУ: перейменовуємо системний IServiceProvider до будь-яких include
#define IServiceProvider IServiceProvider_Windows
#include <windows.h>
#undef IServiceProvider

#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

public value struct Point3D {
    double x, y, z, w;
};

public value struct Face {
    cli::array<int>^ v;
    System::Drawing::Color color;
};

public ref class ConvexPolyhedron {
private:
    System::Collections::Generic::List<Point3D>^ vertices;
    System::Collections::Generic::List<Face>^ faces;

    Point3D GetCentroid() {
        Point3D c = { 0, 0, 0, 1 };
        if (vertices->Count == 0) return c;
        for each(Point3D v in vertices) {
            c.x += v.x; c.y += v.y; c.z += v.z;
        }
        c.x /= vertices->Count;
        c.y /= vertices->Count;
        c.z /= vertices->Count;
        return c;
    }

    System::Drawing::PointF Project(Point3D p, float ox, float oy) {
        double alpha = 45 * 3.14159 / 180.0;
        double kx = 0.5;
        float scale = 1.0f;
        float xe = ox + (float)((p.y - kx * p.x * cos(alpha)) * scale);
        float ye = oy - (float)((p.z - kx * p.x * sin(alpha)) * scale);
        return System::Drawing::PointF(xe, ye);
    }

public:
    ConvexPolyhedron() {
        vertices = gcnew System::Collections::Generic::List<Point3D>();
        faces = gcnew System::Collections::Generic::List<Face>();
    }

    bool LoadFromFile(System::String^ fileName) {
        System::IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(fileName);
        std::string stdFileName = static_cast<const char*>(ptr.ToPointer());
        System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);

        std::ifstream file(stdFileName);
        if (!file.is_open()) return false;

        vertices->Clear(); faces->Clear();
        int vCount, fCount;
        if (!(file >> vCount)) return false;
        for (int i = 0; i < vCount; i++) {
            Point3D p; file >> p.x >> p.y >> p.z; p.w = 1.0;
            vertices->Add(p);
        }
        if (!(file >> fCount)) return false;
        for (int i = 0; i < fCount; i++) {
            int n; file >> n;
            cli::array<int>^ idxs = gcnew cli::array<int>(n);
            for (int j = 0; j < n; j++) {
                int e;
                file >> e;
                idxs[j] = e;
            }
            Face f; f.v = idxs;
            f.color = System::Drawing::Color::FromArgb(150, (i * 50) % 255, 100, 200);
            faces->Add(f);
        }
        return true;
    }

    void Scale(double sx, double sy, double sz) {
        Point3D c = GetCentroid();
        for (int i = 0; i < vertices->Count; i++) {
            Point3D v = vertices[i];
            v.x = c.x + (v.x - c.x) * sx;
            v.y = c.y + (v.y - c.y) * sy;
            v.z = c.z + (v.z - c.z) * sz;
            vertices[i] = v;
        }
    }

    void Rotate(double angle, char axis) {
        double rad = angle * 3.14159 / 180.0;
        Point3D c = GetCentroid(); 

        for (int i = 0; i < vertices->Count; i++) {
            Point3D v = vertices[i];
            double dx = v.x - c.x; 
            double dy = v.y - c.y;
            double dz = v.z - c.z;

            double newDx, newDy, newDz;

            if (axis == 'x') {
                newDx = dx;
                newDy = dy * cos(rad) - dz * sin(rad);
                newDz = dy * sin(rad) + dz * cos(rad);
            }
            else if (axis == 'y') {
                newDx = dx * cos(rad) + dz * sin(rad);
                newDy = dy;
                newDz = -dx * sin(rad) + dz * cos(rad);
            }
            else if (axis == 'z') {
                newDx = dx * cos(rad) - dy * sin(rad);
                newDy = dx * sin(rad) + dy * cos(rad);
                newDz = dz;
            }

            v.x = c.x + newDx;
            v.y = c.y + newDy;
            v.z = c.z + newDz;
            vertices[i] = v;
        }
    }

    void Draw(System::Drawing::Graphics^ g, int width, int height, bool hideInvisible) {
        if (vertices->Count == 0) return;

        float ox = (float)width / 2.0f;
        float oy = (float)height / 2.0f;
        float scale = 1.5f;

        System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black, 2);
        g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::HighQuality;

        for each(Face f in faces) {
            if (f.v->Length < 3) continue;

            cli::array<System::Drawing::PointF>^ screenPts = gcnew cli::array<System::Drawing::PointF>(f.v->Length);

            for (int i = 0; i < f.v->Length; i++) {
                Point3D p = vertices[f.v[i]];

                float x_proj = (float)(p.y - 0.35 * p.x) * scale;
                float y_proj = (float)(p.z - 0.35 * p.x) * scale;

                screenPts[i].X = ox + x_proj;
                screenPts[i].Y = oy - y_proj;
            }

            double area = 0;
            for (int i = 0; i < f.v->Length; i++) {
                int next = (i + 1) % f.v->Length;
                area += (screenPts[i].X * screenPts[next].Y) - (screenPts[next].X * screenPts[i].Y);
            }

            if (!hideInvisible || area < 0) {
                System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(f.color);
                g->FillPolygon(brush, screenPts);

                g->DrawPolygon(pen, screenPts);
            }
        }
    }
};
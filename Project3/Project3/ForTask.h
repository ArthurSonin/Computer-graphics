#pragma once
#include <vector>
#include <cmath>

using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

public ref class GeometryCore {
    // Структура для параметрів масштабування, щоб не передавати 3 змінні окремо
    value struct ViewSettings {
        float scale;
        float offsetX;
        float offsetY;
    };

public:
    // --- Математична логіка ---

    static Point CalculateCentralSymmetry(Point p, Point center) {
        return Point(2 * center.X - p.X, 2 * center.Y - p.Y);
    }

    static Point CalculateLineSymmetry(Point p, double A, double B, double C) {
        if (A == 0 && B == 0) return p;
        double dist = (A * p.X + B * p.Y - C) / (A * A + B * B);
        return Point(cvt(p.X - 2 * A * dist), cvt(p.Y - 2 * B * dist));
    }

    // 3
    static int CheckConvexity(List<Point>^ poly) {
        if (poly->Count < 3) return 0;
        bool hasPos = false, hasNeg = false;
        int n = poly->Count;

        for (int i = 0; i < n; i++) {
            double det = CrossProduct(poly[i], poly[(i + 1) % n], poly[(i + 2) % n]);
            if (det > 0) hasPos = true;
            if (det < 0) hasNeg = true;
        }
        if (hasPos && hasNeg) return 0; // Неопуклий
        return hasPos ? 1 : 2;
    }

    static List<Point>^ BuildConvexHull(List<Point>^ points) {
        if (points->Count < 3) return points;
        List<Point>^ hull = gcnew List<Point>();

        int l = 0;
        for (int i = 1; i < points->Count; i++)
            if (points[i].X < points[l].X) l = i;

        int p = l, q;
        do {
            hull->Add(points[p]);
            q = (p + 1) % points->Count;
            for (int i = 0; i < points->Count; i++) {
                if (Orientation(points[p], points[i], points[q]) == 1) q = i;
            }
            p = q;
        } while (p != l);

        return hull;
    }

    // --- Логіка малювання ---

    static void Draw(Graphics^ g, List<Point>^ points, float width, float height,
        bool drawAsPolygon, Point^ center, List<double>^ axisParams) {

        g->SmoothingMode = SmoothingMode::AntiAlias;
        g->Clear(Color::White);

        if (points->Count == 0 && center == nullptr && axisParams == nullptr) return;

        // Рахуємо масштаб
        ViewSettings vs = CalculateViewSettings(points, width, height);

        // 1 Малюємо центр симетрії
                if (center != nullptr) {
                    DrawCenterPoint(g, center, vs);
                }

        // 2 Малюємо вісь симетрії
        if (axisParams != nullptr && axisParams->Count >= 3) {
            DrawAxis(g, axisParams, vs);
        }

        // 3, 4 Малюємо лінії
        if (points->Count > 1) {
            DrawEdges(g, points, drawAsPolygon, vs);
        }

        // Малюємо точки та їх індекси
        DrawNodes(g, points, vs);
    }
    // 3, 4
    static void UpdateCanvas(PictureBox^ canvas, List<Point>^ points, bool asPolygon) {
        if (canvas->Width <= 0 || canvas->Height <= 0) return;

        Bitmap^ bmp = gcnew Bitmap(canvas->Width, canvas->Height);
        Graphics^ g = Graphics::FromImage(bmp);
        Draw(g, points, (float)canvas->Width, (float)canvas->Height, asPolygon, nullptr, nullptr);

        if (canvas->Image != nullptr) delete canvas->Image;
        canvas->Image = bmp;
        delete g;
    }

private:
    static ViewSettings CalculateViewSettings(List<Point>^ points, float w, float h) {
        float minX = 0, maxX = w, minY = 0, maxY = h;
        if (points->Count > 0) {
            minX = maxX = (float)points[0].X;
            minY = maxY = (float)points[0].Y;
            for each(Point p in points) {
                minX = Math::Min(minX, (float)p.X); maxX = Math::Max(maxX, (float)p.X);
                minY = Math::Min(minY, (float)p.Y); maxY = Math::Max(maxY, (float)p.Y);
            }
        }

        float padding = 40.0f;
        float rangeX = (maxX - minX) + padding * 2;
        float rangeY = (maxY - minY) + padding * 2;

        ViewSettings vs;
        vs.scale = Math::Min(w / (rangeX > 0 ? rangeX : 1), h / (rangeY > 0 ? rangeY : 1));
        vs.offsetX = (w - (maxX + minX) * vs.scale) / 2.0f;
        vs.offsetY = (h - (maxY + minY) * vs.scale) / 2.0f;
        return vs;
    }
    // 1
        static void DrawCenterPoint(Graphics^ g, Point^ c, ViewSettings vs) {
            float cx = c->X * vs.scale + vs.offsetX;
            float cy = c->Y * vs.scale + vs.offsetY;
            g->FillEllipse(Brushes::Orange, cx - 5.0f, cy - 5.0f, 10.0f, 10.0f);
            g->DrawString("Center", SystemFonts::DefaultFont, Brushes::Orange, cx + 5.0f, cy);
        }
    // 2
    static void DrawAxis(Graphics^ g, List<double>^ p, ViewSettings vs) {
        Pen^ axisPen = gcnew Pen(Color::Black, 2.0f);
        float lim = 2000.0f;
        if (Math::Abs(p[1]) > 0.0001) {
            float y1 = (float)((p[2] - p[0] * -lim) / p[1]);
            float y2 = (float)((p[2] - p[0] * lim) / p[1]);
            g->DrawLine(axisPen, -lim * vs.scale + vs.offsetX, y1 * vs.scale + vs.offsetY,
                lim * vs.scale + vs.offsetX, y2 * vs.scale + vs.offsetY);
        }
        else {
            float x_f = (float)(p[2] / p[0]);
            g->DrawLine(axisPen, x_f * vs.scale + vs.offsetX, -lim * vs.scale + vs.offsetY,
                x_f * vs.scale + vs.offsetX, lim * vs.scale + vs.offsetY);
        }
    }
    // 3
    static void DrawEdges(Graphics^ g, List<Point>^ pts, bool isPoly, ViewSettings vs) {
        Pen^ p = isPoly ? gcnew Pen(Color::Black, 1.5f) : gcnew Pen(Color::LightGray, 1.0f);
        if (!isPoly) p->DashStyle = DashStyle::Dash;

        int iterations = isPoly ? pts->Count : pts->Count - 1;
        for (int i = 0; i < iterations; i++) {
            Point p1 = pts[i];
            Point p2 = pts[(i + 1) % pts->Count];
            g->DrawLine(p, p1.X * vs.scale + vs.offsetX, p1.Y * vs.scale + vs.offsetY,
                p2.X * vs.scale + vs.offsetX, p2.Y * vs.scale + vs.offsetY);
        }
    }

    static void DrawNodes(Graphics^ g, List<Point>^ pts, ViewSettings vs) {
        for (int i = 0; i < pts->Count; i++) {
            float px = pts[i].X * vs.scale + vs.offsetX;
            float py = pts[i].Y * vs.scale + vs.offsetY;
            g->FillEllipse(Brushes::Red, px - 4.0f, py - 4.0f, 8.0f, 8.0f);
            g->DrawString(i.ToString(), SystemFonts::DefaultFont, Brushes::DarkBlue, px + 5.0f, py);
        }
    }

    static int cvt(double val) { return (int)Math::Floor(val + 0.5); }

    static double CrossProduct(Point a, Point b, Point c) {
        return (double)(b.X - a.X) * (c.Y - b.Y) - (double)(b.Y - a.Y) * (c.X - b.X);
    }

    static int Orientation(Point p, Point q, Point r) {
        double val = (double)(q.Y - p.Y) * (r.X - q.X) - (double)(q.X - p.X) * (r.Y - q.Y);
        if (val == 0) return 0;
        return (val < 0) ? 1 : 2;
    }
};
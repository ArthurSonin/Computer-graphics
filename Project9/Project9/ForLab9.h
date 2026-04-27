#pragma once
#include <cmath>
#include <complex>

using namespace System;
using namespace System::Drawing;

public ref class FractalManager {
private:
    Random^ rnd = gcnew Random();
public:
    // Фрактал Коха
    void DrawKoch(Graphics^ g, Pen^ pen, float x1, float y1, float x2, float y2, int depth) {
        if (depth == 0) {
            g->DrawLine(pen, x1, y1, x2, y2);
            return;
        }

        float dx = (x2 - x1) / 3.0f;
        float dy = (y2 - y1) / 3.0f;

        float xA = x1 + dx;
        float yA = y1 + dy;

        float xB = x1 + 2 * dx;
        float yB = y1 + 2 * dy;

        float sin60 = 0.866f;
        float xC = (xA + xB) / 2.0f - dy * sin60;
        float yC = (yA + yB) / 2.0f + dx * sin60;

        DrawKoch(g, pen, x1, y1, xA, yA, depth - 1);
        DrawKoch(g, pen, xA, yA, xC, yC, depth - 1);
        DrawKoch(g, pen, xC, yC, xB, yB, depth - 1);
        DrawKoch(g, pen, xB, yB, x2, y2, depth - 1);
    }

    // Фрактальне дерево
    void DrawTree(Graphics^ g, float x, float y, float a, float l) {
        if (l < 8) return;

        int x1 = (int)Math::Round(x + l * Math::Cos(a));
        int y1 = (int)Math::Round(y + l * Math::Sin(a));

        int p = (l > 100) ? 100 : (int)l;

        if (p < 40) {
            Color leafColor = (rnd->NextDouble() > 0.5) ? Color::Lime : Color::ForestGreen;
            Pen^ pLeaf = gcnew Pen(leafColor, 1.0f);
            for (int i = 0; i <= 3; i++) {
                g->DrawLine(pLeaf, x + i, y, (float)x1, (float)y1);
            }
        }
        else {
            Pen^ pBranch = gcnew Pen(Color::SaddleBrown, 1.0f);
            int thickness = p / 6;
            int offset = p / 12;
            for (int i = 0; i <= thickness; i++) {
                g->DrawLine(pBranch, x + i - offset, y, (float)x1, (float)y1);
            }
        }

        int branchCount = rnd->Next(2, 10);
        for (int i = 0; i < branchCount; i++) {
            int minL = (int)l / 6;
            float s = (float)(rnd->Next((int)l - minL) + minL);

            float a1 = a + 1.6f * (0.5f - (float)rnd->NextDouble());

            float nextX = x + s * (float)Math::Cos(a);
            float nextY = y + s * (float)Math::Sin(a);

            DrawTree(g, nextX, nextY, a1, (float)(p - 5 - rnd->Next(30)));
        }
    }

    // Трикутник Серпінського 
    void DrawSierpinski(Graphics^ g, PointF p1, PointF p2, PointF p3, int depth) {
        if (depth == 0) {
            array<PointF>^ points = { p1, p2, p3 };
            g->FillPolygon(Brushes::DarkSlateBlue, points);
            return;
        }

        PointF m1 = PointF((p1.X + p2.X) / 2.0f, (p1.Y + p2.Y) / 2.0f);
        PointF m2 = PointF((p2.X + p3.X) / 2.0f, (p2.Y + p3.Y) / 2.0f);
        PointF m3 = PointF((p1.X + p3.X) / 2.0f, (p1.Y + p3.Y) / 2.0f);

        DrawSierpinski(g, p1, m1, m3, depth - 1);
        DrawSierpinski(g, m1, p2, m2, depth - 1);
        DrawSierpinski(g, m3, m2, p3, depth - 1);
    }

    // Фрактал Жюліа
    void DrawJulia(Bitmap^ bmp, int maxIter, float scale, float reC, float imC) {
        int w = bmp->Width;
        int h = bmp->Height;

        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                double zx = 1.5 * (x - w / 2.0) / (0.5 * scale * w);
                double zy = (y - h / 2.0) / (0.5 * scale * h);

                int i = 0;
                while (zx * zx + zy * zy < 4 && i < maxIter) {
                    double tmp = zx * zx - zy * zy + reC;
                    zy = 2.0 * zx * zy + imC;
                    zx = tmp;
                    i++;
                }

                Color c = (i == maxIter) ? Color::Black : Color::FromArgb(i % 8 * 30, i % 4 * 60, i % 2 * 120);
                bmp->SetPixel(x, y, c);
            }
        }
    }

    // Фрактал Мандельброта
    void DrawMandelbrot(Bitmap^ bmp, int maxIter, float scale) {
        int w = bmp->Width;
        int h = bmp->Height;

        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                double cx = 1.5 * (x - w / 2.0) / (0.5 * scale * w) - 0.5;
                double cy = (y - h / 2.0) / (0.5 * scale * h);
                double zx = 0, zy = 0;

                int i = 0;
                while (zx * zx + zy * zy < 4 && i < maxIter) {
                    double tmp = zx * zx - zy * zy + cx;
                    zy = 2.0 * zx * zy + cy;
                    zx = tmp;
                    i++;
                }

                Color c = (i == maxIter) ? Color::Black : Color::FromArgb(i * 5 % 255, i * 2 % 255, i * 8 % 255);
                bmp->SetPixel(x, y, c);
            }
        }
    }
};
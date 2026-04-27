#pragma once
#include <cmath>
#include <vector>

using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Collections::Generic;

public ref class CurveManager {
public:
    PointF P1, P2, P3, P4;
    PointF R1, R4;

    CurveManager() {
        P1 = PointF(100, 300);
        P2 = PointF(150, 100);
        P3 = PointF(350, 100);
        P4 = PointF(400, 300);
        R1 = PointF(100, -100);
        R4 = PointF(100, 100);
    }

    List<PointF>^ GetHermitePoints(float step) {
        List<PointF>^ points = gcnew List<PointF>();
        for (float t = 0; t <= 1.001f; t += step) {
            float t2 = t * t; float t3 = t2 * t;
            float h1 = 2 * t3 - 3 * t2 + 1;
            float h2 = -2 * t3 + 3 * t2;
            float h3 = t3 - 2 * t2 + t;
            float h4 = t3 - t2;

            float x = P1.X * h1 + P4.X * h2 + R1.X * h3 + R4.X * h4;
            float y = P1.Y * h1 + P4.Y * h2 + R1.Y * h3 + R4.Y * h4;
            points->Add(PointF(x, y));
        }
        return points;
    }

    List<PointF>^ GetBezierPoints(float step) {
        List<PointF>^ points = gcnew List<PointF>();
        for (float t = 0; t <= 1.001f; t += step) {
            float b1 = (float)Math::Pow(1 - t, 3);
            float b2 = 3 * t * (float)Math::Pow(1 - t, 2);
            float b3 = 3 * t * t * (1 - t);
            float b4 = t * t * t;

            float x = P1.X * b1 + P2.X * b2 + P3.X * b3 + P4.X * b4;
            float y = P1.Y * b1 + P2.Y * b2 + P3.Y * b3 + P4.Y * b4;
            points->Add(PointF(x, y));
        }
        return points;
    }

    void Draw(Graphics^ g, bool drawBezier, bool drawHermite) {
        g->SmoothingMode = SmoothingMode::AntiAlias;

        Brush^ mainPtsBrush = Brushes::Black;

        g->FillEllipse(mainPtsBrush, (float)(P1.X - 5.0f), (float)(P1.Y - 5.0f), 10.0f, 10.0f);
        g->FillEllipse(mainPtsBrush, (float)(P4.X - 5.0f), (float)(P4.Y - 5.0f), 10.0f, 10.0f);

        if (drawBezier) {
            Pen^ penB = gcnew Pen(Color::Red, 2);
            Pen^ penLines = gcnew Pen(Color::Gray, 1);
            penLines->DashStyle = DashStyle::Dash;

            g->DrawLine(penLines, P1, P2);
            g->DrawLine(penLines, P4, P3);
            g->FillRectangle(Brushes::OrangeRed, (float)(P2.X - 4.0f), (float)(P2.Y - 4.0f), 8.0f, 8.0f);
            g->FillRectangle(Brushes::OrangeRed, (float)(P3.X - 4.0f), (float)(P3.Y - 4.0f), 8.0f, 8.0f);

            List<PointF>^ pts = GetBezierPoints(0.01f);
            for (int i = 0; i < pts->Count - 1; i++)
                g->DrawLine(penB, pts[i], pts[i + 1]);
        }

        if (drawHermite) {
            Pen^ penH = gcnew Pen(Color::Blue, 2);
            Pen^ penVec = gcnew Pen(Color::DeepSkyBlue, 2);
            penVec->EndCap = LineCap::ArrowAnchor; 

            g->DrawLine(penVec, P1.X, P1.Y, P1.X + R1.X, P1.Y + R1.Y);
            g->DrawLine(penVec, P4.X, P4.Y, P4.X + R4.X, P4.Y + R4.Y);

            List<PointF>^ pts = GetHermitePoints(0.01f);
            for (int i = 0; i < pts->Count - 1; i++)
                g->DrawLine(penH, pts[i], pts[i + 1]);
        }
    }
};
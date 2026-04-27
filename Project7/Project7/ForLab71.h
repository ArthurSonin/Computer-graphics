#pragma once
#include <cmath>
#include <vector>


using namespace System;
using namespace System::Drawing;

public ref class HorizonGraph {
private:
    PointF Project(double x, double y, double z, int w, int h) {
        double alpha = 45 * 3.14159265 / 180.0;
        double k = 0.5; 
        double scale = 40.0;

        float xe = (w / 2) + (float)((y - k * x * cos(alpha)) * scale);
        float ye = (h / 2) - (float)((z - k * x * sin(alpha)) * scale);

        return PointF(xe, ye);
    }

public:
    double f(double x, double y) {
        return sin(x) * cos(y);
    }

    void Draw(Graphics^ g, int w, int h, double a, double b, int steps, bool hideLines) {
        cli::array<double>^ topHorizon = gcnew cli::array<double>(w);
        cli::array<double>^ bottomHorizon = gcnew cli::array<double>(w);

        for (int i = 0; i < w; i++) {
            topHorizon[i] = (double)h;   
            bottomHorizon[i] = 0.0;       
        }

        double dx = a / steps;
        double dy = b / steps;

        Pen^ pTop = gcnew Pen(Color::Blue, 1);   
        Pen^ pBottom = gcnew Pen(Color::Red, 1);
        Pen^ pNet = gcnew Pen(Color::Black, 1); 

        for (double x = 0; x <= a; x += dx) {
            PointF prev;
            bool isFirstPointInRow = true;

            for (double y = 0; y <= b; y += dy) {
                double z = f(x, y);
                PointF curr = Project(x, y, z, w, h);

                if (!hideLines) {
                    if (!isFirstPointInRow) g->DrawLine(pNet, prev, curr);
                }
                else {
                    int ix = (int)curr.X;

                    if (ix >= 0 && ix < w) {
                        if (curr.Y < topHorizon[ix]) {
                            if (!isFirstPointInRow) g->DrawLine(pTop, prev, curr);
                            topHorizon[ix] = curr.Y;
                        }
                        else if (curr.Y > bottomHorizon[ix]) {
                            if (!isFirstPointInRow) g->DrawLine(pBottom, prev, curr);
                            bottomHorizon[ix] = curr.Y; 
                        }
                    }
                }
                prev = curr;
                isFirstPointInRow = false;
            }
        }
    }
};
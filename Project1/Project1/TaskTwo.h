#pragma once
#include <fstream>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;

public ref class MyShape {
private:
    List<PointF>^ points;
    float scale;
public:
    MyShape() {
        points = gcnew List<PointF>();
        scale = 1.0f;
    }
    property float Scale {
        float get() { return scale; }
        void set(float value) { scale = value; }
    }
    void LoadFromFile(String^ fileName) {
        points->Clear();
        IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(fileName);
        std::ifstream file((char*)ptr.ToPointer());
        System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);
        float x, y;
        while (file >> x >> y) { points->Add(PointF(x, y)); }
        file.close();
    }
    void Draw(Graphics^ g, float centerX, float centerY) {
        if (points->Count < 2) return;
        Pen^ pen = gcnew Pen(Color::Red, 2);
        for (int i = 0; i < points->Count - 1; i++) {
            g->DrawLine(pen, centerX + points[i].X * scale, centerY - points[i].Y * scale,
                centerX + points[i + 1].X * scale, centerY - points[i + 1].Y * scale);
        }
    }
    void Destroy() { points->Clear(); }
};
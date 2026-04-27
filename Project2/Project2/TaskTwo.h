#pragma once
#include <fstream>
#include <vector>
#include <cmath>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;

public ref class MyShape {
private:
    List<PointF>^ points;
    PointF fixedCenter; // Сюди запишемо центр ОДИН раз
    bool centerIsSet = false; // Щоб знати, що центр уже готовий
    float drawScale; // Масштаб лише для відображення на екрані

public:
    MyShape() {
        points = gcnew List<PointF>();
        drawScale = 1.0f;
    }

    property float Scale {
        float get() { return drawScale; }
        void set(float value) { drawScale = value; }
    }

    // 1. Обчислення контрольної точки (середнє арифметичне)
    PointF GetControlPoint() {
        if (points->Count == 0) return PointF(0, 0);
        float sumX = 0, sumY = 0;
        for each (PointF p in points) {
            sumX += p.X;
            sumY += p.Y;
        }
        return PointF(sumX / points->Count, sumY / points->Count);
    }

    // --- МЕТОДИ В ОДНОРІДНИХ КООРДИНАТАХ (МАТРИЦІ) ---

    // Універсальний метод множення точки на матрицю 3x3
    PointF MultiplyMatrix(PointF p, float m[3][3]) {
        // [x1, y1, 1] * Matrix
        float x = p.X * m[0][0] + p.Y * m[1][0] + 1.0f * m[2][0];
        float y = p.X * m[0][1] + p.Y * m[1][1] + 1.0f * m[2][1];
        // Третя координата W завжди 1 для афінних перетворень
        return PointF(x, y);
    }

    // Матричний зсув (Translation)
    void TranslateMatrix(float dx, float dy) {
        float M[3][3] = {
            {1,  0,  0},
            {0,  1,  0},
            {dx, dy, 1}
        };
        for (int i = 0; i < points->Count; i++)
            points[i] = MultiplyMatrix(points[i], M);
    }

    // Масштабування відносно контрольної точки (Матричне)
    void ScaleMatrix(float sx, float sy) {
        PointF cp = GetControlPoint();
        // Комбіноване перетворення: Т(-cp) * S(sx,sy) * T(cp)
        TranslateMatrix(-cp.X, -cp.Y); // Зсув у 0,0

        float M[3][3] = {
            {sx, 0,  0},
            {0,  sy, 0},
            {0,  0,  1}
        };
        for (int i = 0; i < points->Count; i++)
            points[i] = MultiplyMatrix(points[i], M);

        TranslateMatrix(cp.X, cp.Y); // Зсув назад
    }

    // Поворот навколо контрольної точки (Матричний)
    void RotateMatrix(float angleDegree) {
        PointF cp = GetControlPoint();
        float rad = angleDegree * 3.14159265f / 180.0f;
        float cosA = cos(rad);
        float sinA = sin(rad);

        TranslateMatrix(-cp.X, -cp.Y); // Крок 1: Зсув у центр

        float M[3][3] = {
            { cosA, sinA, 0},
            {-sinA, cosA, 0},
            {0,     0,    1}
        };
        for (int i = 0; i < points->Count; i++)
            points[i] = MultiplyMatrix(points[i], M);
    }

    // --- МЕТОДИ В ЗВИЧАЙНИХ КООРДИНАТАХ ---

    void TranslateSimple(float dx, float dy) {
        for (int i = 0; i < points->Count; i++) {
            points[i] = PointF(points[i].X + dx, points[i].Y + dy);
        }
    }

    void ScaleSimple(float sx, float sy) {
        // 1. Отримуємо власну контрольну точку (середнє арифметичне)
        PointF cp = GetControlPoint();

        for (int i = 0; i < points->Count; i++) {
            // 2. Обчислюємо відстань від точки до центру
            float dx = points[i].X - cp.X;
            float dy = points[i].Y - cp.Y;

            // 3. Масштабуємо ці відстані та додаємо назад до координат центру
            float x = cp.X + dx * sx;
            float y = cp.Y + dy * sy;

            points[i] = PointF(x, y);
        }
    }

    void RotateSimple(float angle) {
        PointF cp = GetControlPoint();
        float rad = angle * 3.14159265f / 180.0f;
        for (int i = 0; i < points->Count; i++) {
            float dx = points[i].X - cp.X;
            float dy = points[i].Y - cp.Y;
            float x = cp.X + dx * cos(rad) - dy * sin(rad);
            float y = cp.Y + dx * sin(rad) + dy * cos(rad);
            points[i] = PointF(x, y);
        }
    }

    // Стандартні методи завантаження та малювання
    void LoadFromFile(String^ fileName) {
        points->Clear();
        IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(fileName);
        std::ifstream file((char*)ptr.ToPointer());
        System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);
        float x, y;
        while (file >> x >> y) { points->Add(PointF(x, y)); }
        file.close();
    }

    void Draw(Graphics^ g, float screenCX, float screenCY) {
        if (points->Count < 2) return;
        Pen^ pen = gcnew Pen(Color::Red, 2);
        for (int i = 0; i < points->Count - 1; i++) {
            g->DrawLine(pen, screenCX + points[i].X * drawScale, screenCY - points[i].Y * drawScale,
                screenCX + points[i + 1].X * drawScale, screenCY - points[i + 1].Y * drawScale);
        }
    }

    void Destroy() { points->Clear(); }
};
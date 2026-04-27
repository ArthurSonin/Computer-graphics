#pragma once
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms; // Це обов'язково для TextBox та MessageBox

public ref class MyShape {
private:
    List<PointF>^ points;
    float drawScale;

public:
    MyShape() {
        points = gcnew List<PointF>();
        drawScale = 1.0f;
    }

    // Властивість для масштабу
    property float Scale {
        float get() { return drawScale; }
        void set(float value) { drawScale = value; }
    }

    // Метод завантаження з файлу (має бути ПЕРЕД тим, як його викличуть)
    void LoadFromFile(String^ fileName) {
        points->Clear();
        // Конвертація String^ у стандартний string для ifstream
        IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(fileName);
        ifstream file((char*)ptr.ToPointer());
        System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);

        float x, y;
        while (file >> x >> y) {
            points->Add(PointF(x, y));
        }
        file.close();
    }

    // Твій метод, який видавав помилки
    void LoadFromTextBox(TextBox^ tb) {
        try {
            // Тепер LoadFromFile вже відомий програмі
            this->LoadFromFile("data.txt");

            // Зчитуємо масштаб і записуємо у властивість Scale цього ж об'єкта
            this->Scale = Convert::ToSingle(tb->Text);

            MessageBox::Show("Дані завантажено з масштабом: " + tb->Text);
        }
        catch (Exception^ ex) {
            MessageBox::Show("Помилка! Перевірте дані в полі введення.");
        }
    }

    // Метод малювання (щоб бачити зірку)
    void Draw(Graphics^ g, float screenCX, float screenCY) {
        if (points->Count < 2) return;
        Pen^ pen = gcnew Pen(Color::Red, 2);
        for (int i = 0; i < points->Count - 1; i++) {
            g->DrawLine(pen,
                screenCX + points[i].X * drawScale,
                screenCY - points[i].Y * drawScale,
                screenCX + points[i + 1].X * drawScale,
                screenCY - points[i + 1].Y * drawScale);
        }
    }
};
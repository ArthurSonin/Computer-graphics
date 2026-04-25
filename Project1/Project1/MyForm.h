#pragma once
#include "TaskTwo.h"
#include <fstream>
#include <vector>
#include <cmath>


namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->figure = gcnew MyShape();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox7;

	private:
		MyShape^ figure;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(143, 6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(429, 233);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(37, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(37, 64);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"a=";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(22, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"b=";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(21, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"h=";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(37, 93);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 7;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(974, 424);
			this->tabControl1->TabIndex = 8;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->textBox6);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->textBox5);
			this->tabPage1->Controls->Add(this->textBox4);
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(966, 395);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(7, 182);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(49, 16);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Scale=";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(59, 179);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(78, 22);
			this->textBox6->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(7, 154);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(31, 16);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Oy=";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 127);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 16);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Ox=";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(37, 151);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 9;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(37, 122);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 8;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label7);
			this->tabPage2->Controls->Add(this->textBox7);
			this->tabPage2->Controls->Add(this->pictureBox2);
			this->tabPage2->Controls->Add(this->button4);
			this->tabPage2->Controls->Add(this->button3);
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(966, 395);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(4, 98);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(49, 16);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Scale=";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(58, 95);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(60, 22);
			this->textBox7->TabIndex = 4;
			this->textBox7->Text = L"3";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::White;
			this->pictureBox2->Location = System::Drawing::Point(125, 6);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(685, 383);
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(7, 66);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(112, 23);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Destroy";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(7, 36);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(112, 23);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Draw";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Load";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(974, 468);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// 1. Отримуємо математичні параметри графіка
		double a = Convert::ToDouble(textBox1->Text);
		double b = Convert::ToDouble(textBox2->Text);
		double h = Convert::ToDouble(textBox3->Text);

		// 2. Отримуємо параметри масштабування та центру
		float scale = Convert::ToSingle(textBox6->Text);
		float centerX = Convert::ToSingle(textBox4->Text);
		float centerY = Convert::ToSingle(textBox5->Text);

		if (a >= b || h <= 0) {
			MessageBox::Show("Некоректні інтервал або крок!");
			return;
		}

		// 3. Створюємо Bitmap для малювання
		Bitmap^ bmp = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		Graphics^ g = Graphics::FromImage(bmp);
		g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
		g->Clear(Color::White);

		int w = pictureBox1->Width;
		int h_p = pictureBox1->Height;

		// 4. Налаштування пера
		Pen^ pAxes = gcnew Pen(Color::Black, 1);
		Pen^ pGraph = gcnew Pen(Color::Blue, 2);

		// Малюємо стрілочки на осях
		pAxes->CustomEndCap = gcnew Drawing2D::AdjustableArrowCap(3, 3);

		// 5. Малюємо осі координат X та Y 
		// Вісь X 
		g->DrawLine(pAxes, 0.0f, centerY, (float)w, centerY);
		// Вісь Y 
		g->DrawLine(pAxes, centerX, (float)h_p, centerX, 0.0f);

		// Додаємо підписи осей
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 10);
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
		g->DrawString("X", drawFont, drawBrush, (float)w - 20, centerY + 5);
		g->DrawString("Y", drawFont, drawBrush, centerX + 5, 5.0f);

		// 6. Малюємо графік функції y = f(x)
		// Масштабування: x_screen = centerX + x_math * scale
		// y_screen = centerY - y_math * scale 
		for (double x = a; x < b; x += h) {
			float x1 = centerX + (float)(x * scale);
			float y1 = centerY - (float)(Math::Sin(x) * scale);

			float x2 = centerX + (float)((x + h) * scale);
			float y2 = centerY - (float)(Math::Sin(x + h) * scale);

			// Перевірка, щоб не малювати за межами PictureBox 
			g->DrawLine(pGraph, x1, y1, x2, y2);
		}

		// 7. Відображаємо результат
		pictureBox1->Image = bmp;

	}
	catch (...) {
		MessageBox::Show("Помилка! Перевірте правильність заповнення всіх полів (a, b, h, scale, center X, center Y).");
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	try {		
		figure->LoadFromFile("data.txt");
		figure->Scale = Convert::ToSingle(textBox7->Text); // Беремо масштаб з поля
		MessageBox::Show("Дані завантажено!");
	}
	catch (...) {
		MessageBox::Show("Помилка завантаження файлу!");
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Bitmap^ bmp = gcnew Bitmap(pictureBox2->Width, pictureBox2->Height);
	Graphics^ g = Graphics::FromImage(bmp);
	g->Clear(Color::White);

	// Центр для малювання об'єкта (наприклад, центр PictureBox)
	float cx = pictureBox2->Width / 2;
	float cy = pictureBox2->Height / 2;

	figure->Scale = Convert::ToSingle(textBox7->Text);
	figure->Draw(g, cx, cy);

	pictureBox2->Image = bmp;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	figure->Destroy();
	pictureBox2->Image = nullptr;
	MessageBox::Show("Об'єкт знищено!");
}
};
}

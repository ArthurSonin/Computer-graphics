#pragma once

// 1. Спочатку ВСІ системні та стандартні бібліотеки
#include <fstream>
#include <vector>
#include <cmath>

// 3. Тепер твої файли
#include "ForLab71.h"
#include "ForLab72.h"

namespace Project7 {

	#undef IServiceProvider

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		ConvexPolyhedron^ polyhedron;
	public:
		MyForm(void)
		{
			InitializeComponent();
			polyhedron = gcnew ConvexPolyhedron();
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
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private:
		/// <summary>
		System::Collections::Generic::List<System::Drawing::Point>^ currentPolygon;
	private: System::Windows::Forms::CheckBox^ checkBox1;


	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::HScrollBar^ hScrollBar1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
		   /// Required designer variable.
			/// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			   this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			   this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			   this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->label10 = (gcnew System::Windows::Forms::Label());
			   this->label11 = (gcnew System::Windows::Forms::Label());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->tabControl1->SuspendLayout();
			   this->tabPage1->SuspendLayout();
			   this->groupBox1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->tabPage2->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   this->groupBox2->SuspendLayout();
			   this->groupBox3->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // tabControl1
			   // 
			   this->tabControl1->Controls->Add(this->tabPage1);
			   this->tabControl1->Controls->Add(this->tabPage2);
			   this->tabControl1->Location = System::Drawing::Point(-4, -1);
			   this->tabControl1->Name = L"tabControl1";
			   this->tabControl1->SelectedIndex = 0;
			   this->tabControl1->Size = System::Drawing::Size(1453, 632);
			   this->tabControl1->TabIndex = 0;
			   // 
			   // tabPage1
			   // 
			   this->tabPage1->BackColor = System::Drawing::Color::DarkSeaGreen;
			   this->tabPage1->Controls->Add(this->button5);
			   this->tabPage1->Controls->Add(this->checkBox1);
			   this->tabPage1->Controls->Add(this->groupBox1);
			   this->tabPage1->Controls->Add(this->button2);
			   this->tabPage1->Controls->Add(this->pictureBox1);
			   this->tabPage1->Location = System::Drawing::Point(4, 25);
			   this->tabPage1->Name = L"tabPage1";
			   this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			   this->tabPage1->Size = System::Drawing::Size(1445, 603);
			   this->tabPage1->TabIndex = 0;
			   this->tabPage1->Text = L"tabPage1";
			   // 
			   // button5
			   // 
			   this->button5->Location = System::Drawing::Point(6, 77);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(163, 30);
			   this->button5->TabIndex = 10;
			   this->button5->Text = L"Намалювати";
			   this->button5->UseVisualStyleBackColor = true;
			   this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click_1);
			   // 
			   // checkBox1
			   // 
			   this->checkBox1->AutoSize = true;
			   this->checkBox1->Location = System::Drawing::Point(6, 51);
			   this->checkBox1->Name = L"checkBox1";
			   this->checkBox1->Size = System::Drawing::Size(184, 20);
			   this->checkBox1->TabIndex = 9;
			   this->checkBox1->Text = L"Вилучати невидимі лінії";
			   this->checkBox1->UseVisualStyleBackColor = true;
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Controls->Add(this->label3);
			   this->groupBox1->Controls->Add(this->label6);
			   this->groupBox1->Controls->Add(this->textBox4);
			   this->groupBox1->Controls->Add(this->label2);
			   this->groupBox1->Controls->Add(this->textBox2);
			   this->groupBox1->Controls->Add(this->label1);
			   this->groupBox1->Controls->Add(this->textBox1);
			   this->groupBox1->Location = System::Drawing::Point(6, 0);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(357, 45);
			   this->groupBox1->TabIndex = 5;
			   this->groupBox1->TabStop = false;
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(117, 18);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(22, 16);
			   this->label3->TabIndex = 7;
			   this->label3->Text = L"b=";
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Location = System::Drawing::Point(186, 18);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(111, 16);
			   this->label6->TabIndex = 4;
			   this->label6->Text = L"Кількість кроків:";
			   // 
			   // textBox4
			   // 
			   this->textBox4->Location = System::Drawing::Point(306, 15);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->Size = System::Drawing::Size(45, 22);
			   this->textBox4->TabIndex = 1;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(45, 18);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(22, 16);
			   this->label2->TabIndex = 6;
			   this->label2->Text = L"a=";
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(143, 15);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(38, 22);
			   this->textBox2->TabIndex = 5;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(6, 18);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(41, 16);
			   this->label1->TabIndex = 4;
			   this->label1->Text = L"Межі:";
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(71, 15);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(41, 22);
			   this->textBox1->TabIndex = 1;
			   // 
			   // button2
			   // 
			   this->button2->Location = System::Drawing::Point(187, 77);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(163, 30);
			   this->button2->TabIndex = 3;
			   this->button2->Text = L"Очистити";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::Color::Gainsboro;
			   this->pictureBox1->Location = System::Drawing::Point(369, 0);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(1070, 600);
			   this->pictureBox1->TabIndex = 0;
			   this->pictureBox1->TabStop = false;
			   // 
			   // tabPage2
			   // 
			   this->tabPage2->BackColor = System::Drawing::Color::DarkSeaGreen;
			   this->tabPage2->Controls->Add(this->hScrollBar1);
			   this->tabPage2->Controls->Add(this->pictureBox2);
			   this->tabPage2->Controls->Add(this->groupBox2);
			   this->tabPage2->Controls->Add(this->button4);
			   this->tabPage2->Location = System::Drawing::Point(4, 25);
			   this->tabPage2->Name = L"tabPage2";
			   this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			   this->tabPage2->Size = System::Drawing::Size(1445, 603);
			   this->tabPage2->TabIndex = 1;
			   this->tabPage2->Text = L"tabPage2";
			   // 
			   // hScrollBar1
			   // 
			   this->hScrollBar1->Location = System::Drawing::Point(6, 218);
			   this->hScrollBar1->Name = L"hScrollBar1";
			   this->hScrollBar1->Size = System::Drawing::Size(220, 21);
			   this->hScrollBar1->TabIndex = 7;
			   this->hScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar1_Scroll);
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->BackColor = System::Drawing::Color::LightGray;
			   this->pictureBox2->Location = System::Drawing::Point(229, 0);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(1220, 607);
			   this->pictureBox2->TabIndex = 6;
			   this->pictureBox2->TabStop = false;
			   // 
			   // groupBox2
			   // 
			   this->groupBox2->Controls->Add(this->groupBox3);
			   this->groupBox2->Controls->Add(this->button1);
			   this->groupBox2->Controls->Add(this->textBox8);
			   this->groupBox2->Controls->Add(this->textBox9);
			   this->groupBox2->Controls->Add(this->textBox10);
			   this->groupBox2->Controls->Add(this->label9);
			   this->groupBox2->Controls->Add(this->label10);
			   this->groupBox2->Controls->Add(this->label11);
			   this->groupBox2->Location = System::Drawing::Point(6, 35);
			   this->groupBox2->Name = L"groupBox2";
			   this->groupBox2->Size = System::Drawing::Size(220, 180);
			   this->groupBox2->TabIndex = 5;
			   this->groupBox2->TabStop = false;
			   // 
			   // groupBox3
			   // 
			   this->groupBox3->Controls->Add(this->button3);
			   this->groupBox3->Controls->Add(this->textBox5);
			   this->groupBox3->Controls->Add(this->textBox6);
			   this->groupBox3->Controls->Add(this->textBox7);
			   this->groupBox3->Controls->Add(this->label5);
			   this->groupBox3->Controls->Add(this->label4);
			   this->groupBox3->Controls->Add(this->label7);
			   this->groupBox3->Controls->Add(this->label8);
			   this->groupBox3->Controls->Add(this->textBox3);
			   this->groupBox3->Location = System::Drawing::Point(93, 10);
			   this->groupBox3->Name = L"groupBox3";
			   this->groupBox3->Size = System::Drawing::Size(121, 164);
			   this->groupBox3->TabIndex = 7;
			   this->groupBox3->TabStop = false;
			   // 
			   // button3
			   // 
			   this->button3->Location = System::Drawing::Point(6, 126);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(106, 32);
			   this->button3->TabIndex = 12;
			   this->button3->Text = L"Повернути";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_1);
			   // 
			   // textBox5
			   // 
			   this->textBox5->Location = System::Drawing::Point(39, 99);
			   this->textBox5->Name = L"textBox5";
			   this->textBox5->Size = System::Drawing::Size(73, 22);
			   this->textBox5->TabIndex = 11;
			   // 
			   // textBox6
			   // 
			   this->textBox6->Location = System::Drawing::Point(39, 70);
			   this->textBox6->Name = L"textBox6";
			   this->textBox6->Size = System::Drawing::Size(73, 22);
			   this->textBox6->TabIndex = 10;
			   // 
			   // textBox7
			   // 
			   this->textBox7->Location = System::Drawing::Point(38, 41);
			   this->textBox7->Name = L"textBox7";
			   this->textBox7->Size = System::Drawing::Size(74, 22);
			   this->textBox7->TabIndex = 9;
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(7, 102);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(26, 16);
			   this->label5->TabIndex = 8;
			   this->label5->Text = L"Zr=";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(6, 73);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(27, 16);
			   this->label4->TabIndex = 7;
			   this->label4->Text = L"Yr=";
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Location = System::Drawing::Point(6, 44);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(26, 16);
			   this->label7->TabIndex = 6;
			   this->label7->Text = L"Xr=";
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Location = System::Drawing::Point(5, 16);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(37, 16);
			   this->label8->TabIndex = 0;
			   this->label8->Text = L"Кут=";
			   // 
			   // textBox3
			   // 
			   this->textBox3->Location = System::Drawing::Point(48, 13);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(64, 22);
			   this->textBox3->TabIndex = 1;
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(7, 103);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(82, 71);
			   this->button1->TabIndex = 6;
			   this->button1->Text = L"Маштабування";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			   // 
			   // textBox8
			   // 
			   this->textBox8->Location = System::Drawing::Point(33, 75);
			   this->textBox8->Name = L"textBox8";
			   this->textBox8->Size = System::Drawing::Size(54, 22);
			   this->textBox8->TabIndex = 5;
			   // 
			   // textBox9
			   // 
			   this->textBox9->Location = System::Drawing::Point(33, 46);
			   this->textBox9->Name = L"textBox9";
			   this->textBox9->Size = System::Drawing::Size(54, 22);
			   this->textBox9->TabIndex = 4;
			   // 
			   // textBox10
			   // 
			   this->textBox10->Location = System::Drawing::Point(32, 17);
			   this->textBox10->Name = L"textBox10";
			   this->textBox10->Size = System::Drawing::Size(55, 22);
			   this->textBox10->TabIndex = 3;
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->Location = System::Drawing::Point(7, 78);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(22, 16);
			   this->label9->TabIndex = 2;
			   this->label9->Text = L"Z=";
			   // 
			   // label10
			   // 
			   this->label10->AutoSize = true;
			   this->label10->Location = System::Drawing::Point(6, 49);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(23, 16);
			   this->label10->TabIndex = 1;
			   this->label10->Text = L"Y=";
			   // 
			   // label11
			   // 
			   this->label11->AutoSize = true;
			   this->label11->Location = System::Drawing::Point(6, 20);
			   this->label11->Name = L"label11";
			   this->label11->Size = System::Drawing::Size(22, 16);
			   this->label11->TabIndex = 0;
			   this->label11->Text = L"X=";
			   // 
			   // button4
			   // 
			   this->button4->Location = System::Drawing::Point(4, 3);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(222, 32);
			   this->button4->TabIndex = 4;
			   this->button4->Text = L"Завантажити дані";
			   this->button4->UseVisualStyleBackColor = true;
			   this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click_1);
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->FileName = L"openFileDialog1";
			   this->openFileDialog1->InitialDirectory = L"D:\\універ\\2 куркурс\\grafik\\Project7\\Project7";
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1445, 633);
			   this->Controls->Add(this->tabControl1);
			   this->Name = L"MyForm";
			   this->Text = L"MyForm";
			   this->tabControl1->ResumeLayout(false);
			   this->tabPage1->ResumeLayout(false);
			   this->tabPage1->PerformLayout();
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->tabPage2->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   this->groupBox2->ResumeLayout(false);
			   this->groupBox2->PerformLayout();
			   this->groupBox3->ResumeLayout(false);
			   this->groupBox3->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->Image = nullptr;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		pictureBox2->Image = nullptr;
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button5_Click_1(System::Object^ sender, System::EventArgs^ e) {
		try {
			double a = System::Convert::ToDouble(textBox1->Text);
			double b = System::Convert::ToDouble(textBox2->Text);
			int steps = System::Convert::ToInt32(textBox4->Text);
			bool hide = checkBox1->Checked;

			if (pictureBox1->Image != nullptr) delete pictureBox1->Image;
			Bitmap^ bmp = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			Graphics^ g = Graphics::FromImage(bmp);
			g->Clear(Color::White);

			HorizonGraph^ graph = gcnew HorizonGraph();
			graph->Draw(g, bmp->Width, bmp->Height, a, b, steps, hide);

			pictureBox1->Image = bmp;
		}
		catch (...) {
			MessageBox::Show("Будь ласка, введіть коректні числа в поля a, b та кроки.");
		}
	}
	private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (polyhedron->LoadFromFile(openFileDialog1->FileName)) {
				if (pictureBox2->Image != nullptr) delete pictureBox2->Image;
				System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(pictureBox2->Width, pictureBox2->Height);
				System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(bmp);
				g->Clear(System::Drawing::Color::White);
				polyhedron->Draw(g, bmp->Width, bmp->Height, true);
				pictureBox2->Image = bmp;
				delete g;
			}
			else {
				MessageBox::Show("Помилка при читанні файлу!");
			}
		}
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		try {
			double sx = System::Convert::ToDouble(textBox10->Text);
			double sy = System::Convert::ToDouble(textBox9->Text);
			double sz = System::Convert::ToDouble(textBox8->Text);

			polyhedron->Scale(sx, sy, sz);

			if (pictureBox2->Image != nullptr) delete pictureBox2->Image;
			System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(pictureBox2->Width, pictureBox2->Height);
			System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(bmp);
			g->Clear(System::Drawing::Color::White);

			polyhedron->Draw(g, bmp->Width, bmp->Height, true);

			pictureBox2->Image = bmp;
			delete g;
		}
		catch (...) {
			System::Windows::Forms::MessageBox::Show("Помилка вводу даних!");
		}
	}
	private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
		try {
			double angle = System::Convert::ToDouble(textBox3->Text);

			if (System::Convert::ToDouble(textBox7->Text) > 0) polyhedron->Rotate(angle, 'x');
			if (System::Convert::ToDouble(textBox6->Text) > 0) polyhedron->Rotate(angle, 'y');
			if (System::Convert::ToDouble(textBox5->Text) > 0) polyhedron->Rotate(angle, 'z');

			if (pictureBox2->Image != nullptr) delete pictureBox2->Image;
			System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(pictureBox2->Width, pictureBox2->Height);
			System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(bmp);
			g->Clear(System::Drawing::Color::White);

			polyhedron->Draw(g, bmp->Width, bmp->Height, true);

			pictureBox2->Image = bmp;
			delete g;
		}
		catch (...) {
			System::Windows::Forms::MessageBox::Show("Помилка при повороті!");
		}
	}
	private: System::Void hScrollBar1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
		try {
			double angle = System::Convert::ToDouble(textBox3->Text);

			if (System::Convert::ToDouble(textBox7->Text) > 0) polyhedron->Rotate(angle, 'x');
			if (System::Convert::ToDouble(textBox6->Text) > 0) polyhedron->Rotate(angle, 'y');
			if (System::Convert::ToDouble(textBox5->Text) > 0) polyhedron->Rotate(angle, 'z');

			if (pictureBox2->Image != nullptr) delete pictureBox2->Image;
			System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(pictureBox2->Width, pictureBox2->Height);
			System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(bmp);
			g->Clear(System::Drawing::Color::White);

			polyhedron->Draw(g, bmp->Width, bmp->Height, true);

			pictureBox2->Image = bmp;
			delete g;
		}
		catch (...) {
			System::Windows::Forms::MessageBox::Show("Помилка при повороті!");
		}
	}
};
}


#pragma once
#include "ForTask.h"
#include <fstream>
#include <vector>
#include <cmath>

namespace Project3 {

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
	public:
		MyForm(void)
		{
			InitializeComponent();

			this->polyPoints->Add(Point(50, 50));
			this->polyPoints->Add(Point(150, 50));
			this->polyPoints->Add(Point(100, 150));

			this->cloudPoints = gcnew List<Point>();
			this->polyPoints = gcnew List<Point>();

			GeometryCore::UpdateCanvas(this->pictureBox2, this->polyPoints, true);
			this->pictureBox2->Image = nullptr;
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
	private:
		List<Point>^ cloudPoints;
		System::Drawing::Point p1;
		System::Drawing::Point c1;
		System::Drawing::Point r1;
		bool isComputed1 = false;
		System::Collections::Generic::List<System::Drawing::Point>^ polyPoints = gcnew System::Collections::Generic::List<System::Drawing::Point>();
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: GeometryCore^ figure;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::ListBox^ ListPoints;
	private: System::Windows::Forms::ListBox^ ListEnteredPoints;

	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label26;

	private:
		/// <summary>
		System::Collections::Generic::List<System::Drawing::Point>^ currentPolygon;
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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->ListPoints = (gcnew System::Windows::Forms::ListBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->ListEnteredPoints = (gcnew System::Windows::Forms::ListBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->tabPage4->SuspendLayout();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Location = System::Drawing::Point(-4, -1);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1267, 588);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->tabPage1->Controls->Add(this->label23);
			this->tabPage1->Controls->Add(this->label22);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1259, 559);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(6, 135);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(80, 16);
			this->label23->TabIndex = 8;
			this->label23->Text = L"Результат:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(86, 136);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(51, 16);
			this->label22->TabIndex = 7;
			this->label22->Text = L"label22";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Location = System::Drawing::Point(6, 51);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(332, 45);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(222, 18);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 16);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Y=";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(115, 18);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(22, 16);
			this->label5->TabIndex = 6;
			this->label5->Text = L"X=";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(251, 15);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(75, 22);
			this->textBox3->TabIndex = 5;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 18);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(106, 16);
			this->label6->TabIndex = 4;
			this->label6->Text = L"Центр симетрії:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(143, 15);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(75, 22);
			this->textBox4->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(6, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(332, 45);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(222, 18);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(23, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Y=";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(115, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(22, 16);
			this->label2->TabIndex = 6;
			this->label2->Text = L"X=";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(251, 15);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(75, 22);
			this->textBox2->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Вхідна точка:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(143, 15);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(75, 22);
			this->textBox1->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(175, 102);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(163, 30);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Очистити";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 102);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 30);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Розрахувати";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox1->Location = System::Drawing::Point(344, 6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(906, 545);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->tabPage2->Controls->Add(this->label24);
			this->tabPage2->Controls->Add(this->label25);
			this->tabPage2->Controls->Add(this->button3);
			this->tabPage2->Controls->Add(this->button4);
			this->tabPage2->Controls->Add(this->groupBox4);
			this->tabPage2->Controls->Add(this->groupBox3);
			this->tabPage2->Controls->Add(this->pictureBox2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1259, 559);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(6, 149);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(80, 16);
			this->label24->TabIndex = 16;
			this->label24->Text = L"Результат:";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(86, 150);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(51, 16);
			this->label25->TabIndex = 15;
			this->label25->Text = L"label25";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(175, 116);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(163, 30);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Очистити";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(6, 116);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(163, 30);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Розрахувати";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label14);
			this->groupBox4->Controls->Add(this->label13);
			this->groupBox4->Controls->Add(this->label12);
			this->groupBox4->Controls->Add(this->label10);
			this->groupBox4->Controls->Add(this->textBox9);
			this->groupBox4->Controls->Add(this->label11);
			this->groupBox4->Controls->Add(this->textBox8);
			this->groupBox4->Controls->Add(this->textBox7);
			this->groupBox4->Location = System::Drawing::Point(6, 51);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(332, 59);
			this->groupBox4->TabIndex = 12;
			this->groupBox4->TabStop = false;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(272, 24);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(23, 16);
			this->label14->TabIndex = 14;
			this->label14->Text = L"C=";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(212, 25);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(23, 16);
			this->label13->TabIndex = 13;
			this->label13->Text = L"B=";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(155, 25);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(23, 16);
			this->label12->TabIndex = 12;
			this->label12->Text = L"A=";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(4, 18);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(151, 16);
			this->label10->TabIndex = 10;
			this->label10->Text = L"Параметри прямої осі:";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(296, 22);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(30, 22);
			this->textBox9->TabIndex = 9;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(31, 34);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(87, 16);
			this->label11->TabIndex = 11;
			this->label11->Text = L"( Ax + By = C )";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(236, 22);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(30, 22);
			this->textBox8->TabIndex = 8;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(179, 22);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(30, 22);
			this->textBox7->TabIndex = 7;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->textBox5);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->textBox6);
			this->groupBox3->Location = System::Drawing::Point(6, 0);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(332, 45);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(222, 18);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(23, 16);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Y=";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(115, 18);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(22, 16);
			this->label8->TabIndex = 6;
			this->label8->Text = L"X=";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(251, 15);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(75, 22);
			this->textBox5->TabIndex = 5;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 18);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(93, 16);
			this->label9->TabIndex = 4;
			this->label9->Text = L"Вхідна точка:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(143, 15);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(75, 22);
			this->textBox6->TabIndex = 1;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox2->Location = System::Drawing::Point(344, 6);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(906, 545);
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->tabPage3->Controls->Add(this->label26);
			this->tabPage3->Controls->Add(this->label18);
			this->tabPage3->Controls->Add(this->button6);
			this->tabPage3->Controls->Add(this->button5);
			this->tabPage3->Controls->Add(this->ListPoints);
			this->tabPage3->Controls->Add(this->groupBox5);
			this->tabPage3->Controls->Add(this->pictureBox3);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1259, 559);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"tabPage3";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(82, 235);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(51, 16);
			this->label26->TabIndex = 12;
			this->label26->Text = L"label26";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(4, 234);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(80, 16);
			this->label18->TabIndex = 11;
			this->label18->Text = L"Результат:";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(145, 91);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(193, 36);
			this->button6->TabIndex = 10;
			this->button6->Text = L"Очистити список";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(145, 51);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(193, 34);
			this->button5->TabIndex = 9;
			this->button5->Text = L"Перевірити";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// ListPoints
			// 
			this->ListPoints->FormattingEnabled = true;
			this->ListPoints->ItemHeight = 16;
			this->ListPoints->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"50, 50", L"150, 50", L"100, 150" });
			this->ListPoints->Location = System::Drawing::Point(6, 51);
			this->ListPoints->Name = L"ListPoints";
			this->ListPoints->Size = System::Drawing::Size(132, 180);
			this->ListPoints->TabIndex = 8;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label15);
			this->groupBox5->Controls->Add(this->label16);
			this->groupBox5->Controls->Add(this->textBox10);
			this->groupBox5->Controls->Add(this->label17);
			this->groupBox5->Controls->Add(this->textBox11);
			this->groupBox5->Location = System::Drawing::Point(6, 0);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(332, 45);
			this->groupBox5->TabIndex = 7;
			this->groupBox5->TabStop = false;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(237, 18);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(23, 16);
			this->label15->TabIndex = 7;
			this->label15->Text = L"Y=";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(143, 18);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(22, 16);
			this->label16->TabIndex = 6;
			this->label16->Text = L"X=";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(266, 15);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(60, 22);
			this->textBox10->TabIndex = 5;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(6, 18);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(126, 16);
			this->label17->TabIndex = 4;
			this->label17->Text = L"Введення вершин:";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(171, 15);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(60, 22);
			this->textBox11->TabIndex = 1;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox3->Location = System::Drawing::Point(344, 6);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(906, 545);
			this->pictureBox3->TabIndex = 0;
			this->pictureBox3->TabStop = false;
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->tabPage4->Controls->Add(this->button9);
			this->tabPage4->Controls->Add(this->button8);
			this->tabPage4->Controls->Add(this->button7);
			this->tabPage4->Controls->Add(this->ListEnteredPoints);
			this->tabPage4->Controls->Add(this->groupBox6);
			this->tabPage4->Controls->Add(this->pictureBox4);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(1259, 559);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"tabPage4";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(129, 120);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(209, 28);
			this->button9->TabIndex = 12;
			this->button9->Text = L"Очистити";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(130, 86);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(208, 28);
			this->button8->TabIndex = 11;
			this->button8->Text = L"Генерувати випадково";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(130, 52);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(208, 28);
			this->button7->TabIndex = 10;
			this->button7->Text = L"Побудувати оболонку";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// ListEnteredPoints
			// 
			this->ListEnteredPoints->FormattingEnabled = true;
			this->ListEnteredPoints->ItemHeight = 16;
			this->ListEnteredPoints->Location = System::Drawing::Point(6, 52);
			this->ListEnteredPoints->Name = L"ListEnteredPoints";
			this->ListEnteredPoints->Size = System::Drawing::Size(117, 500);
			this->ListEnteredPoints->TabIndex = 9;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->label19);
			this->groupBox6->Controls->Add(this->label20);
			this->groupBox6->Controls->Add(this->textBox12);
			this->groupBox6->Controls->Add(this->label21);
			this->groupBox6->Controls->Add(this->textBox13);
			this->groupBox6->Location = System::Drawing::Point(6, 0);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(332, 45);
			this->groupBox6->TabIndex = 8;
			this->groupBox6->TabStop = false;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(237, 18);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(23, 16);
			this->label19->TabIndex = 7;
			this->label19->Text = L"Y=";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(143, 18);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(22, 16);
			this->label20->TabIndex = 6;
			this->label20->Text = L"X=";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(266, 15);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(60, 22);
			this->textBox12->TabIndex = 5;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(6, 18);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(111, 16);
			this->label21->TabIndex = 4;
			this->label21->Text = L"Множина точок:";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(171, 15);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(60, 22);
			this->textBox13->TabIndex = 1;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox4->Location = System::Drawing::Point(344, 6);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(906, 545);
			this->pictureBox4->TabIndex = 0;
			this->pictureBox4->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1262, 587);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->tabPage4->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		int px = System::Convert::ToInt32(textBox1->Text); 
		int py = System::Convert::ToInt32(textBox2->Text); 
		int cx = System::Convert::ToInt32(textBox4->Text); 
		int cy = System::Convert::ToInt32(textBox3->Text); 

		this->p1 = System::Drawing::Point(px, py);
		this->c1 = System::Drawing::Point(cx, cy);

		this->r1 = GeometryCore::CalculateCentralSymmetry(p1, c1);

		label22->Text = "Результат: P'(" + r1.X + ", " + r1.Y + ")";
		this->isComputed1 = true;

		Bitmap^ bmp = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		Graphics^ g = Graphics::FromImage(bmp);

		List<Point>^ pts = gcnew List<Point>();
		pts->Add(this->p1);
		pts->Add(this->r1);

		GeometryCore::Draw(g, pts, (float)pictureBox1->Width, (float)pictureBox1->Height, false, % this->c1, nullptr);

		pictureBox1->Image = bmp;

		delete g;
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show("Введіть коректні цілі числа!");
	}
}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		Point p = Point(Convert::ToInt32(textBox6->Text), Convert::ToInt32(textBox5->Text));
		double A = Convert::ToDouble(textBox7->Text);
		double B = Convert::ToDouble(textBox8->Text);
		double C = Convert::ToDouble(textBox9->Text);

		Point result = GeometryCore::CalculateLineSymmetry(p, A, B, C);
		label25->Text = "P'(" + result.X + ", " + result.Y + ")";

		if (pictureBox2->Width > 0 && pictureBox2->Height > 0) {
			Bitmap^ bmp = gcnew Bitmap(pictureBox2->Width, pictureBox2->Height);
			Graphics^ g = Graphics::FromImage(bmp);
			g->Clear(Color::White);

			List<Point>^ pts = gcnew List<Point>();
			pts->Add(p);
			pts->Add(result);

			List<double>^ axis = gcnew List<double>();
			axis->Add(A); axis->Add(B); axis->Add(C);

			GeometryCore::Draw(g, pts, (float)pictureBox2->Width, (float)pictureBox2->Height, false, nullptr, axis);

			pictureBox2->Image = bmp;
			delete g;
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Введіть коректні дані!");
	}
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ tx = textBox11->Text->Trim();
		String^ ty = textBox10->Text->Trim();

		if (this->polyPoints->Count == 0) {
			this->polyPoints->Add(Point(50, 50));
			this->polyPoints->Add(Point(150, 50));
			this->polyPoints->Add(Point(100, 150));
		}

		if (tx != "" && ty != "") {
			int x = Convert::ToInt32(tx);
			int y = Convert::ToInt32(ty);
			Point p(x, y);

			if (!this->polyPoints->Contains(p)) {
				this->polyPoints->Add(p);
				this->ListPoints->Items->Add(x + ", " + y);
			}
			textBox11->Text = "";
			textBox10->Text = "";
		}

		GeometryCore::UpdateCanvas(this->pictureBox3, this->polyPoints, true);

		int count = this->polyPoints->Count;
		if (count < 3) {
			label26->Text = "Результат: Треба > 2 точок (зараз: " + count + ")";
			return;
		}

		int res = GeometryCore::CheckConvexity(this->polyPoints);
		label26->Text = (res == 0) ? "Результат: Неопуклий" : "Результат: Опуклий";
	}
	catch (Exception^) {
		MessageBox::Show("Введіть коректні числа!");
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	label22->Text = "";
	pictureBox1->Image = nullptr;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	label25->Text = "";
	pictureBox2->Image = nullptr;
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	label26->Text = "";
	label26->ForeColor = Color::Black;

	this->polyPoints->Clear();

	this->polyPoints->Add(Point(50, 50));
	this->polyPoints->Add(Point(150, 50));
	this->polyPoints->Add(Point(100, 150));

	ListPoints->Items->Clear();
	ListPoints->Items->Add("50, 50");
	ListPoints->Items->Add("150, 50");
	ListPoints->Items->Add("100, 150");

	GeometryCore::UpdateCanvas(this->pictureBox3, this->polyPoints, true);
	pictureBox3->Image = nullptr;
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox13->Text != "" && textBox12->Text != "") {
		int x = Convert::ToInt32(textBox13->Text);
		int y = Convert::ToInt32(textBox12->Text);
		Point p(x, y);
		if (!cloudPoints->Contains(p)) {
			cloudPoints->Add(p);
			ListEnteredPoints->Items->Add(x + "; " + y);
		}
		textBox13->Text = ""; textBox12->Text = "";
	}

	if (cloudPoints->Count < 3) {
		MessageBox::Show("Для побудови оболонки потрібно мінімум 3 точки!");
		return;
	}

	List<Point>^ hull = GeometryCore::BuildConvexHull(this->cloudPoints);

	GeometryCore::UpdateCanvas(this->pictureBox4, hull, true);
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	Random^ rand = gcnew Random();
	int width = pictureBox4->Width - 20;
	int height = pictureBox4->Height - 20;

	for (int i = 0; i < 15; i++) {
		int x = rand->Next(20, width);
		int y = rand->Next(20, height);
		Point p(x, y);

		if (!cloudPoints->Contains(p)) {
			cloudPoints->Add(p);
			ListEnteredPoints->Items->Add(x + "; " + y);
		}
	}
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	this->cloudPoints->Clear();

	this->ListEnteredPoints->Items->Clear();

	this->pictureBox4->Image = nullptr;

	this->pictureBox4->Refresh();
}
};
}

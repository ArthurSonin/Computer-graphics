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
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::HScrollBar^ hScrollBar1;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::HScrollBar^ hScrollBar2;
	private: System::Windows::Forms::Label^ label12;
		   /// <summary>
		/// Required designer variable.
		   int lastScrollX = 100;
		   int lastScrollY = 100;
		   int lastScrollAngle = 400;
	private: System::Windows::Forms::VScrollBar^ vScrollBar1;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::VScrollBar^ vScrollBar2;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::HScrollBar^ hScrollBar3;
	private: System::Windows::Forms::HScrollBar^ hScrollBar4;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
		   /// </summary>
		System::ComponentModel::Container^ components;

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
			this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar2 = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->vScrollBar2 = (gcnew System::Windows::Forms::VScrollBar());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar3 = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollBar4 = (gcnew System::Windows::Forms::HScrollBar());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
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
			this->pictureBox1->Size = System::Drawing::Size(500, 250);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(37, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"-100";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(37, 64);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"100";
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
			this->textBox3->Text = L"3";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
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
			this->textBox6->Text = L"3";
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
			this->textBox5->Text = L"dont work";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(37, 122);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 8;
			this->textBox4->Text = L"dont work";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->vScrollBar1);
			this->tabPage2->Controls->Add(this->label12);
			this->tabPage2->Controls->Add(this->label11);
			this->tabPage2->Controls->Add(this->hScrollBar2);
			this->tabPage2->Controls->Add(this->hScrollBar1);
			this->tabPage2->Controls->Add(this->label10);
			this->tabPage2->Controls->Add(this->textBox10);
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->textBox9);
			this->tabPage2->Controls->Add(this->textBox8);
			this->tabPage2->Controls->Add(this->button7);
			this->tabPage2->Controls->Add(this->button6);
			this->tabPage2->Controls->Add(this->button5);
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
			this->tabPage2->Text = L"Uniform";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// vScrollBar1
			// 
			this->vScrollBar1->Location = System::Drawing::Point(231, 193);
			this->vScrollBar1->Maximum = 200;
			this->vScrollBar1->Name = L"vScrollBar1";
			this->vScrollBar1->Size = System::Drawing::Size(24, 193);
			this->vScrollBar1->TabIndex = 19;
			this->vScrollBar1->Value = 100;
			this->vScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::vScrollBar1_Scroll);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(67, 228);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(113, 16);
			this->label12->TabIndex = 18;
			this->label12->Text = L"Alternative Rotate";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(73, 177);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(107, 16);
			this->label11->TabIndex = 17;
			this->label11->Text = L"Alternative move";
			// 
			// hScrollBar2
			// 
			this->hScrollBar2->Location = System::Drawing::Point(4, 193);
			this->hScrollBar2->Maximum = 200;
			this->hScrollBar2->Name = L"hScrollBar2";
			this->hScrollBar2->Size = System::Drawing::Size(223, 24);
			this->hScrollBar2->TabIndex = 16;
			this->hScrollBar2->Value = 100;
			this->hScrollBar2->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar2_Scroll);
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Location = System::Drawing::Point(4, 244);
			this->hScrollBar1->Maximum = 800;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(223, 24);
			this->hScrollBar1->TabIndex = 15;
			this->hScrollBar1->Value = 400;
			this->hScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar1_Scroll);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(122, 125);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(49, 16);
			this->label10->TabIndex = 14;
			this->label10->Text = L"Angle=";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(173, 122);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(78, 22);
			this->textBox10->TabIndex = 13;
			this->textBox10->Text = L"45";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(195, 95);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(23, 16);
			this->label9->TabIndex = 12;
			this->label9->Text = L"Y=";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(122, 95);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(22, 16);
			this->label8->TabIndex = 11;
			this->label8->Text = L"X=";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(216, 93);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(35, 22);
			this->textBox9->TabIndex = 10;
			this->textBox9->Text = L"20";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(145, 93);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(35, 22);
			this->textBox8->TabIndex = 9;
			this->textBox8->Text = L"20";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(6, 152);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(110, 23);
			this->button7->TabIndex = 8;
			this->button7->Text = L"Scale";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(6, 122);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(109, 23);
			this->button6->TabIndex = 7;
			this->button6->Text = L"Rotate";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(6, 92);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(110, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Move";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(122, 155);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(49, 16);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Scale=";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(174, 152);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(77, 22);
			this->textBox7->TabIndex = 4;
			this->textBox7->Text = L"1";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::White;
			this->pictureBox2->Location = System::Drawing::Point(258, 3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(685, 383);
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(4, 63);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(112, 23);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Destroy";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(4, 33);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(112, 23);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Draw";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(3, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Load";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->vScrollBar2);
			this->tabPage3->Controls->Add(this->label13);
			this->tabPage3->Controls->Add(this->label14);
			this->tabPage3->Controls->Add(this->hScrollBar3);
			this->tabPage3->Controls->Add(this->hScrollBar4);
			this->tabPage3->Controls->Add(this->label15);
			this->tabPage3->Controls->Add(this->textBox11);
			this->tabPage3->Controls->Add(this->label16);
			this->tabPage3->Controls->Add(this->label17);
			this->tabPage3->Controls->Add(this->textBox12);
			this->tabPage3->Controls->Add(this->textBox13);
			this->tabPage3->Controls->Add(this->button8);
			this->tabPage3->Controls->Add(this->button9);
			this->tabPage3->Controls->Add(this->button10);
			this->tabPage3->Controls->Add(this->label18);
			this->tabPage3->Controls->Add(this->textBox14);
			this->tabPage3->Controls->Add(this->pictureBox3);
			this->tabPage3->Controls->Add(this->button11);
			this->tabPage3->Controls->Add(this->button12);
			this->tabPage3->Controls->Add(this->button13);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(966, 395);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Ordinary";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// vScrollBar2
			// 
			this->vScrollBar2->Location = System::Drawing::Point(231, 193);
			this->vScrollBar2->Maximum = 200;
			this->vScrollBar2->Name = L"vScrollBar2";
			this->vScrollBar2->Size = System::Drawing::Size(24, 193);
			this->vScrollBar2->TabIndex = 39;
			this->vScrollBar2->Value = 100;
			this->vScrollBar2->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::vScrollBar2_Scroll);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(67, 228);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(113, 16);
			this->label13->TabIndex = 38;
			this->label13->Text = L"Alternative Rotate";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(73, 177);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(107, 16);
			this->label14->TabIndex = 37;
			this->label14->Text = L"Alternative move";
			// 
			// hScrollBar3
			// 
			this->hScrollBar3->Location = System::Drawing::Point(4, 193);
			this->hScrollBar3->Maximum = 200;
			this->hScrollBar3->Name = L"hScrollBar3";
			this->hScrollBar3->Size = System::Drawing::Size(223, 24);
			this->hScrollBar3->TabIndex = 36;
			this->hScrollBar3->Value = 100;
			this->hScrollBar3->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar3_Scroll);
			// 
			// hScrollBar4
			// 
			this->hScrollBar4->Location = System::Drawing::Point(4, 244);
			this->hScrollBar4->Maximum = 800;
			this->hScrollBar4->Name = L"hScrollBar4";
			this->hScrollBar4->Size = System::Drawing::Size(223, 24);
			this->hScrollBar4->TabIndex = 35;
			this->hScrollBar4->Value = 400;
			this->hScrollBar4->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar4_Scroll);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(122, 125);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(49, 16);
			this->label15->TabIndex = 34;
			this->label15->Text = L"Angle=";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(173, 122);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(78, 22);
			this->textBox11->TabIndex = 33;
			this->textBox11->Text = L"45";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(195, 95);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(23, 16);
			this->label16->TabIndex = 32;
			this->label16->Text = L"Y=";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(122, 95);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(22, 16);
			this->label17->TabIndex = 31;
			this->label17->Text = L"X=";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(216, 93);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(35, 22);
			this->textBox12->TabIndex = 30;
			this->textBox12->Text = L"20";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(145, 93);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(35, 22);
			this->textBox13->TabIndex = 29;
			this->textBox13->Text = L"20";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(6, 152);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(110, 23);
			this->button8->TabIndex = 28;
			this->button8->Text = L"Scale";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(6, 122);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(109, 23);
			this->button9->TabIndex = 27;
			this->button9->Text = L"Rotate";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(6, 92);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(110, 23);
			this->button10->TabIndex = 26;
			this->button10->Text = L"Move";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(122, 155);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(49, 16);
			this->label18->TabIndex = 25;
			this->label18->Text = L"Scale=";
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(174, 152);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(77, 22);
			this->textBox14->TabIndex = 24;
			this->textBox14->Text = L"1";
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::White;
			this->pictureBox3->Location = System::Drawing::Point(258, 3);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(685, 383);
			this->pictureBox3->TabIndex = 23;
			this->pictureBox3->TabStop = false;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(4, 63);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(112, 23);
			this->button11->TabIndex = 22;
			this->button11->Text = L"Destroy";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(4, 33);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(112, 23);
			this->button12->TabIndex = 21;
			this->button12->Text = L"Draw";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(3, 3);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(112, 23);
			this->button13->TabIndex = 20;
			this->button13->Text = L"Load";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(987, 468);
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
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
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
			float centerX = pictureBox1->Width / 2;
			float centerY = pictureBox1->Height / 2;

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

// tabPage2 ================================================================================	

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
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		float dx = Convert::ToSingle(textBox8->Text);
		float dy = Convert::ToSingle(textBox9->Text);
		figure->TranslateMatrix(dx, dy);
		RefreshDrawing(); // Викликаємо перемалювання
	}   

	private: void RefreshDrawing() {
		if (tabControl1->SelectedIndex == 1) {
			Bitmap^ bmp = gcnew Bitmap(pictureBox2->Width, pictureBox2->Height);
			Graphics^ g = Graphics::FromImage(bmp);
			g->Clear(Color::White);

			float cx = pictureBox2->Width / 2;
			float cy = pictureBox2->Height / 2;

			figure->Scale = Convert::ToSingle(textBox7->Text);
			figure->Draw(g, cx, cy);
			pictureBox2->Image = bmp;
		} else if (tabControl1->SelectedIndex == 2) {
			Bitmap^ bmp = gcnew Bitmap(pictureBox3->Width, pictureBox3->Height);
			Graphics^ g = Graphics::FromImage(bmp);
			g->Clear(Color::White);

			float cx = pictureBox3->Width / 2;
			float cy = pictureBox3->Height / 2;

			figure->Scale = Convert::ToSingle(textBox14->Text);
			figure->Draw(g, cx, cy);
			pictureBox3->Image = bmp;
		}
	}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	float angle = Convert::ToSingle(textBox10->Text);
	figure->RotateMatrix(angle);
	RefreshDrawing();
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	float s = Convert::ToSingle(textBox7->Text);
	figure->ScaleMatrix(s, s);
	RefreshDrawing();
}
private: System::Void hScrollBar1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	// Рахуємо на скільки змінився кут відносно минулого положення
	int deltaAngle = e->NewValue - lastScrollAngle;

	figure->RotateMatrix((float)deltaAngle);
	lastScrollAngle = e->NewValue; // Запам'ятовуємо нове положення

	RefreshDrawing();
	textBox10->Text = e->NewValue.ToString(); // Оновлюємо текст для інфо
}
private: System::Void hScrollBar2_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	int deltaX = e->NewValue - lastScrollX;

	figure->TranslateMatrix((float)deltaX, 0); // Зсуваємо тільки по X
	lastScrollX = e->NewValue; // Оновлюємо стан

	RefreshDrawing();
	textBox8->Text = e->NewValue.ToString();
}
private: System::Void vScrollBar1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	int deltaY = e->NewValue - lastScrollY;

	figure->TranslateMatrix(0, (float)-deltaY); // Зсуваємо тільки по Y
	lastScrollY = e->NewValue; // Оновлюємо стан

	RefreshDrawing();
	textBox9->Text = e->NewValue.ToString();
}

// tabPage3 ================================================================================	
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
			figure->LoadFromFile("data.txt");
			figure->Scale = Convert::ToSingle(textBox14->Text); // Беремо масштаб з поля
			MessageBox::Show("Дані завантажено!");
		}
		catch (...) {
			MessageBox::Show("Помилка завантаження файлу!");
		}
}

private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	Bitmap^ bmp = gcnew Bitmap(pictureBox3->Width, pictureBox3->Height);
	Graphics^ g = Graphics::FromImage(bmp);
	g->Clear(Color::White);

	// Центр для малювання об'єкта (наприклад, центр PictureBox)
	float cx = pictureBox3->Width / 2;
	float cy = pictureBox3->Height / 2;

	figure->Scale = Convert::ToSingle(textBox14->Text);
	figure->Draw(g, cx, cy);

	pictureBox3->Image = bmp;
}

private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	figure->Destroy();
	pictureBox3->Image = nullptr;
	MessageBox::Show("Об'єкт знищено!");
}

private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	float dx = Convert::ToSingle(textBox13->Text);
	float dy = Convert::ToSingle(textBox12->Text);
	figure->TranslateSimple(dx, dy);
	RefreshDrawing(); // Викликаємо перемалювання
}

private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	float angle = Convert::ToSingle(textBox11->Text);
	figure->RotateSimple(angle);
	RefreshDrawing();
}

private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	float s = Convert::ToSingle(textBox14->Text);
	figure->ScaleSimple(s, s);
	RefreshDrawing();
}
private: System::Void hScrollBar3_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	int deltaX = e->NewValue - lastScrollX;

	figure->TranslateSimple((float)deltaX, 0); // Зсуваємо тільки по X
	lastScrollX = e->NewValue; // Оновлюємо стан

	RefreshDrawing();
	textBox13->Text = e->NewValue.ToString();
}
private: System::Void vScrollBar2_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	int deltaY = e->NewValue - lastScrollY;

	figure->TranslateSimple(0, (float)-deltaY); // Зсуваємо тільки по Y
	lastScrollY = e->NewValue; // Оновлюємо стан

	RefreshDrawing();
	textBox12->Text = e->NewValue.ToString();
}
private: System::Void hScrollBar4_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	// Рахуємо на скільки змінився кут відносно минулого положення
	int deltaAngle = e->NewValue - lastScrollAngle;

	figure->RotateSimple((float)deltaAngle);
	lastScrollAngle = e->NewValue; // Запам'ятовуємо нове положення

	RefreshDrawing();
	textBox11->Text = e->NewValue.ToString(); // Оновлюємо текст для інфо
}
};
}

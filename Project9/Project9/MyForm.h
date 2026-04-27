#pragma once
#include "ForLab9.h"

namespace Project9 {

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
		int selectedFractal = 0;
		FractalManager^ manager = gcnew FractalManager();
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox22;
	private: System::Windows::Forms::TextBox^ textBox23;
	private: System::Windows::Forms::TextBox^ textBox24;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private:
		/// <summary>
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->groupBox6->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1499, 712);
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Location = System::Drawing::Point(259, -1);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1503, 737);
			this->tabControl1->TabIndex = 13;
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::tabControl1_SelectedIndexChanged);
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1495, 708);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Коха";
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->tabPage2->Controls->Add(this->pictureBox2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1495, 708);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Жюліа";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(0, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(1499, 712);
			this->pictureBox2->TabIndex = 12;
			this->pictureBox2->TabStop = false;
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->tabPage3->Controls->Add(this->pictureBox3);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1495, 708);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Мандельброт";
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(0, 0);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(1499, 712);
			this->pictureBox3->TabIndex = 14;
			this->pictureBox3->TabStop = false;
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->tabPage4->Controls->Add(this->pictureBox4);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(1495, 708);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Дерево";
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(0, 0);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(1499, 712);
			this->pictureBox4->TabIndex = 12;
			this->pictureBox4->TabStop = false;
			// 
			// tabPage5
			// 
			this->tabPage5->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->tabPage5->Controls->Add(this->pictureBox5);
			this->tabPage5->Location = System::Drawing::Point(4, 25);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(1495, 708);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Серпінський";
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(0, 0);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(1499, 712);
			this->pictureBox5->TabIndex = 12;
			this->pictureBox5->TabStop = false;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(8, 120);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(219, 37);
			this->button6->TabIndex = 15;
			this->button6->Text = L"Створити фрактал";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->textBox22);
			this->groupBox6->Controls->Add(this->textBox23);
			this->groupBox6->Controls->Add(this->textBox24);
			this->groupBox6->Controls->Add(this->label22);
			this->groupBox6->Controls->Add(this->label23);
			this->groupBox6->Controls->Add(this->label24);
			this->groupBox6->Location = System::Drawing::Point(8, 7);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(219, 105);
			this->groupBox6->TabIndex = 14;
			this->groupBox6->TabStop = false;
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(145, 74);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(62, 22);
			this->textBox22->TabIndex = 8;
			this->textBox22->Text = L"4,71";
			// 
			// textBox23
			// 
			this->textBox23->Location = System::Drawing::Point(145, 46);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(62, 22);
			this->textBox23->TabIndex = 7;
			this->textBox23->Text = L"100";
			// 
			// textBox24
			// 
			this->textBox24->Location = System::Drawing::Point(145, 18);
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(62, 22);
			this->textBox24->TabIndex = 6;
			this->textBox24->Text = L"10";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(6, 18);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(120, 16);
			this->label22->TabIndex = 4;
			this->label22->Text = L"Кількість ітерацій";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(7, 77);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(65, 16);
			this->label23->TabIndex = 4;
			this->label23->Text = L"Кут (4.71)";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(6, 49);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(134, 16);
			this->label24->TabIndex = 5;
			this->label24->Text = L"Початковий розмір";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(129, 15);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(62, 22);
			this->textBox1->TabIndex = 23;
			this->textBox1->Text = L"1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 16);
			this->label1->TabIndex = 22;
			this->label1->Text = L"Маштаб";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(108, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 16);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Im(c)=";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 16);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Re(c)=";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(60, 21);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(44, 22);
			this->textBox2->TabIndex = 19;
			this->textBox2->Text = L"-0,61";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(156, 21);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(52, 22);
			this->textBox3->TabIndex = 18;
			this->textBox3->Text = L"-0,61";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(12, 163);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(215, 101);
			this->groupBox1->TabIndex = 22;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Жюліа";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Location = System::Drawing::Point(7, 49);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(201, 46);
			this->groupBox2->TabIndex = 22;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Мандельброт";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->ClientSize = System::Drawing::Size(1761, 739);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->tabPage4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->tabPage5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	PictureBox^ currentPB;
	switch (tabControl1->SelectedIndex) {
	case 0: currentPB = pictureBox1; break;
	case 1: currentPB = pictureBox2; break;
	case 2: currentPB = pictureBox3; break;
	case 3: currentPB = pictureBox4; break;
	case 4: currentPB = pictureBox5; break;
	default: return;
	}
	try {
		int depth = System::Convert::ToInt32(textBox24->Text);
		float size = System::Convert::ToSingle(textBox23->Text);
		float angle = System::Convert::ToSingle(textBox22->Text);
		float scale = System::Convert::ToSingle(textBox1->Text);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Будь ласка, введіть коректні числові значення.\n" + ex->Message, "Помилка вводу", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (currentPB->Image != nullptr) delete currentPB->Image;
	Bitmap^ bmp = gcnew Bitmap(currentPB->Width, currentPB->Height);
	Graphics^ g = Graphics::FromImage(bmp);
	g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
	g->Clear(Color::White);

	int depth = System::Convert::ToInt32(textBox24->Text);    // Ітерації
	float size = System::Convert::ToSingle(textBox23->Text);  // Розмір
	float angle = System::Convert::ToSingle(textBox22->Text); // Кут
	float scale = System::Convert::ToSingle(textBox1->Text);  // Масштаб

	switch (tabControl1->SelectedIndex) {
	case 0: // Коха
		manager->DrawKoch(g, Pens::Blue, 10, bmp->Height / 2, bmp->Width - 10, bmp->Height / 2, depth);
		break;
	case 1: // Жюліа
		manager->DrawJulia(bmp, depth, scale, System::Convert::ToSingle(textBox2->Text), System::Convert::ToSingle(textBox3->Text));
		break;
	case 2: // Мандельброт
		manager->DrawMandelbrot(bmp, depth, scale);
		break;
	case 3: // Дерево
		manager->DrawTree(g, currentPB->Width / 2, currentPB->Height - 20, angle, size);
		break;
	case 4: // Серпінський
		PointF p1(bmp->Width / 2, 10);
		PointF p2(10, bmp->Height - 10);
		PointF p3(bmp->Width - 10, bmp->Height - 10);
		manager->DrawSierpinski(g, p1, p2, p3, depth);
		break;
	}

	currentPB->Image = bmp;
	delete g;
}
private: System::Void tabControl1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	selectedFractal = tabControl1->SelectedIndex;
}
};
}


#pragma once
#include "MyForm2.h"
#include <winsock2.h>
//#include <iostream>
extern int f, bal, dep, cr, l1, l2, l3, l4, l5;
extern SOCKET  Connect;
namespace OS6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::Label^ label4;
	public: System::Windows::Forms::Label^ label5;
	public: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	public: System::Windows::Forms::Label^ label13;
	public: System::Windows::Forms::Label^ label14;
	public: System::Windows::Forms::Label^ label15;
	public: System::Windows::Forms::Label^ label16;
	public: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ textBox1;
	public:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Button^ button6;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(83, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Баланс:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(83, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 26);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Вклад:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(83, 118);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 26);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Кредит:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(181, 40);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(72, 26);
			this->label4->TabIndex = 3;
			this->label4->Text = L"12535";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm1::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(170, 79);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(60, 26);
			this->label5->TabIndex = 4;
			this->label5->Text = L"5000";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm1::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(179, 118);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(60, 26);
			this->label6->TabIndex = 5;
			this->label6->Text = L"1000";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm1::label6_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(438, 42);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 29);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Пополнить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(438, 79);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 29);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Пополнить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(438, 114);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 29);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Погасить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(413, 243);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 35);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Сделать перевод";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(413, 317);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 29);
			this->button5->TabIndex = 11;
			this->button5->Text = L"Выйти";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm1::button5_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(89, 186);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(26, 24);
			this->label7->TabIndex = 12;
			this->label7->Text = L"1.";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm1::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(89, 211);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(26, 24);
			this->label8->TabIndex = 13;
			this->label8->Text = L"2.";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(89, 239);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(26, 24);
			this->label9->TabIndex = 14;
			this->label9->Text = L"3.";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->ForeColor = System::Drawing::Color::White;
			this->label10->Location = System::Drawing::Point(89, 264);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(26, 24);
			this->label10->TabIndex = 15;
			this->label10->Text = L"4.";
			this->label10->Click += gcnew System::EventHandler(this, &MyForm1::label10_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->ForeColor = System::Drawing::Color::White;
			this->label11->Location = System::Drawing::Point(89, 289);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(26, 24);
			this->label11->TabIndex = 16;
			this->label11->Text = L"5.";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->ForeColor = System::Drawing::Color::White;
			this->label12->Location = System::Drawing::Point(83, 157);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(247, 26);
			this->label12->TabIndex = 17;
			this->label12->Text = L"Последние операции:";
			this->label12->Click += gcnew System::EventHandler(this, &MyForm1::label12_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->ForeColor = System::Drawing::Color::White;
			this->label13->Location = System::Drawing::Point(110, 186);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(74, 24);
			this->label13->TabIndex = 18;
			this->label13->Text = L"label13";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->ForeColor = System::Drawing::Color::White;
			this->label14->Location = System::Drawing::Point(110, 211);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(74, 24);
			this->label14->TabIndex = 19;
			this->label14->Text = L"label14";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::Transparent;
			this->label15->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->ForeColor = System::Drawing::Color::White;
			this->label15->Location = System::Drawing::Point(110, 236);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(74, 24);
			this->label15->TabIndex = 20;
			this->label15->Text = L"label15";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BackColor = System::Drawing::Color::Transparent;
			this->label16->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->ForeColor = System::Drawing::Color::Transparent;
			this->label16->Location = System::Drawing::Point(110, 264);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(74, 24);
			this->label16->TabIndex = 21;
			this->label16->Text = L"label16";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BackColor = System::Drawing::Color::Transparent;
			this->label17->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label17->ForeColor = System::Drawing::Color::White;
			this->label17->Location = System::Drawing::Point(110, 289);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(74, 24);
			this->label17->TabIndex = 22;
			this->label17->Text = L"label17";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(332, 47);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 24;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(332, 84);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 25;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(332, 119);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 26;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(398, 186);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 27;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(398, 217);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 28;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BackColor = System::Drawing::Color::Transparent;
			this->label18->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label18->ForeColor = System::Drawing::Color::White;
			this->label18->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			this->label18->Location = System::Drawing::Point(353, 177);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(46, 26);
			this->label18->TabIndex = 29;
			this->label18->Text = L"ID:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->BackColor = System::Drawing::Color::Transparent;
			this->label19->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->ForeColor = System::Drawing::Color::White;
			this->label19->Location = System::Drawing::Point(306, 211);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(92, 26);
			this->label19->TabIndex = 30;
			this->label19->Text = L"Сумма:";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(94, 323);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 31;
			this->button6->Text = L"Обновить";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm1::button6_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(516, 364);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->Name = L"MyForm1";
			this->Text = L"BetaBank";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	char mes[2] = "y";
	send(Connect, mes, sizeof(mes), NULL);
	Application::Exit();
}
protected:
	virtual void OnFormClosing(System::Windows::Forms::FormClosingEventArgs^ e) override {
		char mes[2] = "y";
		send(Connect, mes, sizeof(mes), NULL);
		Application::Exit();
	}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
	   bool Protect(String^ s, int size) {
		   if (size == 0 || s[0] == '0' || s[0] == '-') {
			   MessageBox::Show("Некорректный ввод", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return false;
		   }
		   for (int i = 1; i < size; ++i) {
			   if (s[i] < '0' || s[i] > '9') {
				   MessageBox::Show("Некорректный ввод", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return false;
			   }
		   }
		   return true;
	   }
	   
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	char mes[100];
	char temp[100];
	System::String^ s;
	button6_Click(sender, e);
	if (Protect(MyForm1::textBox1->Text, MyForm1::textBox1->Text->Length)) {
		int x = Int32::Parse(MyForm1::textBox1->Text);
		int y = Int32::Parse(MyForm1::label4->Text);
		int z = Int32::Parse(MyForm1::label5->Text);
		if (x<=z) {
			z -= x;
			y += x;
			int i = 0;
			int j = 0;
			mes[i++] = 'q';
			itoa(y, temp, 10);
			while (temp[j] != '\0')
				mes[i + j] = temp[j++];
			mes[i + j++] = '/';
			i += j;
			j = 0;
			itoa(z, temp, 10);
			while (temp[j] != '\0')
				mes[i + j] = temp[j++];
			mes[i + j] = '\0';
			if (send(Connect, mes, sizeof(mes), NULL) != -1) {
				s = z.ToString();
				MyForm1::label5->Text = s;
				MyForm1::label5->Refresh();
				s = y.ToString();
				MyForm1::label4->Text = s;
				MyForm1::label4->Refresh();
			}
			MyForm1::textBox1->Clear();
		}
		else {
			MyForm1::textBox1->Clear();
			MessageBox::Show("Недостаточно средст", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else {
		MyForm1::textBox1->Clear();
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	char mes[100];
	char temp[100];
	System::String^ s;
	button6_Click(sender, e);
	if (Protect(MyForm1::textBox2->Text, MyForm1::textBox2->Text->Length)) {
		int x = Int32::Parse(MyForm1::textBox2->Text);
		int y = Int32::Parse(MyForm1::label5->Text);
		int z = Int32::Parse(MyForm1::label4->Text);
		if (x <= z) {
			z -= x;
			y += x;
			int i = 0;
			int j = 0;
			mes[i++] = 'w';
			itoa(z, temp, 10);
			while (temp[j] != '\0')
				mes[i + j] = temp[j++];
			mes[i + j++] = '/';
			i += j;
			j = 0;
			itoa(y, temp, 10);
			while (temp[j] != '\0')
				mes[i + j] = temp[j++];
			mes[i + j] = '\0';
			if (send(Connect, mes, sizeof(mes), NULL) != -1) {
				s = z.ToString();
				MyForm1::label4->Text = s;
				MyForm1::label4->Refresh();
				s = y.ToString();
				MyForm1::label5->Text = s;
				MyForm1::label5->Refresh();
			}
			MyForm1::textBox2->Clear();
		}
		else {
			MyForm1::textBox2->Clear();
			MessageBox::Show("Недостаточно средст", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else {
		MyForm1::textBox2->Clear();
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	char mes[200];
	char temp[100];
	System::String^ s;
	button6_Click(sender, e);
	if (Protect(MyForm1::textBox3->Text, MyForm1::textBox3->Text->Length)) {
		int x = Int32::Parse(MyForm1::textBox3->Text);
		int y = Int32::Parse(MyForm1::label4->Text);
		int z = Int32::Parse(MyForm1::label6->Text);
		if (x <= z && x <= y) {
			z -= x;
			y -= x;
			int i = 0;
			int j = 0;
			mes[i++] = 'e';
			itoa(y, temp, 10);
			while (temp[j] != '\0')
				mes[i + j] = temp[j++];
			mes[i + j++] = '/';
			i += j;
			j = 0;
			itoa(z, temp, 10);
			while (temp[j] != '\0')
				mes[i + j] = temp[j++];
			mes[i + j] = '\0';
			if (send(Connect, mes, sizeof(mes), NULL) != -1) {
				s = y.ToString();
				MyForm1::label4->Text = s;
				MyForm1::label4->Refresh();
				s = z.ToString();
				MyForm1::label6->Text = s;
				MyForm1::label6->Refresh();
				

				MyForm1::label17->Text = MyForm1::label16->Text;
				MyForm1::label17->ForeColor = MyForm1::label16->ForeColor;

				MyForm1::label16->Text = MyForm1::label15->Text;
				MyForm1::label16->ForeColor = MyForm1::label15->ForeColor;

				MyForm1::label15->Text = MyForm1::label14->Text;
				MyForm1::label15->ForeColor = MyForm1::label14->ForeColor;

				MyForm1::label14->Text = MyForm1::label13->Text;
				MyForm1::label14->ForeColor = MyForm1::label13->ForeColor;

				x *= -1;
				s = x.ToString();
				MyForm1::label13->Text = s;
				MyForm1::label13->ForeColor = Color::FromName("Red");
			}
			MyForm1::textBox3->Clear();

		}
		else {
			MyForm1::textBox3->Clear();
			MessageBox::Show("Недопустимое значение", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else {
		MyForm1::textBox3->Clear();
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	char mes[200];
	char temp[100];
	System::String^ s;
	button6_Click(sender, e);
	if (Protect(MyForm1::textBox4->Text, MyForm1::textBox4->Text->Length) && Protect(MyForm1::textBox5->Text, MyForm1::textBox5->Text->Length)) {
		int x = Int32::Parse(MyForm1::textBox5->Text);
		int y = Int32::Parse(MyForm1::label4->Text);
		if (x <= y) {
			y -= x;
			int i = 0;
			int j = 0;
			mes[i++] = 'r';
			while (MyForm1::textBox4->Text->Length > j)
				mes[i + j] = MyForm1::textBox4->Text[j++];
			mes[i + j++] = '/';
			i += j;
			j = 0;
			itoa(x, temp, 10);
			while (temp[j] != '\0')
				mes[i + j] = temp[j++];
			mes[i + j] = '\0';
			if (send(Connect, mes, sizeof(mes), NULL) != -1) {
				if(recv(Connect, mes, sizeof(mes), NULL) != 0){
					if (mes[0] == 's') {
						s = y.ToString();
						MyForm1::label4->Text = s;
						MyForm1::label4->Refresh();
						MyForm1::label17->Text = MyForm1::label16->Text;
						MyForm1::label17->ForeColor = MyForm1::label16->ForeColor;

						MyForm1::label16->Text = MyForm1::label15->Text;
						MyForm1::label16->ForeColor = MyForm1::label15->ForeColor;

						MyForm1::label15->Text = MyForm1::label14->Text;
						MyForm1::label15->ForeColor = MyForm1::label14->ForeColor;

						MyForm1::label14->Text = MyForm1::label13->Text;
						MyForm1::label14->ForeColor = MyForm1::label13->ForeColor;

						x *= -1;
						s = x.ToString();
						MyForm1::label13->Text = s;
						MyForm1::label13->ForeColor = Color::FromName("Red");;
					}
					else {
						MessageBox::Show("ID не найдено", "Сервер", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
				else {
					MessageBox::Show("Ошибка со стороны сервера", "Сервер", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else {
				MessageBox::Show("Ошибка со стороны сервера", "Сервер", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			MyForm1::textBox4->Clear();
			MyForm1::textBox5->Clear();
		}
		else {
			MyForm1::textBox4->Clear();
			MyForm1::textBox5->Clear();
			MessageBox::Show("Недопустимое значение", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else {
		MyForm1::textBox4->Clear();
		MyForm1::textBox5->Clear();
	}
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	int n;
	char mes[256] = "t";
	char temp[20];
	int i = 0;
	int j = 0;
	send(Connect, mes, sizeof(mes), NULL);
	recv(Connect, mes, sizeof(mes), 0);
	for (i = 0; mes[i] != '/'; ++i)
		temp[i] = mes[i];
	temp[i++] = '\0';
	n = atoi(temp);
	String^ str = gcnew String(temp);
	str = n.ToString();
	MyForm1::label4->Text = str;
	MyForm1::label4->Refresh();
	for (j = 0; mes[i+j] != '/'; ++j)
		temp[j] = mes[i+j];
	temp[j++] = '\0';
	i += j;
	n = atoi(temp);
	str = n.ToString();
	MyForm1::label5->Text = str;
	MyForm1::label5->Refresh();
	for (j = 0; mes[i + j] != '/'; ++j)
		temp[j] = mes[i + j];
	temp[j++] = '\0';
	i += j;
	n = atoi(temp);
	str = n.ToString();
	MyForm1::label6->Text = str;
	MyForm1::label6->Refresh();
	for (j = 0; mes[i + j] != '/'; ++j)
		temp[j] = mes[i + j];
	temp[j++] = '\0';
	i += j;
	n = atoi(temp);
	str = n.ToString();
	if (n > 0)
		MyForm1::label13->ForeColor = Color::FromName("White");
	else
		MyForm1::label13->ForeColor = Color::FromName("Red");
	MyForm1::label13->Text = str;
	MyForm1::label13->Refresh();
	for (j = 0; mes[i + j] != '/'; ++j)
		temp[j] = mes[i + j];
	temp[j++] = '\0';
	i += j;
	n = atoi(temp);
	str = n.ToString();
	if (n > 0)
		MyForm1::label14->ForeColor = Color::FromName("White");
	else
		MyForm1::label14->ForeColor = Color::FromName("Red");
	MyForm1::label14->Text = str;
	MyForm1::label14->Refresh();
	for (j = 0; mes[i + j] != '/'; ++j)
		temp[j] = mes[i + j];
	temp[j++] = '\0';
	i += j;
	n = atoi(temp);
	str = n.ToString();
	if (n > 0)
		MyForm1::label15->ForeColor = Color::FromName("White");
	else
		MyForm1::label15->ForeColor = Color::FromName("Red");
	MyForm1::label15->Text = str;
	MyForm1::label15->Refresh();
	for (j = 0; mes[i + j] != '/'; ++j)
		temp[j] = mes[i + j];
	temp[j++] = '\0';
	i += j;
	n = atoi(temp);
	str = n.ToString();
	if (n > 0)
		MyForm1::label16->ForeColor = Color::FromName("White");
	else
		MyForm1::label16->ForeColor = Color::FromName("Red");
	MyForm1::label16->Text = str;
	MyForm1::label16->Refresh();
	for (j = 0; mes[i + j] != '/'; ++j)
		temp[j] = mes[i + j];
	temp[j++] = '\0';
	i += j;
	n = atoi(temp);
	str = n.ToString();
	if (n > 0)
		MyForm1::label17->ForeColor = Color::FromName("White");
	else
		MyForm1::label17->ForeColor = Color::FromName("Red");
	MyForm1::label17->Text = str;
	MyForm1::label17->Refresh();
}
};
}

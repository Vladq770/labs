#pragma once
#include "MyForm1.h"
//#include "MyForm.cpp"
#include <string>
#include <winsock2.h>
extern SOCKET Connect;
//int id;
namespace OS6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(153, 113);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Логин:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(137, 161);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 26);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Пароль:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(246, 122);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(246, 170);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Green;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(246, 219);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Вход";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(246, 248);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(101, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Забыли пароль\?";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(224, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(154, 26);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Авторизация";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(558, 343);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::White;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"BetaBank";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool Protect() {
			if (textBox1->Text->Length == 0 || textBox1->Text[0] == '0' || textBox2->Text->Length < 2) {
				textBox1->Clear();
				textBox2->Clear();
				MessageBox::Show("Некорректный логин или пароль", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return false;
			}
			for (int i = 1; i < textBox1->Text->Length; ++i) {
				if (textBox1->Text[i] < '0' || textBox1->Text[i] > '9') {
					textBox1->Clear();
					textBox2->Clear();
					MessageBox::Show("Логин может состоять только из цифр, первая цифра не ноль", "Некорректный логин", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}
			}
			return true;
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Protect()) {
			char mes[256];
			
			int i = 0;
			int j = 0;
			for (i = 0; i < textBox1->Text->Length; ++i) {
				mes[i] = textBox1->Text[i];
			}
			mes[i++] = '/';
			for (j = 0; j < textBox2->Text->Length; ++j) {
				mes[i + j] = textBox2->Text[j];
			}
			mes[i + j] = '\0';
			if (send(Connect, mes, sizeof(mes), 0) == -1) {
				textBox1->Clear();
				textBox2->Clear();
				MessageBox::Show("Ошибка со стороны сервера", "Сервер", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (recv(Connect, mes, sizeof(mes), 0) == 0) {
				textBox1->Clear();
				textBox2->Clear();
				MessageBox::Show("Ошибка со стороны сервера", "Сервер", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (mes[0] == 's') {
				textBox1->Clear();
				textBox2->Clear();
				MyForm1^ form1 = gcnew MyForm1();
				recv(Connect, mes, sizeof(mes), 0);
				String^ str = gcnew String(mes);
				form1->label4->Text = str;
				form1->label4->Refresh();
				recv(Connect, mes, sizeof(mes), 0);
				str = gcnew String(mes);
				form1->label5->Text = str;
				form1->label5->Refresh();
				recv(Connect, mes, sizeof(mes), 0);
				str = gcnew String(mes);
				form1->label6->Text = str;
				form1->label6->Refresh();
				recv(Connect, mes, sizeof(mes), 0);
				str = gcnew String(mes);
				if (atoi(mes) > 0)
					form1->label13->ForeColor = Color::FromName("White");
				else
					form1->label13->ForeColor = Color::FromName("Red");
				form1->label13->Text = str;
				form1->label13->Refresh();
				recv(Connect, mes, sizeof(mes), 0);
				str = gcnew String(mes);
				if (atoi(mes) > 0)
					form1->label14->ForeColor = Color::FromName("White");
				else
					form1->label14->ForeColor = Color::FromName("Red");
				form1->label14->Text = str;
				form1->label14->Refresh();
				recv(Connect, mes, sizeof(mes), 0);
				str = gcnew String(mes);
				if (atoi(mes) > 0)
					form1->label15->ForeColor = Color::FromName("White");
				else
					form1->label15->ForeColor = Color::FromName("Red");
				form1->label15->Text = str;
				form1->label15->Refresh();
				recv(Connect, mes, sizeof(mes), 0);
				str = gcnew String(mes);
				if (atoi(mes) > 0)
					form1->label16->ForeColor = Color::FromName("White");
				else
					form1->label16->ForeColor = Color::FromName("Red");
				form1->label16->Text = str;
				form1->label16->Refresh();
				recv(Connect, mes, sizeof(mes), 0);
				str = gcnew String(mes);
				if (atoi(mes) > 0)
					form1->label17->ForeColor = Color::FromName("White");
				else
					form1->label17->ForeColor = Color::FromName("Red");
				form1->label17->Text = str;
				form1->label17->Refresh();
				form1->Show();
				MyForm::Hide();
				return;
			}
			else if(mes[0] =='0'){
				textBox1->Clear();
				textBox2->Clear();
				MessageBox::Show("ID не найдено", "Сервер", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else if (mes[0] == '1') {
				textBox1->Clear();
				textBox2->Clear();
				MessageBox::Show("Неверный пароль", "Сервер", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
	
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Пишите на почту laptew.vlad2016@gmail.com", "Восстановление пароля", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
protected:
	virtual void OnFormClosing(System::Windows::Forms::FormClosingEventArgs^ e) override {
		char mes[2] = "y";
		send(Connect, mes, sizeof(mes), NULL);
		Application::Exit();
	}
};
}

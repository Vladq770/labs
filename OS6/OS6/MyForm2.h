#pragma once
//#include "MyForm1.h"
#include <string>
extern int f, bal, dep, cr, l1, l2, l3, l4, l5;
namespace OS6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
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
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ textBox1;
	protected:
	public: System::Windows::Forms::Button^ button1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(72, 23);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(92, 49);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(59, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(244, 94);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm2";
			this->Text = L"BetaBank";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	protected:
		virtual void OnFormClosing(System::Windows::Forms::FormClosingEventArgs^ e) override {
			Owner->Enabled = true;
		}

#pragma endregion
		bool Protect() {
			if (textBox1->Text->Length == 0 || textBox1->Text[0] == '0') {
				textBox1->Clear();
				MessageBox::Show("Некорректный ввод", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return false;
			}
			for (int i = 1; i < textBox1->Text->Length; ++i) {
				if (textBox1->Text[i] < '0' || textBox1->Text[i] > '9') {
					textBox1->Clear();
					MessageBox::Show("Некорректный ввод", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}
			}
			return true;
		}
		int sToInt(String^ s, int size){
			char num[20];
			int i = 0;
			while (i < size)
				num[i] = s[i++];
			num[i] == '\0';
			int number = atoi(num);
			return number;
		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Protect()) {
			char num[20];
			int s = sToInt(MyForm2::textBox1->Text, MyForm2::textBox1->Text->Length);
			if (f == 1) {
				if (s <= dep) {
					bal += s;
					dep -= s;
					MyForm2::Close();
				}
				else {
					
				}
			}
			else if (f == 2) {
				if (s <= bal) {

				}
				else {

				}
			}
			else if (f == 3) {

			}
		}
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}


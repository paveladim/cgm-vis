#pragma once

#include "CGM.h"

namespace GGMVIS {

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
	private: System::Windows::Forms::ComboBox^ chooseInter;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxForN;
	private: System::Windows::Forms::TextBox^ textBoxForM;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBoxForIter;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxForDesEps;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ buildSolution;
	private: System::Windows::Forms::DataGridView^ tableForU;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ labelForIter;
	private: System::Windows::Forms::Label^ labelForEps;
	private: System::Windows::Forms::Label^ labelForMax;
	private: System::Windows::Forms::Label^ labelForX;
	private: System::Windows::Forms::Label^ labelForY;
	private: System::Windows::Forms::Label^ labelForR0;
	private: System::Windows::Forms::Label^ labelForRN;

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
			this->chooseInter = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxForN = (gcnew System::Windows::Forms::TextBox());
			this->textBoxForM = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBoxForIter = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxForDesEps = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->buildSolution = (gcnew System::Windows::Forms::Button());
			this->tableForU = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
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
			this->labelForIter = (gcnew System::Windows::Forms::Label());
			this->labelForEps = (gcnew System::Windows::Forms::Label());
			this->labelForMax = (gcnew System::Windows::Forms::Label());
			this->labelForX = (gcnew System::Windows::Forms::Label());
			this->labelForY = (gcnew System::Windows::Forms::Label());
			this->labelForR0 = (gcnew System::Windows::Forms::Label());
			this->labelForRN = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tableForU))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// chooseInter
			// 
			this->chooseInter->FormattingEnabled = true;
			this->chooseInter->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Нулевое", L"Интерполяция вдоль x", L"Интерполяция вдоль y" });
			this->chooseInter->Location = System::Drawing::Point(202, 132);
			this->chooseInter->Name = L"chooseInter";
			this->chooseInter->Size = System::Drawing::Size(121, 21);
			this->chooseInter->TabIndex = 0;
			this->chooseInter->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::chooseInter_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(141, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Введите:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(131, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"1. число разбиений по x:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 59);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(131, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"2. число разбиений по y:";
			// 
			// textBoxForN
			// 
			this->textBoxForN->Location = System::Drawing::Point(223, 30);
			this->textBoxForN->Name = L"textBoxForN";
			this->textBoxForN->Size = System::Drawing::Size(100, 20);
			this->textBoxForN->TabIndex = 4;
			// 
			// textBoxForM
			// 
			this->textBoxForM->Location = System::Drawing::Point(223, 56);
			this->textBoxForM->Name = L"textBoxForM";
			this->textBoxForM->Size = System::Drawing::Size(100, 20);
			this->textBoxForM->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 85);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(171, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"3. максимально число итераций";
			// 
			// textBoxForIter
			// 
			this->textBoxForIter->Location = System::Drawing::Point(223, 80);
			this->textBoxForIter->Name = L"textBoxForIter";
			this->textBoxForIter->Size = System::Drawing::Size(100, 20);
			this->textBoxForIter->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 109);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(120, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"4. желаемую точность";
			// 
			// textBoxForDesEps
			// 
			this->textBoxForDesEps->Location = System::Drawing::Point(223, 106);
			this->textBoxForDesEps->Name = L"textBoxForDesEps";
			this->textBoxForDesEps->Size = System::Drawing::Size(100, 20);
			this->textBoxForDesEps->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 135);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(184, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Выберите начальное приближение";
			// 
			// buildSolution
			// 
			this->buildSolution->Location = System::Drawing::Point(15, 159);
			this->buildSolution->Name = L"buildSolution";
			this->buildSolution->Size = System::Drawing::Size(308, 94);
			this->buildSolution->TabIndex = 11;
			this->buildSolution->Text = L"Построить решение";
			this->buildSolution->UseVisualStyleBackColor = true;
			this->buildSolution->Click += gcnew System::EventHandler(this, &MyForm::buildSolution_Click);
			// 
			// tableForU
			// 
			this->tableForU->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableForU->Location = System::Drawing::Point(12, 272);
			this->tableForU->Name = L"tableForU";
			this->tableForU->Size = System::Drawing::Size(492, 436);
			this->tableForU->TabIndex = 12;
			this->tableForU->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(329, 9);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(441, 244);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(776, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(150, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Результаты работы метода.";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(776, 37);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(160, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Число потраченных итераций:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(776, 56);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(123, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Достигнутая точность:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(777, 80);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(166, 13);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Максимум разности истинного";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(777, 93);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(124, 13);
			this->label11->TabIndex = 18;
			this->label11->Text = L"и численного решений:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(777, 113);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(116, 13);
			this->label12->TabIndex = 19;
			this->label12->Text = L"Был достигнут в узле";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(900, 113);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(24, 13);
			this->label13->TabIndex = 20;
			this->label13->Text = L"x = ";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(900, 132);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(21, 13);
			this->label14->TabIndex = 21;
			this->label14->Text = L"y =";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(776, 156);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(221, 13);
			this->label15->TabIndex = 22;
			this->label15->Text = L"Норма невязки начального приближения:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(776, 178);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(215, 13);
			this->label16->TabIndex = 23;
			this->label16->Text = L"Норма невязки конечного приближения:";
			// 
			// labelForIter
			// 
			this->labelForIter->AutoSize = true;
			this->labelForIter->Location = System::Drawing::Point(942, 37);
			this->labelForIter->Name = L"labelForIter";
			this->labelForIter->Size = System::Drawing::Size(13, 13);
			this->labelForIter->TabIndex = 24;
			this->labelForIter->Text = L"0";
			// 
			// labelForEps
			// 
			this->labelForEps->AutoSize = true;
			this->labelForEps->Location = System::Drawing::Point(899, 56);
			this->labelForEps->Name = L"labelForEps";
			this->labelForEps->Size = System::Drawing::Size(22, 13);
			this->labelForEps->TabIndex = 25;
			this->labelForEps->Text = L"0.0";
			// 
			// labelForMax
			// 
			this->labelForMax->AutoSize = true;
			this->labelForMax->Location = System::Drawing::Point(899, 93);
			this->labelForMax->Name = L"labelForMax";
			this->labelForMax->Size = System::Drawing::Size(22, 13);
			this->labelForMax->TabIndex = 26;
			this->labelForMax->Text = L"0.0";
			// 
			// labelForX
			// 
			this->labelForX->AutoSize = true;
			this->labelForX->Location = System::Drawing::Point(920, 113);
			this->labelForX->Name = L"labelForX";
			this->labelForX->Size = System::Drawing::Size(22, 13);
			this->labelForX->TabIndex = 27;
			this->labelForX->Text = L"0.0";
			// 
			// labelForY
			// 
			this->labelForY->AutoSize = true;
			this->labelForY->Location = System::Drawing::Point(920, 132);
			this->labelForY->Name = L"labelForY";
			this->labelForY->Size = System::Drawing::Size(22, 13);
			this->labelForY->TabIndex = 28;
			this->labelForY->Text = L"0.0";
			// 
			// labelForR0
			// 
			this->labelForR0->AutoSize = true;
			this->labelForR0->Location = System::Drawing::Point(998, 156);
			this->labelForR0->Name = L"labelForR0";
			this->labelForR0->Size = System::Drawing::Size(22, 13);
			this->labelForR0->TabIndex = 29;
			this->labelForR0->Text = L"0.0";
			// 
			// labelForRN
			// 
			this->labelForRN->AutoSize = true;
			this->labelForRN->Location = System::Drawing::Point(997, 178);
			this->labelForRN->Name = L"labelForRN";
			this->labelForRN->Size = System::Drawing::Size(22, 13);
			this->labelForRN->TabIndex = 30;
			this->labelForRN->Text = L"0.0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1453, 763);
			this->Controls->Add(this->labelForRN);
			this->Controls->Add(this->labelForR0);
			this->Controls->Add(this->labelForY);
			this->Controls->Add(this->labelForX);
			this->Controls->Add(this->labelForMax);
			this->Controls->Add(this->labelForEps);
			this->Controls->Add(this->labelForIter);
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
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->tableForU);
			this->Controls->Add(this->buildSolution);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBoxForDesEps);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBoxForIter);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBoxForM);
			this->Controls->Add(this->textBoxForN);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chooseInter);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tableForU))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void chooseInter_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
private: System::Void buildSolution_Click(System::Object^ sender, System::EventArgs^ e) {

	if (textBoxForN->Text->Length == 0)
	{
		MessageBox::Show("Не введено число разбиений по x", "Ошибка");
		return;
	}

	if (textBoxForM->Text->Length == 0)
	{
		MessageBox::Show("Не введено число разбиений по y", "Ошибка");
		return;
	}

	if (textBoxForIter->Text->Length == 0)
	{
		MessageBox::Show("Не введено максимально допустимое число итераций", "Ошибка");
		return;
	}

	if (textBoxForDesEps->Text->Length == 0)
	{
		MessageBox::Show("Не введена желаемая точность", "Ошибка");
		return;
	}

	if (chooseInter->SelectedIndex == -1)
	{
		MessageBox::Show("Не выбрано начальное приближение", "Ошибка");
		return;
	}

	unsigned int n = Convert::ToUInt32(textBoxForN->Text);
	unsigned int m = Convert::ToUInt32(textBoxForM->Text);
	unsigned int max_iter = Convert::ToUInt32(textBoxForIter->Text);
	double des_eps = Convert::ToDouble(textBoxForDesEps->Text);
	unsigned int inter = chooseInter->SelectedIndex;

	if ((n % 4 != 0) || (m % 4 != 0)) {
		MessageBox::Show("Не соблюдены условия кратности", "Ошибка");
		return;
	}

	CGM solveTask(n, m, inter, max_iter, des_eps);
	solveTask.solver();

	labelForIter->Text = Convert::ToString(solveTask.giveIter());
	labelForEps->Text = Convert::ToString(solveTask.giveEps());
	labelForMax->Text = Convert::ToString(solveTask.giveMaxTrue());
	labelForX->Text = Convert::ToString(solveTask.returnX());
	labelForY->Text = Convert::ToString(solveTask.returnY());
	labelForR0->Text = Convert::ToString(solveTask.returnR0());
	labelForRN->Text = Convert::ToString(solveTask.returnRN());
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}

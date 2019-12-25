#pragma once
#include"tqueue.h"

namespace CppCLR_WinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung fьr Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		int MaxSize;
		int Size;
		double AddProb;
		double ExtrProb;
		int PopCount;
		int PushCount;
		int buf;

		TQueue<int>* pQueue;
		int CenterX, CenterY, Width, Height;
		Graphics^ gr;
		Random^ rndl;
		Pen^ BlackPen;
		Pen^ ClearPen;
		Pen^ ALLCLPen;

	private: System::Windows::Forms::Label^  MaxSizeL;
	private: System::Windows::Forms::TextBox^  MaxSizeT;
	private: System::Windows::Forms::Label^  CurrSizeL;
	private: System::Windows::Forms::TextBox^  CurrSizeT;
	private: System::Windows::Forms::Label^  AddProbL;
	private: System::Windows::Forms::TextBox^  AddProbT;
	private: System::Windows::Forms::Label^  ExtrProbL;
	private: System::Windows::Forms::TextBox^  ExtrProbT;
	private: System::Windows::Forms::Label^  QAddL;
	private: System::Windows::Forms::Label^  QAddLo;
	private: System::Windows::Forms::Label^  QExtrL;
	private: System::Windows::Forms::Label^  QExtrLo;
	private: System::Windows::Forms::Button^  StartB;
	private: System::Windows::Forms::Button^  StopB;
	private: System::Windows::Forms::Timer^  timer1;

	private: System::ComponentModel::IContainer^  components;

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufьgen.
			//
			gr = CreateGraphics();
			rndl = gcnew Random();

			BlackPen = gcnew Pen(Color::Black);
			BlackPen->Width = 15.0F;
			ClearPen = gcnew Pen(Color::White);
			ClearPen->Width = 15.0F;
			ALLCLPen = gcnew Pen(Color::White);
			ALLCLPen->Width = 500.0F;

			CenterX = 150;
			CenterY = 200;
			Width = 200;
			Height = 200;

			PopCount = 0;
			PushCount = 0;
			buf = 0;
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode fьr die Designerunterstьtzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geдndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->MaxSizeL = (gcnew System::Windows::Forms::Label());
			this->MaxSizeT = (gcnew System::Windows::Forms::TextBox());
			this->CurrSizeL = (gcnew System::Windows::Forms::Label());
			this->CurrSizeT = (gcnew System::Windows::Forms::TextBox());
			this->AddProbL = (gcnew System::Windows::Forms::Label());
			this->AddProbT = (gcnew System::Windows::Forms::TextBox());
			this->ExtrProbL = (gcnew System::Windows::Forms::Label());
			this->ExtrProbT = (gcnew System::Windows::Forms::TextBox());
			this->QAddL = (gcnew System::Windows::Forms::Label());
			this->QAddLo = (gcnew System::Windows::Forms::Label());
			this->QExtrL = (gcnew System::Windows::Forms::Label());
			this->QExtrLo = (gcnew System::Windows::Forms::Label());
			this->StartB = (gcnew System::Windows::Forms::Button());
			this->StopB = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// MaxSizeL
			// 
			this->MaxSizeL->Location = System::Drawing::Point(8, 10);
			this->MaxSizeL->Name = L"MaxSizeL";
			this->MaxSizeL->Size = System::Drawing::Size(227, 22);
			this->MaxSizeL->TabIndex = 0;
			this->MaxSizeL->Text = L"Максимальный размер очереди";
			this->MaxSizeL->Click += gcnew System::EventHandler(this, &Form1::MaxSizeL_Click);
			// 
			// MaxSizeT
			// 
			this->MaxSizeT->Location = System::Drawing::Point(11, 35);
			this->MaxSizeT->Name = L"MaxSizeT";
			this->MaxSizeT->Size = System::Drawing::Size(224, 22);
			this->MaxSizeT->TabIndex = 1;
			this->MaxSizeT->TextChanged += gcnew System::EventHandler(this, &Form1::MaxSizeT_TextChanged);
			// 
			// CurrSizeL
			// 
			this->CurrSizeL->Location = System::Drawing::Point(8, 60);
			this->CurrSizeL->Name = L"CurrSizeL";
			this->CurrSizeL->Size = System::Drawing::Size(224, 22);
			this->CurrSizeL->TabIndex = 2;
			this->CurrSizeL->Text = L"Начальный размер очереди";
			this->CurrSizeL->Click += gcnew System::EventHandler(this, &Form1::CurrSizeL_Click);
			// 
			// CurrSizeT
			// 
			this->CurrSizeT->Location = System::Drawing::Point(11, 85);
			this->CurrSizeT->Name = L"CurrSizeT";
			this->CurrSizeT->Size = System::Drawing::Size(224, 22);
			this->CurrSizeT->TabIndex = 3;
			this->CurrSizeT->TextChanged += gcnew System::EventHandler(this, &Form1::CurrSizeT_TextChanged);
			// 
			// AddProbL
			// 
			this->AddProbL->Location = System::Drawing::Point(241, 10);
			this->AddProbL->Name = L"AddProbL";
			this->AddProbL->Size = System::Drawing::Size(177, 22);
			this->AddProbL->TabIndex = 4;
			this->AddProbL->Text = L"Вероятность добавления";
			this->AddProbL->Click += gcnew System::EventHandler(this, &Form1::AddProbL_Click);
			// 
			// AddProbT
			// 
			this->AddProbT->Location = System::Drawing::Point(244, 35);
			this->AddProbT->Name = L"AddProbT";
			this->AddProbT->Size = System::Drawing::Size(174, 22);
			this->AddProbT->TabIndex = 5;
			this->AddProbT->TextChanged += gcnew System::EventHandler(this, &Form1::AddProbT_TextChanged);
			// 
			// ExtrProbL
			// 
			this->ExtrProbL->Location = System::Drawing::Point(241, 60);
			this->ExtrProbL->Name = L"ExtrProbL";
			this->ExtrProbL->Size = System::Drawing::Size(177, 22);
			this->ExtrProbL->TabIndex = 6;
			this->ExtrProbL->Text = L"Вероятность извлечения";
			this->ExtrProbL->Click += gcnew System::EventHandler(this, &Form1::ExtrProbL_Click);
			// 
			// ExtrProbT
			// 
			this->ExtrProbT->Location = System::Drawing::Point(244, 85);
			this->ExtrProbT->Name = L"ExtrProbT";
			this->ExtrProbT->Size = System::Drawing::Size(174, 22);
			this->ExtrProbT->TabIndex = 7;
			this->ExtrProbT->TextChanged += gcnew System::EventHandler(this, &Form1::ExtrProbT_TextChanged);
			// 
			// QAddL
			// 
			this->QAddL->Location = System::Drawing::Point(424, 10);
			this->QAddL->Name = L"QAddL";
			this->QAddL->Size = System::Drawing::Size(180, 22);
			this->QAddL->TabIndex = 8;
			this->QAddL->Text = L"Количество добавленных";
			this->QAddL->Click += gcnew System::EventHandler(this, &Form1::QAddL_Click);
			// 
			// QAddLo
			// 
			this->QAddLo->Location = System::Drawing::Point(427, 32);
			this->QAddLo->Name = L"QAddLo";
			this->QAddLo->Size = System::Drawing::Size(177, 22);
			this->QAddLo->TabIndex = 9;
			this->QAddLo->Text = L"0";
			this->QAddLo->Click += gcnew System::EventHandler(this, &Form1::QAddLo_Click);
			// 
			// QExtrL
			// 
			this->QExtrL->Location = System::Drawing::Point(424, 60);
			this->QExtrL->Name = L"QExtrL";
			this->QExtrL->Size = System::Drawing::Size(180, 22);
			this->QExtrL->TabIndex = 10;
			this->QExtrL->Text = L"Количество извлечённых";
			this->QExtrL->Click += gcnew System::EventHandler(this, &Form1::QExtrL_Click);
			// 
			// QExtrLo
			// 
			this->QExtrLo->Location = System::Drawing::Point(427, 85);
			this->QExtrLo->Name = L"QExtrLo";
			this->QExtrLo->Size = System::Drawing::Size(177, 22);
			this->QExtrLo->TabIndex = 11;
			this->QExtrLo->Text = L"0";
			this->QExtrLo->Click += gcnew System::EventHandler(this, &Form1::QExtrLo_Click);
			// 
			// StartB
			// 
			this->StartB->Location = System::Drawing::Point(11, 113);
			this->StartB->Name = L"StartB";
			this->StartB->Size = System::Drawing::Size(304, 35);
			this->StartB->TabIndex = 12;
			this->StartB->Text = L"Старт";
			this->StartB->UseVisualStyleBackColor = true;
			this->StartB->Click += gcnew System::EventHandler(this, &Form1::StartB_Click);
			// 
			// StopB
			// 
			this->StopB->Location = System::Drawing::Point(321, 113);
			this->StopB->Name = L"StopB";
			this->StopB->Size = System::Drawing::Size(304, 35);
			this->StopB->TabIndex = 13;
			this->StopB->Text = L"Стоп";
			this->StopB->UseVisualStyleBackColor = true;
			this->StopB->Click += gcnew System::EventHandler(this, &Form1::StopB_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(655, 559);
			this->Controls->Add(this->StopB);
			this->Controls->Add(this->StartB);
			this->Controls->Add(this->QExtrLo);
			this->Controls->Add(this->QExtrL);
			this->Controls->Add(this->QAddLo);
			this->Controls->Add(this->QAddL);
			this->Controls->Add(this->ExtrProbT);
			this->Controls->Add(this->ExtrProbL);
			this->Controls->Add(this->AddProbT);
			this->Controls->Add(this->AddProbL);
			this->Controls->Add(this->CurrSizeT);
			this->Controls->Add(this->CurrSizeL);
			this->Controls->Add(this->MaxSizeT);
			this->Controls->Add(this->MaxSizeL);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void DrawQueue() {
			int start = 360 * pQueue->GetHead() / pQueue->GetMaxSize();
			int finish = 360 * (pQueue->GetSize()) / pQueue->GetMaxSize();
			gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, start, finish);
		}
		void Clean()
		{
			int start = 360 * pQueue->GetHead() / pQueue->GetMaxSize();
			int finish = 360 * (pQueue->GetSize()) / pQueue->GetMaxSize();

			gr->DrawArc(ClearPen, CenterX, CenterY, Width, Height, start, finish);
		}
	private: System::Void CurrSizeL_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MaxSizeT_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MaxSizeL_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void CurrSizeT_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void AddProbL_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void AddProbT_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void ExtrProbL_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void ExtrProbT_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void QAddL_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void QAddLo_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void QExtrL_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void QExtrLo_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void StartB_Click(System::Object^  sender, System::EventArgs^  e) {
		gr->DrawLine(ALLCLPen, 0, 200, 630, 200);
		MaxSize = Convert::ToInt32(MaxSizeT->Text);
		Size = Convert::ToInt32(CurrSizeT->Text);
		AddProb = Convert::ToDouble(AddProbT->Text);
		ExtrProb = Convert::ToDouble(ExtrProbT->Text);
		timer1->Interval = 15;

		pQueue = new TQueue<int>(MaxSize);
		//pQueue = new TQueue<int>;             //для списковой очереди
		for (int i = 0; i < Size; i++)
		{
			pQueue->Push(i);
		}
		DrawQueue();
		timer1->Enabled = true;
		StopB->Text = "Пауза";
		buf = 0;
	}
	private: System::Void StopB_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = buf;
		if (!buf)
		{
			StopB->Text = "Продолжить";
		}
		else
		{
			StopB->Text = "Пауза";
		}
		buf++;
		if (buf == 2)
		{
			buf = 0;
		}
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Clean();

		if (rndl->NextDouble() < AddProb)
		{
			if (!pQueue->IsFull())
			{
				pQueue->Push(1);
				PushCount++;
			}
		}
		if (rndl->NextDouble() < ExtrProb)
		{
			if (!pQueue->IsEmpty())
			{
				pQueue->Pop();
				PopCount++;
			}
		}
		DrawQueue();
		QAddLo->Text = Convert::ToString(PushCount);
		QExtrLo->Text = Convert::ToString(PopCount);
	}
	};
}

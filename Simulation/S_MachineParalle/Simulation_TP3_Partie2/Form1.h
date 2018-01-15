#include "Head.h"
#pragma once


namespace Simulation_TP3_Partie2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;

	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;

	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::RadioButton^  radioButton7;



	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private:
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint4 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0, 
				0));
			System::Windows::Forms::DataVisualization::Charting::Title^  title10 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::Title^  title11 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::Title^  title12 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint5 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0, 
				0));
			System::Windows::Forms::DataVisualization::Charting::Title^  title13 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::Title^  title14 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::Title^  title15 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint6 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0, 
				0));
			System::Windows::Forms::DataVisualization::Charting::Title^  title16 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::Title^  title17 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::Title^  title18 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(420, 31);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Simuler";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(558, 13);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(565, 375);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(364, 281);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(188, 107);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Choisir une Règle";
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(79, 69);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(95, 17);
			this->radioButton4->TabIndex = 3;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Sans Règle (4)";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(7, 69);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(62, 17);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Règle 3";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(75, 30);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(62, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Règle 2";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(7, 30);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(62, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Règle 1";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButton7);
			this->groupBox2->Controls->Add(this->radioButton6);
			this->groupBox2->Controls->Add(this->radioButton5);
			this->groupBox2->Location = System::Drawing::Point(364, 125);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(188, 101);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Type de système";
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Location = System::Drawing::Point(10, 42);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(134, 17);
			this->radioButton7->TabIndex = 1;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"Assemblagem sans File";
			this->radioButton7->UseVisualStyleBackColor = true;
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(10, 65);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(109, 17);
			this->radioButton6->TabIndex = 1;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"Sans Assemblage";
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(10, 19);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(128, 17);
			this->radioButton5->TabIndex = 0;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"Assemblage avec File";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton5_CheckedChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox7);
			this->groupBox3->Controls->Add(this->textBox8);
			this->groupBox3->Controls->Add(this->textBox4);
			this->groupBox3->Controls->Add(this->textBox5);
			this->groupBox3->Controls->Add(this->textBox3);
			this->groupBox3->Controls->Add(this->textBox2);
			this->groupBox3->Controls->Add(this->textBox1);
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Location = System::Drawing::Point(16, 125);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(342, 263);
			this->groupBox3->TabIndex = 4;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Paramètres du modèle";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(223, 207);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(101, 20);
			this->textBox7->TabIndex = 17;
			this->textBox7->Text = L"20";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(223, 234);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(101, 20);
			this->textBox8->TabIndex = 16;
			this->textBox8->Text = L"10";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(223, 124);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(101, 20);
			this->textBox4->TabIndex = 14;
			this->textBox4->Text = L"4";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(223, 156);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(101, 20);
			this->textBox5->TabIndex = 13;
			this->textBox5->Text = L"10";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(223, 76);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(101, 20);
			this->textBox3->TabIndex = 11;
			this->textBox3->Text = L"3";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(223, 53);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(101, 20);
			this->textBox2->TabIndex = 10;
			this->textBox2->Text = L"6";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(223, 28);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(101, 20);
			this->textBox1->TabIndex = 9;
			this->textBox1->Text = L"1000";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(28, 234);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(189, 13);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Durée de traitement d\'un client sur M3:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(26, 210);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(189, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Durée de traitement d\'un client sur M2:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 187);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(80, 13);
			this->label9->TabIndex = 6;
			this->label9->Text = L"Client de type 2";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(29, 156);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(189, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Durée de traitement d\'un client sur M3:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(29, 131);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(189, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Durée de traitement d\'un client sur M1:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 102);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(80, 13);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Client de type 1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(29, 76);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(182, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Durée entre deux clients sur l\'entre 2:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(182, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Durée entre deux clients sur l\'entre 1:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(97, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Durée de la simulation:";
			// 
			// chart1
			// 
			chartArea4->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea4);
			legend4->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend4->Name = L"Legend1";
			this->chart1->Legends->Add(legend4);
			this->chart1->Location = System::Drawing::Point(16, 399);
			this->chart1->Name = L"chart1";
			this->chart1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Legend = L"Legend1";
			series4->Name = L"Series1";
			series4->Points->Add(dataPoint4);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(362, 300);
			this->chart1->TabIndex = 5;
			this->chart1->Text = L"chart1";
			title10->Alignment = System::Drawing::ContentAlignment::TopCenter;
			title10->Name = L"Title1";
			title10->Text = L"Source";
			title10->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Horizontal;
			title11->Alignment = System::Drawing::ContentAlignment::TopLeft;
			title11->Name = L"Title2";
			title11->Text = L"N Pièces";
			title12->Alignment = System::Drawing::ContentAlignment::TopCenter;
			title12->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			title12->Name = L"Title3";
			title12->Text = L"Temps";
			this->chart1->Titles->Add(title10);
			this->chart1->Titles->Add(title11);
			this->chart1->Titles->Add(title12);
			this->chart1->Click += gcnew System::EventHandler(this, &Form1::chart1_Click);
			// 
			// chart2
			// 
			chartArea5->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea5);
			legend5->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend5->Name = L"Legend1";
			this->chart2->Legends->Add(legend5);
			this->chart2->Location = System::Drawing::Point(384, 399);
			this->chart2->Name = L"chart2";
			this->chart2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series5->Legend = L"Legend1";
			series5->Name = L"Series1";
			series5->Points->Add(dataPoint5);
			this->chart2->Series->Add(series5);
			this->chart2->Size = System::Drawing::Size(362, 300);
			this->chart2->TabIndex = 5;
			this->chart2->Text = L"chart1";
			title13->Alignment = System::Drawing::ContentAlignment::TopCenter;
			title13->Name = L"Title1";
			title13->Text = L"Station";
			title13->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Horizontal;
			title14->Alignment = System::Drawing::ContentAlignment::TopLeft;
			title14->Name = L"Title2";
			title14->Text = L"Réponse";
			title15->Alignment = System::Drawing::ContentAlignment::TopCenter;
			title15->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			title15->Name = L"Title3";
			title15->Text = L"Temps";
			this->chart2->Titles->Add(title13);
			this->chart2->Titles->Add(title14);
			this->chart2->Titles->Add(title15);
			this->chart2->Click += gcnew System::EventHandler(this, &Form1::chart1_Click);
			// 
			// chart3
			// 
			chartArea6->Name = L"ChartArea1";
			this->chart3->ChartAreas->Add(chartArea6);
			legend6->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend6->Name = L"Legend1";
			this->chart3->Legends->Add(legend6);
			this->chart3->Location = System::Drawing::Point(761, 399);
			this->chart3->Name = L"chart3";
			this->chart3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series6->Legend = L"Legend1";
			series6->Name = L"Series1";
			series6->Points->Add(dataPoint6);
			this->chart3->Series->Add(series6);
			this->chart3->Size = System::Drawing::Size(362, 300);
			this->chart3->TabIndex = 5;
			this->chart3->Text = L"chart1";
			title16->Alignment = System::Drawing::ContentAlignment::TopCenter;
			title16->Name = L"Title1";
			title16->Text = L"Sortie";
			title16->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Horizontal;
			title17->Alignment = System::Drawing::ContentAlignment::TopLeft;
			title17->Name = L"Title2";
			title17->Text = L"N Pièces";
			title18->Alignment = System::Drawing::ContentAlignment::TopCenter;
			title18->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			title18->Name = L"Title3";
			title18->Text = L"Temps";
			this->chart3->Titles->Add(title16);
			this->chart3->Titles->Add(title17);
			this->chart3->Titles->Add(title18);
			this->chart3->Click += gcnew System::EventHandler(this, &Form1::chart1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(16, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(387, 106);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1136, 728);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->chart3);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Simulation - TP3";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			
				this->chart1->Series->Clear(); 
				this->chart2->Series->Clear();
				this->chart3->Series->Clear();
				this->richTextBox1->AppendText ("\n***********DEBUT DE LA NOUVELLE SIMULATION ***********\n");
				//Declarations et inicialisations
				int TEMPSMAX = Convert::ToInt32(textBox1->Text);
				double DIA1 = Convert::ToDouble(textBox2->Text);
				double DIA2 = Convert::ToDouble(textBox3->Text);
				double S1 = Convert::ToDouble(textBox4->Text);
				double S3_1 = Convert::ToDouble(textBox5->Text);;
				double S2 = Convert::ToDouble(textBox7->Text);
				double S3_2 = Convert::ToDouble(textBox8->Text);
				int Regle = 4;
				if(radioButton1->Checked==true)
					 Regle = 1;
				else 
					if (radioButton2->Checked == true)
						Regle = 2;
					else 
						if (radioButton3->Checked == true)
						 Regle = 3;
				String^ tipo;
				int TYPE_SYSTEM = 0;
				tipo = "SANS assemblage";
				if(radioButton5->Checked == true)
				{
					 TYPE_SYSTEM = 1;
					 tipo = "Assemblage AVEC File";
				}
				else
					if (radioButton7->Checked == true)
					{
						TYPE_SYSTEM = 2;
						tipo = "Assemblage SANS File";

					}
				String^ s = "Regle (" + Convert ::ToString(Regle) + ") Type_Système (" + tipo + ")";
				this->richTextBox1->AppendText(s);

				 Simuler (this->richTextBox1, TEMPSMAX, DIA1, DIA2,S1, S3_1, S2, S3_2, Regle, TYPE_SYSTEM,this->chart1,this->chart2,this->chart3);
				
			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}


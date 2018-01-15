#include "head.h"
#pragma once



namespace TP4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	using namespace System::Timers;

	/// <summary>
	/// Description résumée de Form1
	///
	/// AVERTISSEMENT : si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propriété 'Nom du fichier de ressources' de l'outil de compilation de ressource managée
	///          pour tous les fichiers .resx dont dépend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localisées associées à ce formulaire.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO : ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::RadioButton^  radioButton6;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;


	private: System::ComponentModel::IContainer^  components;








	protected: 

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(351, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(211, 128);
			this->button1->TabIndex = 0;
			this->button1->Text = L"SIMULER";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(582, 3);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(462, 335);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(12, 236);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(119, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Enabled = false;
			this->label1->Location = System::Drawing::Point(12, 207);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 26);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Quantité MAX de Pièces\r\n  dans Système ";
			// 
			// panel1
			// 
			this->panel1->AccessibleName = L"";
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->radioButton3);
			this->panel1->Controls->Add(this->radioButton2);
			this->panel1->Controls->Add(this->radioButton1);
			this->panel1->Location = System::Drawing::Point(12, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(291, 130);
			this->panel1->TabIndex = 4;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(19, 95);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(226, 17);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Système trouve bon ordre (Algo. descente)";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(19, 53);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(276, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Système qui Permette Choisir Ordre de la file d\'entrée ";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(19, 14);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(108, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Système aleatoire";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->textBox7);
			this->panel2->Controls->Add(this->textBox6);
			this->panel2->Controls->Add(this->textBox5);
			this->panel2->Controls->Add(this->textBox4);
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Controls->Add(this->textBox2);
			this->panel2->Enabled = false;
			this->panel2->Location = System::Drawing::Point(12, 262);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(276, 97);
			this->panel2->TabIndex = 6;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(225, 63);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(17, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"6°";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(187, 63);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(17, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"5°";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(150, 63);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(17, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"4°";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(110, 63);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"3°";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(74, 63);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"2°";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(36, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"1°";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(214, 38);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(32, 20);
			this->textBox7->TabIndex = 9;
			this->textBox7->Text = L"6";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(177, 38);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(32, 20);
			this->textBox6->TabIndex = 10;
			this->textBox6->Text = L"5";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(141, 38);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(32, 20);
			this->textBox5->TabIndex = 11;
			this->textBox5->Text = L"4";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(104, 38);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(32, 20);
			this->textBox4->TabIndex = 6;
			this->textBox4->Text = L"3";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(68, 38);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(32, 20);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"2";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(30, 38);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(32, 20);
			this->textBox2->TabIndex = 8;
			this->textBox2->Text = L"1";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Enabled = false;
			this->label8->Location = System::Drawing::Point(166, 207);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(100, 26);
			this->label8->TabIndex = 3;
			this->label8->Text = L"Quantité de Pièces \r\n(jusqu\'à 50)";
			this->label8->Click += gcnew System::EventHandler(this, &Form1::label8_Click);
			// 
			// textBox8
			// 
			this->textBox8->Enabled = false;
			this->textBox8->Location = System::Drawing::Point(169, 236);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(119, 20);
			this->textBox8->TabIndex = 2;
			this->textBox8->Text = L"1";
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &Form1::textBox8_TextChanged);
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->radioButton5);
			this->panel3->Controls->Add(this->radioButton4);
			this->panel3->Enabled = false;
			this->panel3->Location = System::Drawing::Point(12, 139);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(139, 65);
			this->panel3->TabIndex = 7;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(11, 45);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(115, 17);
			this->radioButton5->TabIndex = 1;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"Interdire la blocage";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(12, 12);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(123, 17);
			this->radioButton4->TabIndex = 0;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Permettre la Blocage";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4->Controls->Add(this->radioButton7);
			this->panel4->Controls->Add(this->radioButton6);
			this->panel4->Enabled = false;
			this->panel4->Location = System::Drawing::Point(169, 139);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(134, 65);
			this->panel4->TabIndex = 7;
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Location = System::Drawing::Point(6, 45);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(84, 17);
			this->radioButton7->TabIndex = 1;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"Sans Retard";
			this->radioButton7->UseVisualStyleBackColor = true;
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(6, 12);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(119, 17);
			this->radioButton6->TabIndex = 0;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"Permettre le  Retard";
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(55, 391);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(44, 116);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(8, 344);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(1034, 298);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(55, 556);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(44, 44);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 10;
			this->pictureBox3->TabStop = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(351, 266);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(121, 24);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Animation";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click_1);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(55, 556);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(44, 44);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 10;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(55, 556);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(44, 44);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 10;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(55, 393);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(47, 71);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox6->TabIndex = 12;
			this->pictureBox6->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1054, 660);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->richTextBox1->Clear();
				 int type = 0;
				 int Ordre[7];
				 int Type_Retard = 0; // 0 = solutions sans retard de pieces; 1 = Permit retard
				 int Type_Bloq = 0; //0 = sans bloque; 1 = permit bloque
				
				 if (this->radioButton4->Checked)
					 Type_Bloq = 1;

				 if (this->radioButton6->Checked)
					 Type_Retard = 1;
				
				 if (this->radioButton2->Checked)
					 type = 2;
				 if (this->radioButton3->Checked)
					 type = 1;

				 int Qt_Max_Piece_Syst = Convert::ToInt32 (this->textBox1->Text);
				 int Qt_Pieces = Convert::ToInt32 (this->textBox8->Text);
				 //conpletar vetor
				 Ordre[1] = Convert::ToInt32 (this->textBox2->Text);
				 Ordre[2] = Convert::ToInt32 (this->textBox3->Text);
				 Ordre[3] = Convert::ToInt32 (this->textBox4->Text);
				 Ordre[4] = Convert::ToInt32 (this->textBox5->Text);
				 Ordre[5] = Convert::ToInt32 (this->textBox6->Text);
				 Ordre[6] = Convert::ToInt32 (this->textBox7->Text);

					 // debut de la function principale

				 Simuler(this->richTextBox1, Qt_Max_Piece_Syst, type, Qt_Pieces, Ordre, Type_Bloq, Type_Retard);
			 }
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 this->label1->Enabled = true;
				 this->textBox1->Enabled = true;
				 this->label8->Enabled = true;
				 this->textBox8->Enabled = true;
				 this->panel2->Enabled = false;
				 this->panel3->Enabled = true;
				 this->panel4->Enabled = true;
			 }
	private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 	 this->label1->Enabled = true;
				 this->textBox1->Enabled = true;
				 this->label8->Enabled = false;
				 this->textBox8->Enabled = false;
				 this->panel2->Enabled = true;
				 this->panel3->Enabled = true;
				 this->panel4->Enabled = true;
		 }
	private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 this->label1->Enabled = false;
				 this->textBox1->Enabled = false;
				 this->label8->Enabled = true;
				 this->textBox8->Enabled = true;
				 this->panel2->Enabled = false;
				 this->panel3->Enabled = true;
				 this->panel4->Enabled = true;
				 this->panel3->Enabled = false;
				 this->panel4->Enabled = false;
		 }
	private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			int Distance_descendre = 65;
			int Distance_Cuve = 81;
			this->timer1->Enabled = true;
			this->pictureBox1->Location = System::Drawing::Point(55, 391);
			this->pictureBox3->Location = System::Drawing::Point(55, 556);
			this->pictureBox4->Location = System::Drawing::Point(55, 556);
			this->pictureBox5->Location = System::Drawing::Point(55, 556);
			this->pictureBox6->Location = System::Drawing::Point(55, 393);

			 //abaixar
			 for (int i = 0; i<= Distance_descendre; i++)
				 this->pictureBox1->Top ++;
			Attender_Segunds (1, this->timer1);
			for (int i = 0; i<= Distance_descendre; i++){
				this->pictureBox1->Top --;
				 this->pictureBox3->Top --;
			}
// fazer tempo parar 4 segundos:
			Attender_Segunds (4, this->timer1);

//ir direit
			for (int i = 0; i<= 2*Distance_Cuve; i++){
				 this->pictureBox1->Left ++;
				 this->pictureBox3->Left ++;
				 this->pictureBox6->Left ++;
			}
		Attender_Segunds (1, this->timer1);
			for (int i = 0; i<= Distance_descendre; i++){
				 this->pictureBox1->Top ++;
				 this->pictureBox3->Top ++;
			}
			for (int i = 0; i<= Distance_descendre; i++)
				 this->pictureBox1->Top --;
			
			Attender_Segunds (10, this->timer1);

		// robot retourner
			for (int i = 0; i<= 2*Distance_Cuve; i++){//robot retourne
				 this->pictureBox1->Left --;
				 this->pictureBox6->Left --;
			}
		Attender_Segunds (1, this->timer1);
			for (int i = 0; i<= Distance_descendre; i++)
				 this->pictureBox1->Top ++;
		Attender_Segunds (1, this->timer1);
			for (int i = 0; i<= Distance_descendre; i++){ // montre prendre piece 2
				this->pictureBox1->Top --;
				 this->pictureBox4->Top --;
			}
		Attender_Segunds (1, this->timer1);
			for (int i = 0; i<= 3*Distance_Cuve; i++){ // mettre dans cuve 4
				 this->pictureBox1->Left ++;
				 this->pictureBox4->Left ++;
				 this->pictureBox6->Left ++;

			}
		Attender_Segunds (1, this->timer1);
			for (int i = 0; i<= Distance_descendre; i++){ // descendre avec piece 2
				this->pictureBox1->Top ++;
				 this->pictureBox4->Top ++;
			}
			for (int i = 0; i<= Distance_descendre; i++)//robot montre 
				 this->pictureBox1->Top --;
		Attender_Segunds (1, this->timer1);
			
		for (int i = 0; i<= 1*Distance_Cuve; i++){//robot retourne cuve 3
				 this->pictureBox1->Left --;
				 this->pictureBox6->Left --;
		}
		Attender_Segunds (1, this->timer1);
			for (int i = 0; i<= Distance_descendre; i++)
				 this->pictureBox1->Top ++;
		Attender_Segunds (1, this->timer1);
			for (int i = 0; i<= Distance_descendre; i++){
				this->pictureBox1->Top --;
				 this->pictureBox3->Top --;
			}
			for (int i = 0; i<= 7*Distance_Cuve; i++){
				 this->pictureBox1->Left ++;
				 this->pictureBox3->Left ++;
				 this->pictureBox6->Left ++;
			}
		Attender_Segunds (1, this->timer1);
			for (int i = 0; i<= Distance_descendre; i++){
				 this->pictureBox1->Top ++;
				 this->pictureBox3->Top ++;
			}
			for (int i = 0; i<= Distance_descendre; i++)//robot montre 
				 this->pictureBox1->Top --;
		Attender_Segunds (1, this->timer1);
		for (int i = 0; i<= 6*Distance_Cuve; i++){//robot retourne
				 this->pictureBox1->Left --;
				 this->pictureBox6->Left --;
		}

			for (int i = 0; i<= Distance_descendre; i++)//robot descendre 
				 this->pictureBox1->Top ++;

			for (int i = 0; i<= Distance_descendre; i++){ // montre prendre piece 2
				this->pictureBox1->Top --;
				 this->pictureBox4->Top --;
			}

			for (int i = 0; i<= 8*Distance_Cuve; i++){ // mettre dans cuve 4
				 this->pictureBox1->Left ++;
				 this->pictureBox4->Left ++;
				 this->pictureBox6->Left ++;
			}
		Attender_Segunds (1, this->timer1);
			for (int i = 0; i<= Distance_descendre; i++){ // descendre avec piece 2
				this->pictureBox1->Top ++;
				 this->pictureBox4->Top ++;
			}
			for (int i = 0; i<= Distance_descendre; i++)//robot montre 
				 this->pictureBox1->Top --;
		Attender_Segunds (10, this->timer1);
		
		//this->pictureBox4->Top += 100;

		for (int i = 0; i<= 11*Distance_Cuve; i++){//robot retourne
				 this->pictureBox1->Left --;
				 this->pictureBox6->Left --;
		}
			



			


			
			
			
			this->timer1->Stop();

			
		 }
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
				//this->timer1->Enabled = true;
				this->timer1->Start();
		 }
private: System::Void textBox8_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}


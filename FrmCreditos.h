#pragma once

namespace Ullyses {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for FrmCreditos
	/// </summary>
	public ref class FrmCreditos : public System::Windows::Forms::Form
	{
	public:
		FrmCreditos(void)
		{
			InitializeComponent();
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmCreditos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	protected:

	private:
		Bitmap^ FondoCreditos;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::PictureBox^ picBorde2;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmCreditos::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->picBorde2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBorde2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(790, 109);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(237, 45);
			this->label1->TabIndex = 1;
			this->label1->Text = L"CREDITOS";
			this->label1->Click += gcnew System::EventHandler(this, &FrmCreditos::label1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label5->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Location = System::Drawing::Point(769, 311);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(318, 30);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Rafael Justo Tito Martel";
			this->label5->Click += gcnew System::EventHandler(this, &FrmCreditos::label5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(748, 222);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(329, 30);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Boris Ore Laureano Ango";
			this->label4->Click += gcnew System::EventHandler(this, &FrmCreditos::label4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(694, 269);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(438, 30);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Kevin Imanol Bustamante Velasco";
			this->label3->Click += gcnew System::EventHandler(this, &FrmCreditos::label3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(813, 169);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(196, 38);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Integrantes";
			this->label2->Click += gcnew System::EventHandler(this, &FrmCreditos::label2_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label6->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label6->Location = System::Drawing::Point(704, 365);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(405, 38);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Herramientas utilizadas";
			this->label6->Click += gcnew System::EventHandler(this, &FrmCreditos::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->label7->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label7->Location = System::Drawing::Point(1064, 427);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(110, 38);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Codex";
			this->label7->Click += gcnew System::EventHandler(this, &FrmCreditos::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->label8->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label8->Location = System::Drawing::Point(869, 427);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(118, 38);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Piksel";
			this->label8->Click += gcnew System::EventHandler(this, &FrmCreditos::label8_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->label9->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label9->Location = System::Drawing::Point(677, 427);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(124, 38);
			this->label9->TabIndex = 12;
			this->label9->Text = L"Claude";
			this->label9->Click += gcnew System::EventHandler(this, &FrmCreditos::label9_Click);
			// 
			// picBorde2
			// 
			this->picBorde2->BackColor = System::Drawing::Color::Transparent;
			this->picBorde2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBorde2.Image")));
			this->picBorde2->Location = System::Drawing::Point(-34, 30);
			this->picBorde2->Name = L"picBorde2";
			this->picBorde2->Size = System::Drawing::Size(1908, 960);
			this->picBorde2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picBorde2->TabIndex = 13;
			this->picBorde2->TabStop = false;
			this->picBorde2->Click += gcnew System::EventHandler(this, &FrmCreditos::pictureBox1_Click);
			// 
			// FrmCreditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1844, 977);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->picBorde2);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"FrmCreditos";
			this->Text = L"FrmCreditos";
			this->Load += gcnew System::EventHandler(this, &FrmCreditos::FrmCreditos_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBorde2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Bitmap^ cargarImagen(String^ nombre) {
			String^ ruta = Path::Combine(Application::StartupPath, nombre);
			if (!File::Exists(ruta)) ruta = nombre;
			return gcnew Bitmap(ruta);
		};

		private: System::Void FrmCreditos_Load(System::Object^ sender, System::EventArgs^ e) {
			FondoCreditos = cargarImagen("Sprites\\PantallaInicio.png");
			this->BackgroundImage = FondoCreditos;
			this->BackgroundImageLayout = ImageLayout::Stretch;


			picBorde2->Location = Point(
				(this->ClientSize.Width - picBorde2->Width) / 2,
				(this->ClientSize.Height - picBorde2->Height) / 2
			);
			//recorre los labels para poder ordenarlos, es parte del diseño
			for (int i = 1; i <= 9; i++)
			{
				Label^ lbl = (Label^)this->Controls["label" + i.ToString()];

				lbl->Parent = picBorde2;
				lbl->BackColor = Color::Transparent;

				if (i <= 6)
					lbl->Left = (picBorde2->Width - lbl->Width) / 2;
			}
		}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}

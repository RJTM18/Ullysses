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
	/// Resumen de FrmConversacion2
	/// </summary>
	public ref class FrmConversacion2 : public System::Windows::Forms::Form
	{
	private:
		String^ dialogo;
		int indiceDialogo;
	private: System::Windows::Forms::Timer^ timerDialogo2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

		   int respuesta;
	public:
		FrmConversacion2(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		int getRespuesta() {
			return respuesta;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmConversacion2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ picPersonaje2;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblMolly;
	private: System::Windows::Forms::Button^ btnRespuesta1;
	private: System::Windows::Forms::Button^ btnRespuesta2;
	private: System::Windows::Forms::Button^ btnRespuesta3;
	private: System::ComponentModel::IContainer^ components;





	private:
		Bitmap^ Fondo3;
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmConversacion2::typeid));
			this->picPersonaje2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblMolly = (gcnew System::Windows::Forms::Label());
			this->btnRespuesta1 = (gcnew System::Windows::Forms::Button());
			this->btnRespuesta2 = (gcnew System::Windows::Forms::Button());
			this->btnRespuesta3 = (gcnew System::Windows::Forms::Button());
			this->timerDialogo2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPersonaje2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// picPersonaje2
			// 
			this->picPersonaje2->BackColor = System::Drawing::Color::Transparent;
			this->picPersonaje2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picPersonaje2.Image")));
			this->picPersonaje2->Location = System::Drawing::Point(772, 12);
			this->picPersonaje2->Name = L"picPersonaje2";
			this->picPersonaje2->Size = System::Drawing::Size(500, 405);
			this->picPersonaje2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picPersonaje2->TabIndex = 0;
			this->picPersonaje2->TabStop = false;
			this->picPersonaje2->Click += gcnew System::EventHandler(this, &FrmConversacion2::picPersonaje2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Peru;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(940, 522);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(180, 36);
			this->label1->TabIndex = 1;
			this->label1->Text = L"MollyBloom";
			// 
			// lblMolly
			// 
			this->lblMolly->AutoSize = true;
			this->lblMolly->BackColor = System::Drawing::Color::Tan;
			this->lblMolly->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMolly->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblMolly->Location = System::Drawing::Point(724, 560);
			this->lblMolly->Name = L"lblMolly";
			this->lblMolly->Size = System::Drawing::Size(98, 32);
			this->lblMolly->TabIndex = 2;
			this->lblMolly->Text = L"label2";
			this->lblMolly->Visible = false;
			this->lblMolly->Click += gcnew System::EventHandler(this, &FrmConversacion2::lblMolly_Click);
			// 
			// btnRespuesta1
			// 
			this->btnRespuesta1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRespuesta1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRespuesta1.Image")));
			this->btnRespuesta1->Location = System::Drawing::Point(445, 728);
			this->btnRespuesta1->Name = L"btnRespuesta1";
			this->btnRespuesta1->Size = System::Drawing::Size(524, 75);
			this->btnRespuesta1->TabIndex = 3;
			this->btnRespuesta1->Text = L"button1";
			this->btnRespuesta1->UseVisualStyleBackColor = true;
			this->btnRespuesta1->Click += gcnew System::EventHandler(this, &FrmConversacion2::btnRespuesta1_Click);
			// 
			// btnRespuesta2
			// 
			this->btnRespuesta2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRespuesta2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRespuesta2.Image")));
			this->btnRespuesta2->Location = System::Drawing::Point(1132, 728);
			this->btnRespuesta2->Name = L"btnRespuesta2";
			this->btnRespuesta2->Size = System::Drawing::Size(516, 75);
			this->btnRespuesta2->TabIndex = 4;
			this->btnRespuesta2->Text = L"button2";
			this->btnRespuesta2->UseVisualStyleBackColor = true;
			this->btnRespuesta2->Click += gcnew System::EventHandler(this, &FrmConversacion2::btnRespuesta2_Click);
			// 
			// btnRespuesta3
			// 
			this->btnRespuesta3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRespuesta3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRespuesta3.Image")));
			this->btnRespuesta3->Location = System::Drawing::Point(772, 851);
			this->btnRespuesta3->Name = L"btnRespuesta3";
			this->btnRespuesta3->Size = System::Drawing::Size(524, 75);
			this->btnRespuesta3->TabIndex = 5;
			this->btnRespuesta3->Text = L"button3";
			this->btnRespuesta3->UseVisualStyleBackColor = true;
			this->btnRespuesta3->Click += gcnew System::EventHandler(this, &FrmConversacion2::btnRespuesta3_Click);
			// 
			// timerDialogo2
			// 
			this->timerDialogo2->Interval = 45;
			this->timerDialogo2->Tick += gcnew System::EventHandler(this, &FrmConversacion2::timerDialogo2_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(477, 339);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1103, 506);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// FrmConversacion2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1745, 938);
			this->Controls->Add(this->btnRespuesta3);
			this->Controls->Add(this->btnRespuesta2);
			this->Controls->Add(this->btnRespuesta1);
			this->Controls->Add(this->lblMolly);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->picPersonaje2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"FrmConversacion2";
			this->Text = L"FrmConversacion2";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmConversacion2::FrmConversacion2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPersonaje2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Bitmap^ cargarImagen(String^ nombre) {
			String^ ruta = Path::Combine(Application::StartupPath, nombre);
			if (!File::Exists(ruta)) ruta = nombre;
			return gcnew Bitmap(ruta);
		};
	private: System::Void lblMolly_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
private: System::Void FrmConversacion2_Load(System::Object^ sender, System::EventArgs^ e) {
	Fondo3 = cargarImagen("Sprites\\PantallaInicio.png");
	this->BackgroundImage = Fondo3;
	this->BackgroundImageLayout = ImageLayout::Stretch;
	
	
	dialogo = L"Bloom, te noto bastante pensativo.\n"
		L"S\u00E9 que la p\u00E9rdida de Rudy fue dif\u00EDcil para ti.\n"
		L"Dime, \u00BFc\u00F3mo has logrado seguir adelante?";

	indiceDialogo = 0;
	respuesta = 0;

	lblMolly->Text = "";
	lblMolly->Visible = true;
	lblMolly->TextAlign = ContentAlignment::MiddleCenter;

	btnRespuesta1->Text = L"No quiero hablar de mi pasado.";

	btnRespuesta2->Text = L"Todav\u00EDa me duele recordarlo.";

	btnRespuesta3->Text = L"Su recuerdo me da fuerzas para continuar.";

	btnRespuesta1->Visible = false;
	btnRespuesta2->Visible = false;
	btnRespuesta3->Visible = false;

	timerDialogo2->Start();
}
private: System::Void picPersonaje2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void timerDialogo2_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (indiceDialogo < dialogo->Length)
	{
		indiceDialogo++;

		lblMolly->Text = dialogo->Substring(0, indiceDialogo);
	}
	else
	{
		timerDialogo2->Stop();

		btnRespuesta1->Visible = true;
		btnRespuesta2->Visible = true;
		btnRespuesta3->Visible = true;
	}
}
private: System::Void btnRespuesta1_Click(System::Object^ sender, System::EventArgs^ e) {
	respuesta = 1;
	this->Close();
}
private: System::Void btnRespuesta2_Click(System::Object^ sender, System::EventArgs^ e) {
	respuesta = 2;
	this->Close();
}
private: System::Void btnRespuesta3_Click(System::Object^ sender, System::EventArgs^ e) {
	respuesta = 3;
	this->Close();
}
};
}

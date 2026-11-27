#pragma once
namespace  Ullyses {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Resumen de FrmConversación
	/// </summary>
	public ref class FrmConversacion : public System::Windows::Forms::Form
	{
	private:
		String^ dialogo;
		int indiceDialogo;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   int respuesta;

	public:
		FrmConversacion(void)
		{
			InitializeComponent();
		}

		int getRespuesta() {
			return respuesta;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmConversacion()
		{
			if (components)
			{
				delete components;
			}
		}

		

	private: System::Windows::Forms::PictureBox^ picPersonaje;
	protected:
	private: System::Windows::Forms::Label^ lblPersonaje;
	private: System::Windows::Forms::Label^ lblDialogo;
	private: System::Windows::Forms::Button^ btnRespuesta1;


	private: System::Windows::Forms::Timer^ timerDialogo;
	private: System::Windows::Forms::Button^ btnRespuesta2;
	private: System::Windows::Forms::Button^ btnRespuesta3;


	private: System::ComponentModel::IContainer^ components;

	private:
		Bitmap^ Fondo2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmConversacion::typeid));
			this->picPersonaje = (gcnew System::Windows::Forms::PictureBox());
			this->lblPersonaje = (gcnew System::Windows::Forms::Label());
			this->lblDialogo = (gcnew System::Windows::Forms::Label());
			this->btnRespuesta1 = (gcnew System::Windows::Forms::Button());
			this->timerDialogo = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnRespuesta2 = (gcnew System::Windows::Forms::Button());
			this->btnRespuesta3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPersonaje))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// picPersonaje
			// 
			this->picPersonaje->BackColor = System::Drawing::Color::Black;
			this->picPersonaje->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picPersonaje.Image")));
			this->picPersonaje->Location = System::Drawing::Point(722, 1);
			this->picPersonaje->Name = L"picPersonaje";
			this->picPersonaje->Size = System::Drawing::Size(500, 505);
			this->picPersonaje->TabIndex = 0;
			this->picPersonaje->TabStop = false;
			this->picPersonaje->Click += gcnew System::EventHandler(this, &FrmConversacion::picPersonaje_Click);
			// 
			// lblPersonaje
			// 
			this->lblPersonaje->AutoSize = true;
			this->lblPersonaje->BackColor = System::Drawing::Color::Moccasin;
			this->lblPersonaje->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPersonaje->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblPersonaje->Location = System::Drawing::Point(868, 530);
			this->lblPersonaje->Name = L"lblPersonaje";
			this->lblPersonaje->Size = System::Drawing::Size(209, 36);
			this->lblPersonaje->TabIndex = 1;
			this->lblPersonaje->Text = L"Desconocido:";
			// 
			// lblDialogo
			// 
			this->lblDialogo->AutoSize = true;
			this->lblDialogo->BackColor = System::Drawing::Color::PapayaWhip;
			this->lblDialogo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDialogo->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblDialogo->Location = System::Drawing::Point(569, 575);
			this->lblDialogo->Name = L"lblDialogo";
			this->lblDialogo->Size = System::Drawing::Size(41, 32);
			this->lblDialogo->TabIndex = 2;
			this->lblDialogo->Text = L"...";
			this->lblDialogo->Click += gcnew System::EventHandler(this, &FrmConversacion::lblDialogo_Click);
			// 
			// btnRespuesta1
			// 
			this->btnRespuesta1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnRespuesta1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRespuesta1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btnRespuesta1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRespuesta1.Image")));
			this->btnRespuesta1->Location = System::Drawing::Point(354, 705);
			this->btnRespuesta1->Name = L"btnRespuesta1";
			this->btnRespuesta1->Size = System::Drawing::Size(528, 97);
			this->btnRespuesta1->TabIndex = 3;
			this->btnRespuesta1->Text = L"button1";
			this->btnRespuesta1->UseVisualStyleBackColor = true;
			this->btnRespuesta1->Click += gcnew System::EventHandler(this, &FrmConversacion::btnRespuesta1_Click);
			// 
			// timerDialogo
			// 
			this->timerDialogo->Interval = 45;
			this->timerDialogo->Tick += gcnew System::EventHandler(this, &FrmConversacion::timerDialogo_Tick);
			// 
			// btnRespuesta2
			// 
			this->btnRespuesta2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnRespuesta2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRespuesta2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btnRespuesta2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRespuesta2.Image")));
			this->btnRespuesta2->Location = System::Drawing::Point(1056, 705);
			this->btnRespuesta2->Name = L"btnRespuesta2";
			this->btnRespuesta2->Size = System::Drawing::Size(523, 97);
			this->btnRespuesta2->TabIndex = 4;
			this->btnRespuesta2->Text = L"button2";
			this->btnRespuesta2->UseVisualStyleBackColor = true;
			this->btnRespuesta2->Click += gcnew System::EventHandler(this, &FrmConversacion::btnRespuesta2_Click);
			// 
			// btnRespuesta3
			// 
			this->btnRespuesta3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnRespuesta3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRespuesta3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btnRespuesta3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRespuesta3.Image")));
			this->btnRespuesta3->Location = System::Drawing::Point(722, 865);
			this->btnRespuesta3->Name = L"btnRespuesta3";
			this->btnRespuesta3->Size = System::Drawing::Size(527, 97);
			this->btnRespuesta3->TabIndex = 5;
			this->btnRespuesta3->Text = L"button3";
			this->btnRespuesta3->UseVisualStyleBackColor = true;
			this->btnRespuesta3->Click += gcnew System::EventHandler(this, &FrmConversacion::btnRespuesta3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(404, 353);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1103, 506);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// FrmConversacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1617, 994);
			this->ControlBox = false;
			this->Controls->Add(this->btnRespuesta3);
			this->Controls->Add(this->btnRespuesta2);
			this->Controls->Add(this->btnRespuesta1);
			this->Controls->Add(this->lblDialogo);
			this->Controls->Add(this->lblPersonaje);
			this->Controls->Add(this->picPersonaje);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->KeyPreview = true;
			this->Name = L"FrmConversacion";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"FrmConversación";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmConversacion::FrmConversación_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPersonaje))->EndInit();
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


	private: System::Void FrmConversación_Load(System::Object^ sender, System::EventArgs^ e) {
		Fondo2 = cargarImagen("Sprites\\PantallaInicio.png");
		this->BackgroundImage = Fondo2;
		this->BackgroundImageLayout = ImageLayout::Stretch;

		dialogo = L"Bloom, \u00BFpor qu\u00E9 insistes en caminar por estas calles?\n"
			L"Sabes perfectamente que muchos aqu\u00ED\n"
			L"no te consideran uno de los nuestros.";

		indiceDialogo = 0;
		respuesta = 0;

		lblDialogo->TextAlign = ContentAlignment::MiddleCenter;

		btnRespuesta1->Text = L"Tengo tanto derecho como t\u00FA.";
		btnRespuesta2->Text = L"Prefiero evitar problemas.";
		btnRespuesta3->Text = L"\u00BFPor qu\u00E9 me juzgas sin conocerme?";

		btnRespuesta1->Visible = false;
		btnRespuesta2->Visible = false;
		btnRespuesta3->Visible = false;

		timerDialogo->Start();
		
	
	}
private: System::Void picPersonaje_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void lblDialogo_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void timerDialogo_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (indiceDialogo < dialogo->Length) {

		indiceDialogo++;

		lblDialogo->Text = dialogo->Substring(0, indiceDialogo);
	}
	else {

		timerDialogo->Stop();

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

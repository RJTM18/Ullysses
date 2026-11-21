#pragma once
#include "FrmNivel1.h"
namespace Lab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Summary for FrmMenuInicio
	/// </summary>
	public ref class FrmMenuInicio : public System::Windows::Forms::Form
	{
	public:
		FrmMenuInicio(void)
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
		~FrmMenuInicio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnJugar;
	protected:
	private: System::Windows::Forms::Button^ btnInstrucciones;
	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Label^ label1;

	private:
		Bitmap^ FondoMenu;
	private: System::Windows::Forms::Button^ btnSalir;
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
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnJugar
			// 
			this->btnJugar->Location = System::Drawing::Point(286, 188);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(325, 71);
			this->btnJugar->TabIndex = 0;
			this->btnJugar->Text = L"JUGAR";
			this->btnJugar->UseVisualStyleBackColor = true;
			this->btnJugar->Click += gcnew System::EventHandler(this, &FrmMenuInicio::btnJugar_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->Location = System::Drawing::Point(286, 265);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(325, 71);
			this->btnInstrucciones->TabIndex = 1;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = true;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &FrmMenuInicio::btnInstrucciones_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->Location = System::Drawing::Point(286, 342);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(325, 71);
			this->btnCreditos->TabIndex = 2;
			this->btnCreditos->Text = L"Creditos";
			this->btnCreditos->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 25.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(377, 116);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(134, 57);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Ulises";
			// 
			// btnSalir
			// 
			this->btnSalir->Location = System::Drawing::Point(679, 12);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(250, 50);
			this->btnSalir->TabIndex = 4;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmMenuInicio::btnSalir_Click);
			// 
			// FrmMenuInicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(941, 686);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnJugar);
			this->Name = L"FrmMenuInicio";
			this->Text = L"FrmMenuInicio";
			this->Load += gcnew System::EventHandler(this, &FrmMenuInicio::FrmMenuInicio_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Bitmap^ cargarImagen(String^ nombre) {
			String^ ruta = Path::Combine(Application::StartupPath, nombre);
			if (!File::Exists(ruta)) ruta = nombre;
			return gcnew Bitmap(ruta);
		}
	private: System::Void FrmMenuInicio_Load(System::Object^ sender, System::EventArgs^ e) {
		FondoMenu = cargarImagen("Sprites\\PantallaInicio.png");

		this->BackgroundImage = FondoMenu;
		this->BackgroundImageLayout = ImageLayout::Stretch;
	}
	private: System::Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e) {
		Ullyses::FrmNivel1^ nivel1 = gcnew Ullyses::FrmNivel1();

		this->Hide();
		nivel1->ShowDialog();
		this->Show();
	}
private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
};
}

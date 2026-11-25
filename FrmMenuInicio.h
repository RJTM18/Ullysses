#pragma once
#include "FrmNivel1.h"
#include "FrmNivel2.h"
#include "FrmNivel3.h"
#include "FrmCreditos.h"
namespace Ullyses {

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
	public ref class FrmMenuInicio : public System::Windows::Forms::Form {
	public:
		FrmMenuInicio(void) {
			InitializeComponent();
			
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;

			btnJugar->FlatStyle = FlatStyle::Flat;
			btnJugar->FlatAppearance->BorderSize = 0;
			btnJugar->FlatAppearance->MouseOverBackColor = Color::Transparent;
			btnJugar->FlatAppearance->MouseDownBackColor = Color::Transparent;
			btnJugar->BackColor = Color::Transparent;
			btnJugar->BackgroundImageLayout = ImageLayout::Zoom;
			btnJugar->UseVisualStyleBackColor = false;

			btnCreditos->FlatStyle = FlatStyle::Flat;
			btnCreditos->FlatAppearance->BorderSize = 0;
			btnCreditos->FlatAppearance->MouseOverBackColor = Color::Transparent;
			btnCreditos->FlatAppearance->MouseDownBackColor = Color::Transparent;
			btnCreditos->BackColor = Color::Transparent;
			btnCreditos->BackgroundImageLayout = ImageLayout::Zoom;
			btnCreditos->UseVisualStyleBackColor = false;

			btnInstrucciones->FlatStyle = FlatStyle::Flat;
			btnInstrucciones->FlatAppearance->BorderSize = 0;
			btnInstrucciones->FlatAppearance->MouseOverBackColor = Color::Transparent;
			btnInstrucciones->FlatAppearance->MouseDownBackColor = Color::Transparent;
			btnInstrucciones->BackColor = Color::Transparent;
			btnInstrucciones->BackgroundImageLayout = ImageLayout::Zoom;
			btnInstrucciones->UseVisualStyleBackColor = false;
		}



	protected:
		~FrmMenuInicio() {
			if (components) { delete components; }
		}
	private:
		Bitmap^ FondoMenu;

	private: System::Windows::Forms::Button^ btnJugar;
	private: System::Windows::Forms::Button^ btnInstrucciones;
	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Button^ btnNivel2;
	private: System::Windows::Forms::Button^ btnNivel3;





	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMenuInicio::typeid));
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->btnNivel2 = (gcnew System::Windows::Forms::Button());
			this->btnNivel3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnJugar
			// 
			this->btnJugar->BackColor = System::Drawing::Color::Transparent;
			this->btnJugar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnJugar.BackgroundImage")));
			this->btnJugar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnJugar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugar->Location = System::Drawing::Point(726, 175);
			this->btnJugar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(525, 204);
			this->btnJugar->TabIndex = 0;
			this->btnJugar->Text = L"Jugar";
			this->btnJugar->UseVisualStyleBackColor = false;
			this->btnJugar->Click += gcnew System::EventHandler(this, &FrmMenuInicio::btnJugar_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackColor = System::Drawing::Color::Transparent;
			this->btnInstrucciones->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnInstrucciones.BackgroundImage")));
			this->btnInstrucciones->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->Location = System::Drawing::Point(726, 409);
			this->btnInstrucciones->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(525, 204);
			this->btnInstrucciones->TabIndex = 1;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = false;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &FrmMenuInicio::btnInstrucciones_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackColor = System::Drawing::Color::Transparent;
			this->btnCreditos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCreditos.BackgroundImage")));
			this->btnCreditos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->Location = System::Drawing::Point(726, 653);
			this->btnCreditos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(525, 204);
			this->btnCreditos->TabIndex = 2;
			this->btnCreditos->Text = L"Creditos";
			this->btnCreditos->UseVisualStyleBackColor = false;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &FrmMenuInicio::btnCreditos_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 26.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(924, 99);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 50);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Ulises";
			// 
			// btnSalir
			// 
			this->btnSalir->Location = System::Drawing::Point(342, 128);
			this->btnSalir->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(307, 71);
			this->btnSalir->TabIndex = 4;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmMenuInicio::btnSalir_Click);
			// 
			// btnNivel2
			// 
			this->btnNivel2->Location = System::Drawing::Point(342, 53);
			this->btnNivel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnNivel2->Name = L"btnNivel2";
			this->btnNivel2->Size = System::Drawing::Size(325, 71);
			this->btnNivel2->TabIndex = 5;
			this->btnNivel2->Text = L"temporal NIvel2";
			this->btnNivel2->UseVisualStyleBackColor = true;
			this->btnNivel2->Click += gcnew System::EventHandler(this, &FrmMenuInicio::btnNivel2_click);
			// 
			// btnNivel3
			// 
			this->btnNivel3->Location = System::Drawing::Point(34, 460);
			this->btnNivel3->Margin = System::Windows::Forms::Padding(2);
			this->btnNivel3->Name = L"btnNivel3";
			this->btnNivel3->Size = System::Drawing::Size(244, 58);
			this->btnNivel3->TabIndex = 6;
			this->btnNivel3->Text = L"temporal NIvel3";
			this->btnNivel3->UseVisualStyleBackColor = true;
			this->btnNivel3->Click += gcnew System::EventHandler(this, &FrmMenuInicio::button1_Click);
			// 
			// FrmMenuInicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1911, 932);
			this->Controls->Add(this->btnNivel2);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnJugar);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"FrmMenuInicio";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
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
		};

		private: System::Void FrmMenuInicio_Load(System::Object^ sender, System::EventArgs^ e) {
			FondoMenu = cargarImagen("Sprites\\PantallaInicio.png");

			this->BackgroundImage = FondoMenu;
			this->BackgroundImageLayout = ImageLayout::Stretch;
		};

	    private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e)
	    {
				 
	    }

		private: System::Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e) {
			Ullyses::FrmNivel1^ nivel1 = gcnew Ullyses::FrmNivel1();

			this->Hide();
			nivel1->ShowDialog();
			this->Show();
		};



		private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		};

		private: System::Void btnNivel2_click(System::Object^ sender, System::EventArgs^ e) {
			Ullyses::FrmNivel2^ nivel2 = gcnew Ullyses::FrmNivel2();

			this->Hide();
			nivel2->ShowDialog();
			this->Show();
		};
private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
	Ullyses::FrmCreditos^ creditos = gcnew Ullyses::FrmCreditos();
	this->Hide();
	creditos->ShowDialog();
	this->Show();
	
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Ullyses::FrmNivel3^ nivel3 = gcnew Ullyses::FrmNivel3();
	this->Hide();
	nivel3->ShowDialog();
	this->Show();
}
};
}

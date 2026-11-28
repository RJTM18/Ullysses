#pragma once
#include "FrmNivel1.h"
#include "FrmNivel2.h"
#include "FrmNivel3.h"
#include "FrmCreditos.h"
#include "FrmInstrucciones.h"
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

			this->WindowState = FormWindowState::Maximized;
			this->FormBorderStyle =
				System::Windows::Forms::FormBorderStyle::None;
			//boton a configurar, su direccion y
			configurarBoton(btnJugar, 340);
			configurarBoton(btnInstrucciones, 510);
			configurarBoton(btnCreditos, 680);
			configurarBoton(btnSalir, 850);
		}



	protected:
		~FrmMenuInicio() {
			if (components) { delete components; }
		}
	private:

		void configurarBoton(Button^ btn, int y) {
			//sirve para eliminar el fondo blanco entre otros
			btn->Parent = picBorde;
			btn->FlatStyle = FlatStyle::Flat;
			btn->FlatAppearance->BorderSize = 0;
			btn->FlatAppearance->MouseOverBackColor = Color::Transparent;
			btn->FlatAppearance->MouseDownBackColor = Color::Transparent;
			btn->BackColor = Color::Transparent;

			btn->BackgroundImageLayout = ImageLayout::Zoom;
			btn->UseVisualStyleBackColor = false;
			//esto es para centrarlo
			btn->Left = (picBorde->Width - btn->Width) / 2;
			//esto es para ya establecerlos en la posicion vertical
			btn->Top = y;
		}
		Bitmap^ FondoMenu;

	private: System::Windows::Forms::Button^ btnJugar;
	private: System::Windows::Forms::Button^ btnInstrucciones;
	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ btnNivel2;
	private: System::Windows::Forms::Button^ btnNivel3;
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::PictureBox^ picBorde;
	private: System::Windows::Forms::Button^ btnNivel3Temporal;






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
			this->btnNivel2 = (gcnew System::Windows::Forms::Button());
			this->btnNivel3 = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->picBorde = (gcnew System::Windows::Forms::PictureBox());
			this->btnNivel3Temporal = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBorde))->BeginInit();
			this->SuspendLayout();
			// 
			// btnJugar
			// 
			this->btnJugar->BackColor = System::Drawing::Color::Transparent;
			this->btnJugar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnJugar.BackgroundImage")));
			this->btnJugar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnJugar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugar->Location = System::Drawing::Point(566, 168);
			this->btnJugar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(394, 166);
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
			this->btnInstrucciones->Location = System::Drawing::Point(566, 347);
			this->btnInstrucciones->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(394, 166);
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
			this->btnCreditos->Location = System::Drawing::Point(566, 530);
			this->btnCreditos->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(394, 166);
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
			this->label1->Location = System::Drawing::Point(710, 28);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 39);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Ulises";
			// 
			// btnNivel2
			// 
			this->btnNivel2->Location = System::Drawing::Point(256, 43);
			this->btnNivel2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnNivel2->Name = L"btnNivel2";
			this->btnNivel2->Size = System::Drawing::Size(244, 58);
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
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::Transparent;
			this->btnSalir->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSalir.BackgroundImage")));
			this->btnSalir->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(566, 715);
			this->btnSalir->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(394, 166);
			this->btnSalir->TabIndex = 2;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmMenuInicio::btnSalir_Click_1);
			// 
			// picBorde
			// 
			this->picBorde->BackColor = System::Drawing::Color::Transparent;
			this->picBorde->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBorde.Image")));
			this->picBorde->Location = System::Drawing::Point(428, -67);
			this->picBorde->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->picBorde->Name = L"picBorde";
			this->picBorde->Size = System::Drawing::Size(610, 1268);
			this->picBorde->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picBorde->TabIndex = 6;
			this->picBorde->TabStop = false;
			// 
			// btnNivel3Temporal
			// 
			this->btnNivel3Temporal->Location = System::Drawing::Point(65, 309);
			this->btnNivel3Temporal->Margin = System::Windows::Forms::Padding(2);
			this->btnNivel3Temporal->Name = L"btnNivel3Temporal";
			this->btnNivel3Temporal->Size = System::Drawing::Size(244, 58);
			this->btnNivel3Temporal->TabIndex = 7;
			this->btnNivel3Temporal->Text = L"temporal NIvel3";
			this->btnNivel3Temporal->UseVisualStyleBackColor = true;
			this->btnNivel3Temporal->Click += gcnew System::EventHandler(this, &FrmMenuInicio::btnNivel3Temporal_Click);
			// 
			// FrmMenuInicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1433, 862);
			this->Controls->Add(this->btnNivel3Temporal);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnNivel2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnJugar);
			this->Controls->Add(this->picBorde);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"FrmMenuInicio";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmMenuInicio";
			this->Load += gcnew System::EventHandler(this, &FrmMenuInicio::FrmMenuInicio_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBorde))->EndInit();
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
			//para localizar el borde en el centro
			picBorde->Location = Point(
				(this->ClientSize.Width - picBorde->Width) / 2,
				(this->ClientSize.Height - picBorde->Height) / 2
			);

			btnJugar->Left = (picBorde->Width - btnJugar->Width) / 2;
			btnInstrucciones->Left = (picBorde->Width - btnInstrucciones->Width) / 2;
			btnCreditos->Left = (picBorde->Width - btnCreditos->Width) / 2;
			btnSalir->Left = (picBorde->Width - btnSalir->Width) / 2;
		};

	    private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e)
	    {
			Ullyses::FrmInstrucciones^ instrucciones = gcnew Ullyses::FrmInstrucciones();
			this->Hide();
			instrucciones->ShowDialog();
			this->Show();
			
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
}
private: System::Void btnSalir_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void btnNivel3Temporal_Click(System::Object^ sender, System::EventArgs^ e) {
	FrmNivel3^ nivel3 = gcnew FrmNivel3();
	this->Hide();
	nivel3->ShowDialog();
	this->Show();
}
};
}

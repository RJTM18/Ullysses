#pragma once
#include "LogicaNivel3.h"

namespace Ullyses {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for FrmNivel3
	/// </summary>
	public ref class FrmNivel3 : public System::Windows::Forms::Form
	{
	public:
		FrmNivel3(void)
		{
			InitializeComponent();
			logica = nullptr;
			teclaPresionada = Ninguno;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmNivel3()
		{
			if (components)
			{
				delete components;
			}
			if (logica != nullptr) delete logica;
		}

	private:
		LogicaNivel3* logica;

		Bitmap^ fondoNivel3;
		Bitmap^ pesadillaImg;
		Bitmap^ mollyImg;

		Direccion teclaPresionada;

		System::Windows::Forms::Panel^ pnlSpriteNivel3;
		System::Windows::Forms::Timer^ timer1;
		System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlSpriteNivel3 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// pnlSpriteNivel3
			// 
			this->pnlSpriteNivel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlSpriteNivel3->Location = System::Drawing::Point(0, 0);
			this->pnlSpriteNivel3->Margin = System::Windows::Forms::Padding(4);
			this->pnlSpriteNivel3->Name = L"pnlSpriteNivel3";
			this->pnlSpriteNivel3->Size = System::Drawing::Size(914, 871);
			this->pnlSpriteNivel3->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmNivel3::timer1_Tick);
			// 
			// FrmNivel3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(914, 871);
			this->Controls->Add(this->pnlSpriteNivel3);
			this->Name = L"FrmNivel3";
			this->Text = L"FrmNivel3";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmNivel3::FrmNivel3_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel3::FrmNivel3_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel3::FrmNivel3_KeyUp);
			this->ResumeLayout(false);
		}
#pragma endregion

		Bitmap^ cargarImagen(String^ nombre) {
			String^ ruta = Path::Combine(Application::StartupPath, nombre);
			if (!File::Exists(ruta)) ruta = nombre;
			return gcnew Bitmap(ruta);
		};

	private: System::Void FrmNivel3_Load(System::Object^ sender, System::EventArgs^ e) {
		if (pnlSpriteNivel3->Width <= 0 || pnlSpriteNivel3->Height <= 0) return;

		logica = new LogicaNivel3(pnlSpriteNivel3->Width, pnlSpriteNivel3->Height);

		fondoNivel3 = cargarImagen("Sprites\\NivelTres.png");
		pesadillaImg = cargarImagen("Sprites\\Pesadilla.png");

		// Crear a la Pesadilla en la parte superior del nivel
		logica->crearPesadilla(
			/* Posicion X */			pnlSpriteNivel3->Width / 2,
			/* Posicion Y */			40,
			/* AnchoSpriteSheet */		pesadillaImg->Width,
			/* AltoSpriteSheet */		pesadillaImg->Height,
			/* Filas */					1,
			/* Columnas */				1,
			/* Velocidad */				8,
			/* Escala */				0.6
		);

		timer1->Enabled = true;
	};

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (logica == nullptr || fondoNivel3 == nullptr || pesadillaImg == nullptr) return;

		// Mover al monstruo (rebote izquierda/derecha)
		logica->moverPesadilla();

		Graphics^ canvas = pnlSpriteNivel3->CreateGraphics();
		BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(canvas, pnlSpriteNivel3->ClientRectangle);

		buffer->Graphics->DrawImage(fondoNivel3, 0, 0, pnlSpriteNivel3->Width, pnlSpriteNivel3->Height);
		logica->dibujarPesadilla(buffer->Graphics, pesadillaImg);

		buffer->Render(canvas);
		delete buffer;
		delete canvas;
	};

	private: System::Void FrmNivel3_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A) teclaPresionada = Izquierda;
		if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) teclaPresionada = Derecha;
	};

	private: System::Void FrmNivel3_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A) { if (teclaPresionada == Izquierda) teclaPresionada = Ninguno; }
		if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) { if (teclaPresionada == Derecha)   teclaPresionada = Ninguno; }
	};
	};
}

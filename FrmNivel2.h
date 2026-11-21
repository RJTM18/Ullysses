#pragma once
#include "Juego.h"
namespace Ullyses {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for FrmNewJuego
	/// </summary>
	public ref class FrmNivel2 : public System::Windows::Forms::Form
	{
	public:
		FrmNivel2(void) {
			InitializeComponent();
			juego = nullptr;
		}

	protected:
		~FrmNivel2() {
			if (components) { delete components; }
			if (juego != nullptr) delete juego;
		}

	private:
		Juego* juego;

		Bitmap^ junior;
		Bitmap^ fondoJuego;

		Direccion TeclaPresionada;

	private: System::Windows::Forms::Panel^ pnlSpriteScreen;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlSpriteScreen = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// pnlSpriteScreen
			// 
			this->pnlSpriteScreen->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlSpriteScreen->Location = System::Drawing::Point(0, 0);
			this->pnlSpriteScreen->Name = L"pnlSpriteScreen";
			this->pnlSpriteScreen->Size = System::Drawing::Size(1326, 662);
			this->pnlSpriteScreen->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmNivel2::timer1_Tick);
			// 
			// FrmJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1326, 662);
			this->Controls->Add(this->pnlSpriteScreen);
			this->Name = L"FrmJuego";
			this->Text = L"Juego";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmNivel2::FrmJuego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel2::FrmJuego_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel2::FrmJuego_KeyUp);
			this->ResumeLayout(false);
		}
#pragma endregion

		Bitmap^ cargarImagen(String^ nombre) {
			String^ ruta = Path::Combine(Application::StartupPath, nombre);
			if (!File::Exists(ruta)) ruta = nombre;
			return gcnew Bitmap(ruta);
		}

	private: System::Void FrmJuego_Load(System::Object^ sender, System::EventArgs^ e) {
		if (pnlSpriteScreen->Width <= 0 || pnlSpriteScreen->Height <= 0) return;

		if (juego == nullptr) juego = new Juego(pnlSpriteScreen->Width, pnlSpriteScreen->Height);

		junior = cargarImagen("developer.png");
		fondoJuego = cargarImagen("fondo.png");

		juego->crearJunior(
			/* Posicion X */			30,
			/* Posicion Y */			(int)(pnlSpriteScreen->Height / 2),
			/* AnchoSpriteSheet */		junior->Width,
			/* AltoSpriteSheet*/		junior->Height,
			/* columnas */				4,
			/* filas */					4,
			/* velocidad */				25,
			/* escala (1/2/3) */		1
		);
	};

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		juego->moverJunior(TeclaPresionada, pnlSpriteScreen->Width, pnlSpriteScreen->Height);

		Graphics^ canvas = pnlSpriteScreen->CreateGraphics();
		BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(canvas, pnlSpriteScreen->ClientRectangle);
		buffer->Graphics->DrawImage(fondoJuego, 0, 0, pnlSpriteScreen->Width, pnlSpriteScreen->Height);

		juego->dibujarJunior(buffer->Graphics, junior);
		buffer->Render(canvas);

		delete buffer;
		delete canvas;
	};

	private: System::Void FrmJuego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S)	TeclaPresionada = Abajo;
		if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A)	TeclaPresionada = Izquierda;
		if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) TeclaPresionada = Derecha;
		if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W)	TeclaPresionada = Arriba;
	};

	private: System::Void FrmJuego_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S) { if (TeclaPresionada == Abajo)		TeclaPresionada = Ninguno; }
		if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A) { if (TeclaPresionada == Izquierda)	TeclaPresionada = Ninguno; }
		if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) { if (TeclaPresionada == Derecha)	TeclaPresionada = Ninguno; }
		if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W) { if (TeclaPresionada == Arriba)		TeclaPresionada = Ninguno; }
	};
	};
}


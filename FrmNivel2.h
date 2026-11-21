#pragma once
#include "LogicaNivel1.h"
#include "LogicaNivel2.h"
namespace Ullyses {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class FrmNivel2 : public System::Windows::Forms::Form {
	public:
		FrmNivel2(void) {
			InitializeComponent();
			logicaNivel2 = nullptr;
		}

	protected:
		~FrmNivel2() {
			if (components) { delete components; }
			if (logicaNivel2 != nullptr) delete logicaNivel2;
		}

	private:
		Bitmap^ stephen;
		Bitmap^ fondoNivel2;
		Bitmap^ Antisemita;
		Nivel_2* logicaNivel2;

		Direccion teclaPresionada;

	private: System::Windows::Forms::Panel^ pnlSpriteNivel2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlSpriteNivel2 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// pnlSpriteNivel2
			// 
			this->pnlSpriteNivel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlSpriteNivel2->Location = System::Drawing::Point(0, 0);
			this->pnlSpriteNivel2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pnlSpriteNivel2->Name = L"pnlSpriteNivel2";
			this->pnlSpriteNivel2->Size = System::Drawing::Size(843, 564);
			this->pnlSpriteNivel2->TabIndex = 0;
			this->pnlSpriteNivel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmNivel2::pnlSpriteNivel2_Paint);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmNivel2::Timer1_tick);
			// 
			// FrmNivel2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(843, 564);
			this->Controls->Add(this->pnlSpriteNivel2);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"FrmNivel2";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmNivel2::FrmNivel2_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		Bitmap^ cargarImagen(String^ name) {
			String^ ruta = Path::Combine(Application::StartupPath, name);
			if (!File::Exists(ruta)) ruta = name;
			return gcnew Bitmap(ruta);
		};

		private: System::Void FrmNivel2_Load(System::Object^ sender, System::EventArgs^ e) {
			if (pnlSpriteNivel2->Height <= 0 || pnlSpriteNivel2->Width <= 0) return;
			logicaNivel2 = new Nivel_2(pnlSpriteNivel2->Height, pnlSpriteNivel2->Width);

			stephen = cargarImagen("Sprites\\StephenDedalus.png");
			fondoNivel2 = cargarImagen("Sprites\\NivelDos.png");
			Antisemita = cargarImagen("Sprites\\Anti_Semita.png");

			
			logicaNivel2->crearStephen(
				/* Posicion x: */			30,
				/* Posicion y: */			pnlSpriteNivel2->Height / 2,
				/* Anchura de Imagen: */	stephen->Width,
				/* Altura de Imagen: */		stephen->Height,
				/* Nº Columnas: */			8,
				/* Nº Filas: */				4,
				/* Velocidad: */			20,
				/* Escala: */				1
			);
			teclaPresionada = Ninguno;

			
		};

		private: System::Void Timer1_tick(System::Object^ sender, System::EventArgs^ e) {
			logicaNivel2->moverStephen(teclaPresionada, pnlSpriteNivel2->Width, pnlSpriteNivel2->Height);

			Graphics^ canvas = pnlSpriteNivel2->CreateGraphics();
			BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(canvas, pnlSpriteNivel2->ClientRectangle);
			buffer->Graphics->Clear(Color::White);

			logicaNivel2->dibujarStephen(buffer->Graphics, stephen);
			buffer->Render(canvas);

			delete buffer;
			delete canvas;
		};

		private: System::Void FrmJuego_keyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S)	teclaPresionada = Abajo;
			if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W)	teclaPresionada = Arriba;
			if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A)	teclaPresionada = Izquierda;
			if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) teclaPresionada = Derecha;
		};

		private: System::Void FrmJuego_keyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S) { if (teclaPresionada == Abajo)		teclaPresionada = Ninguno; }
			if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W) { if (teclaPresionada == Arriba)	teclaPresionada = Ninguno; }
			if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A) { if (teclaPresionada == Izquierda) teclaPresionada = Ninguno; }
			if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) { if (teclaPresionada == Derecha)	teclaPresionada = Ninguno; }
		};

	private: System::Void pnlSpriteNivel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
};
}

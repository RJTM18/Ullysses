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
			teclaPresionada = Ninguno;

			CONFIG_POLICIAS = gcnew array<ConfiguracionPolicia^> {
				gcnew ConfiguracionPolicia(75, 0.75, -1, 1, 1, -1),
					gcnew ConfiguracionPolicia(50, 0.75, 1, -1, -1, 1),
					gcnew ConfiguracionPolicia(50, 0.75, -1, 1, 1, -1)
			};
		}

	protected:
		~FrmNivel2() {
			if (components) { delete components; }
			if (logicaNivel2 != nullptr) delete logicaNivel2;
		}

	private:
		Bitmap^ stephen;
		Bitmap^ policia;
		Bitmap^ fondoNivel2;
		
		LogicaNivel2* logicaNivel2;

		Direccion teclaPresionada;

		ref struct ConfiguracionPolicia {
			int    velocidad;
			double escala;
			int    dxJugadorDerecha;    // reacción cuando el jugador va a la derecha
			int    dxJugadorIzquierda;  // reacción cuando va a la izquierda
			int    dyJugadorArriba;     // reacción cuando va arriba
			int    dyJugadorAbajo;      // reacción cuando va abajo

			ConfiguracionPolicia(int vel, double esc,
				int dxDer, int dxIzq, int dyArr, int dyAba)
				: velocidad(vel), escala(esc),
				dxJugadorDerecha(dxDer), dxJugadorIzquierda(dxIzq),
				dyJugadorArriba(dyArr), dyJugadorAbajo(dyAba) {
			}
		};

	private:
		// Tabla central de policías del nivel 2.
		// Orden: (xRatio, yRatio, velocidad, escala,
		//         dxJugadorDerecha, dxJugadorIzquierda, dyJugadorArriba, dyJugadorAbajo)
		static array<ConfiguracionPolicia^>^ CONFIG_POLICIAS;



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
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel2::FrmNivel2_keyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel2::FrmNivel2_keyUp);
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
			logicaNivel2 = new LogicaNivel2(pnlSpriteNivel2->Width, pnlSpriteNivel2->Height);
			timer1->Enabled = true;

			stephen = cargarImagen("Sprites\\StephenDedalus.png");
			policia = cargarImagen("Sprites\\Policia.png");
			fondoNivel2 = cargarImagen("Sprites\\NivelDos.png");
					
			logicaNivel2->crearStephen(
				/* Posicion x: */			pnlSpriteNivel2->Width / 2 - 80,
				/* Posicion y: */			pnlSpriteNivel2->Height - 10,
				/* Anchura de Imagen: */	stephen->Width,
				/* Altura de Imagen: */		stephen->Height,
				/* Nº Filas: */             4, 
				/* Nº Columnas: */			8,
				/* Velocidad: */			40,
				/* Escala: */				0.75
			);

			//Policía 1
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width / 2 - 80,
				/* Posicion y: */			10,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			75,
				/* Escala: */				0.75,
				/* Si el jugador va a la derecha: */		if (teclaPresionada == Derecha)		{ RespuestaDireccionPolicia = Izquierda; }, 
				/* Si el jugador va a la izquierda: */		if (teclaPresionada == izquierda)	{ RespuestaDireccionPolicia = Derecha; },	//policía a la derecha.
				/* Si el jugador va arriba: */				if (teclaPresionada == arriba)		{ RespuestaDireccionPolicia = Abajo; },		//policía va abajo.
				/* Si el jugador va abajo: */				if (teclaPresionada == Abajo)		{ RespuestaDireccionPolicia = Arriba; }		//policía arriba
			);

			//Policía 2
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width / 2 - 80,
				/* Posicion y: */			pnlSpriteNivel2->Height / 2,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			50,
				/* Escala: */				0.75,
				/* Si el jugador va a la derecha: */		1, //Policía a la izquierda.
				/* Si el jugador va a la izquierda: */		-1,	//policía a la derecha.
				/* Si el jugador va arriba: */				-1,	//policía va abajo.
				/* Si el jugador va abajo: */				1	//policía arriba
			);

			//Policía número 3
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width / 2 + 120,
				/* Posicion y: */			pnlSpriteNivel2->Height / 0.75,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			50,
				/* Escala: */				0.75,
				/* Si el jugador va a la derecha: */		-1, //Policía a la izquierda.
				/* Si el jugador va a la izquierda: */		1,	//policía a la derecha.
				/* Si el jugador va arriba: */				1,	//policía va abajo.
				/* Si el jugador va abajo: */				-1	//policía arriba
			);

			logicaNivel2->setCantidadPuntosVida(3);

			teclaPresionada = Ninguno;
		};

		private: System::Void Timer1_tick(System::Object^ sender, System::EventArgs^ e) {
			if (logicaNivel2 == nullptr) return;

			logicaNivel2->moverStephen(teclaPresionada, pnlSpriteNivel2->Width, pnlSpriteNivel2->Height);

			Graphics^ canvas = pnlSpriteNivel2->CreateGraphics();
			BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(canvas, pnlSpriteNivel2->ClientRectangle);
			buffer->Graphics->DrawImage(fondoNivel2, 0, 0, pnlSpriteNivel2->Width, pnlSpriteNivel2->Height);

			logicaNivel2->dibujarEntidades(buffer->Graphics, stephen, policia);
			buffer->Render(canvas);

			delete buffer;
			delete canvas;
		};

		private: System::Void FrmNivel2_keyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S)	teclaPresionada = Abajo;
			if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W)	teclaPresionada = Arriba;
			if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A)	teclaPresionada = Izquierda;
			if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) teclaPresionada = Derecha;
		};

		private: System::Void FrmNivel2_keyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S) { if (teclaPresionada == Abajo)		teclaPresionada = Ninguno; }
			if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W) { if (teclaPresionada == Arriba)	teclaPresionada = Ninguno; }
			if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A) { if (teclaPresionada == Izquierda) teclaPresionada = Ninguno; }
			if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) { if (teclaPresionada == Derecha)	teclaPresionada = Ninguno; }
		};


	};
};

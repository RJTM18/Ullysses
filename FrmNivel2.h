#pragma once
#include "Nivel2.h"

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
		};

	protected:
		~FrmNivel2() {
			if (components) { delete components; }
			if (logicaNivel2 != nullptr) delete logicaNivel2;
		};

	private:
		int alturaFondoNivel2 = 0;

		Bitmap^ stephen;
		Bitmap^ leopold;
		Bitmap^ policia;
		Bitmap^ fondoNivel2;
		Bitmap^ fondoStats;
		
		Nivel2* logicaNivel2;

		Direccion teclaPresionada;

		//dialogo
		String^ dialogo;
		int indiceDialogo;
		bool AcasoMostrandoDialogo; //Acaso == pregunta cerrada

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
			};
		};

	private: System::Windows::Forms::Panel^ pnlSpriteNivel2;
	private: System::Windows::Forms::Timer^ timerGame;
	private: System::Windows::Forms::Label^ lblHP;
	private: System::Windows::Forms::Label^ lblDialogo;
	private: System::Windows::Forms::Timer^ timerDialogo;
	private: System::Windows::Forms::Label^ lblContinuar;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlSpriteNivel2 = (gcnew System::Windows::Forms::Panel());
			this->lblContinuar = (gcnew System::Windows::Forms::Label());
			this->lblDialogo = (gcnew System::Windows::Forms::Label());
			this->lblHP = (gcnew System::Windows::Forms::Label());
			this->timerGame = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerDialogo = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlSpriteNivel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlSpriteNivel2
			// 
			this->pnlSpriteNivel2->BackColor = System::Drawing::SystemColors::Desktop;
			this->pnlSpriteNivel2->Controls->Add(this->lblContinuar);
			this->pnlSpriteNivel2->Controls->Add(this->lblDialogo);
			this->pnlSpriteNivel2->Controls->Add(this->lblHP);
			this->pnlSpriteNivel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlSpriteNivel2->Location = System::Drawing::Point(0, 0);
			this->pnlSpriteNivel2->Margin = System::Windows::Forms::Padding(4);
			this->pnlSpriteNivel2->Name = L"pnlSpriteNivel2";
			this->pnlSpriteNivel2->Size = System::Drawing::Size(1304, 491);
			this->pnlSpriteNivel2->TabIndex = 0;
			// 
			// lblContinuar
			// 
			this->lblContinuar->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->lblContinuar->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->lblContinuar->Location = System::Drawing::Point(0, 468);
			this->lblContinuar->Name = L"lblContinuar";
			this->lblContinuar->Size = System::Drawing::Size(1304, 23);
			this->lblContinuar->TabIndex = 2;
			this->lblContinuar->Text = L"Presiona Enter para continuar";
			this->lblContinuar->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblContinuar->Visible = false;
			// 
			// lblDialogo
			// 
			this->lblDialogo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lblDialogo->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDialogo->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lblDialogo->Location = System::Drawing::Point(0, 50);
			this->lblDialogo->Name = L"lblDialogo";
			this->lblDialogo->Size = System::Drawing::Size(1304, 441);
			this->lblDialogo->TabIndex = 1;
			this->lblDialogo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblHP
			// 
			this->lblHP->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblHP->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 30, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblHP->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lblHP->Location = System::Drawing::Point(0, 0);
			this->lblHP->Name = L"lblHP";
			this->lblHP->Size = System::Drawing::Size(1304, 50);
			this->lblHP->TabIndex = 0;
			this->lblHP->Text = L"Puntos de vida: -";
			this->lblHP->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->lblHP->Visible = false;
			// 
			// timerGame
			// 
			this->timerGame->Tick += gcnew System::EventHandler(this, &FrmNivel2::TimerGame_tick);
			// 
			// timerDialogo
			// 
			this->timerDialogo->Tick += gcnew System::EventHandler(this, &FrmNivel2::TimerDialogo_tick);
			// 
			// FrmNivel2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1304, 491);
			this->Controls->Add(this->pnlSpriteNivel2);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"FrmNivel2";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmNivel2::FrmNivel2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel2::FrmNivel2_keyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel2::FrmNivel2_keyUp);
			this->pnlSpriteNivel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		private: Bitmap^ cargarImagen(String^ name);
		private: void InicializarDialogo();		
		private: void InicializarJuego();

		private: System::Void FrmNivel2_Load(System::Object^ sender, System::EventArgs^ e) {
			if (pnlSpriteNivel2->Height <= 0 || pnlSpriteNivel2->Width <= 0) return;
			logicaNivel2 = new Nivel2(pnlSpriteNivel2->Width, pnlSpriteNivel2->Height);
		
			// Inicializar el diálogo
			InicializarDialogo();
		};

		private: System::Void TimerDialogo_tick(System::Object^ sender, System::EventArgs^ e) {
			if (indiceDialogo < dialogo->Length) {
				indiceDialogo++;
				lblDialogo->Text = dialogo->Substring(0, indiceDialogo);
			}
			else {
				timerDialogo->Stop();
				lblContinuar->Visible = true;
			}
		};

		private: System::Void TimerGame_tick(System::Object^ sender, System::EventArgs^ e) {
			if (logicaNivel2 == nullptr) return;

			logicaNivel2->moverStephen(teclaPresionada, pnlSpriteNivel2->Width / 2, alturaFondoNivel2);
			logicaNivel2->moverPolicias(teclaPresionada, pnlSpriteNivel2->Width / 2, alturaFondoNivel2);

			logicaNivel2->actualizarCamara();

			Graphics^ canvas = pnlSpriteNivel2->CreateGraphics();
			BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(canvas, pnlSpriteNivel2->ClientRectangle);

			lblHP->BackgroundImage = fondoStats;

			logicaNivel2->dibujarFondo(buffer->Graphics, fondoNivel2);
			logicaNivel2->aplicarCamara(buffer->Graphics);
			logicaNivel2->dibujarEntidades(buffer->Graphics, stephen, leopold, policia);
			logicaNivel2->graficarCuadros(buffer->Graphics);
			logicaNivel2->quitarCamara(buffer->Graphics);
			buffer->Render(canvas);

			delete buffer;
			delete canvas;

			//verifica en cada tick si jugador impacto con alguna entidad
			logicaNivel2->impactoJugadorConEntidad();
			lblHP->Text = "Puntos de vida: " + logicaNivel2->getStephenPuntosVida().ToString();

			if (logicaNivel2->stephenLlegoALaMeta()) {
				//     timer1->Enabled = false;
				//     // TODO: mensaje de victoria / abrir FrmNivel3 / cerrar este formulario
			}
		};

		private: System::Void FrmNivel2_keyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (AcasoMostrandoDialogo) {
				if (e->KeyCode == Keys::Enter) {
					AcasoMostrandoDialogo = false;
					teclaPresionada = Ninguno;
					InicializarJuego();
				}
				return;
			}
			
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

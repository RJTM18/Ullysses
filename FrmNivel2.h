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
		Bitmap^ policia;
		Bitmap^ fondoNivel2;
		
		Nivel2* logicaNivel2;

		Direccion teclaPresionada;

		//dialogo
		String^ dialogo;
		Timer^ timerDialogo;
		int indiceDialogo;


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
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lblHP;
	private: System::Windows::Forms::Label^ lblDialogo;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlSpriteNivel2 = (gcnew System::Windows::Forms::Panel());
			this->lblHP = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblDialogo = (gcnew System::Windows::Forms::Label());
			this->pnlSpriteNivel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlSpriteNivel2
			// 
			this->pnlSpriteNivel2->BackColor = System::Drawing::SystemColors::Desktop;
			this->pnlSpriteNivel2->Controls->Add(this->lblDialogo);
			this->pnlSpriteNivel2->Controls->Add(this->lblHP);
			this->pnlSpriteNivel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlSpriteNivel2->Location = System::Drawing::Point(0, 0);
			this->pnlSpriteNivel2->Name = L"pnlSpriteNivel2";
			this->pnlSpriteNivel2->Size = System::Drawing::Size(1304, 491);
			this->pnlSpriteNivel2->TabIndex = 0;
			// 
			// lblHP
			// 
			this->lblHP->AutoSize = true;
			this->lblHP->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHP->Location = System::Drawing::Point(902, 20);
			this->lblHP->Name = L"lblHP";
			this->lblHP->Size = System::Drawing::Size(160, 23);
			this->lblHP->TabIndex = 0;
			this->lblHP->Text = L"Puntos de vida: -";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmNivel2::Timer1_tick);
			// 
			// lblDialogo
			// 
			this->lblDialogo->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblDialogo->AutoSize = true;
			this->lblDialogo->Location = System::Drawing::Point(587, 214);
			this->lblDialogo->Name = L"lblDialogo";
			this->lblDialogo->Size = System::Drawing::Size(35, 13);
			this->lblDialogo->TabIndex = 1;
			this->lblDialogo->Text = L"label1";
			// 
			// FrmNivel2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1304, 491);
			this->Controls->Add(this->pnlSpriteNivel2);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"FrmNivel2";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmNivel2::FrmNivel2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel2::FrmNivel2_keyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel2::FrmNivel2_keyUp);
			this->pnlSpriteNivel2->ResumeLayout(false);
			this->pnlSpriteNivel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: Bitmap^ cargarImagen(String^ name) {
			String^ ruta = Path::Combine(Application::StartupPath, name);
			if (!File::Exists(ruta)) ruta = name;
			return gcnew Bitmap(ruta);
		};

		private: void InicializarDialogo() {
			dialogo = "¡Bienvenido al Nivel 2! En este nivel, te enfrentarás a un grupo de policías que intentarán detenerte. Mantente alerta y utiliza tus habilidades para esquivarlos y llegar a la meta. ¡Buena suerte!";
			indiceDialogo = 0;
			timerDialogo->Interval = 40; // velocidad de escritura del diálogo
			timerDialogo->Start();
		};
		
		private: void timerDialogo_Tick(Object^ sender, EventArgs^ e) {
			if (indiceDialogo < dialogo->Length) {
				indiceDialogo++;
				lblDialogo->Text = dialogo->Substring(0, indiceDialogo);
			}
			else {
				timerDialogo->Stop();
				InicializarJuego();          // salto a fase 2
			}
		};

		private: void InicializarJuego() {
			// Aquí puedes agregar la lógica para iniciar el juego, como habilitar controles, iniciar temporizadores, etc.
			// Por ejemplo
			stephen = cargarImagen("Sprites\\StephenDedalus.png");
			policia = cargarImagen("Sprites\\Policia.png");
			fondoNivel2 = cargarImagen("Sprites\\NivelDosFondo.png");

			int altoPantalla = pnlSpriteNivel2->Height;

			//proporcion de diferencia (tamaño de ventana / tamaño de fondo)
			double escalaFondo = (double)pnlSpriteNivel2->Width / (double)fondoNivel2->Width;

			//ajustado con la proporcion de las anchuras
			alturaFondoNivel2 = (int)(fondoNivel2->Height * escalaFondo);

			if (alturaFondoNivel2 < altoPantalla) alturaFondoNivel2 = altoPantalla; //un reajuste en caso el fondo sea tamaño menor

			logicaNivel2->setAltoNivel(alturaFondoNivel2); //desde abajo

			int altoStephen = (int)((stephen->Height / 4) * 0.75);
			int altoPolicia = (int)((policia->Height / 4) * 0.75);

			int nuevaUbicacionY = alturaFondoNivel2 - altoPantalla;

			logicaNivel2->crearStephen(
				/* Posicion x: */			pnlSpriteNivel2->Width / 2 - 80,
				/* Posicion y: */			alturaFondoNivel2,
				/* Anchura de Imagen: */	stephen->Width,
				/* Altura de Imagen: */		stephen->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			8,
				/* Velocidad: */			40,
				/* Escala: */				0.75
			);

			//jugador DERECHA, IZQUIERDA, ARRIBA, ABAJO
			//Policía 1
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width / 2 - 80,
				/* Posicion y: */			10 + nuevaUbicacionY,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			75,
				/* Escala: */				0.75,
				/* Direcciones: */			ReaccionPolicia(Izquierda, Derecha, Abajo, Arriba)
			);

			//Policía 2
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width / 2 - 80,
				/* Posicion y: */			pnlSpriteNivel2->Height / 2 + nuevaUbicacionY,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			8,
				/* Escala: */				0.75,
				/* Direcciones: */			ReaccionPolicia(Derecha, Izquierda, Abajo, Arriba)
			);

			//Policía número 3
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width / 2 + 120,
				/* Posicion y: */			pnlSpriteNivel2->Height,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			23,
				/* Escala: */				0.75,
				/* Direcciones: */			ReaccionPolicia(Derecha, Izquierda, Arriba, Abajo)
			);

			//Policía número 4
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width - 200,
				/* Posicion y: */			alturaFondoNivel2 / 2,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			30,
				/* Escala: */				0.75,
				/* Direcciones: */			ReaccionPolicia(Abajo, Arriba, Izquierda, Derecha)
			);

			//Policía número 3
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width / 2 - 120,
				/* Posicion y: */			alturaFondoNivel2 * 0.1,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			54,
				/* Escala: */				0.75,
				/* Direcciones: */			ReaccionPolicia(Abajo, Derecha, Arriba, Izquierda)
			);

			//Policía número 3
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width / 2 + 30,
				/* Posicion y: */			pnlSpriteNivel2->Height,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			99,
				/* Escala: */				0.75,
				/* Direcciones: */			ReaccionPolicia(Izquierda, Derecha, Abajo, Arriba)
			);


			//jugador DERECHA, IZQUIERDA, ARRIBA, ABAJO
			//Policía 1
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width / 2 - 80,
				/* Posicion y: */			10 + nuevaUbicacionY,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			75,
				/* Escala: */				0.75,
				/* Direcciones: */			ReaccionPolicia(Izquierda, Derecha, Abajo, Arriba)
			);

			//Policía 2
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width / 2 - 80,
				/* Posicion y: */			pnlSpriteNivel2->Height / 2 + nuevaUbicacionY,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			10,
				/* Escala: */				0.75,
				/* Direcciones: */			ReaccionPolicia(Derecha, Izquierda, Abajo, Arriba)
			);

			//Policía número 3
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width / 2 + 120,
				/* Posicion y: */			pnlSpriteNivel2->Height / 0.75 + nuevaUbicacionY,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			29,
				/* Escala: */				0.75,
				/* Direcciones: */			ReaccionPolicia(Derecha, Izquierda, Arriba, Abajo)
			);

			//Policía número 4
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width / 2,
				/* Posicion y: */			alturaFondoNivel2 / 2,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			50,
				/* Escala: */				0.75,
				/* Direcciones: */			ReaccionPolicia(Abajo, Arriba, Izquierda, Derecha)
			);

			// Policía número 1
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width * 0.25,
				/* Posicion y: */			alturaFondoNivel2 * 0.25,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			77,
				/* Escala: */				0.75,
				/* Direcciones: */			ReaccionPolicia(Abajo, Derecha, Arriba, Izquierda)
			);

			// Policía número 2
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width * 0.75,
				/* Posicion y: */			alturaFondoNivel2 * 0.25,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			66,
				/* Escala: */				0.75,
				/* Direcciones: */			ReaccionPolicia(Izquierda, Derecha, Abajo, Arriba)
			);

			// Policía número 3
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width * 0.75,
				/* Posicion y: */			alturaFondoNivel2 * 0.75,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			49,
				/* Escala: */				0.75,
				/* Direcciones: */			ReaccionPolicia(Derecha, Izquierda, Arriba, Abajo)
			);

			// Policía número 4
			logicaNivel2->crearNuevoPolicia(
				/* Posicion x: */			pnlSpriteNivel2->Width * 0.25,
				/* Posicion y: */			alturaFondoNivel2 * 0.75,
				/* Anchura de Imagen: */	policia->Width,
				/* Altura de Imagen: */		policia->Height,
				/* Nº Filas: */             4,
				/* Nº Columnas: */			4,
				/* Velocidad: */			57,
				/* Escala: */				0.75,
				/* Direcciones: */			ReaccionPolicia(Abajo, Arriba, Izquierda, Derecha)
			);


			// Distribución equilibrada: 2 policías en cada zona vertical.
			logicaNivel2->crearNuevoPolicia(
				pnlSpriteNivel2->Width / 2 - 80, alturaFondoNivel2 * 0.12,
				policia->Width, policia->Height, 4, 4, 50, 0.75,
				ReaccionPolicia(Izquierda, Derecha, Abajo, Arriba));

			logicaNivel2->crearNuevoPolicia(
				pnlSpriteNivel2->Width / 2 - 80, alturaFondoNivel2 * 0.45,
				policia->Width, policia->Height, 4, 4, 44, 0.75,
				ReaccionPolicia(Derecha, Izquierda, Abajo, Arriba));

			logicaNivel2->crearNuevoPolicia(
				pnlSpriteNivel2->Width / 2 + 120, alturaFondoNivel2 * 0.75,
				policia->Width, policia->Height, 4, 4, 29, 0.75,
				ReaccionPolicia(Derecha, Izquierda, Arriba, Abajo));

			logicaNivel2->crearNuevoPolicia(
				pnlSpriteNivel2->Width - 200, alturaFondoNivel2 * 0.18,
				policia->Width, policia->Height, 4, 4, 12, 0.75,
				ReaccionPolicia(Abajo, Arriba, Abajo, Derecha));

			logicaNivel2->crearNuevoPolicia(
				pnlSpriteNivel2->Width / 2 - 120, alturaFondoNivel2 * 0.50,
				policia->Width, policia->Height, 4, 4, 42, 0.75,
				ReaccionPolicia(Abajo, Derecha, Arriba, Izquierda));

			logicaNivel2->crearNuevoPolicia(
				pnlSpriteNivel2->Width / 2 + 30, alturaFondoNivel2 * 0.82,
				policia->Width, policia->Height, 4, 4, 100, 0.75,
				ReaccionPolicia(Izquierda, Derecha, Abajo, Arriba));


			// Distribución equilibrada: 3 policías en cada zona vertical.
			logicaNivel2->crearNuevoPolicia(
				pnlSpriteNivel2->Width * 0.25, alturaFondoNivel2 * 0.12,
				policia->Width, policia->Height, 4, 4, 80, 0.75,
				ReaccionPolicia(Abajo, Derecha, Arriba, Izquierda));

			logicaNivel2->crearNuevoPolicia(
				pnlSpriteNivel2->Width * 0.75, alturaFondoNivel2 * 0.12,
				policia->Width, policia->Height, 4, 4, 82, 0.75,
				ReaccionPolicia(Izquierda, Derecha, Abajo, Arriba));

			logicaNivel2->crearNuevoPolicia(
				pnlSpriteNivel2->Width / 2 - 80, alturaFondoNivel2 * 0.18,
				policia->Width, policia->Height, 4, 4, 12, 0.75,
				ReaccionPolicia(Derecha, Izquierda, Abajo, Arriba));

			logicaNivel2->crearNuevoPolicia(
				pnlSpriteNivel2->Width / 2 - 80, alturaFondoNivel2 * 0.45,
				policia->Width, policia->Height, 4, 4, 87, 0.75,
				ReaccionPolicia(Izquierda, Derecha, Abajo, Arriba));

			logicaNivel2->crearNuevoPolicia(
				pnlSpriteNivel2->Width / 2, alturaFondoNivel2 * 0.50,
				policia->Width, policia->Height, 4, 4, 13, 0.75,
				ReaccionPolicia(Abajo, Arriba, Abajo, Derecha));

			logicaNivel2->crearNuevoPolicia(
				pnlSpriteNivel2->Width / 2 + 120, alturaFondoNivel2 * 0.50,
				policia->Width, policia->Height, 4, 4, 92, 0.75,
				ReaccionPolicia(Abajo, Derecha, Arriba, Izquierda));

			logicaNivel2->crearNuevoPolicia(
				pnlSpriteNivel2->Width * 0.75, alturaFondoNivel2 * 0.75,
				policia->Width, policia->Height, 4, 4, 95, 0.75,
				ReaccionPolicia(Derecha, Izquierda, Arriba, Abajo));

			logicaNivel2->crearNuevoPolicia(
				pnlSpriteNivel2->Width * 0.25, alturaFondoNivel2 * 0.75,
				policia->Width, policia->Height, 4, 4, 99, 0.75,
				ReaccionPolicia(Abajo, Arriba, Abajo, Derecha));

			logicaNivel2->crearNuevoPolicia(
				pnlSpriteNivel2->Width / 2 + 30, alturaFondoNivel2 * 0.82,
				policia->Width, policia->Height, 4, 4, 21, 0.75,
				ReaccionPolicia(Izquierda, Derecha, Arriba, Abajo));


			logicaNivel2->setMetaY(0);
			logicaNivel2->setStephenPuntosVida(100);
			logicaNivel2->actualizarCamara();

			teclaPresionada = Ninguno;

			timer1->Enabled = true; // Habilitar el temporizador del juego
			lblDialogo->Visible = false; // Ocultar el diálogo
		};


		private: System::Void FrmNivel2_Load(System::Object^ sender, System::EventArgs^ e) {
			if (pnlSpriteNivel2->Height <= 0 || pnlSpriteNivel2->Width <= 0) return;
			logicaNivel2 = new Nivel2(pnlSpriteNivel2->Width, pnlSpriteNivel2->Height);
			timer1->Enabled = true;
			
			// Inicializar el diálogo
			InicializarDialogo();
		};

		private: System::Void Timer1_tick(System::Object^ sender, System::EventArgs^ e) {
			if (logicaNivel2 == nullptr) return;

			timerDialogo_Tick(sender, e);

			logicaNivel2->moverStephen(teclaPresionada, pnlSpriteNivel2->Width / 2, alturaFondoNivel2);
			logicaNivel2->moverPolicias(teclaPresionada, pnlSpriteNivel2->Width / 2, alturaFondoNivel2);

			logicaNivel2->actualizarCamara();

			Graphics^ canvas = pnlSpriteNivel2->CreateGraphics();
			BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(canvas, pnlSpriteNivel2->ClientRectangle);

			logicaNivel2->dibujarFondo(buffer->Graphics, fondoNivel2);
			logicaNivel2->aplicarCamara(buffer->Graphics);
			logicaNivel2->dibujarEntidades(buffer->Graphics, stephen, policia);
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

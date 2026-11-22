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
	public ref class FrmNivel1 : public System::Windows::Forms::Form
	{
	public:
		FrmNivel1(void) {
			InitializeComponent();
			juego = nullptr;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		}

	protected:
		~FrmNivel1() {
			if (components) { delete components; }
			if (juego != nullptr) delete juego;
		}

	private:
		Juego* juego;
		Bitmap^ fondoJuego;
		Bitmap^ Leopold;
		Direccion TeclaPresionada;
		Bitmap^ AutoNegro;
		Bitmap^ Antisemita;
	private: System::Windows::Forms::Panel^ pnlSpriteScreen;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ pnlEstadistica;
	private: System::Windows::Forms::Label^ lblVida;

	private: System::Windows::Forms::Label^ lblNombre;
	private: System::Windows::Forms::Label^ lblMetros;



	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlSpriteScreen = (gcnew System::Windows::Forms::Panel());
			this->pnlEstadistica = (gcnew System::Windows::Forms::Panel());
			this->lblMetros = (gcnew System::Windows::Forms::Label());
			this->lblVida = (gcnew System::Windows::Forms::Label());
			this->lblNombre = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlSpriteScreen->SuspendLayout();
			this->pnlEstadistica->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlSpriteScreen
			// 
			this->pnlSpriteScreen->Controls->Add(this->pnlEstadistica);
			this->pnlSpriteScreen->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlSpriteScreen->Location = System::Drawing::Point(0, 0);
			this->pnlSpriteScreen->Margin = System::Windows::Forms::Padding(4);
			this->pnlSpriteScreen->Name = L"pnlSpriteScreen";
			this->pnlSpriteScreen->Size = System::Drawing::Size(1768, 815);
			this->pnlSpriteScreen->TabIndex = 0;
			this->pnlSpriteScreen->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmNivel1::pnlSpriteScreen_Paint);
			// 
			// pnlEstadistica
			// 
			this->pnlEstadistica->BackColor = System::Drawing::SystemColors::Info;
			this->pnlEstadistica->Controls->Add(this->lblMetros);
			this->pnlEstadistica->Controls->Add(this->lblVida);
			this->pnlEstadistica->Controls->Add(this->lblNombre);
			this->pnlEstadistica->Dock = System::Windows::Forms::DockStyle::Right;
			this->pnlEstadistica->Location = System::Drawing::Point(1413, 0);
			this->pnlEstadistica->Name = L"pnlEstadistica";
			this->pnlEstadistica->Size = System::Drawing::Size(355, 815);
			this->pnlEstadistica->TabIndex = 0;
			// 
			// lblMetros
			// 
			this->lblMetros->AutoSize = true;
			this->lblMetros->Font = (gcnew System::Drawing::Font(L"Matura MT Script Capitals", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMetros->Location = System::Drawing::Point(104, 353);
			this->lblMetros->Name = L"lblMetros";
			this->lblMetros->Size = System::Drawing::Size(152, 37);
			this->lblMetros->TabIndex = 3;
			this->lblMetros->Text = L"Metros: 0";
			this->lblMetros->Click += gcnew System::EventHandler(this, &FrmNivel1::lblMetros_Click);
			// 
			// lblVida
			// 
			this->lblVida->AutoSize = true;
			this->lblVida->Font = (gcnew System::Drawing::Font(L"Magneto", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVida->Location = System::Drawing::Point(120, 222);
			this->lblVida->Name = L"lblVida";
			this->lblVida->Size = System::Drawing::Size(136, 32);
			this->lblVida->TabIndex = 2;
			this->lblVida->Text = L"Vidas: 3";
			this->lblVida->Click += gcnew System::EventHandler(this, &FrmNivel1::lblVida_Click);
			// 
			// lblNombre
			// 
			this->lblNombre->AutoSize = true;
			this->lblNombre->Font = (gcnew System::Drawing::Font(L"Matura MT Script Capitals", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNombre->Location = System::Drawing::Point(24, 52);
			this->lblNombre->Name = L"lblNombre";
			this->lblNombre->Size = System::Drawing::Size(302, 44);
			this->lblNombre->TabIndex = 0;
			this->lblNombre->Text = L"Nivel 1: Leopold";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmNivel1::timer1_Tick);
			// 
			// FrmNivel1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1768, 815);
			this->Controls->Add(this->pnlSpriteScreen);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"FrmNivel1";
			this->Text = L"Juego";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmNivel1::FrmJuego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel1::FrmJuego_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel1::FrmJuego_KeyUp);
			this->pnlSpriteScreen->ResumeLayout(false);
			this->pnlEstadistica->ResumeLayout(false);
			this->pnlEstadistica->PerformLayout();
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
		fondoJuego = cargarImagen("Sprites\\NivelUno.png");
		Leopold = cargarImagen("Sprites\\LeopoldBloom.png");
		Antisemita = cargarImagen("Sprites\\Anti_Semita.png");
		AutoNegro = cargarImagen("Sprites\\AutoNegro.png");
		juego->crearLeopold(
			/* Posicion X */			30,
			/* Posicion Y */			(int)(pnlSpriteScreen->Height / 2),
			/* AnchoSpriteSheet */		Leopold->Width,
			/* AltoSpriteSheet*/		Leopold->Height,
			/* columnas */				4,
			/* filas */					4,
			/* velocidad */				25,
			/* escala (1/2/3) */		0.6
		);
		

		int carriles[3] = { 325, 400, 600 };
		int antiSemitas[3] = { 340, 420, 620 };
			for (int i = 0; i < 3; i++) 
			{
				juego->crearCarro(
					pnlSpriteScreen->Width + i * 500,
					carriles[i],
					AutoNegro->Width,
					AutoNegro->Height,
					4, 4, 30, 0.8
				);

				juego->crearAntisemita(
    pnlSpriteScreen->Width + i * 250,
    antiSemitas[i],
    Antisemita->Width,
    Antisemita->Height,
    4, 4, 15, 0.6
);
			}
		
	};

private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	if (juego == nullptr || fondoJuego == nullptr ||
		Leopold == nullptr || AutoNegro == nullptr) return;

	juego->moverLeopold(TeclaPresionada,
		pnlSpriteScreen->Width - pnlEstadistica->Width,
		pnlSpriteScreen->Height);
	juego->actualizarMetros(TeclaPresionada);
	juego->moverAntisemita();
	juego->moverCarros();

	Graphics^ canvas = pnlSpriteScreen->CreateGraphics();
	BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(canvas, pnlSpriteScreen->ClientRectangle);
	
	buffer->Graphics->DrawImage(fondoJuego, 0, 0, pnlSpriteScreen->Width, pnlSpriteScreen->Height);

	juego->dibujarAntisemita(buffer->Graphics, Antisemita);
	juego->dibujarCarros(buffer->Graphics, AutoNegro);
	juego->dibujarLeopold(buffer->Graphics, Leopold);
	juego->dibujarColisiones(buffer->Graphics);
	buffer->Render(canvas);

	delete buffer;
	delete canvas;

	juego->verificarColisiones();

	lblVida->Text = "Vidas: " + juego->getVida().ToString();
	lblMetros->Text = "Metros: " + juego->metros().ToString();

	if (juego->gano())
	{
		timer1->Stop();
		MessageBox::Show("Ganaste!!!");
		return;
	}

	if (juego->perdio())
	{
		timer1->Stop();
		MessageBox::Show("GAME OVER");
	}
	
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
	private: System::Void pnlSpriteScreen_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
 	}
private: System::Void lblVida_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblMetros_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
};
}


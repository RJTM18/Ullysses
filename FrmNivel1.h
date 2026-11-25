#pragma once
#include "Nivel1.h"
#include "FrmConversacion.h"
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
			timer1->Stop();
			MostrandoHistoria = true;
			this->KeyPreview = true;
			lblNombre->Parent = pictureBox1;
			lblNombre->BackColor = Color::Transparent;
			//(x,y)
			lblNombre->Location = Point(20,40);

			lblMetros->Parent = pictureBox2;
			lblMetros->BackColor = Color::Transparent;
			lblMetros->Location = Point(60, 40);

			lblConfianza->Parent = pictureBox3;
			lblConfianza->BackColor = Color::Transparent;
			lblConfianza->Location = Point(40, 45);

			
			juego = nullptr;
			TeclaPresionada = Ninguno;

			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		}

	protected:
		~FrmNivel1() {
			if (components) { delete components; }
			if (juego != nullptr) delete juego;
		}

	private:
		int anchoPantallaSprite;
		int altoPantallaSprite;

		Nivel1* juego;
		String^ historia;
		int IndiceHistoria = 0;
		bool MostrandoHistoria;
		Bitmap^ fondoJuego;
		int fondoX = 0;
		Bitmap^ Leopold;
		Bitmap^ AutoNegro;
		Bitmap^ Antisemita;

		Direccion TeclaPresionada;

	private: System::Windows::Forms::Panel^ pnlSpriteScreen;
	private: System::Windows::Forms::Timer^ timer1;

	private: System::Windows::Forms::Label^ lblConfianza;


	private: System::Windows::Forms::Label^ lblNombre;
	private: System::Windows::Forms::Label^ lblMetros;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Panel^ pnlHistoria;
	private: System::Windows::Forms::Label^ lblHistoria;
	private: System::Windows::Forms::Label^ lblContinuar;
	private: System::Windows::Forms::Timer^ timerHistoria;




	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void) {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmNivel1::typeid));
			   this->pnlSpriteScreen = (gcnew System::Windows::Forms::Panel());
			   this->pnlHistoria = (gcnew System::Windows::Forms::Panel());
			   this->lblContinuar = (gcnew System::Windows::Forms::Label());
			   this->lblHistoria = (gcnew System::Windows::Forms::Label());
			   this->lblMetros = (gcnew System::Windows::Forms::Label());
			   this->lblConfianza = (gcnew System::Windows::Forms::Label());
			   this->lblNombre = (gcnew System::Windows::Forms::Label());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timerHistoria = (gcnew System::Windows::Forms::Timer(this->components));
			   this->pnlSpriteScreen->SuspendLayout();
			   this->pnlHistoria->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // pnlSpriteScreen
			   // 
			   this->pnlSpriteScreen->Controls->Add(this->lblMetros);
			   this->pnlSpriteScreen->Controls->Add(this->lblConfianza);
			   this->pnlSpriteScreen->Controls->Add(this->lblNombre);
			   this->pnlSpriteScreen->Controls->Add(this->pictureBox1);
			   this->pnlSpriteScreen->Controls->Add(this->pictureBox2);
			   this->pnlSpriteScreen->Controls->Add(this->pictureBox3);
			   this->pnlSpriteScreen->Controls->Add(this->pnlHistoria);
			   this->pnlSpriteScreen->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pnlSpriteScreen->Location = System::Drawing::Point(0, 0);
			   this->pnlSpriteScreen->Margin = System::Windows::Forms::Padding(4);
			   this->pnlSpriteScreen->Name = L"pnlSpriteScreen";
			   this->pnlSpriteScreen->Size = System::Drawing::Size(1487, 815);
			   this->pnlSpriteScreen->TabIndex = 0;
			   this->pnlSpriteScreen->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmNivel1::pnlSpriteScreen_Paint);
			   // 
			   // pnlHistoria
			   // 
			   this->pnlHistoria->BackColor = System::Drawing::Color::Black;
			   this->pnlHistoria->Controls->Add(this->lblContinuar);
			   this->pnlHistoria->Controls->Add(this->lblHistoria);
			   this->pnlHistoria->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pnlHistoria->Location = System::Drawing::Point(0, 0);
			   this->pnlHistoria->Name = L"pnlHistoria";
			   this->pnlHistoria->Size = System::Drawing::Size(1487, 815);
			   this->pnlHistoria->TabIndex = 7;
			   this->pnlHistoria->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmNivel1::pnlHistoria_Paint);
			   // 
			   // lblContinuar
			   // 
			   this->lblContinuar->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->lblContinuar->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblContinuar->ForeColor = System::Drawing::Color::Gray;
			   this->lblContinuar->Location = System::Drawing::Point(0, 788);
			   this->lblContinuar->Name = L"lblContinuar";
			   this->lblContinuar->Size = System::Drawing::Size(1487, 27);
			   this->lblContinuar->TabIndex = 1;
			   this->lblContinuar->Text = L"Presiona Enter para Continuar";
			   this->lblContinuar->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->lblContinuar->Visible = false;
			   // 
			   // lblHistoria
			   // 
			   this->lblHistoria->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->lblHistoria->Font = (gcnew System::Drawing::Font(L"Consolas", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblHistoria->ForeColor = System::Drawing::Color::White;
			   this->lblHistoria->Location = System::Drawing::Point(0, 0);
			   this->lblHistoria->Name = L"lblHistoria";
			   this->lblHistoria->Size = System::Drawing::Size(1487, 815);
			   this->lblHistoria->TabIndex = 0;
			   this->lblHistoria->Text = L"...";
			   this->lblHistoria->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->lblHistoria->Click += gcnew System::EventHandler(this, &FrmNivel1::lblHistoria_Click);
			   // 
			   // lblMetros
			   // 
			   this->lblMetros->AutoSize = true;
			   this->lblMetros->BackColor = System::Drawing::Color::Transparent;
			   this->lblMetros->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblMetros->Location = System::Drawing::Point(906, 96);
			   this->lblMetros->Name = L"lblMetros";
			   this->lblMetros->Size = System::Drawing::Size(156, 39);
			   this->lblMetros->TabIndex = 3;
			   this->lblMetros->Text = L"Metros: 0";
			   // 
			   // lblConfianza
			   // 
			   this->lblConfianza->AutoSize = true;
			   this->lblConfianza->BackColor = System::Drawing::Color::Transparent;
			   this->lblConfianza->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblConfianza->Location = System::Drawing::Point(1224, 96);
			   this->lblConfianza->Name = L"lblConfianza";
			   this->lblConfianza->Size = System::Drawing::Size(233, 35);
			   this->lblConfianza->TabIndex = 2;
			   this->lblConfianza->Text = L"Confianza: 100%";
			   this->lblConfianza->Click += gcnew System::EventHandler(this, &FrmNivel1::lblConfianza_Click);
			   // 
			   // lblNombre
			   // 
			   this->lblNombre->AutoSize = true;
			   this->lblNombre->BackColor = System::Drawing::Color::Transparent;
			   this->lblNombre->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblNombre->Location = System::Drawing::Point(510, 107);
			   this->lblNombre->Name = L"lblNombre";
			   this->lblNombre->Size = System::Drawing::Size(246, 39);
			   this->lblNombre->TabIndex = 0;
			   this->lblNombre->Text = L"Nivel 1: Leopold";
			   this->lblNombre->Click += gcnew System::EventHandler(this, &FrmNivel1::lblNombre_Click);
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			   this->pictureBox1->Location = System::Drawing::Point(467, 42);
			   this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(324, 154);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox1->TabIndex = 4;
			   this->pictureBox1->TabStop = false;
			   this->pictureBox1->Click += gcnew System::EventHandler(this, &FrmNivel1::pictureBox1_Click);
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			   this->pictureBox2->Location = System::Drawing::Point(823, 42);
			   this->pictureBox2->Margin = System::Windows::Forms::Padding(4);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(324, 154);
			   this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox2->TabIndex = 5;
			   this->pictureBox2->TabStop = false;
			   this->pictureBox2->Click += gcnew System::EventHandler(this, &FrmNivel1::pictureBox2_Click);
			   // 
			   // pictureBox3
			   // 
			   this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			   this->pictureBox3->Location = System::Drawing::Point(1178, 42);
			   this->pictureBox3->Margin = System::Windows::Forms::Padding(4);
			   this->pictureBox3->Name = L"pictureBox3";
			   this->pictureBox3->Size = System::Drawing::Size(324, 154);
			   this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox3->TabIndex = 6;
			   this->pictureBox3->TabStop = false;
			   this->pictureBox3->Click += gcnew System::EventHandler(this, &FrmNivel1::pictureBox3_Click);
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Interval = 30;
			   this->timer1->Tick += gcnew System::EventHandler(this, &FrmNivel1::timer1_Tick);
			   // 
			   // timerHistoria
			   // 
			   this->timerHistoria->Interval = 45;
			   this->timerHistoria->Tick += gcnew System::EventHandler(this, &FrmNivel1::timerHistoria_Tick);
			   // 
			   // FrmNivel1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1487, 815);
			   this->Controls->Add(this->pnlSpriteScreen);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"FrmNivel1";
			   this->Text = L"Juego";
			   this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			   this->Load += gcnew System::EventHandler(this, &FrmNivel1::FrmJuego_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel1::FrmJuego_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel1::FrmJuego_KeyUp);
			   this->pnlSpriteScreen->ResumeLayout(false);
			   this->pnlSpriteScreen->PerformLayout();
			   this->pnlHistoria->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
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
		if (juego == nullptr) juego = new Nivel1(100, 0, pnlSpriteScreen->Width, pnlSpriteScreen->Height);

		altoPantallaSprite = pnlSpriteScreen->Height;

		fondoJuego = cargarImagen("Sprites\\NivelUno.png");
		AutoNegro = cargarImagen("Sprites\\AutoNegro.png");
		Leopold = cargarImagen("Sprites\\Leopold.png");
		Antisemita = cargarImagen("Sprites\\AntiSemita.png");

		juego->crearLeopold(
			/* Posicion X */			30,
			/* Posicion Y */			(int)(pnlSpriteScreen->Height / 2),
			/* AnchoSpriteSheet */		Leopold->Width,
			/* AltoSpriteSheet*/		Leopold->Height,
			/* columnas */				4,
			/* filas */					4,
			/* velocidad */				20,
			/* escala (1/2/3) */		1.6
		);

		
		int carriles[3] = { 470, 600, 800 };
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
				carriles[i],
				Antisemita->Width,
				Antisemita->Height,
				4, 4, 25, 0.6
			);
		}

		//unicode utilizado para poder mostrar los signos sin ningun problema, mostrando la historia
		historia = L"Dubl\u00EDn, Irlanda.\r\n"
			L"16 de junio de 1904.\r\n\r\n"

			L"La ciudad despertaba como cualquier otra ma\u00F1ana.\r\n"
			L"Las calles comenzaban a llenarse de comerciantes, "
			L"trabajadores y desconocidos.\r\n\r\n"

			L"Entre ellos se encontraba Leopold Bloom, "
			L"un hombre corriente que cargaba con recuerdos "
			L"que el tiempo no hab\u00EDa logrado borrar.\r\n\r\n"

			L"La p\u00E9rdida de su hijo, el distanciamiento de su esposa "
			L"y el rechazo de una sociedad que lo consideraba diferente "
			L"hab\u00EDan debilitado poco a poco su confianza.\r\n\r\n"

			L"A pesar de todo, decidi\u00F3 salir de casa "
			L"y continuar con su vida.\r\n\r\n"

			L"Pero las calles de Dubl\u00EDn no ser\u00EDan un camino sencillo.\r\n"
			L"Entre veh\u00EDculos, miradas hostiles y hombres consumidos "
			L"por el prejuicio, Leopold tendr\u00EDa que encontrar "
			L"la fuerza para seguir adelante.\r\n\r\n"

			L"Su mayor desaf\u00EDo no ser\u00EDa llegar a su destino...\r\n\r\n"

			L"Sino llegar sin perderse a s\u00ED mismo.\r\n\r\n"

			L"OBJETIVO: Recorre 400 metros sin perder toda tu confianza.";

		//activarlos
		IndiceHistoria = 0;
		MostrandoHistoria = true;

		lblHistoria->Text = "";
		lblContinuar->Visible = false;

		pnlHistoria->Visible = true;
		pnlHistoria->BringToFront();

		timer1->Stop();
		timerHistoria->Start();

	};

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		if (juego == nullptr || fondoJuego == nullptr ||
			Leopold == nullptr || AutoNegro == nullptr) return;

		juego->moverLeopold(TeclaPresionada, anchoPantallaSprite, altoPantallaSprite);
		juego->actualizarMetros(TeclaPresionada);
		juego->moverAntisemita();
		juego->moverCarros();

		Graphics^ canvas = pnlSpriteScreen->CreateGraphics();
		BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(canvas, pnlSpriteScreen->ClientRectangle);
		//sirve para el movimiento del fondo cuando el personaje se mueve
		if (TeclaPresionada == Derecha)
		{
			fondoX -= 23;
		}

		if (TeclaPresionada == Izquierda)
		{
			fondoX += 15;
		}
		//sirve para no irse de largo y esperar que el personaje se mueva para avanzar
		if (fondoX <= -pnlSpriteScreen->Width)
			fondoX = 0;

		if (fondoX <= -pnlSpriteScreen->Width)
			fondoX += pnlSpriteScreen->Width;

		if (fondoX > 0)
			fondoX -= pnlSpriteScreen->Width;

		buffer->Graphics->DrawImage(fondoJuego, fondoX, 0, pnlSpriteScreen->Width, pnlSpriteScreen->Height);

		buffer->Graphics->DrawImage(fondoJuego,
			fondoX + pnlSpriteScreen->Width, 0,
			pnlSpriteScreen->Width, pnlSpriteScreen->Height);

		//dibujar a los personajes
		juego->dibujarAntisemita(buffer->Graphics, Antisemita);
		juego->dibujarCarros(buffer->Graphics, AutoNegro);
		juego->dibujarLeopold(buffer->Graphics, Leopold);

		//esto sirve para dibujar las colisiones mediante rectangulos
		//juego->dibujarColisiones(buffer->Graphics);

		buffer->Render(canvas);
		//eliminarlos de la memoria
		delete buffer;
		delete canvas;

		juego->verificarColisiones();
		lblConfianza->Text = "Confianza: " + juego->getConfianza().ToString() + "%";
		lblMetros->Text = "Metros: " + juego->metros().ToString();
		
		//estas son las condiciones cuando el personaje ha ganado o ha perdido dentro de la lógica
		if (juego->gano())
		{
			timer1->Stop();
			MessageBox::Show("Victoria");

			this->Close();
			
			

			return;
		}

		if (juego->perdio())
		{
			timer1->Stop();
			MessageBox::Show("Derrota..");

			this->Close();
			return;
		}

	};

	private: System::Void FrmJuego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S)	TeclaPresionada = Abajo;
		if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A)	TeclaPresionada = Izquierda;
		if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) TeclaPresionada = Derecha;
		if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W)	TeclaPresionada = Arriba;
		//funcion para pausar
		if (e->KeyCode == Keys::Escape)
		{
			//funcion en donde para pausar, el juego va desde verdadero a falso y viceversa
			timer1->Enabled = !timer1->Enabled;
		}

		if (MostrandoHistoria)
		{
			if (e->KeyCode == Keys::Enter)
			{
				timerHistoria->Stop();

				MostrandoHistoria = false;
				pnlHistoria->Visible = false;
				TeclaPresionada = Ninguno;

				timer1->Start();
			}
		}
		//la accion cuando se hable
		juego->actualizarMetros(TeclaPresionada);
		if (juego->conversar())
		{
			timer1->Stop();
			TeclaPresionada = Ninguno;

			juego->finalizarConversacion();

			MessageBox::Show("Un desconocido se acerca a Leopold...");

			FrmConversacion^ ventana = gcnew FrmConversacion();
			ventana->ShowDialog(this);

			juego->aplicarRespuesta(ventana->getRespuesta());

			delete ventana;

			timer1->Start();
			return;
		}
		
		
	
	};

	private: System::Void FrmJuego_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S) { if (TeclaPresionada == Abajo)		TeclaPresionada = Ninguno; }
		if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A) { if (TeclaPresionada == Izquierda)	TeclaPresionada = Ninguno; }
		if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) { if (TeclaPresionada == Derecha)	TeclaPresionada = Ninguno; }
		if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W) { if (TeclaPresionada == Arriba)		TeclaPresionada = Ninguno; }
	};
	private: System::Void pnlSpriteScreen_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void lblConfianza_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void lblNombre_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pnlHistoria_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void timerHistoria_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (IndiceHistoria < historia->Length)
	{
		IndiceHistoria++;

		lblHistoria->Text = historia->Substring(0, IndiceHistoria);

  }
	else
	{
		timerHistoria->Stop();
		lblContinuar->Visible = true;
	}
}
private: System::Void lblHistoria_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
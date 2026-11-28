#pragma once
#include "LogicaNivel3.h"

namespace Ullyses {
    using namespace System;
    using namespace System::Drawing;
    using namespace System::Windows::Forms;
    using namespace System::IO;

    public ref class FrmNivel3 : public System::Windows::Forms::Form {
        LogicaNivel3* logica;
        Bitmap^ fondo;
        Bitmap^ imagenMolly;
        Bitmap^ imagenBoylan;
        Bitmap^ imagenPistas;
        Direccion teclaPresionada;
        bool esperandoSoltar;
        String^ avisoReto;
        System::Windows::Forms::PictureBox^ pnlSpriteNivel3;
        System::Windows::Forms::Panel^ pnlEstadoNivel3;
        System::Windows::Forms::Label^ lblEstadoNivel3;
        System::Windows::Forms::Label^ lblAccionNivel3;
        System::Windows::Forms::Timer^ timer1;
        System::ComponentModel::IContainer^ components;

    public:
        FrmNivel3(void) {
            logica = nullptr;
            fondo = imagenMolly = imagenBoylan = imagenPistas = nullptr;
            teclaPresionada = Ninguno;
            esperandoSoltar = false;
            avisoReto = L"";
            InitializeComponent();
        }
    protected:
        ~FrmNivel3() {
            timer1->Stop();
            delete logica;
            delete fondo; delete imagenMolly; delete imagenBoylan; delete imagenPistas;
            if (components) delete components;
        }
    private:
#pragma region Windows Form Designer generated code
        /// <summary>
        /// Controles visibles en el disenador de Windows Forms.
        /// </summary>
        void InitializeComponent(void) {
            this->components = (gcnew System::ComponentModel::Container());
            this->pnlSpriteNivel3 = (gcnew System::Windows::Forms::PictureBox());
            this->pnlEstadoNivel3 = (gcnew System::Windows::Forms::Panel());
            this->lblEstadoNivel3 = (gcnew System::Windows::Forms::Label());
            this->lblAccionNivel3 = (gcnew System::Windows::Forms::Label());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pnlSpriteNivel3))->BeginInit();
            this->pnlSpriteNivel3->SuspendLayout();
            this->pnlEstadoNivel3->SuspendLayout();
            this->SuspendLayout();
            // 
            // pnlSpriteNivel3
            // 
            this->pnlSpriteNivel3->BackColor = System::Drawing::Color::FromArgb(39, 37, 53);
            this->pnlSpriteNivel3->Controls->Add(this->pnlEstadoNivel3);
            this->pnlSpriteNivel3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pnlSpriteNivel3->Location = System::Drawing::Point(0, 0);
            this->pnlSpriteNivel3->Name = L"pnlSpriteNivel3";
            this->pnlSpriteNivel3->Size = System::Drawing::Size(1000, 640);
            this->pnlSpriteNivel3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pnlSpriteNivel3->TabIndex = 0;
            this->pnlSpriteNivel3->TabStop = false;
            this->pnlSpriteNivel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmNivel3::dibujarNivel);
            // 
            // pnlEstadoNivel3
            // 
            this->pnlEstadoNivel3->BackColor = System::Drawing::Color::FromArgb(25, 17, 30);
            this->pnlEstadoNivel3->Controls->Add(this->lblAccionNivel3);
            this->pnlEstadoNivel3->Controls->Add(this->lblEstadoNivel3);
            this->pnlEstadoNivel3->Dock = System::Windows::Forms::DockStyle::Top;
            this->pnlEstadoNivel3->Location = System::Drawing::Point(0, 0);
            this->pnlEstadoNivel3->Name = L"pnlEstadoNivel3";
            this->pnlEstadoNivel3->Size = System::Drawing::Size(1000, 80);
            this->pnlEstadoNivel3->TabIndex = 0;
            // 
            // lblEstadoNivel3
            // 
            this->lblEstadoNivel3->AutoSize = true;
            this->lblEstadoNivel3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
            this->lblEstadoNivel3->ForeColor = System::Drawing::Color::White;
            this->lblEstadoNivel3->Location = System::Drawing::Point(18, 8);
            this->lblEstadoNivel3->Name = L"lblEstadoNivel3";
            this->lblEstadoNivel3->Text = L"PENELOPE  |  Recuerdos 0/3  |  Tiempo 120 s  |  Calma 3/3";
            // 
            // lblAccionNivel3
            // 
            this->lblAccionNivel3->AutoSize = true;
            this->lblAccionNivel3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
            this->lblAccionNivel3->ForeColor = System::Drawing::Color::Wheat;
            this->lblAccionNivel3->Location = System::Drawing::Point(18, 43);
            this->lblAccionNivel3->Name = L"lblAccionNivel3";
            this->lblAccionNivel3->Text = L"Flechas/WASD: mover    Espacio: alejar a Boylan (2 usos)";
            // 
            // timer1
            // 
            this->timer1->Interval = 30;
            this->timer1->Tick += gcnew System::EventHandler(this, &FrmNivel3::actualizarNivel);
            // 
            // FrmNivel3
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1000, 640);
            this->Controls->Add(this->pnlSpriteNivel3);
            this->KeyPreview = true;
            this->Name = L"FrmNivel3";
            this->Text = L"Nivel 3 - Penelope";
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            this->Load += gcnew System::EventHandler(this, &FrmNivel3::cargarNivel);
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel3::teclaAbajo);
            this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel3::teclaArriba);
            this->pnlEstadoNivel3->ResumeLayout(false);
            this->pnlEstadoNivel3->PerformLayout();
            this->pnlSpriteNivel3->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pnlSpriteNivel3))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion
        Bitmap^ cargarImagen(String^ nombre) {
            String^ ruta = Path::Combine(Application::StartupPath, L"Sprites", nombre);
            if (!File::Exists(ruta)) throw gcnew FileNotFoundException(L"Falta el sprite: " + nombre);
            return gcnew Bitmap(ruta);
        }
        System::Void cargarNivel(Object^ sender, EventArgs^ e) {
            try {
                fondo = cargarImagen(L"DormitorioNivel3.png");
                imagenMolly = cargarImagen(L"MollyNivel3.png");
                imagenBoylan = cargarImagen(L"BoylanNivel3.png");
                imagenPistas = cargarImagen(L"PistasNivel3.png");
                logica = new LogicaNivel3(imagenMolly->Width, imagenMolly->Height,
                                          imagenBoylan->Width, imagenBoylan->Height);
                pnlSpriteNivel3->Image = fondo;
            } catch (Exception^ ex) {
                MessageBox::Show(ex->Message, L"No se puede abrir el nivel 3");
                this->Close();
                return;
            }
            MessageBox::Show(
                L"16 de junio de 1904. Molly esta en su dormitorio.\n"
                L"Toca la partitura, la carta y la flor. En cada recuerdo repite "
                L"cuatro flechas para ordenarlo. Un error o un encuentro con Boylan "
                L"reduce tu calma.\n\n"
                L"Flechas o WASD: mover y resolver. Espacio: alejar a Boylan "
                L"(solo dos usos y debes esperar entre ellos). "
                L"Tras los tres recuerdos, vuelve a la puerta de la izquierda.",
                L"Nivel 3 - Penelope");
            timer1->Start();
        }
        System::Void actualizarNivel(Object^ sender, EventArgs^ e) {
            if (logica == nullptr) return;
            int retoAnterior = logica->getRetoActivo();
            logica->actualizar(teclaPresionada);
            if (retoAnterior < 0 && logica->getRetoActivo() >= 0) {
                teclaPresionada = Ninguno;
                esperandoSoltar = true;
                avisoReto = L"";
            }
            lblEstadoNivel3->Text = L"PENELOPE  |  Recuerdos " +
                logica->getRecuerdos().ToString() + L"/3  |  Tiempo " +
                logica->getTiempo().ToString() + L" s  |  Calma " +
                logica->getCalma().ToString() + L"/3";
            if (logica->getUsosVoz() == 0)
                lblAccionNivel3->Text = L"Flechas/WASD: mover    Voz agotada";
            else if (logica->getVozEspera() == 0)
                lblAccionNivel3->Text = L"Flechas/WASD: mover    Espacio: alejar a Boylan (" +
                    logica->getUsosVoz().ToString() + L" usos)";
            else
                lblAccionNivel3->Text = L"Flechas/WASD: mover    Voz: " +
                    logica->getUsosVoz().ToString() + L" usos, espera " +
                    logica->getVozEspera().ToString() + L" s";
            pnlSpriteNivel3->Invalidate();
            if (logica->gano()) {
                timer1->Stop();
                System::Windows::Forms::DialogResult respuesta = MessageBox::Show(
                    L"Boylan queda atras como un recuerdo. Molly decide que hacer "
                    L"con su propia historia.\n\u00BFQuiere responder con su propia voz?",
                    L"La perspectiva de Molly", MessageBoxButtons::YesNo);
                logica->registrarDecision(
                    respuesta == System::Windows::Forms::DialogResult::Yes);
                String^ cierre = logica->getDecisionesSi() >= 2
                    ? L"Molly afirma su voz. Los mismos hechos se ven distintos "
                      L"desde Leopold, Stephen y Molly."
                    : L"Molly aun duda, pero reconoce que los recuerdos tambien "
                      L"le pertenecen. Cada mirada cambia lo que sabemos.";
                MessageBox::Show(
                    cierre + L"\n\n\u00BFCon cual de los tres personajes te identificaste "
                    L"mas y por que? \u00BFCambio tu lectura de lo ocurrido?\n\nYOU WIN",
                    L"Fin del nivel 3");
                this->Close();
                return;
            }
            if (logica->perdio()) {
                timer1->Stop();
                MessageBox::Show(L"Molly pierde la calma o se acaba la noche.\nYOU LOST",
                                 L"Nivel 3");
                this->Close();
            }
        }
        System::Void dibujarNivel(Object^ sender, PaintEventArgs^ e) {
            if (logica == nullptr || pnlSpriteNivel3->Width <= 0 ||
                pnlSpriteNivel3->Height <= 0) return;
            Graphics^ g = e->Graphics;
            g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;
            g->ScaleTransform(pnlSpriteNivel3->Width / 1000.0f,
                              pnlSpriteNivel3->Height / 640.0f);
            logica->dibujar(g, imagenMolly, imagenBoylan, imagenPistas);
            SolidBrush^ sombra = gcnew SolidBrush(Color::FromArgb(200, 25, 17, 30));
            System::Drawing::Font^ titulo = gcnew System::Drawing::Font(L"Segoe UI", 15, FontStyle::Bold);
            System::Drawing::Font^ ayuda = gcnew System::Drawing::Font(L"Segoe UI", 12);
            if (logica->getRetoActivo() >= 0) {
                g->FillRectangle(sombra, 150, 210, 700, 230);
                g->DrawString(L"ORDENA EL RECUERDO", titulo, Brushes::White, 320.0f, 230.0f);
                String^ secuencia = L"";
                for (int i = 0; i < 4; i++) {
                    Direccion d = logica->teclaEsperada(i);
                    if (d == Arriba) secuencia += L"ARRIBA";
                    if (d == Abajo) secuencia += L"ABAJO";
                    if (d == Izquierda) secuencia += L"IZQUIERDA";
                    if (d == Derecha) secuencia += L"DERECHA";
                    if (i < 3) secuencia += L" - ";
                }
                g->DrawString(secuencia, ayuda, Brushes::Wheat, 180.0f, 300.0f);
                String^ avance = L"Flechas correctas: " +
                    logica->getPaso().ToString() + L"/4. Un error resta calma.";
                g->DrawString(avance, ayuda, Brushes::White, 260.0f, 365.0f);
                g->DrawString(avisoReto, ayuda, Brushes::OrangeRed, 260.0f, 398.0f);
            } else if (logica->getRecuerdos() == 3) {
                g->FillRectangle(sombra, 245, 550, 510, 52);
                g->DrawString(L"Vuelve a la puerta izquierda", titulo,
                              Brushes::White, 320.0f, 560.0f);
            }
            delete ayuda; delete titulo; delete sombra;
        }
        System::Void recuerdoCompleto(int indice) {
            String^ pregunta;
            String^ recuerdo;
            if (indice == 0) {
                pregunta = L"La partitura recuerda su trabajo como cantante.\n"
                           L"\u00BFMolly decide recuperar su propia voz?";
                recuerdo = L"La musica tambien cuenta la historia de Molly.";
            } else if (indice == 1) {
                pregunta = L"La carta de Boylan guarda una promesa.\n"
                           L"\u00BFMolly decide leerla con sus propias dudas?";
                recuerdo = L"Boylan tiene su version; Molly conserva la suya.";
            } else {
                pregunta = L"La flor trae recuerdos de su juventud.\n"
                           L"\u00BFMolly decide conservar ese recuerdo?";
                recuerdo = L"El pasado vuelve, pero Molly puede elegir su camino.";
            }
            System::Windows::Forms::DialogResult respuesta = MessageBox::Show(
                pregunta, L"Recuerdo de Molly", MessageBoxButtons::YesNo);
            logica->registrarDecision(
                respuesta == System::Windows::Forms::DialogResult::Yes);
            MessageBox::Show(recuerdo, L"Pensamiento de Molly");
        }
        System::Void teclaAbajo(Object^ sender, KeyEventArgs^ e) {
            if (logica == nullptr || logica->gano() || logica->perdio()) return;
            if (e->KeyCode == Keys::Space) {
                logica->usarVoz();
                pnlSpriteNivel3->Invalidate();
                return;
            }
            Direccion tecla = Ninguno;
            if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S) tecla = Abajo;
            if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W) tecla = Arriba;
            if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A) tecla = Izquierda;
            if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) tecla = Derecha;
            if (logica->getRetoActivo() >= 0) {
                if (esperandoSoltar || tecla == Ninguno) return;
                esperandoSoltar = true;
                int indice = logica->getRetoActivo();
                int resultado = logica->probarTecla(tecla);
                if (resultado == -1) avisoReto = L"Orden incorrecto. Intenta de nuevo.";
                else avisoReto = L"";
                if (resultado == 2) recuerdoCompleto(indice);
                if (resultado == -2) {
                    timer1->Stop();
                    MessageBox::Show(L"Molly pierde la calma.\nYOU LOST", L"Nivel 3");
                    this->Close();
                    return;
                }
                pnlSpriteNivel3->Invalidate();
                return;
            }
            if (tecla != Ninguno) teclaPresionada = tecla;
        }
        System::Void teclaArriba(Object^ sender, KeyEventArgs^ e) {
            esperandoSoltar = false;
            if ((e->KeyCode == Keys::Down || e->KeyCode == Keys::S) && teclaPresionada == Abajo)
                teclaPresionada = Ninguno;
            if ((e->KeyCode == Keys::Up || e->KeyCode == Keys::W) && teclaPresionada == Arriba)
                teclaPresionada = Ninguno;
            if ((e->KeyCode == Keys::Left || e->KeyCode == Keys::A) && teclaPresionada == Izquierda)
                teclaPresionada = Ninguno;
            if ((e->KeyCode == Keys::Right || e->KeyCode == Keys::D) && teclaPresionada == Derecha)
                teclaPresionada = Ninguno;
        }
    };
}

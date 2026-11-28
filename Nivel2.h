#pragma once
#include "pch.h"
#include "Stephen.h"
#include "LeopoldNivel2.h"
#include "Policia.h"

class Nivel2{
public:
	Nivel2(int anchoPantalla, int altoPantalla) : anchoPantallaSprite(anchoPantalla), altoPantallaSprite(altoPantalla), stephen(nullptr), leopold(nullptr) {};
	~Nivel2() { 
		delete stephen; 
		delete leopold;
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) delete escuadronPolicias[i];
	};

	void setAltoNivel(int alto) {
		alturaNivel = (alto < altoPantallaSprite) ? altoPantallaSprite : alto;
		camaraY = alturaNivel - altoPantallaSprite; //parte final
	};

	int getAltoNivel() { return alturaNivel; }
	int getAltoVista() { return altoPantallaSprite; }
	int getCamaraY() { return camaraY; }

	void actualizarCamara() {
		if (stephen == nullptr) return;

		Rectangle r = stephen->getRectangle();
		int centroY = r.Y + r.Height / 2;                  // centro de Stephen en MUNDO
		int objetivo = centroY - altoPantallaSprite / 2;   // camaraY que lo deja centrado

		int camaraMax = alturaNivel - altoPantallaSprite;    // límite inferior del mapa
		if (objetivo < 0) objetivo = 0;                    // límite superior del mapa
		if (objetivo > camaraMax) objetivo = camaraMax;
		camaraY = objetivo;
	};

	void dibujarFondo(Graphics^ g, Bitmap^ fondo) {
		// factor imagen -> mundo en vertical (si alturaNivel = alto * ancho_vista/ancho_img, es el mismo que en horizontal)
		float escalaY = (float)alturaNivel / (float)fondo->Height;

		float srcAlto = (float)altoPantallaSprite / escalaY;   // alto visible, en píxeles de la imagen
		float srcY = (float)camaraY / escalaY;                 // desde qué fila de la imagen empieza la vista
		if (srcY + srcAlto > (float)fondo->Height) srcY = (float)fondo->Height - srcAlto; // evita pasarse por redondeo
		if (srcY < 0) srcY = 0;

		Rectangle destino(0, 0, anchoPantallaSprite, altoPantallaSprite);
		g->DrawImage(fondo, destino, 0.0f, srcY, (float)fondo->Width, srcAlto, GraphicsUnit::Pixel);
	};

	// Desde aquí todo lo que se dibuje con 'g' en coordenadas de MUNDO sale en su sitio de pantalla.
	// Funciona igual para dibujar() y dibujarRectangulo(), porque getRectangle() sigue en mundo.
	void aplicarCamara(Graphics^ g) { g->TranslateTransform(0.0f, (float)(-camaraY)); };
	void quitarCamara(Graphics^ g) { g->ResetTransform(); };

	// ---------------------------- META (parte superior) ----------------------------
	// Aún NO se usa: la llamada está comentada en FrmNivel2::Timer1_tick.
	void setMetaY(int y) { metaY = y; }
	bool stephenLlegoALaMeta() { return stephen != nullptr && stephen->getY() <= metaY; }
	// ------------------------------------------------------------------------------

	void crearStephen(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale) {
		stephen = new Stephen(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale);
	};

	void crearLeopold(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale) {
		leopold = new NewLeopold(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale);
	};

	void crearNuevoPolicia(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale,
		ReaccionPolicia reaccionPoli) {
		Policia* nuevoPolicia = new Policia(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale, reaccionPoli);
		nuevoPolicia->setHitbox(0.38, 0.25, 0.28, 0.5);
		escuadronPolicias.push_back(nuevoPolicia);
	};

	void dibujarEntidades(Graphics^ g, Bitmap^ ImgStephen, Bitmap^ ImgLeopold, Bitmap^ ImgPolicia) {
		if (stephen == nullptr || escuadronPolicias.empty()) return;

		stephen->dibujar(g, ImgStephen);
		leopold->dibujar(g, ImgLeopold);
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) escuadronPolicias[i]->dibujar(g, ImgPolicia);
	};

	void moverStephen(Direccion teclaPresionada, int WidthScreen, int HeightScreen) {
		if (stephen == nullptr) return;

		stephen->mover(teclaPresionada, WidthScreen, HeightScreen);
	};

	void moverPolicias(Direccion dicJugador, int WidthScreen, int HeightScreen) {
		if (escuadronPolicias.empty()) return;
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) escuadronPolicias[i]->mover(dicJugador, WidthScreen, HeightScreen);
	};

	void graficarCuadros(Graphics^ g) {
		stephen->dibujarRectangulo(g);
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) { escuadronPolicias[i]->dibujarRectangulo(g);		}
	};

	//colisiones
	//Sumar text tiene que sumar de 0 a 90 desde el momento que el jugador se impacta.
	//Mientras que el contador esté subiendo, este puede reiniciarse en el caso de que el jugador vuelva a pactar con una entidad.
	//En el caso de llegar a 90, se vuelve a cero y de ahí no se suman más.


	void impactoJugadorConEntidad() {
		//si alguno de ellos recibio un impacto, 
		if (stephen->getRecibioImpactoPrevio() || leopold->getRecibioImpactoPrevio()) stephen->sumarTicks();
		
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) {
			if (stephen->getRectangle().IntersectsWith(escuadronPolicias[i]->getRectangle()) ||
				leopold->getRectangle().IntersectsWith(escuadronPolicias[i]->getRectangle())   ) {
				stephen->fueImpactado();
				if (stephen->getAcasoEstaMuerto()) {
					//juegoterminado()
				}
			}
		};
	};

	//El tick tiene que comenzar desde el impacto.

	void setStephenPuntosVida(int puntosDeVida) { stephen->setPuntosVida(puntosDeVida); }
	int getStephenPuntosVida() { return stephen->getPuntosVida(); }


private:
	int anchoPantallaSprite; //ancho de pantalla donde se movera el sprite en cada nivel
	int altoPantallaSprite; //alto de pantalla donde se movera el sprite en cada nivel

	Stephen* stephen;
	NewLeopold* leopold;
	std::vector<Policia*> escuadronPolicias;

	//Un vector que contenga las direcciones
	std::vector<Direccion> Direcciones;

	int alturaNivel;  //alto TOTAL del nivel en coordenadas de mundo (>= altoPantallaSprite)
	int camaraY;    //y del mundo que coincide con el borde superior de la vista
	int metaY;      //y del mundo a partir de la cual se considera "meta" (arriba)
};

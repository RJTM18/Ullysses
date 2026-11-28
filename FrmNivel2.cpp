#include "pch.h"
#include "FrmNivel2.h"

namespace Ullyses {
	Bitmap^ FrmNivel2::cargarImagen(String^ name) {
		String^ ruta = Path::Combine(Application::StartupPath, name);
		if (!File::Exists(ruta)) ruta = name;
		return gcnew Bitmap(ruta);
	};
	
	void FrmNivel2::InicializarDialogo() {
		dialogo = L"¡Bienvenido al Nivel 2! En este nivel, te enfrentarás a un grupo de policías que intentarán detenerte. Mantente alerta y utiliza tus habilidades para esquivarlos y llegar a la meta. ¡Buena suerte!";
		indiceDialogo = 0;
		timerDialogo->Interval = 40; // velocidad de escritura del diálogo
		timerDialogo->Start(); 
	};

	void FrmNivel2::InicializarJuego() {
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

		timerGame->Enabled = true; // Habilitar el temporizador del juego
		lblDialogo->Visible = false; // Ocultar el diálogo
	}
}
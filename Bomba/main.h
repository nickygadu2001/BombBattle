 
#ifndef __BOMBA_H__
#define __BOMBA_H__

using namespace System::Drawing;

enum Estado{normal,explosion,desaparecer};

class Cbomba {

public:
	Cbomba(int x, int y);
	this->x = x;
	this->y = y;
	estado = Estado::normal;

	ancho = 66 / 3; // esto es por los pixeles de la imagen, el ancho es de 66 y la cantidad de imagenes es 3 (3 imagenes pa la animacion pws)

	alto = 24; // solo es una imagen que tiene 24 pixeles de alto, osea la escala en alto no varia, solo en largo 

	indiceX = 0; // se inicializa la animacion desde la izquierda (eje X)

	tiempo_antes_de_explotar = 0;

	// DATOS INICIALES PARA LA EXPLOSION:

	indiceX = 0;
	indiceY = 0;  // ambas son 0 pq empieza desde EL CENTRO en donde esta la bomba

	altoExplosion = 160/8;  // El 160 es la dimension de la imagen, y se divide entre 8 pq son 8 imagenes (no lo entendi, sinceramente)
	anchoExplosion = 80 / 4; // Lo mismo, el  80 la dimension y el 4 el numero de imagenes(tampoco lo entendi)




	~Cbomba() {};
	// 0 es donde el jugador puede iniciar y 2 son los espacios libres donde se puede caminar, solo en estos espacios es posible colocar bomba
	bool validarLugar(int xJugador, int yJugador, int** matriz;) {
		if (matriz[yJugador/50][xJugador/50] == 0 || matriz[yJugador/50][xJugador/50] == 2) {   // se divide entre 50 pq es el tamaño de cada cuadrado
			return true; 
		}
		else {
			return false;
		}
	}

	void dibujarBomba(Graphics^ g, Bitmap^ bmpBomba, int xJugador, int yJugador, int** matriz;) {
		if (validarLugar(xJugador, yJugador, matriz) == true) { // si esta en el lugar correcto, dibuja la bomba
			Rectangle porcionAUsar = Rectangle(indiceX * ancho, 0, ancho, alto); // el "0" representa al indice en Y, como no hay pws lo ponemos como 0
			Rectangle aumento = Rectangle(x, y, 40, 40); // la matriz tiene un tamaño de 50 x 50, paq el tamaño de la bomba no sea mas que el del cuadrado lo dejamos en 40
			g->DrawImage(bmpBomba, aumento, porcionAUsar, GraphicsUnit::Pixel);
		}
		if (tiempo_antes_de_explotar == 6) {
			estado = Estado::explosion;
		}		
	} 
	void animar() {
		if (indiceX >= 0 && indiceX < 2) {
			indiceX++;
		}
		else {
			tiempo_antes_de_explotar++;
			indiceX = 0;
		}

	void animarExplosion(){
		if (indiceX >= 0 && indiceX > 3) {
			indiceX++; // esto para q vaya escalando la explosion y vaya creciendo
		}
		else {
			estado = Estado::desaparecer; // a diferencia del jugador, esto no vuelve a 1, pq no lo queremos volver a usar, lo queremos DESAPARECER 

		}
		 


	Estado getEstado() {
			return estado;
		}
	

private ://datos de la explosion

	int indiceEX;
	int indiceEY;
	int altoExplosion;
	int anchoeExplosion;

private: // datos de la bomba
	int x;
	int y;
	int ancho;
	int alto;
	int indiceX;
	int tiempo_antes_de_explotar;

	Estado estado;




};

#endif 

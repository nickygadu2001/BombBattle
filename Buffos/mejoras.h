#ifndef __MEJORAS_H__
#define __MEJORAS_H__
#include <ctime>
#include <stdlib.h>

class CMejora
{
public:
	CMejora() {
		ubicado = false;

		srand(time(NULL));
		tipodemejora - rand() % 5 + 1;
		i = rand() % 13 + 1;//se omiten los muros externos
		j = rand() % 15 + 1;

		ancho = 128 / 8;
		alto = 96 / 6;

		indiceX = 0;
		indiceY = 0;
	}
	~CMejora(){}
	void dibujar(Graphics^ g, Bitmap^ bmpMejoras, int** matriz) {
		Rectangle usarpixeles = Rectangle(indiceX * ancho, indiceY * alto, alto, ancho);

		while (ubicado==false){
			if (matriz[i][j]==3){
				ubicado = true;

			}
			else
			{
				if (j<17){
					i++;
					if (i==14){
						i = 0;
						j++;
					}

				}
			}

		}
		Rectangle aumento - Rectangle(j * 50, i * 50, ancho * 3.125, alto * 3.125);
		g->DrawImage(bmpMejoras, aumento, usarpixeles, GraphicsUnit::Pixel);
	}

	void animar(){
		switch (tipodemejora)
		{
		case 1://bomba
			indiceX = 0;
			if (indiceY >= 0 && indiceY < 1)
				indiceY++;
			else
				indiceY = 0;
			break;
		case 2://mover bomba
			indiceX = 4;
			if (indiceY >= 0 && indiceY < 1)
				indiceY++;
			else
				indiceY = 0;
			break;
		case 3://calaca
			indiceX = 5;
			if (indiceY >= 0 && indiceY < 1)
				indiceY++;
			else
				indiceY = 0;
			break;
		case 4://patin
			indiceX = 8;
			if (indiceY >= 0 && indiceY < 1)
				indiceY++;
			else
				indiceY = 0;
			break;
		case 5://xvida
			indiceX = 9;
			if (indiceY >= 0 && indiceY < 1)
				indiceY++;
			else
				indiceY = 0;
			break;
		default:
			break;
		}
	}

private:
	int i;
	int j;
	int indiceX;
	int indiceY;

	int ancho;
	int alto;

	int tipodemejora;

	bool ubicado;

};

CMejora::CMejora()
{
}

CMejora::~CMejora()
{
}

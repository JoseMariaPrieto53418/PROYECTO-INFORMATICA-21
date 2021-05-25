
#pragma once
//#include "Esfera.h"
#include "Pared.h"
#include "Hombre.h"
#include "Dragon.h"
#include "ListaDisparos.h"

class Mundo
{
public:
	Mundo();
	~Mundo();

	void RotarOjo();
	void Inicializa();
	void Dibuja();

	void Mueve();

	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);
	void TeclaArriba(unsigned char _key);



private:
	double x_ojo;
	double y_ojo;
	double z_ojo;

	//Esfera esfera;
	Pared  suelo;
	Hombre jugador;
	Dragon dragon;
	ListaDisparos disparos;
};
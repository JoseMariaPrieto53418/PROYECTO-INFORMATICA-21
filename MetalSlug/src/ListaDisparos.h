#pragma once
#define MAX_DISPAROS 50
#include "disparo.h"
#include "Interaccion.h"

class ListaDisparos
{
public:
	ListaDisparos();
	bool agregar(Disparo* d);
	void destruirContenido();
	void mueve(float t);
	void dibuja();

private:
	Disparo* lista[MAX_DISPAROS];
	Disparo disparo;
	int numero;
};


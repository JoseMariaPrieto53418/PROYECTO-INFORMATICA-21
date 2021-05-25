#include "ListaDisparos.h"

ListaDisparos::ListaDisparos()
{
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		lista[i] = 0;
}

bool ListaDisparos::agregar(Disparo *d)
{
	if (numero < MAX_DISPAROS)
	{
		lista[numero++] = d;
		return true;
	}
	else
		return false;
	for (int i = 0; i < numero; i++)
	{
		for (int j = numero - 1; i >= 0; i--)
		{
			if ((i != j) && lista[i] == lista[j])
				return false;
		}
	}
}

void ListaDisparos::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];

	numero = 0;
}

void ListaDisparos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaDisparos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}
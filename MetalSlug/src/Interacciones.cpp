#include"Interaccion.h"



Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}

void Interaccion::Rebote(Hombre& j, Pared& p)
{
	/*
	if (j.GetYPosicion() - j.GetAltura() / 2 +1 < p.GetYsuperior() &&  j.GetXPosicion() < p.GetXd() && j.GetXPosicion() > p.GetXi())
					j.SetPosicion(j.GetXPosicion(), p.GetYsuperior() + j.GetAltura() / 2);
	*/
	if ((j.GetYPosicion() < p.GetYsuperior() + 1) && (j.GetYPosicion() > p.GetYsuperior() - 1) && (j.GetXPosicion() > p.GetXi()) && (j.GetXPosicion() < p.GetXd()))
	{
		j.SetPosicion(j.GetXPosicion(), p.GetYsuperior() + 1);
		j.SetVelocidad(j.GetXVelocidad(), 0);
		j.setSalto(1);
	}
}
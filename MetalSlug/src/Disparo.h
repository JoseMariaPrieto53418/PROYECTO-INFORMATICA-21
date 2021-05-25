#pragma once
#include "Vector2D.h"
class Disparo
{
public:
	friend class Interaccion;
	Disparo();
	virtual void Dibuja();
	void mueve(float t);
	void setPos(float xi, float yi);
	void setVel(float vx, float vy);
	float getRadio();
	Vector2D getPos();

private:
	float radio;
	Vector2D origen;
	Vector2D velocidad;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
};


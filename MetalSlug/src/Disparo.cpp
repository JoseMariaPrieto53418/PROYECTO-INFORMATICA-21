#include "Disparo.h"
#include "Vector2D.h"
#include "freeglut.h"

Disparo::Disparo()
{
	radio = 0.5f;
	rojo = 0;
	verde = 255;
	azul = 255;
}

void Disparo::setPos(float ix, float iy)
{
	origen.x = ix;
	origen.y = iy;
}

void Disparo::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

float Disparo::getRadio()
{
	return radio;
}

Vector2D Disparo::getPos()
{
	return origen;
}

void Disparo::mueve(float t)
{
	origen = origen + velocidad * t;
}

void Disparo::Dibuja()
{
	glPushMatrix();
	glColor3f(0, 255, 255);
	glTranslatef(origen.x, origen.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();
}
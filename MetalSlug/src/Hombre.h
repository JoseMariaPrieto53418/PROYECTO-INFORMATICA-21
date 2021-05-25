#pragma once
#include"Vector2D.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Hombre
{
private:

	SpriteSequence Walk;
	SpriteSequence Idle;
	SpriteSequence Jump;
	SpriteSequence Dead;


	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	float altura;
	int vida;
	int Salto_cargado;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

public:
	Hombre();
	~Hombre(); //pa que

	//Metodos GLUT
	void Dibuja();
	void Mueve(float t);

	//Metodos SET
	void SetPosicion(double _x, double _y);
	void SetPosicion(Vector2D _xy);
	void SetVelocidad(double _vx, double _vy);
	void SetAceleracion(double _xa, double _ya);
	void SetVida(int _vida);
	void SetAltura(float _a);
	void setSalto(int s);
	int getSalto();

	//Metodos GET
	float GetXPosicion();
	float GetYPosicion();
	float GetXVelocidad();
	float GetYVelocidad();
	float GetXAceleracion();
	float GetYAceleracion();
	float GetAltura();
	int GetVida();
	Vector2D GetPosicion();


	friend class Interaccion;
};
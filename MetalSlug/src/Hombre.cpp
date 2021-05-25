#include"Hombre.h"
#include"freeglut.h"
#include"ETSIDI.h"

Hombre::Hombre() :Walk("bin/Imagenes/walk.png",3,1,60), Idle("bin/Imagenes/parado.png",5,1,20), Jump("bin/Imagenes/jump2.png", 2,1,500), Dead("bin/Imagenes/dead.png",1,1,50)
{
	SetVida(5); //que el personaje tenga 5 vidas?
	SetAltura(17); //no se que poner en altura

	Walk.setCenter(5, 3); //hay que configurar todos los setCenter y setSize
	Walk.setSize(12, altura);

	Idle.setCenter(5, 3);
	Idle.setSize(10, altura);

	Jump.setCenter(5, 1);
	Jump.setSize(10, altura);

	Dead.setCenter(5, 1);
	Dead.setSize(10, 7);

	//altura = 5; ¿ESTO NO SIRVE NO? Si ya se define arriba
	rojo = 255;
	verde = 0;
	azul = 0;
	posicion = 0;
	velocidad = 0;
	aceleracion = 0;
}

Hombre::~Hombre() //pa que
{
}

// Metodos GLUT 

void Hombre::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.GetX(), posicion.GetY(), 0);
	glColor3ub(rojo, verde, azul);

	if (velocidad.GetX() > 0.01 && vida > 0)
	{
		Walk.flip(false, false);
		Jump.flip(false, false);
	}
	else if (velocidad.GetX() < -0.01 && vida > 0)
	{
		Walk.flip(true, false);
		Jump.flip(true, false);

	}

	if (velocidad.GetX() < 0.01 && velocidad.GetX() > -0.01 && velocidad.GetY() == 0 && vida > 0)
	{
		Idle.setState(1);
		Idle.draw();
	}

	if (velocidad.GetY() == 0 && (velocidad.GetX() > 0.1 || velocidad.GetX() < -0.1) && vida > 0)
	{
		Walk.draw();
	}
	if (velocidad.GetY() != 0 && vida > 0)
	{
		Jump.draw();

	}
	if (vida <= 0)
	{
		Dead.draw();
	}

	glTranslatef(-posicion.GetX(), -posicion.GetY(), 0);
	glPopMatrix();
}
void Hombre::Mueve(float t)
{
	if (vida > 0)
	{
		posicion = posicion + velocidad * t + aceleracion * (0, 5 * t * t);
		velocidad = velocidad + aceleracion * t;
		Walk.loop();
		Jump.loop();
	}
}


// Metodos Set

void Hombre::SetAltura(float _a)
{
	altura = _a;
}


void Hombre::SetPosicion(double _x, double _y)
{
	posicion.SetCoordenadas(_x, _y);

}

void Hombre::SetPosicion(Vector2D _xy)
{
	posicion = _xy;
}


void Hombre::SetVelocidad(double _vx, double _vy)
{
	velocidad.SetCoordenadas(_vx, _vy);

}
void Hombre::SetAceleracion(double _ax, double _ay)
{
	aceleracion.SetCoordenadas(_ax, _ay);

}

void Hombre::SetVida(int _vida)
{
	vida = _vida;
}

// Metodos Get

float Hombre::GetAltura()
{
	return altura;
}

float Hombre::GetXPosicion()
{
	return posicion.x;
}
float Hombre::GetYPosicion()
{
	return posicion.y;
}
float Hombre::GetXVelocidad()
{
	return velocidad.x;
}
float Hombre::GetYVelocidad()
{
	return velocidad.y;
}
float Hombre::GetXAceleracion()
{
	return aceleracion.x;
}
float Hombre::GetYAceleracion()
{
	return aceleracion.y;
}

Vector2D Hombre::GetPosicion()
{
	return posicion;
}

int Hombre::GetVida()
{
	return vida;
}

void Hombre::setSalto(int s)
{
	Salto_cargado = s;
}

int Hombre::getSalto()
{
	return Salto_cargado;

}
#include "Cancion.h"

Cancion::Cancion()
{
}

Cancion::Cancion(string Titulo, string Artista, int Duracion, string Genero, int YearDeLanzamiento)
{
	this->Titulo = Titulo;
	this->Artista = Artista;
	this->Duracion = Duracion;
	this->Genero = Genero;
	this->YearDeLanzamiento = YearDeLanzamiento;
}

Cancion::~Cancion()
{
	Titulo = "";
	Artista = "";
	Duracion = 0;
	Genero = "";
	YearDeLanzamiento = 0;
}

string Cancion::getTitulo()
{
	return this->Titulo;
}

void Cancion::setTitulo(string Titulo)
{
	this->Titulo = Titulo;
}

string Cancion::getArtista()
{
	return this->Artista;
}

void Cancion::setArtista(string Artista)
{
	this->Artista = Artista;
}

int Cancion::getDuracion()
{
	return this->Duracion;
}

void Cancion::setDuracion(int Duracion)
{
	this->Artista = Artista;
}

string Cancion::getGenero()
{
	return this->Genero;
}

void Cancion::setGenero(string Genero)
{
	this->Genero = Genero;
}

int Cancion::getYear()
{
	return this->YearDeLanzamiento;
}

void Cancion::setYear(int YearDeLanzamiento)
{
	this->YearDeLanzamiento = YearDeLanzamiento;
}

void Cancion::toString()
{
	cout << "Titulo: " << this->Titulo << endl;
	cout << "Artista: " << this->Artista << endl;
	cout << "Duracion: " << this->Duracion << endl;
	cout << "Genero: " << this->Genero << endl;
	cout << "Año de Lanzamiento: " << this->YearDeLanzamiento << endl;
}

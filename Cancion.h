#pragma once
#include <string>
using namespace std;
#include <iostream>
class Cancion
{
private:
	string Titulo;
	string Artista;
	int Duracion;
	string Genero;
	int YearDeLanzamiento;
public:
	Cancion(string Titulo, string Artista, int Duracion, string Genero, int YearDeLanzamiento);
	~Cancion();
	string getTitulo();
	void setTitulo(string Titulo);
	string getArtista();
	void setArtista(string Artista);
	int getDuracion();
	void setDuracion(int Duracion);
	string getGenero();
	void setGenero(string Genero);
	int getYear();
	void setYear(int YearDeLanzamiento);
	void toString();
};


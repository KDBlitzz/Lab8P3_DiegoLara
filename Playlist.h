#pragma once
#include "Cancion.h"
#include <vector>
class Playlist
{
private:
	string Nombre;
	string Descripcion;
	int Duracion;
	vector <Cancion*> Canciones;
public:
	Playlist(string Nombre, string Descripcion, int Duracion, vector<Cancion*> Canciones);
	string getNombre();
	void setNombre(string Nombre);
	string getDescripcion();
	void setDescripcion(string Descripcion);
	int getDuracion();
	void setDuracion(int Duracion);
	vector<Cancion*> getCanciones();
	void setCanciones(vector<Cancion*> Canciones);
	void toString();
	void calcularDuracion();
	Playlist* operator+(Cancion*);
};


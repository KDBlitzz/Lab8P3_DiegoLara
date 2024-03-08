#include "Playlist.h"

Playlist::Playlist(string Nombre, string Descripcion, int Duracion, vector<Cancion*> Canciones)
{
	this->Nombre = Nombre;
	this->Descripcion = Descripcion;
	this->Duracion = Duracion;
	this->Canciones = Canciones;
}

string Playlist::getNombre()
{
	return this->Nombre;
}

void Playlist::setNombre(string Nombre)
{
	this->Nombre = Nombre;
}

string Playlist::getDescripcion()
{
	return this->Descripcion;
}

void Playlist::setDescripcion(string Descripcion)
{
	this->Descripcion = Descripcion;
}

int Playlist::getDuracion()
{
	return this->Duracion;
}

void Playlist::setDuracion(int Duracion)
{
	this->Duracion = Duracion;
}

vector<Cancion*> Playlist::getCanciones()
{
	return this->Canciones;
}

void Playlist::setCanciones(vector<Cancion*> Canciones)
{
	this->Canciones = Canciones;
}

void Playlist::toString()
{
	if (this->Canciones.empty())// validacion
	{
		cout << "No hay ninguna cuenta" << endl;
	}
	else {
		int contador = 1;
		int contadorCanciones = 1;
		for (int i = 0; i < this->Canciones.size(); i++) {
			cout << "Playlist: " << contador << endl;
			this->Nombre = Nombre;
			this->Descripcion = Descripcion;
			this->Duracion = Duracion;
			this->Canciones = Canciones;
			cout << "Nombre de Playlist: " << this->Nombre << endl;
			cout << "Descripcion de la Playlist: " << this->Descripcion << endl;
			cout << "Duracion de la Playlist: " << this->Duracion << endl;
			cout << "Cancion: " << contadorCanciones << endl;
			this->Canciones[i]->toString(); // mostrar las Canciones adentro de la Playlist
			cout << endl;
			contador++;
			contadorCanciones++;
		}
	}
}

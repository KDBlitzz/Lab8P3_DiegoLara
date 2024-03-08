#include "Playlist.h"

Playlist::Playlist()
{
}

Playlist::Playlist(string Nombre, string Descripcion)
{
	this->Nombre = Nombre;
	this->Descripcion = Descripcion;
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
	int contador = 1;
	int contadorCanciones = 1;
		cout << "Playlist: " << contador << endl;
		this->Nombre = Nombre;
		this->Descripcion = Descripcion;
		this->Duracion = Duracion;
		this->Canciones = Canciones;
		cout << "Nombre de Playlist: " << this->Nombre << endl;
		cout << "Descripcion de la Playlist: " << this->Descripcion << endl;
		cout << "Duracion de la Playlist: " << this->Duracion << endl;
		for (int i = 0; i < this->Canciones.size(); i++) {
		if (!Canciones.empty())
		{
			cout << "Cancion: " << contadorCanciones << endl;
			this->Canciones[i]->toString();
			contadorCanciones++;
		} // mostrar las Canciones adentro de la Playlist
		cout << endl;
		contador++;
	}
}

void Playlist::calcularDuracion()
{
	int sumaDuracion = 0;
	if (Canciones.empty())
	{
		cout << "No hay canciones en esta playlist" << endl;
	}
	else {
		for (int i = 0; i < Canciones.size(); i++)
		{
			sumaDuracion += Canciones[i]->getDuracion();
		}
		setDuracion(sumaDuracion);
	}
}

Playlist* Playlist::operator+(Cancion* song)
{
	for (int i = 0; i < Canciones.size(); i++)
	{
		if (Canciones[i]->getTitulo() == song->getTitulo())
		{
			if (Canciones[i]->getArtista() == song->getArtista())
			{
				cout << "Esta canción tiene el mismo nombre de otra, es el mismo artista, no se agregara" << endl;
			}
			else {
				Canciones.push_back(song);
				calcularDuracion();
			}
		}
		else {
			Canciones.push_back(song);
			calcularDuracion();
		}
	}
	return this;
}

Playlist* Playlist::operator-(Cancion* song)
{
	for (int i = 0; i < cuentas.size(); i++)
	{
		if (cuentas[i]->getNumeroDeCuenta() == numCuenta)
		{
			cuentas.erase(cuentas.begin() + i); // eliminar la cuenta
		}
	}
	return nullptr;
}

Playlist* Playlist::operator+(Playlist* lista)
{
	return nullptr;
}

bool Playlist::operator>(Playlist*)
{
	return false;
}

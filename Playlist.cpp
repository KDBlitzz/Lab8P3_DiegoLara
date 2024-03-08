#include "Playlist.h"

Playlist::Playlist()
{
}

Playlist::Playlist(string Nombre, string Descripcion)
{
	this->Nombre = Nombre;
	this->Descripcion = Descripcion;
}

Playlist::~Playlist()
{
	for (int i = 0; i < Canciones.size(); i++) // borrar memoria
	{
		delete this->Canciones[i];
	}
	this->Canciones.clear();
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
	if (Canciones.empty())
	{
		Canciones.push_back(song);
		calcularDuracion();
	}
	else {
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
	}
	return this;
}

Playlist* Playlist::operator-(Cancion* song)
{
	if (!Canciones.empty())
	{
		for (int i = 0; i < Canciones.size(); i++)
		{
			if (Canciones[i]->getArtista() == song->getArtista())
			{
				if (Canciones[i]->getTitulo() == song->getTitulo())
				{
					Canciones.erase(Canciones.begin() + i); // eliminar la cancion de la playlist
					calcularDuracion();
				}
			}
		}
	}
	return this;
}

Playlist* Playlist::operator+(Playlist* lista)
{
	
	Playlist *listaNueva = new Playlist(this->getNombre() + lista->getNombre(), this->getDescripcion() + lista->getDescripcion());
	
	for (int i = 0; i < lista->getCanciones().size(); i++)
	{
		listaNueva->getCanciones().push_back(lista->getCanciones()[i]);
	}
	for (int i = 0; i < this->getCanciones().size(); i++)
	{
		listaNueva->getCanciones().push_back(this->getCanciones()[i]);
	}
	listaNueva->setDuracion(this->getDuracion() + lista->getDuracion());
	for (int i = 0; i < this->getCanciones().size(); i++)
	{
		this->getCanciones().erase(this->getCanciones().begin() + i);
	}
	for (int i = 0; i < lista->getCanciones().size(); i++)
	{
		lista->getCanciones().erase(lista->getCanciones().begin() + i);
	}
	delete this;
	delete lista;
	return listaNueva;
}

bool Playlist::operator>(Playlist*)
{
	return false;
}

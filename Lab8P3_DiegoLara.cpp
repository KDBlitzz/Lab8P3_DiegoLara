#include <locale>
#include "Cancion.h"
#include "Playlist.h"
void ejercicio_1() {
	// variables a usar
	int selectPlaylist = 0;
	int selectCancion = 0;
	int elimPlaylist = 0;
	int elimCancion = 0;
	int firstPlaylist = 0;
	int secondPlaylist = 0;
	int firstPlaylistComparar = 0;
	int secondPlaylistComparar = 0;
	string nombreFusionado = "";
	bool ejer1 = true;
	int opcion = 0;
	string titulo = ""; 
	string artista = "";
	int duracion = 0;
	string nombre = "";
	string desc = "";
	string genero = "";
	int year = 0;
	vector<Playlist*> listas;
	vector<Cancion*> canciones;
	while (ejer1) {
		cout << "1. Agregar Canciones" << endl;
		cout << "2. Agregar Playlist" << endl;
		cout << "3. Agregar canciones a Playlist" << endl;
		cout << "4. Eliminar Canciones de Playlist" << endl;
		cout << "5. Fusionar Playlist" << endl;
		cout << "6. Comparar duraciones de Playlist" << endl;
		cout << "7. Salir" << endl;
		cin >> opcion;
		switch (opcion) {
		case 1: // agregar canciones
			cout << "Ingrese el título de la canción: " << endl;
			cin >> titulo;
			cout << "Ingrese el nombre del artista: " << endl;
			cin >> artista;
			cout << "Ingrese la duración de la canción (en segundos): " << endl;
			cin >> duracion;
			while (duracion < 0) {
				cout << "Favor ingrese una duración mayor a 0" << endl;
				cin >> duracion;
			}
			cout << "Ingrese el genero de la canción: " << endl;
			cin >> genero;
			cout << "Ingrese el año de lanzamiento de la canción: " << endl;
			cin >> year;
			while (year < 0) {
				cout << "Favor ingrese un año mayor a 0" << endl;
				cin >> year;
			}
			canciones.push_back(new Cancion(titulo, artista, duracion, genero, year));
			cout << "Canción '" << titulo << "' agregada exitosamente." << endl;
			break;
		case 2: // agregar playlists
			cout << "Crear nueva playlist:" << endl;
			cout << "Ingrese el nombre de la playlist: " << endl;
			cin >> nombre;
			cout << "Ingrese la descripción de la playlist:" << endl;
			cin.ignore();
			getline(cin, desc);
			listas.push_back(new Playlist(nombre, desc));
			cout << "Playlist '" << nombre << "' creada exitosamente." << endl;
			break;
		case 3:   // agregar canciones a playlists
			if (canciones.empty())
			{
				cout << "No hay canciones para añadir." << endl;
			}
			else if (listas.empty()) {
				cout << "No hay playlists para poder añadirle canciones." << endl;
			}
			else {
				cout << "--- Agregar Canción a Playlist ---" << endl;
				for (int i = 0; i < listas.size(); i++)
				{
					cout << "Playlist: " << i + 1 << endl;
					listas[i]->toString();
				}
				cout << "Seleccione una playlist por número: " << endl;
				cin >> selectPlaylist;
				while (listas.size() < selectPlaylist)
				{
					cout << "Escoja el numero de la playlist." << endl;
					cin >> selectPlaylist;
				}
				for (int i = 0; i < canciones.size(); i++)
				{
					cout << "Canción: " << i + 1 << endl;
					canciones[i]->toString();
				}
				cout << "Seleccione una canción por número: " << endl;
				cin >> selectCancion;
				while (canciones.size() < selectCancion)
				{
					cout << "Escoja el numero de la canción." << endl;
					cin >> selectCancion;
				}
				*listas[selectPlaylist - 1] + canciones[selectCancion - 1];
			}
			break;
		case 4: // eliminar canciones de playlists
			if (canciones.empty())
			{
				cout << "No hay canciones para eliminar." << endl;
			}
			else if (listas.empty()) {
				cout << "No hay playlists para poder eliminarle canciones." << endl;
			}
			else {
				cout << "--- Eliminar Canción de Playlist ---" << endl;
				for (int i = 0; i < listas.size(); i++)
				{
					cout << "Playlist: " << i + 1 << endl;
					listas[i]->toString();
				}
				cout << "Seleccione una playlist por número: " << endl;
				cin >> elimPlaylist;
				while (listas.size() < elimPlaylist)
				{
					cout << "Escoja el numero de la playlist." << endl;
					cin >> elimPlaylist;
				}
				for (int i = 0; i < canciones.size(); i++)
				{
					cout << "Canción: " << i + 1 << endl;
					canciones[i]->toString();
				}
				cout << "Seleccione una canción por número: " << endl;
				cin >> elimCancion;
				while (canciones.size() < elimCancion)
				{
					cout << "Escoja el numero de la canción." << endl;
					cin >> elimCancion;
				}
				*listas[elimPlaylist - 1] - canciones[elimCancion - 1];
			}
			break;
		case 5: // fusionar dos playlists
			if (listas.empty()) {
				cout << "No hay playlists para poder fusionar." << endl;
			}
			else if (listas.size() < 1) {
				cout << "Se ocupan 2 playlists para poder fusionarlas." << endl;
			}
			else {
				cout << "--- Fusionar Playlists ---" << endl;
				for (int i = 0; i < listas.size(); i++)
				{
					cout << "Playlist: " << i + 1 << endl;
					listas[i]->toString();
				}
				cout << "Seleccione la primer playlist por número: " << endl;
				cin >> firstPlaylist;
				while (listas.size() < firstPlaylist)
				{
					cout << "Escoja el numero de la playlist." << endl;
					cin >> firstPlaylist;
				}
				for (int i = 0; i < listas.size(); i++)
				{
					cout << "Playlist: " << i + 1 << endl;
					listas[i]->toString();
				}
				cout << "Seleccione la segunda playlist por número: " << endl;
				cin >> secondPlaylist;
				while (listas.size() < secondPlaylist)
				{
					cout << "Escoja el numero de la playlist." << endl;
					cin >> secondPlaylist;
				}
				*listas[firstPlaylist - 1] + listas[secondPlaylist - 1];
				cout << "Playlists fusionadas exitosamente. Nueva Playlist creada: " << nombreFusionado << endl;
			}
			break;
		case 6: // comparar duracion de dos playlists
			if (listas.empty()) {
				cout << "No hay playlists para poder comparar." << endl;
			}
			else if (listas.size() < 1) {
				cout << "Se ocupan 2 playlists para poder compararlas." << endl;
			}
			else {
				cout << "--- Comparar Duración de Playlists ---" << endl;
				for (int i = 0; i < listas.size(); i++)
				{
					cout << "Playlist: " << i + 1 << endl;
					listas[i]->toString();
				}
				cout << "Seleccione la primer playlist por número: " << endl;
				cin >> firstPlaylistComparar;
				while (listas.size() < firstPlaylistComparar)
				{
					cout << "Escoja el numero de la playlist." << endl;
					cin >> firstPlaylistComparar;
				}
				for (int i = 0; i < listas.size(); i++)
				{
					cout << "Playlist: " << i + 1 << endl;
					listas[i]->toString();
				}
				cout << "Seleccione la segunda playlist por número: " << endl;
				cin >> secondPlaylistComparar;
				while (listas.size() < secondPlaylistComparar)
				{
					cout << "Escoja el numero de la playlist." << endl;
					cin >> secondPlaylistComparar;
				}

				bool temp = listas[firstPlaylistComparar - 1] > listas[secondPlaylistComparar - 1];
				if (temp)
				{
					cout << "La playlist '" << listas[firstPlaylistComparar - 1]->getNombre() << "' es más larga que '"
						<< listas[secondPlaylistComparar - 1]->getNombre() << "'" << endl;
				}
				else {
					cout << "La playlist '" << listas[secondPlaylistComparar - 1]->getNombre() << "' es más larga que '"
						<< listas[firstPlaylistComparar - 1]->getNombre() << "'" << endl;
				}
			}
			break;
		case 7: // salir
			ejer1 = false;
			
			for (int i = 0; i < canciones.size(); i++) // borrar memoria
			{
				canciones[i]->~Cancion();
				delete canciones[i];
			}
			canciones.clear();
			for (int i = 0; i < listas.size(); i++) // borrar memoria
			{
				listas[i]->~Playlist();
				delete listas[i];
			}
			listas.clear();
			break;
		default:
			cout << "Opcion Invalida" << endl;
		}
	}
}
void menu() { // menu
	bool menu = true;
	int option = 0;
	while (menu) {
		cout << "Ejercicio Práctico 1 – Generador de Playlist" << endl;
		cout << "2. Salir" << endl;
		cin >> option;
		switch (option) {
		case 1:
			ejercicio_1();
			break;
		case 2:
			menu = false;
			break;
		default:
			cout << "Opcion Invalida" << endl;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "spanish");
	menu();
}

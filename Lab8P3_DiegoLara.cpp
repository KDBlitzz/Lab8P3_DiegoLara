#include <locale>
#include "Cancion.h"
#include "Playlist.h"
void ejercicio_1() {
    int selectPlaylist = 0;
    int selectCancion = 0;
    int contCancion = 0;
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
        case 1:
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
            canciones.push_back(new Cancion(titulo,artista,duracion,genero,year));
            cout << "Canción '" << titulo << "' agregada exitosamente." << endl;
            contCancion++;
            break;
        case 2:
            /*string Nombre;
	string Descripcion;*/
            cout << "Crear nueva playlist:" << endl;
            cout << "Ingrese el nombre de la playlist: " << endl;
            cin >> nombre;
            cout << "Ingrese la descripción de la playlist:" << endl;
            cin.ignore();
            getline(cin, desc);
            listas.push_back(new Playlist(nombre, desc));
            cout << "Playlist '" << nombre << "' creada exitosamente." << endl;
            break;
        case 3:
            if (canciones.empty())
            {
                cout << "No hay canciones para añadir." << endl;
            }
            else if(listas.empty()){
                cout << "No hay playlists para poder añadirle canciones." << endl;
            }
            else {
                cout << "--- Agregar Canción a Playlist ---" << endl;
                for (int i = 0; i < listas.size(); i++)
                {
                    listas[i]->toString();
                }
                cout << "Seleccione una playlist por número: " << endl;
                cin >> selectPlaylist;
                while (listas.size() < selectPlaylist)
                {
                    cout << "Escoja el numero de la playlist." << endl;
                    cin >> selectPlaylist;
                }
                cout << "Cancion: " << contCancion << endl;
                for (int i = 0; i <  canciones.size(); i++)
                {
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
                cout << "Canción añadida a la playlist exitosamente." << endl;
            }
            break;
        case 4:
            if (canciones.empty())
            {
                cout << "No hay canciones para eliminar." << endl;
            }
            else if (listas.empty()) {
                cout << "No hay playlists para poder eliminarle canciones." << endl;
            }
            else {
                cout << "--- Eliminar Canción de Playlist ---" << endl;
            }
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            ejer1 = false;
            break;
        default:
            cout << "Opcion Invalida" << endl;
        }
    }
}
void menu() {
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

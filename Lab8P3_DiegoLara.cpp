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
            cout << "Ingrese el t�tulo de la canci�n: " << endl;
            cin >> titulo;
            cout << "Ingrese el nombre del artista: " << endl;
            cin >> artista;
            cout << "Ingrese la duraci�n de la canci�n (en segundos): " << endl;
            cin >> duracion;
            while (duracion < 0) {
                cout << "Favor ingrese una duraci�n mayor a 0" << endl;
                cin >> duracion;
            }
            cout << "Ingrese el genero de la canci�n: " << endl;
            cin >> genero;
            cout << "Ingrese el a�o de lanzamiento de la canci�n: " << endl;
            cin >> year;
            while (year < 0) {
                cout << "Favor ingrese un a�o mayor a 0" << endl;
                cin >> year;
            }
            canciones.push_back(new Cancion(titulo,artista,duracion,genero,year));
            cout << "Canci�n '" << titulo << "' agregada exitosamente." << endl;
            contCancion++;
            break;
        case 2:
            /*string Nombre;
	string Descripcion;*/
            cout << "Crear nueva playlist:" << endl;
            cout << "Ingrese el nombre de la playlist: " << endl;
            cin >> nombre;
            cout << "Ingrese la descripci�n de la playlist:" << endl;
            cin.ignore();
            getline(cin, desc);
            listas.push_back(new Playlist(nombre, desc));
            cout << "Playlist '" << nombre << "' creada exitosamente." << endl;
            break;
        case 3:
            if (canciones.empty())
            {
                cout << "No hay canciones para a�adir." << endl;
            }
            else if(listas.empty()){
                cout << "No hay playlists para poder a�adirle canciones." << endl;
            }
            else {
                cout << "--- Agregar Canci�n a Playlist ---" << endl;
                for (int i = 0; i < listas.size(); i++)
                {
                    listas[i]->toString();
                }
                cout << "Seleccione una playlist por n�mero: " << endl;
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
                cout << "Seleccione una canci�n por n�mero: " << endl;
                cin >> selectCancion;
                while (canciones.size() < selectCancion)
                {
                    cout << "Escoja el numero de la canci�n." << endl;
                    cin >> selectCancion;
                }
                *listas[selectPlaylist - 1] + canciones[selectCancion - 1];
                cout << "Canci�n a�adida a la playlist exitosamente." << endl;
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
                cout << "--- Eliminar Canci�n de Playlist ---" << endl;
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
        cout << "Ejercicio Pr�ctico 1 � Generador de Playlist" << endl;
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

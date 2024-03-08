#include <iostream>
using namespace std;
void ejercicio_1() {
    bool ejer1 = true;
    int opcion = 0;
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
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
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
        cout << "" << endl;
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
    menu();
}

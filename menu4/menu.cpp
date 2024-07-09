//primer avance 
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

string eleccionUsuario(int jugadorNum);
string eleccionComputadora();
void mostrareleccion(string eleccion);
void elegirGanador(string jugador1, string jugador2, ofstream &archivo);
void jugar1vs1(ofstream &archivo);


int main() {
    int opcion;
    bool continuar = true;
    ofstream archivo("resultados.txt", ios::app);

    while (continuar) {
        cout<<"=================================\n";
        cout<<" bienvenido a piedra, papel o tijera \n";
        cout<<"=================================\n";
        cout << "Selecciona una de las opciones:\n";
        cout << "1. Jugar 1 vs 1\n";
        cout << "2. Jugar contra la computadora\n";
        cout << "3. Salir\n";
        cin >> opcion;

        switch (opcion) {
            case 1:
                jugar1vs1(archivo);
                break;
            case 2: {
                string jugador;
                string computadora;
                jugador = eleccionUsuario(1);
                cout << "Jugador: ";
                mostrareleccion(jugador);

                computadora = eleccionComputadora();
                cout << "Computadora: ";
                mostrareleccion(computadora);

                elegirGanador(jugador, computadora, archivo);
                break;
            }
            case 3:
                continuar = false;
                break;
            default:
                cout << "Opción no válida, intenta de nuevo.\n";
        }
    }

    archivo.close();
    return 0;
}

string eleccionUsuario(int jugadorNum) {
    string jugador;
    cout << "==================================\n";
    cout << "Piedras, papel o tijera | Jugador " << jugadorNum << "\n";
    cout << "==================================\n";
    do {
        cout << " 'p' para piedra\n";
        cout << " 'pa' para papel\n";
        cout << " 't' para tijera\n";
        cout << " Elige uno: ";
        cin >> jugador;
    } while (jugador != "p" && jugador != "pa" && jugador != "t");
    return jugador;
}

string eleccionComputadora() {
    srand(time(0));
    int num = rand() % 3 + 1;
    switch (num) {
        case 1: return "p";
        case 2: return "pa";
        case 3: return "t";
    }
    return "";
}

void mostrareleccion(string eleccion) {
    if (eleccion == "p") {
        cout << "piedra\n";
    } else if (eleccion == "pa") {
        cout << "papel\n";
    } else if (eleccion == "t") {
        cout << "tijera\n";
    }
}

void jugar1vs1(ofstream &archivo) {
    string jugador1, jugador2;

    cout << "Jugador 1:\n";
    jugador1 = eleccionUsuario(1);
    cout << "Jugador 1 eligio: ";
    mostrareleccion(jugador1);

    cout << "Jugador 2:\n";
    jugador2 = eleccionUsuario(2);
    cout << "Jugador 2 eligio: ";
    mostrareleccion(jugador2);

    elegirGanador(jugador1, jugador2, archivo);
}

void elegirGanador(string jugador1, string jugador2, ofstream &archivo) {
    string resultado;

    if (jugador1 == jugador2) {
        resultado = "EMPATE";
        cout << "EMPATE\n";
    } else if ((jugador1 == "p" && jugador2 == "t") 
               || (jugador1 == "pa" && jugador2 == "p") 
               || (jugador1 == "t" && jugador2 == "pa")) {
        resultado = "Jugador 1 GANA!!";
        cout << "Jugador 1 GANA!!\n";
    } else {
        resultado = "Jugador 2 GANA!!";
        cout << "Jugador 2 GANA!!\n";
    }

    // Registrar el resultado en el archivo
    archivo << "Jugador 1: " << jugador1 << ", Jugador 2: " << jugador2 << " => " << resultado << endl;
        }
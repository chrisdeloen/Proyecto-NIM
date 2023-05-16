#include <iostream>
#include <string>
using namespace std;

int main() {
	int objetos[3] = {3, 5, 7};
	int total_objetos = 15;
	int turno = 1;
	int puntos_jugador1 = 0;
	int puntos_jugador2 = 0;
	string nombre_jugador1, nombre_jugador2;
	bool terminado = false;
	
	cout << "Bienvenido al juego NIM." << endl;
	cout << "Jugador 1, ingrese su nombre: ";
	getline(cin, nombre_jugador1);
	cout << "Jugador 2, ingrese su nombre: ";
	getline(cin, nombre_jugador2);
	cout << endl;
	
	while (!terminado) {
		cout << "Puntuación: " << nombre_jugador1 << " (" << puntos_jugador1 << ") vs " << nombre_jugador2 << " (" << puntos_jugador2 << ")" << endl;
		cout << "Total de objetos restantes: " << total_objetos << endl;
		for (int i = 0; i < 3; i++) {
			cout << "Fila " << i+1 << ": ";
			for (int j = 0; j < objetos[i]; j++) {
				cout << "*";
			}
			cout << endl;
		}
		
		int fila, cantidad;
		string nombre_jugador = (turno == 1) ? nombre_jugador1 : nombre_jugador2;
		cout << nombre_jugador << ", escoja una fila (1-3): ";
		cin >> fila;
		fila--; 
		if (fila < 0 || fila > 2 || objetos[fila] == 0) {
			cout << "Fila no válida. Intente de nuevo." << endl;
			continue;
		}
		cout << "Cantidad de objetos a retirar (1-" << objetos[fila] << "): ";
		cin >> cantidad;
		if (cantidad < 1 || cantidad > objetos[fila]) {
			cout << "Cantidad no válida. Intente de nuevo." << endl;
			continue;
		}
		
		objetos[fila] -= cantidad;
		total_objetos -= cantidad;
		if (total_objetos == 1) {
			cout << "¡" << nombre_jugador << " pierde!" << endl;
			if (turno == 1) {
				puntos_jugador2 += 3;
			} else {
				puntos_jugador1 += 3;
			}
			terminado = true;
		}
		if (total_objetos == 0){
			cout<<"¡Es un empate!"<<endl;
			terminado = true;
		}
		turno = (turno == 1) ? 2 : 1;
		cout << endl;
	}
	
	cout << "Resultados finales:" << endl;
	cout << nombre_jugador1 << ": " << puntos_jugador1 << " puntos" << endl;
	cout << nombre_jugador2 << ": " << puntos_jugador2 << " puntos" << endl;
	
	return 0;
}

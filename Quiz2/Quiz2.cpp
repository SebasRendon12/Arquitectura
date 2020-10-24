/*                      Proyecto diseñado en C++ con Assembly embebido                       */
/* Diseñado para Arquitectura de computadores Universidad Nacional de Colombia sede Medellín */

#include <iostream>													//Libreria	
#include <string>													//Libreria

using namespace std;												//Estandar

int main() {
	int x1, x2, n;
	double y1, y2, tol;
	cout << "Ingrese el valor minimo del intervalo" << endl;		//mostrar en consola el mensaje
	cin >> x1;
	cout << endl << "Ingrese el valor máximo del intervalo" << endl;//mostrar en consola el mensaje
	cin >> x2;
	cout << endl << "Ingrese el valor de tolerancia" << endl;		//mostrar en consola el mensaje
	cin >> tol;
	cout << endl << "Ingrese el numero de iteraciones " << endl;	//mostrar en consola el mensaje
	cin >> n;
	system("pause");												//frenar la ejecucion del programa
	_asm {

	}
}
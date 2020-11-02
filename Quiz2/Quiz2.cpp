/*                      Proyecto diseñado en C++ con Assembly embebido                       */
/* Diseñado para Arquitectura de computadores Universidad Nacional de Colombia sede Medellín */

#include <iostream>													//Libreria	
#include <string>													//Libreria
#include <cmath>													//Libreria

using namespace std;												//Estandar

int main() {
	int  n;
	double y1, x1, x2, y2, tol, resultado;
	const double euler = std::exp(1.0);
	cout << "Ingrese el valor minimo del intervalo" << endl;		//mostrar en consola el mensaje
	cin >> x1;
	cout << endl << "Ingrese el valor maximo del intervalo" << endl;//mostrar en consola el mensaje
	cin >> x2;
	cout << endl << "Ingrese el valor de tolerancia" << endl;		//mostrar en consola el mensaje
	cin >> tol;
	cout << endl << "Ingrese el numero de iteraciones " << endl;	//mostrar en consola el mensaje
	cin >> n;
	system("pause");												//frenar la ejecucion del programa
	_asm {
		finit
		fldln2; st: loge(2)
		fld x1; st: loge(2) x1
		fyl2x; st: ln(x1)
		fstp y1; guardamos el resulado

		fld x1
		FLDL2E; ST = log2 e, ST(1) = x1
		fmulp ST(1), ST(0); ST = x1 * log2 e
		fld1
		fscale; 1 * 2elevado(x1 * log2 e)
		fld y1
		fadd st(0), st(1); se suman ln(x1) y e
		fstp y1; se guarda
		ffree; libera registro

		fldln2; st: loge(2)
		fld x2; st: loge(2) x2
		fyl2x; st: ln(x2)
		fstp y2; guardamos el resulado

		fld x2
		FLDL2E; ST = log2 e, ST(1) = x2
		fmulp ST(1), ST(0); ST = x2 * log2 e
		fld1
		fscale; 1 * 2elevado(x2 * log2 e)
		fld y2
		fadd st(0), st(1); se suman ln(x2) y e
		fstp y2; se guarda
		ffree; libera registro




	}
	cout << "Resultado: " << y1 << endl;
}
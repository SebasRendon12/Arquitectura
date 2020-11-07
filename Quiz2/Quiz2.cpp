/*                      Proyecto diseñado en C++ con Assembly embebido                       */
/* Diseñado para Arquitectura de computadores Universidad Nacional de Colombia sede Medellín */

#include <iostream>													//Libreria	
#include <string>													//Libreria
#include <cmath>													//Libreria

using namespace std;												//Estandar

int main() {
	int  interacciones, resultado, contador = 1;
	double y1, x1, x2, y2, tol, raiz, xm, ym, testing, aux;
	const double euler = std::exp(1.0);
	double dos = 2.0;
	cout << "Ingrese el valor minimo del intervalo" << endl;		//mostrar en consola el mensaje
	cin >> x1;
	cout << endl << "Ingrese el valor maximo del intervalo" << endl;//mostrar en consola el mensaje
	cin >> x2;
	cout << endl << "Ingrese el valor de tolerancia" << endl;		//mostrar en consola el mensaje
	cin >> tol;
	cout << endl << "Ingrese el numero de iteraciones " << endl;	//mostrar en consola el mensaje
	cin >> interacciones;
	double error = tol + 1;
	_asm {
		finit;							se inicia la pila
		fldln2;							st: loge(2)
		fld x1;							st(1) : loge(2)  st(0) : x1
		fyl2x;							st: loge(2)* log2(x1) = ln(x1)
		fstp y1;						guardamos el resultado parcial en y1


		fld x1;							Carga x1 a la pila
		fldl2e;							ST(0) = log2 e, ST(1) = x1
		fmulp   st(1), st(0);			st(0) = log2(e) * x1
		fld1;							st(0) = 1
		fld     st(1);					st(0) = log2(e) * x1
		fprem;							st(0) = residuo de log2(e) * x1 / 1
		f2xm1;							calcula 2 ^ (residuo de log2(e) * x1 / 1) - 1
		faddp   st(1), st(0);			suma 2 ^ (residuo de log2(e) * x1 / 1) - 1 con 1
		fscale;							2 ^ (residuo de log2(e) * x1 / 1) * 2 ^ (x1 * log2(e))
		fld y1;							Cargamos y1 a la pila
		fadd st(0), st(1);				se suman ln(x1) y e^ x1
		fstp y1;						se guarda y1
		finit;							limpia registros


		fldln2;							st: loge(2)
		fld x2;							st: st(1) : loge(2)  st(0) : x2
		fyl2x;							st: ln(x2)
		fstp y2;						guardamos el resultado parcial en y2

		fld x2;							Carga x2 a la pila
		fldl2e;							ST(0) = log2 e, ST(1) = x2
		fmulp   st(1), st(0);			st(0) = log2(e) * x2
		fld1;							st(0) = 1
		fld     st(1);					st(0) = log2(e) * x2
		fprem;							st(0) = residuo de log2(e) * x2 / 1
		f2xm1;							calcula 2 ^ (residuo de log2(e) * x2 / 1) - 1
		faddp   st(1), st(0);			suma 2 ^ (residuo de log2(e) * x2 / 1) - 1 con 1
		fscale;							2 ^ (residuo de log2(e) * x2 / 1) * 2 ^ (x2 * log2(e))
		fld y2;							Cargamos y1 a la pila
		fadd st(0), st(1);				se suman ln(x2) y e^ x2
		fstp y2;						se guarda y2
		finit;							limpia registros

		fldz;							se carga un 0 a la pila
		fld y1;							se carga y1 a la pila
		fcomi ST(0), ST(1);				se compara y1 == 0
		jne else1;						salta si no es igual
		mov resultado, 1;				si es igual se guarda como solucion tipo 1
		fld x1;							carga x1 a la pila
		fstp raiz;						se guarda a x1 como raiz
		jmp finalif1;					Salto al final del programa

		else1 :

		fldz;							se carga un 0 a la pila
			fld y2;						se carga y2 a la pila
			fcomi ST(0), ST(1);			se compara y2 == 0
			jne else2;					salta si no es igual
			mov resultado, 1;			si es igual se guarda como solucion tipo 1
			fld x2;						carga x2 a la pila
			fstp raiz;					se guarda a x2 como raiz
			jmp finalif2;				Salto al final del programa

			else2 :

		finit;							se limpia la pila
			fld y1;						se carga y1 a la pila
			fld y2;						se carga y2 a la pila
			fmul st(0), st(1);			st: y1* y2
			fldz;						st(0) :0 st(1) : y1 * y2
			fcomi st(0), st(1);			se compara y1* y2 con 0
			jnb else3;					salta si 0 no es menor a y1 * y2
			mov resultado, 0;			se guarda que el resultado es tipo 0
			jmp finalif3;				Salto al final del programa

			else3 :

		finit;							se empieza a calcular xm
			fld x1;						se carga x1 a la pila
			fld x2;						se carga x2 a la pila
			fadd st(0), st(1);			se suman x1 y x2
			fld dos;					Se carga 2.0 a la pila
			fdiv st(1), st(0);			se divide x1 + x2 por 2
			fstp xm;					guarda el valor de x1 + x2 que esta en el tope de pila
			fstp xm;					guarda el valor de(x1 + x2) / 2 que esta en el tope de pila

			finit;						se le aplica la funcion a xm
			fldln2;						st: loge(2)
			fld xm;						st: loge(2) xm
			fyl2x;						st: ln(xm)
			fstp ym;					guardamos el resultado parcial en ym

			fld xm;						Carga xm a la pila
			fldl2e;						ST(0) = log2 e, ST(1) = xm
			fmulp   st(1), st(0);		st(0) = log2(e) * xm
			fld1;						st(0) = 1
			fld     st(1);				st(0) = log2(e) * xm
			fprem;						st(0) = residuo de log2(e) * xm / 1
			f2xm1;						calcula 2 ^ (residuo de log2(e) * xm / 1) - 1
			faddp   st(1), st(0);		suma 2 ^ (residuo de log2(e) * xm / 1) - 1 con 1
			fscale;						2 ^ (residuo de log2(e) * xm / 1) * 2 ^ (xm * log2(e))
			fld ym;						Cargamos ym a la pila
			fadd st(0), st(1);			se suman ln(xm) y e^ xm
			fstp ym;					se guarda ym
			finit;						limpia registros


			while:
		finit;							condicion 1 de while
			fldz;						Cargamos 0 a la pila
			fld ym;						Cargamos ym a la pila
			fcomi st(0), st(1);			se compara ym con 0
			je finwhile;				acaba el while si ym es igual a 0

			finit;						condicion 2 de while
			fld tol;					Cargamos tol a la pila
			fld error;					Cargamos error a la pila
			fcomi st(0), st(1);			se compara tolerancia con error
			jbe finwhile;				acaba el while si error es menor a tolerancia

			mov eax, interacciones;		condicion 3 de while
			cmp contador, eax;			compara contador con interacciones
			jge finwhile;				acaba el while si contador es mayor a interacciones

			finit;						primer if dentro del while
			fld ym;						Cargamos ym a la pila
			fld y1;						Cargamos y1 a la pila
			fmul st(0), st(1);			multiplica ym con y1
			fldz;						carga 0 a la pila
			fcomi st(0), st(1);			compara 0 con ym * y1
			jbe else4;					salta si 0 es menor o igual a y1 * ym
			fld xm;						carga xm a la pila
			fstp x2;					le asigna el valor de xm a x2
			fld ym;						carga ym a la pila
			fstp y2;					se le asigna el valor de ym a y2
			jmp finalif4;				salta a la siguiente parte

			else4 : ;					si no se cumple el condicional anterior
			finit;						reinicia lapila
			fld xm;						carga xm a la pila
			fstp x1;					le asigna el valor de xm a x1
			fld ym;						carga ym a la pila
			fstp y1;					se le asigna el valor de ym a y1

			finalif4 : ;				fin del condicional del while

			finit;						reinicia la pila
			fld xm;						carga xm a la pila
			fstp aux;					le asigna el valor de xm a aux
			fld x1;						Cargamos x1 a la pila
			fld x2;						Cargamos x2 a la pila
			fadd st(0), st(1);			suma x1 con x2
			fld dos;					Cargamos 2.0 a la pila
			fdiv st(1), st(0);			divide x1 + x2 con 2 y se guarda en st(1)
			fstp xm;					guarda el valor de x1 + x2
			fstp xm;					guarda el valor de(x1 + x2) / 2

			finit;						evalua el nuevo xm en la funcion
			fldln2;						st: loge(2)
			fld xm;						st: loge(2) xm
			fyl2x;						st: ln(xm)
			fstp ym;					guardamos el resultado parcial en ym

			fld xm;						Carga xm a la pila
			fldl2e;						ST(0) = log2 e, ST(1) = xm
			fmulp   st(1), st(0);		st(0) = log2(e) * xm
			fld1;						st(0) = 1
			fld     st(1);				st(0) = log2(e) * xm
			fprem;						st(0) = residuo de log2(e) * xm / 1
			f2xm1;						calcula 2 ^ (residuo de log2(e) * xm / 1) - 1
			faddp   st(1), st(0);		suma 2 ^ (residuo de log2(e) * xm / 1) - 1 con 1
			fscale;						2 ^ (residuo de log2(e) * xm / 1) * 2 ^ (xm * log2(e))
			fld ym;						Cargamos ym a la pila
			fadd st(0), st(1);			se suman ln(xm) y e^ xm
			fstp ym;					se guarda ym
			finit;						limpia registros


			finit;						reinicia datos en la pila
			fld xm;						carga xm
			fld aux;					carga la variable aux
			fsub st(0), st(1);			realiza la operacion xm - aux y se guarda en st(0)
			fdiv st(0), st(1);			divide xm - aux por xm
			fabs;						realiza el valor absoluto de la variable en st(0), osea(xm - aux) / xm
			fstp error;					guarda | (xm - aux) / xm | en error

			add contador, 1;			suma 1 al contador

			jmp while;					reinicia el while hasta que no se cumpla alguna de las condiciones

			finwhile : ;				acaba el while

			finit;						bloque de primer if despues del while
			fldz;						carga 0 a la pila
			fld ym;						carga ym a la pila
			fcomi st(0), st(1);			compara ym con 0
			jne else5;					salta si son distintos
			mov resultado, 1;			en caso de que sean iguales se guarda como resultado tipo 1
			fld xm;						carga xm a la pila
			fstp raiz;					guarda xm como raiz
			jmp finalif5;				salta al final del codigo

			else5 : ;					si no se cumple lo anterior
			finit;						reiniciamos la pila
			fld tol;					Cargamos tol a la pila
			fld error;					Cargamos error a la pila
			fcomi st(0), st(1);			compara error con tolerancia
			ja else6;					salta si e es mayor que tolerancia
			mov resultado, 2;			se guarda como resultado tipo 2
			fstp error;					se guarda el error
			fld xm;						carga a xm como raiz
			fstp raiz;					guarda a xm como raiz
			jmp finalif6;				salta al final del codigo

			else6 : ;					en caso de que no se cumpla ninguna de los anteriores
			mov resultado, 3;			se guarda como resultado tipo 3



		finalif1:
	finalif2:
	finalif3:
	finalif5:
	finalif6:


	}
	switch (resultado) {
	case 0:
		cout << "No hay raiz";
		break;

	case 1:
		cout << raiz << " es raiz";
		break;

	case 2:
		cout << endl << xm << " es raiz con error " << error;
		break;

	case 3:
		cout << "Fallo por iteraciones";
		break;
	default:
		break;
	}
}
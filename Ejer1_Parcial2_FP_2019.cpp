#include <iostream>
using namespace std;
/// Un año es bisiesto si cumple con alguna de las siguientes condiciones
/// 1 - Es divisible por 4 y no es divisible por 100
/// 2 - Es divisible por 4, por 100 y por 400
/// Escribir una función que diga si un años es bisiesto
/// Mostrar los 100 años bisienstos porteriores a una fecha que se ingresa
/// por teclado con formato aaaammyy

bool EsBisiesto(int Anio){
	if (Anio % 4 == 0 && Anio % 100 != 0){
		///1 - Es divisible por 4 y no es divisible por 100
		return true;
	}
	if (Anio % 4 == 0 && Anio % 100 == 0 && Anio % 400 == 0){
		///2 - Es divisible por 4, por 100 y por 400
		return true;
	}
	return false;
}

int main() {
	int fecha,anio;
	int conteo = 0;
	cout<<"Ingrese fecha (aaaammdd)"<<endl;
	cin>>fecha;
	anio = fecha / 10000;
	
	do {
		if (EsBisiesto(anio)){
			conteo++;
			cout<<"Bisiesto "<<conteo<<" "<<anio<<endl;
		}
		anio++;
	}while (conteo < 100);
	
	
	return 0;
}


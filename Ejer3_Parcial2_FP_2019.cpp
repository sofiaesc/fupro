#include <iostream>
#include <matrix>
using namespace std;
/// Una farmacia posee 11 sucursales y se desea estudiar las ventas de los 
/// 12 meses de un año
/// Se ingresan ternas de datos, codigo de farmacia, mes e importe, los datos
/// terminan con farmacia = -1, puede haber mas de una venta en el mismo mes
/// para la misma farmacia
int main() {
	matrix<int>ventas(12,13,0); /// 1 a 11 y 1 a 12 omitiendo el 0
	
	/// ingreso de los datos
	int importe,codfarmacia,mes;
	int i;
	cout<<"Ingrese código de farmacia (-1 termina)"<<endl;
	cin>>codfarmacia;
	while (codfarmacia != -1){
		cout<<"Ingrese mes (1 a 12)"<<endl;
		cin>>mes;
		cout<<"Ingrese Importe"<<endl;
		cin>>importe;
		ventas[codfarmacia][mes] += importe;
		
		cout<<"Ingrese código de farmacia (-1 termina)"<<endl;
		cin>>codfarmacia;
	}
	/// Inciso b, ingresar un código de farmacia e informar la venta del 1er 
	/// trimestre
	cout<<"Ingrese código de farmacia "<<endl;
	cin>>codfarmacia;
	int suma = 0;
	for (i=1;i<=3;i++){
		suma += ventas[codfarmacia][i];
	}
	cout<<"La farmacia "<<codfarmacia<<" vendió $ "<<suma<<endl;
	
	/// Inciso c, la farmacia que menos vendió en el 2do semestre
	int ventamenor = 100000000; /// para un menos se empieza con numero alto
	int cod_f_menor;
	
	for (codfarmacia = 1;codfarmacia<12;codfarmacia++){
		suma=0; /// pongo la sumatoria de la farmacia en 0
		for (mes = 7;mes<=12;mes++){
			suma += ventas[codfarmacia][mes];
		}
		if (suma < ventamenor){
			ventamenor = suma;
			cod_f_menor = codfarmacia;
		}
	}
	cout<<"La farmacia que menos vendió "<<cod_f_menor<<" con $ "<<ventamenor<<endl;
	
	/// inciso d, promedio de venta mensual
	for (mes = 1;mes<=12;mes++){
		suma=0; /// pongo la sumatoria del mes
		for (codfarmacia = 1;codfarmacia<12;codfarmacia++){
			suma += ventas[codfarmacia][mes];
		}
		cout<<"El promedio del mes"<<mes<<"  $ "<<suma/11<<endl;
	}
	
	
	return 0;
}


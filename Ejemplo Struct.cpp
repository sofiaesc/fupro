#include <iostream>
#include <string>
using namespace std;

struct materia{
	string nombre;
	int nota;
};

struct persona{
	long dni;
	string nombre;
	int edad;
	vector<int>notas;
	vector<materia>materias_rendidas;
};

int main() {
	persona p;
	vector<persona>personas(5);
	
	p.dni = 17222360;
	p.nombre = "Vallejos";
	p.edad = 54;
		
	cout<<"DNI : "<<p.dni<<endl;
	cout<<"Nombre : "<<p.nombre<<endl;
	cout<<"Edad : "<<p.edad<<endl;
	
	int i,nota;
	for (i=1;i<=3;i++){
		cout<<"Ingrese Nota "<<i<<endl;
		cin>>nota;
		/// agrego la nota a la lista
		p.notas.push_back(nota);
	}
	
	personas[0].dni = 23568341;
	personas[0].nombre = "José";
	personas[0].edad = 38;
	for (i=1;i<=3;i++){
		cout<<"Ingrese Nota "<<i<<endl;
		cin>>nota;
		/// agrego la nota a la lista
		personas[0].notas.push_back(nota);
	}
	
	return 0;
}


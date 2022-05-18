#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<string>aprobados;
	vector<string>no_aprobados;
	
	string nombre;
	int calif;
	
	cout<<"Ingrese calificación"<<endl;
	cin>>calif;
	
	while (calif != 0){
		cout<<"Ingrese nombre"<<endl;
		cin>>nombre;
		
		/// push_back genera un nuevo elemento en el vector
		/// al final y coloca el dato en ese nuevo lugar
		if (calif >= 6){
			aprobados.push_back(nombre);}
		else {
			no_aprobados.push_back(nombre);
		}
		
		cout<<"Ingrese calificación"<<endl;
		cin>>calif;
	}
	cout<<endl<<endl;
	int i;
	if (aprobados.size() > 0){
		cout<<"LISTA DE APROBADOS"<<endl;
		for (i=0;i<aprobados.size();i++){
			cout<<aprobados[i]<<endl;
		}
	}
	cout<<endl<<endl;
	if (no_aprobados.size() > 0){
		cout<<"LISTA DE NO APROBADOS"<<endl;
		for (i=0;i<no_aprobados.size();i++){
			cout<<no_aprobados[i]<<endl;
		}
	}
	
	return 0;
}


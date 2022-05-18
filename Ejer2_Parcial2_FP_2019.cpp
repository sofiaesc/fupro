#include <iostream>
#include <vector>
#include <string>
using namespace std;
/// Cargar una lista de N pacientes con los datos del struct de abajo.
/// Escribir una función que busque un paciente a partir de su código
/// Escribir una función que obtenga la cantidad de pacientes por día de nacimiento
struct paciente{
	string codigo;
	int dni;
	string nombres;
	string apellido;
	int fechanac;
};

int GetPosicionPaciente(vector<paciente>lista,string codigo){
	int i;
	for (i=0;i<lista.size();i++){
		if (lista[i].codigo == codigo){
			return i;
		}
	}
	return -1; /// no lo encuentra
}
vector<int>GetNacidos(vector<paciente>lista){
	vector<int>nacidos(32,0); /// 1 a 31 dejando el 0
	int i,dia;
	for (i=0;i<lista.size();i++){
		dia = lista[i].fechanac % 100; /// obtengo el dia
		nacidos[dia]++; /// uso el dia como índice e incremento el contador
	}
	return nacidos;
}
int main() {
	int N,i;
	cout<<"Ingrese cantidad de pacientes"<<endl;
	cin>>N;
	vector<paciente>lista(N);
	
	/// Ingresar los datos
	for (i=0;i<lista.size();i++){
	   cin>>lista[i].codigo;
	   cin>>lista[i].dni;
	   cin>>lista[i].nombres;
	   cin>>lista[i].apellido;
	   cin>>lista[i].fechanac;
	}
	int posicion = GetPosicionPaciente(lista,"AF0001");
	if (posicion > -1){
		cout<<lista[posicion].codigo;
		cout<<lista[posicion].dni;
		cout<<lista[posicion].nombres;
		cout<<lista[posicion].apellido;
		cout<<lista[posicion].fechanac;}
	else{
		cout<<"No existen pacientes con el código AF0001 "<<endl;
	}
	
	/// Nacidos por dia
	vector<int>nacidos = GetNacidos(lista);
	for (i=1;i<nacidos.size();i++){
		cout<<"Los Nacidos el día "<<i<<" son "<<nacidos[i]<<endl;
	}
	
	return 0;
}


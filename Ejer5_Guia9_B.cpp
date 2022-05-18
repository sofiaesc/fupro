#include <iostream>
#include <vector>
using namespace std;

int buscar(vector<int>lista,int valor);
int buscar(vector<int>lista,int valor,int p);
void eliminar(vector<int>&lista,int valor);
int main() {
	int N;
	cout<<"Ingrese cantidad de valores"<<endl;
	cin>>N;
	vector<int>lista(N);
	
	int i;
	/// lo llenamos con valores al azar
	for (i=0;i<lista.size();i++){
		lista[i] = 10 + rand() % 20;
		cout<<lista[i]<<endl;
	}
	int valor;
	cout<<"Ingrese un valor a eliminar"<<endl;
	cin>>valor;
	/// dejo 2 lineas en blanco
	cout<<endl<<endl;
	eliminar(lista,valor);
	cout<<endl<<endl;
	for (i=0;i<lista.size();i++){
		cout<<lista[i]<<endl;
	}
	
	
	
	return 0;
}

int buscar(vector<int>lista,int valor){
	int i;
	for (i=0;i<lista.size();i++){
		if ( lista[i] == valor ){
			return i; /// retorna el indice o posicion dentro del vector
		}
	}
	/// si llega hasta ac�, significa que no encontr� el valor en la lista
	return -1;
}


int buscar(vector<int>lista,int valor,int p){
	if (p == lista.size()){
		/// recorri� toda la lista y no lo encontr�
		return -1; /// retorna -1 y se corta el autollamado
	}
	if (lista[p] == valor){
		return p; /// lo encontr�, retorno la posici�n
	}
	return buscar(lista,valor,p+1);
}


void eliminar(vector<int>&lista,int valor){
	int posicion;
	int i;
	
	posicion = buscar(lista,valor,0);
	while (posicion != -1){
		/// correr todo 1 a la izquierda
		for (i=posicion;i<lista.size()-1;i++){
			lista[i] = lista[i+1];
		}
		/// recorto el vector
		lista.resize(lista.size()-1); /// le quito 1 elemento
		posicion = buscar(lista,valor,0); /// vuelvo a buscar
	}
}

#include <iostream>
using namespace std;

struct alumno{
	long dni;
	int orden;
	vector<int>notas;
};

int buscar(vector<alumno>lista;int orden){
	int i;
	for (i=0;i<lista.size();i++){
		if (lista[i].orden == orden){
			return i; /// retorno la posicion
		}
	}
	/// si sale del for sin encontrar nada, retorna -1
	return -1;
}

int main() {
	int N;
	cout<<"Ingrese cantidad de alumnos"<<endl;
	cin>>N;
	
	vector<alumno>lista(N);
	
	int dni,orden,i;
	
	for (i=0;i<N;i++){
		cout<<"Ingrese dni del alumno"<<endl;
		cin>>dni;
		cout<<"Ingrese nro de orden del alumno"<<endl;
		cin>>orden;
		lista[i].dni = dni;
		lista[i].orden = orden;
		/// le asigno 3 lugares el campo vector de notas
		lista[i].notas.resize(3);
	}
	
	/// comienza la lectura de datos de notas
	int cant = N * 3 ; /// N alumnos x 3 notas
	int codmat; /// 1 a 3, código de materia
	int nota,posicion;
	
	for (i=0;i<cant;i++){
		cout<<"Ingrese còdigo de materia (1 a 3)"<<endl;
		cin>>codmat;
		cout<<"Ingrese nro de orden del alumno"<<endl;
		cin>>orden;
		cout<<"Ingrese Nota del alumno"<<endl;
		cin>>nota;
		/// Buscar en qué posición se encuentra el número de orden
		posicion = buscar(lista,orden);
		
		lista[posicion].notas[codmat-1] = nota;
		
	}
	
	/// una vez que se cargan las notas, se buscan los dos mayores
	int may1=0,may2=0;
	int dni1,dni2;
	int sumanotas;
	int j;
	int nota_comp;
	for (i=0;i<N;i++){
		/// por cada alumno, pongo la sumatoria de notas en 0
		sumanotas = 0;
		/// sumar las notas del alumno
		for (j=0;j<lista[i].notas.size();j++){
			sumanotas += lista[i].notas[j];
		}
		/// una vez que tengo la suma de notas comparo los dos mayores
		if (sumanotas > may1){
			may2=may1,dni2 = dni1;
			nota_comp = lista[i].notas[2]; /// inciso c
			may1 = sumanotas;dni1=lista[i].dni;}
		else{
			if (sumanotas > may2){
				may2 = sumanotas;dni2=lista[i].dni;
			}
		}
	}
	cout<<"El ganador es "<<dni1<<" puntaje "<<may1<<endl;
	cout<<"El 2do es "<<dni2<<" puntaje "<<may2<<endl;
	cout<<"El ganador sacó "<<nota_comp<<" en computación"<<endl;
	return 0;
}


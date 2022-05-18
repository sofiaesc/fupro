#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

struct medicamento{
	int codigo;
	string nombre;
	int stock;
	int cod_reemplazo;
	int faltantes;
};

int buscar(vector<medicamento>lista,int codmed,int posicion){
	/// evalùo si llegué al final de la lista
	if (posicion == lista.size()){
		/// llegó al final y no encontró nada
		return -1;
	}
	/// evalúo si lo encontró en la posición
	if (lista[posicion].codigo == codmed){
		/// lo encontró, retorno el ínidice
		return posicion;
	}
	/// no llegó al final y tampoco lo encontró, se autollama
	/// en la siguiente posición
	return buscar(lista,codmed,posicion+1);
}

tuple<int,int>get_faltantes(vector<medicamento>lista){
	int i,may1=0,may2=0;
	int cod1,cod2;
	
	for (i=0;i<lista.size();i++){
		if (lista[i].faltantes > may1){
			may2 = may1;cod2 = cod1;
			may1 = lista[i].faltantes;
			cod1 = lista[i].codigo;}
		else{
			may2 = lista[i].faltantes;
			cod2 = lista[i].codigo;
		}
	}
	return make_tuple(cod1,cod2);
}

int main() {
	vector<medicamento>lista(10);
	int dia,codmed,cantidad;
	
	int posi1,posi2,faltante,codreemp;
	
	cout<<"Ingrese día (0 termina)"<<endl;
	cin>>dia;
	while (dia != 0){
		cout<<"Código de medicamento"<<endl;
		cin>>codmed;
		cout<<"Cantidad"<<endl;
		cin>>cantidad;
		
		/// busco al medicamento por su codigo
		posi1 = buscar(lista,codmed,0);
		
		/// caso 1, el stock actual del medicamento es mayor o igual
		/// a la cantidad pedida
		if (lista[posi1].stock >= cantidad){
			/// le resto la cantidad al stock
			lista[posi1].stock -= cantidad;}
		else{
			/// si el stock es menor a la cantidad pedida, tenemos faltante
			faltante = cantidad - lista[posi1].stock;
			/// el stock del medicamento queda en 0
			lista[posi1].stock = 0;
			/// se le suma el faltante
			lista[posi1].faltantes += faltante;
			
			codreemp = lista[posi1].cod_reemplazo;  /// obtengo el cod de reemplazo
			posi2 = buscar(lista,codreemp,0);  /// busco el reemplazo
			/// descuento el faltante al stock del reemplazo
			lista[posi2].stock -= faltante;
		}
		
		cout<<"Ingrese día (0 termina)"<<endl;
		cin>>dia;
	}
	
	/// informo los stock finales
	int i;
	for (i=0;i<lista.size();i++){
		cout<<lista[i].nombre<<"   stock "<<lista[i].stock<<endl;
	}
	
	
	int cod1,cod2;
	/// llamo a la tupla
	tie(cod1,cod2) = get_faltantes(lista);
	
	cout<<"los códigos con mas faltantes son "<<cod1<<" - "<<cod2<<endl;
	
	return 0;
}


#include <iostream>
#include <matrix>
#include <cstdlib>
using namespace std;

int promedio(matrix<int>lluvias,int fila);

int main() {
	matrix<int>lluvias(5,12);
	int i,j;
	
	for (i=0;i<lluvias.size(0);i++){
		for (j=0;j<lluvias.size(1);j++){
			lluvias[i][j] = 10 + rand()%180;
		}
	}
	/// fabrico algunos - 1 para probar 
	lluvias[1][3] = -1;lluvias[1][9] = -1;lluvias[3][8] = -1;lluvias[4][10] = -1;
	for (i=0;i<lluvias.size(0);i++){
		for (j=0;j<lluvias.size(1);j++){
			cout<<lluvias[i][j]<<"   ";
		}
		cout<<endl<<endl;
	}
	
	int prom;
	for (i=0;i<lluvias.size(0);i++){
		for (j=0;j<lluvias.size(1);j++){
			if (lluvias[i][j] == -1){
				prom = promedio(lluvias,i);
				lluvias[i][j] = prom;
			}
		}
	}
	
	cout<<endl<<endl;
	for (i=0;i<lluvias.size(0);i++){
		for (j=0;j<lluvias.size(1);j++){
			cout<<lluvias[i][j]<<"   ";
		}
		cout<<endl<<endl;
	}
	
	return 0;
}

int promedio(matrix<int>lluvias,int fila){
	int i;
	int conteo = 0; /// cantidad valores <> -1
	int suma = 0;
	for (i=0;i<lluvias.size(1);i++){
		if (lluvias[fila][i] != -1){
			conteo++;
			suma+=lluvias[fila][i];
		}
	}
	return suma/conteo;
}

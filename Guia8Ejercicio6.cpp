#include <iostream>
using namespace std;
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <vector>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Funcion para ordenar un vector
void ordenamientoBurbuja();

int main(int argc, char** argv) {
	srand(time(NULL));
	int n;
	int c;
	int lista[5];
	
	
	try{
		printf("Indique la canditdad de datos a generar: ");
		cin>>c;
		if(c>0){
			//Llenado del vector con numeros aleatorios
			for(int i=0;i<c;i++){
				n=1+rand()%(16-1);
				lista[i]=n;
				cout<<lista[i]<<endl;
			}
		ordenamientoBurbuja(lista,c);
		for(int i=0;i<c;i++) cout<<lista[i]<<", ";
		}
		else throw 404;
	}
	catch(int e)
	{
		printf("Cantidad de datos no valida\t");
	}
	
	system("PAUSE");
	return 0;
}

void ordenamientoBurbuja(int n[], int cantidad){
	int temp;
	for(int i=0;i<cantidad;i++){
		for(int j=i+1;j<j<cantidad;j++){
			if(n[i]>n[j]){
				temp = n[j];
				n[i]=n[j];
				n[j]=temp;
			}
		}
	}
};

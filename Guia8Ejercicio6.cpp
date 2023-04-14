#include <vcl.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

#include <tchar.h>

#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <vector>


//Funcion para ordenar un vector
void ordenamientoBurbuja(int n[], int cantidad);

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	int n;
	int c = 5;
	int lista[c];


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

	getch();
	return 0;
}

void ordenamientoBurbuja(int n[], int cantidad){
	int temp;
	for(int i=0; i<cantidad;i++){
		for(int j=0; j<cantidad; j++){
			if(n[j]>n[j+1]){
			   temp = n[j];
			   n[j]=n[j+1];
			   n[j+1]=temp;
			}
		}
	}
}


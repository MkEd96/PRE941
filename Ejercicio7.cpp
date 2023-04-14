#include <iostream>
using namespace std;
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <vector>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void OrdenarMatriz(int m[5][4]);

int main(int argc, char** argv) {
	srand(time(NULL));
	float pimpares;
	int numeros[5][4];
	
	for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){
			numeros[i][j]=(-102+rand()%(99-1))+2;
		}
	}
	
	//Impresión como tabla
	for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){
			printf("| %d |",numeros[i][j]);
		}
		printf("\n");
	}
	cout<<endl;
	cout<<endl;
	
	OrdenarMatriz(numeros);
	
	for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){
			printf("| %d |",numeros[i][j]);
		}
		printf("\n");
	}
	
	//Porcentaje numeros impares
	for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){
			if(numeros[i][j]%2!=0) pimpares++;
		}
	}
	pimpares=(pimpares/20)*100;
	
	cout<<endl<<endl;
	cout<<"El porcentaje de numeros impares es de: "<<pimpares<<"%";
	
	getch();
	return 0;
}

//Modulo para ordenar una matriz. Es necesario definir las dimensiones para pasarla como parametro.
void OrdenarMatriz(int m[5][4]){
	int temp, i=0;
	int v[20];
	for(int j=0;j<5;j++){
		for(int y=0;y<4;y++){
			v[i++]=m[j][y];
		}
	}
	
//Para ordenar de forma ascendente cambiar el > por < en el if
	for(int p=0; p<20;p++){
		for(int j=0; j<20; j++){
			if(v[j]>v[j+1]){
			   temp = v[j];
			   v[j]=v[j+1];
			   v[j+1]=temp;
			}
		}
	}
	
	i=0;
	
	for(int j=0;j<5;j++){
		for(int y=0;y<4;y++){
			m[j][y] = v[i++];
		}
	}
	
}

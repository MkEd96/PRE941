//#include <vcl.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

#include <tchar.h>

#include <stdio.h>

//int _tmain(int argc, _TCHAR* argv[])


#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<conio.h>
#include<queue>
#include "InfoClass.h"

using namespace std;

bool checkForItemInt(const vector<int>& arr, int data);
bool checkForItemString(const vector<string>& arr, const string& data);
void printTable(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year);
void printUserInputQueue(const queue<string>& userInputQueue);

int main(int argc, _TCHAR* argv[]){
	char respuesta = '\0';
    int control;
    int opciones;
    int placataxi;
    int yeartaxi;
    string type;
    string motortaxi;
    string modelotaxi;
    vector<int> placa;
    vector<int> year;
	vector<string> motor;
    vector<string> modelo;
    vector<string> vtype;
    queue<string> userInputQueue;

    //Conductor

    string nombre;
    string apellido;
    int dui;
    int licencia;
	int numisss;
    int telefono;
    vector<string> vnombre;
    vector<string> vapellido;
    vector<int> vdui;
    vector<int> vlicencia;
    vector<int> vnumisss;
    vector<int> vtelefono;

    cout << "Bienvenido a TrueDrive" << endl;

	do {
        system("cls");
        cout << "Por favor seleccione una opción:\n\n";
        cout << "\t\t1. Ingresar nuevo vehículo y conductor" << endl;
        cout << "\t\t2. Comenzar Viaje" << endl;
        cout << "\t\t3. Terminar Viaje" << endl;
        cout << "\t\t4. Ver lista de conductores" << endl;
        cout << "\t\t5. Salir del programa" << endl << endl;
        cout << "Escribir su opcion: ";
        cin >> opciones;

		switch (opciones) {
			case 1:

                // YEAR ES INT
				
				do{
					cout << "Ingresando Vehículo..." << endl;	
					cout << "Año: ";
					cin >> yeartaxi;
					if(yeartaxi>=2015)
						type="Ejecutiva";
					if(yeartaxi>=2010 && yeartaxi<2015)
						type="Tradicional";
					if(yeartaxi<2010)
						cout<<"No es posible ingresar este vehiculo debido a la antiguedad...\n";
					// while (checkForItemInt(year, yeartaxi)); el año de los autos puede ser el mismo
				}while(yeartaxi<2010);
				year.push_back(yeartaxi);
				vtype.push_back(type);

            	// PLACA ES INT

                do {
                    cout << "placa: ";
                    cin >> placataxi;
				} while (checkForItemInt(placa, placataxi));
                placa.push_back(placataxi);

                cin.ignore();  // Ignore newline character

                //DATOS DEL VEHICULO

                // MOTOR ES STRING

                do {
                    cout << "motor: ";
					getline(cin, motortaxi);
                } while (checkForItemString(motor, motortaxi));
                motor.push_back(motortaxi);

                // MODELO ES STRING

				cout << "modelo: ";
				getline(cin, modelotaxi);
				//while (checkForItemString(modelo, modelotaxi)); Puede haber el mismo modelo para varios autos
                modelo.push_back(modelotaxi);

				//DATOS DEL CONDUCTOR

                do{
                	cout<< "Ingresando datos del conductor...\n";
                	cout<< "Ingrese el nombre: ";
                	cin>>nombre;
				}while(checkForItemString(vnombre,nombre));
				vnombre.push_back(nombre);

				do{
					cout<< "Ingrese el apellido: ";
					cin>>apellido;
				}while(checkForItemString(vapellido,apellido));
				vapellido.push_back(apellido);

                do{
                	cout<<"Ingrese el # de DUI sin guion: ";
                	cin>>dui;
				}while(checkForItemInt(vdui,dui));
				vdui.push_back(dui);

				do{
					cout<<"Ingresa el # de licencia sin guion: ";
					cin>>licencia;
				}while(checkForItemInt(vlicencia,licencia));
				vlicencia.push_back(licencia);

				do{
					cout<< "Ingresa el numero de seguro social sin guiones: ";
					cin>>numisss;
				}while(checkForItemInt(vnumisss,numisss));
				vnumisss.push_back(numisss);

				do{
					cout<< "Ingresa el numero de telefono: ";
					cin>>telefono;
				}while(checkForItemInt(vtelefono,telefono));
				vtelefono.push_back(telefono);


                // Agrega todo al QUEUE ()
    			userInputQueue.push(to_string(placataxi));
    			userInputQueue.push(motortaxi);
    			userInputQueue.push(modelotaxi);
				userInputQueue.push(to_string(yeartaxi));
    			userInputQueue.push(nombre);
    			userInputQueue.push(apellido);
    			userInputQueue.push(to_string(dui));
    			userInputQueue.push(to_string(licencia));
    			userInputQueue.push(to_string(numisss));
    			userInputQueue.push(to_string(telefono));
    			userInputQueue.push(type);

                break;

            case 2:
				// Code logic for starting a trip
                printUserInputQueue(userInputQueue);
                break;

            case 3:
                // Code logic for ending a trip
                break;

            case 4:
                printTable(placa, motor, modelo, year,vnombre,vapellido,vdui,vlicencia,vnumisss,vtelefono,vtype);
                break;

            case 5:
                cout << "Saliendo de TrueDrive..." << endl;
                system("pause");
                system("exit");
                break;

            default:
                cout << "No ha seleccionado una opción válida (1-5)." << endl;
                break;
        }

        cout << "¿Desea continuar? (Y/N): ";
        respuesta = getch();
    } while (respuesta == 'Y' || respuesta == 'y');
}

bool checkForItemInt(const vector<int>& arr, int data) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == data) {
            cout << "Data is already registered at position [" << i << "].\nPlease enter data again.\n";
            return true;
		}
    }
    return false;
}

bool checkForItemString(const vector<string>& arr, const string& data) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == data) {
            cout << "Data is already registered at position [" << i << "].\nPlease enter data again.\n";
            return true;
        }
	}
    return false;
}
void printTable(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year, const vector<string>& vnombre,const vector<string>& vapellido,const vector<int>& vdui,const vector<int>& vlicencia,const vector<int>& vnumisss,const vector<int>& vtelefono,const vector<string>& vtype) {
    InfoClass t('-', '|', '+');
    t.add("Order");
    t.add("Placa");
    t.add("Motor");
    t.add("Modelo");
    t.add("Año");
    t.add("Nombre");
    t.add("Apellido");
    t.add("DUI");
    t.add("Licencia");
    t.add("Seguro social");
    t.add("Telefono");
    t.add("Tipo de vehiculo");
    t.endOfRow();

    for (int i = 0; i < placa.size(); i++) {
        t.add(to_string(i));
        t.add(to_string(placa[i]));
        t.add(motor[i]);
        t.add(modelo[i]);
        t.add(to_string(year[i]));
        t.add(vnombre[i]);
        t.add(vapellido[i]);
        t.add(to_string(vdui[i]));
        t.add(to_string(vlicencia[i]));
        t.add(to_string(vnumisss[i]));
        t.add(to_string(vtelefono[i]));
        t.add(vtype[i]);
        t.endOfRow();
    }

    t.setAlignment(2, InfoClass::Alignment::RIGHT);
	cout << t;
}

void printUserInputQueue(const queue<string>& userInputQueue) {
    InfoClass t('-', '|', '+');
    t.add("Order");
    t.add("Placa");
    t.add("Motor");
    t.add("Modelo");
    t.add("Año");
    t.add("Nombre");
    t.add("Apellido");
    t.add("DUI");
    t.add("Licencia");
    t.add("Seguro social");
    t.add("Telefono");
    t.add("Tipo de vehiculo");
    t.endOfRow();

    queue<string> tempQueue = userInputQueue; // Create a temporary queue to preserve the original queue
    int order = 1; // Start the order from 1

    while (!tempQueue.empty()) {
        t.add(to_string(order));
        t.add(tempQueue.front());
        tempQueue.pop();
        t.add(tempQueue.front());
        tempQueue.pop();
        t.add(tempQueue.front());
		tempQueue.pop();
        t.add(tempQueue.front());
        tempQueue.pop();
        t.endOfRow();
        order++;
    }

    t.setAlignment(2, InfoClass::Alignment::RIGHT);
    cout << "User Input Queue:\n";
    cout << t;
}

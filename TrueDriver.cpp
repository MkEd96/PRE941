#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<conio.h>
#include<queue>
#include "InfoClass.h"

//Prueba

using namespace std;

bool checkForItemInt(const vector<int>& arr, int data);
bool checkForItemString(const vector<string>& arr, const string& data);
void printTable(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year, const vector<string>& nombre, const vector<string>& apellido, const vector<int>& dui, const vector<int>& licencia, const vector<int>& isss, const vector<int>& tel);
void printTableEjecutiva(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year, const vector<string>& nombre, const vector<string>& apellido, const vector<int>& dui, const vector<int>& licencia, const vector<int>& isss, const vector<int>& tel);
void printTableTradicional(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year, const vector<string>& nombre, const vector<string>& apellido, const vector<int>& dui, const vector<int>& licencia, const vector<int>& isss, const vector<int>& tel);


int main(){
    char respuesta = '\0';
    int control;
    int opciones;
    int opcioneslista;
    vector<string> vtype; 
    queue<string> userInputQueue;
    int yearchecker;
    
    //U S E R   I N P U T S
    //Carros
	int placataxi;
    int yeartaxi;
    int type;
    string motortaxi;
    string modelotaxi;
    //Conductor
    string nombre;
    string apellido;
    int dui;
    int licencia;
    int numisss;
    int telefono;
    
    
    //V E C T O R E S   G E N E R A L E S
    //Carro
    vector<int> placa;
    vector<int> year;
    vector<string> motor;
    vector<string> modelo;
    //Conductor 
    vector<string> vnombre;
    vector<string> vapellido;
    vector<int> vdui;
    vector<int> vlicencia;
    vector<int> vnumisss;
    vector<int> vtelefono;
    
    //V E C T O R E S   T R A D I C I O N A L E S
    //Carro
    vector<int> placaTradicional;
    vector<int> yearTradicional;
    vector<string> motorTradicional;
    vector<string> modeloTradicional;
    //Conductor 
    vector<string> vnombreTradicional;
    vector<string> vapellidoTradicional;
    vector<int> vduiTradicional;
    vector<int> vlicenciaTradicional;
    vector<int> vnumisssTradicional;
    vector<int> vtelefonoTradicional;
    
    //V E C T O R E S   E J E C U T I V O
    //Carro
    vector<int> placaEjecutivo;
    vector<int> yearEjecutivo;
    vector<string> motorEjecutivo;
    vector<string> modeloEjecutivo;
    //Conductor 
    vector<string> vnombreEjecutivo;
    vector<string> vapellidoEjecutivo;
    vector<int> vduiEjecutivo;
    vector<int> vlicenciaEjecutivo;
    vector<int> vnumisssEjecutivo;
    vector<int> vtelefonoEjecutivo;
    
    //V E C T O R E S   E N   V I A J E
    //Carro
    vector<int> placaenviaje;
    vector<int> yearenviaje;
    vector<string> motorenviaje;
    vector<string> modeloenviaje;
    //Conductor 
    vector<string> vnombreenviaje;
    vector<string> vapellidoenviaje;
    vector<int> vduienviaje;
    vector<int> vlicenciaenviaje;
    vector<int> vnumisssenviaje;
    vector<int> vtelefonoenviaje;
    

    cout << "Bienvenido a TrueDrive" << endl;

    do {
        system("cls");
        cout << "Por favor seleccione una opción:\n\n";
        cout << "\t\t1. Ingresar nuevo vehículo y conductor" << endl;
        cout << "\t\t2. Ver lista de conductores" << endl;
        cout << "\t\t3. Comenzar Viaje" << endl;
        cout << "\t\t4. Terminar Viaje" << endl;
        cout << "\t\t5. Salir del programa" << endl << endl;
        cout << "Escribir su opción: ";
        cin >> opciones;

        switch (opciones) {
            case 1: //AGREGAR CONDUCTOR
        		//* * * D A T O S   D E L   V E H I C U L O * * *
        		
        		// YEAR ES INT (REPETIR)
        	
                do{
                cout << "Año: ";
                cin >> yeartaxi;
                	
                    if(yeartaxi>=2015) {
					
				    	//type="Ejecutiva";
				    	yearchecker = 1;
				    	yearEjecutivo.push_back(yeartaxi); 
				    	//ENVIARLO A QUEUE EJECUTIVO
                    } else if(yeartaxi>=2010 && yeartaxi<2015) {
					 	 //type="Tradicional";
					 	 yearchecker = 2;
					 	 yearTradicional.push_back(yeartaxi); 
					 	 //ENVIARLO A QUEUE TRADICIONAL
                    } else {
						cout<<"No es posible ingresar este vehiculo debido a la antiguedad...\n";
						yearchecker = 0;
						//REPETIR AÑO
					}
                } while (yearchecker==0);
				year.push_back(yeartaxi);
				
                //YEARCHEKER CATEGORIZA:
                
                //(0) ES DEMASIADO ANTIGUO
                //(1) EJECUTIVO
                //(2) TRADICIONAL
                
                switch (yearchecker) {
                case 1:
                	// PLACA ES INT (ÚNICO)
            	
                	do {
                    	cout << "Ingresando Vehículo Ejecutivo" << endl;     
                    	cout << "placa: ";
                    	cin >> placataxi;
                	} while (checkForItemInt(placa, placataxi));
                	placa.push_back(placataxi);
                	placaEjecutivo.push_back(placataxi);

                	cin.ignore();
                
                
                	// MOTOR ES STRING (REPETIR)

                	cout << "motor: ";                               
                	getline(cin, motortaxi);
					motor.push_back(motortaxi);
					motorEjecutivo.push_back(motortaxi);
                
                	// MODELO ES STRING (REPETIR)

                	cout << "modelo: ";
                	getline(cin, modelotaxi);
                	modelo.push_back(modelotaxi);
                	modeloEjecutivo.push_back(modelotaxi);
                
                	//DATOS DEL CONDUCTOR
                
                	//NOMBRE ES STRING (ÚNICO)
                
                	do{
                		cout<< "Ingresando datos del conductor...\n";
                		cout<< "Ingrese el nombre: ";
                		cin>>nombre;
					}while(checkForItemString(vnombre,nombre));
					vnombre.push_back(nombre);
					vnombreEjecutivo.push_back(nombre);
				
					//APELLIDO ES STRING (ÚNICO)
				
					do{
					cout<< "Ingrese el apellido: ";
					cin>>apellido;
					}while(checkForItemString(vapellido,apellido));
					vapellido.push_back(apellido);
					vapellidoEjecutivo.push_back(apellido);
                
                	//DUI ES INT (ÚNICO)
                
                	do{
                		cout<<"Ingrese el # de DUI sin guion: ";
                		cin>>dui;
					}while(checkForItemInt(vdui,dui));
					vdui.push_back(dui);
					vduiEjecutivo.push_back(dui);
				
					//LICENCIA (ÚNICO)
				
					do{
						cout<<"Ingresa el # de licencia sin guion: ";
						cin>>licencia;
					}while(checkForItemInt(vlicencia,licencia));
					vlicencia.push_back(licencia);
					vlicenciaEjecutivo.push_back(licencia);
				
					//SEGURO SOCIAL ES INT (ÚNICO)
				
					do{
						cout<< "Ingresa el numero de seguro social sin guiones: ";
						cin>>numisss;
					}while(checkForItemInt(vnumisss,numisss));
					vnumisss.push_back(numisss);
					vnumisssEjecutivo.push_back(numisss);
				
					//NÚMERO DE TELÉFONO ES INT (ÚNICO)
				
					do{
						cout<< "Ingresa el numero de telefono: ";
						cin>>telefono;
					}while(checkForItemInt(vtelefono,telefono));
					vtelefono.push_back(telefono);
					vtelefonoEjecutivo.push_back(telefono);
                
                	break;
                		
                	case 2:
                	
					// PLACA ES INT (ÚNICO)
            	
                	do {
                    	cout << "Ingresando Vehículo Tradicional" << endl;     
                    	cout << "placa: ";
                    	cin >> placataxi;
                	} while (checkForItemInt(placa, placataxi));
                	placa.push_back(placataxi);
                	placaTradicional.push_back(placataxi);

                	cin.ignore();
                
                
                	// MOTOR ES STRING (REPETIR)

                	cout << "motor: ";                               
                	getline(cin, motortaxi);
					motor.push_back(motortaxi);
					motorTradicional.push_back(motortaxi);
                
                	// MODELO ES STRING (REPETIR)

                	cout << "modelo: ";
                	getline(cin, modelotaxi);
                	modelo.push_back(modelotaxi);
                	modeloTradicional.push_back(modelotaxi);
                
                	//DATOS DEL CONDUCTOR
                
                	//NOMBRE ES STRING (ÚNICO)
                
                	do{
                		cout<< "Ingresando datos del conductor...\n";
                		cout<< "Ingrese el nombre: ";
                		cin>>nombre;
					}while(checkForItemString(vnombre,nombre));
					vnombre.push_back(nombre);
					vnombreTradicional.push_back(nombre);
				
					//APELLIDO ES STRING (ÚNICO)
				
					do{
					cout<< "Ingrese el apellido: ";
					cin>>apellido;
					}while(checkForItemString(vapellido,apellido));
					vapellido.push_back(apellido);
					vapellidoTradicional.push_back(apellido);
                
                	//DUI ES INT (ÚNICO)
                
                	do{
                		cout<<"Ingrese el # de DUI sin guion: ";
                		cin>>dui;
					}while(checkForItemInt(vdui,dui));
					vdui.push_back(dui);
					vduiTradicional.push_back(dui);
				
					//LICENCIA (ÚNICO)
				
					do{
						cout<<"Ingresa el # de licencia sin guion: ";
						cin>>licencia;
					}while(checkForItemInt(vlicencia,licencia));
					vlicencia.push_back(licencia);
					vlicenciaTradicional.push_back(licencia);
				
					//SEGURO SOCIAL ES INT (ÚNICO)
				
					do{
						cout<< "Ingresa el numero de seguro social sin guiones: ";
						cin>>numisss;
					}while(checkForItemInt(vnumisss,numisss));
					vnumisss.push_back(numisss);
					vnumisssTradicional.push_back(numisss);
				
					//NÚMERO DE TELÉFONO ES INT (ÚNICO)
				
					do{
						cout<< "Ingresa el numero de telefono: ";
						cin>>telefono;
					}while(checkForItemInt(vtelefono,telefono));
					vtelefono.push_back(telefono);
					vtelefonoTradicional.push_back(telefono);
                
                	break;
                				
				}
                
            	break;

            case 2:
                // Ver lista de vehículos y conductores
                cout << "¿Cual lista desea ver?:\n\n";
        		cout << "\t\t1. Lista de conductores totales" << endl;
        		cout << "\t\t2. Lista de conductores ejecutivos disponibles" << endl;
        		cout << "\t\t3. Lista de conductores Tradicionales disponibles" << endl;
        		cout << "\t\t4. Lista de conductores en viaje" << endl;
                
                cout << "Seleccionar (1,2,3 o 4): ";
        		cin>>opcioneslista;
        		
        		switch(opcioneslista) {
        			case 1:
        				printTable(placa, motor, modelo, year, vnombre, vapellido, vdui, vlicencia, vnumisss, vtelefono);//Imprime tabla completa
        				break;
        			case 2:
        				printTableEjecutiva(placaEjecutivo, motorEjecutivo, modeloEjecutivo, yearEjecutivo, vnombreEjecutivo, vapellidoEjecutivo, vduiEjecutivo, vlicenciaEjecutivo, vnumisssEjecutivo, vtelefonoEjecutivo);//Imprime ejecutiva disponible
        				break;
        			case 3:
        				printTableTradicional(placaTradicional, motorTradicional, modeloTradicional, yearTradicional, vnombreTradicional, vapellidoTradicional, vduiTradicional, vlicenciaTradicional, vnumisssTradicional, vtelefonoTradicional);//Imprime tradicional disponible
        				break;
        			case 4:
        				break;
        			//Imprimirá los que estan en viaje
				}

                //printUserInputQueue(userInputQueue);  
                break;

            case 3:
                //Iniciar viaje
                cout<<"Seleccione el tipo de vehiculo en el que desea viajar: "<<endl;
                cout<<"1. Ejecutivo."<<endl;
                cout<<"2. Tradicional."<<endl;
                cin>>type;
                
            	switch(type){
            		case 1: 
            			//printTableEjecutiva(placaEjecutivo, motorEjecutivo, modeloEjecutivo, yearEjecutivo, vnombreEjecutivo, vapellidoEjecutivo, vduiEjecutivo, vlicenciaEjecutivo, vnumisssEjecutivo, vtelefonoEjecutivo);
            			
				}
                
                break;

            case 4:
                
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
void printTable(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year, const vector<string>& nombre, const vector<string>& apellido, const vector<int>& dui, const vector<int>& licencia, const vector<int>& isss, const vector<int>& tel) {
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
    t.add("ISSS");
    t.add("Telefono");
    t.endOfRow();

    for (int i = 0; i < placa.size(); i++) {
        t.add(to_string(i+1)); //agrega el orden
        t.add(to_string(placa[i])); //agrega el PLACA
        t.add(motor[i]); //agrega el MOTOR
        t.add(modelo[i]); //agrega el MODELO
        t.add(to_string(year[i])); //agrega el AÑO
        t.add(nombre[i]);
        t.add(apellido[i]);
        t.add(to_string(dui[i]));
        t.add(to_string(licencia[i]));
        t.add(to_string(isss[i]));
        t.add(to_string(tel[i]));
        t.endOfRow();
    }

    t.setAlignment(2, InfoClass::Alignment::RIGHT);
    cout << t;
}
void printTableEjecutiva(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year, const vector<string>& nombre, const vector<string>& apellido, const vector<int>& dui, const vector<int>& licencia, const vector<int>& isss, const vector<int>& tel) {
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
    t.add("ISSS");
    t.add("Telefono");
    t.endOfRow();

    for (int i = 0; i < placa.size(); i++) {
        t.add(to_string(i+1)); //agrega el orden
        t.add(to_string(placa[i])); //agrega el PLACA
        t.add(motor[i]); //agrega el MOTOR
        t.add(modelo[i]); //agrega el MODELO
        t.add(to_string(year[i])); //agrega el AÑO
        t.add(nombre[i]);
        t.add(apellido[i]);
        t.add(to_string(dui[i]));
        t.add(to_string(licencia[i]));
        t.add(to_string(isss[i]));
        t.add(to_string(tel[i]));
        t.endOfRow();
    }

    t.setAlignment(2, InfoClass::Alignment::RIGHT);
    cout << t;
}
void printTableTradicional(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year, const vector<string>& nombre, const vector<string>& apellido, const vector<int>& dui, const vector<int>& licencia, const vector<int>& isss, const vector<int>& tel) {
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
    t.add("ISSS");
    t.add("Telefono");
    t.endOfRow();

    for (int i = 0; i < placa.size(); i++) {
        t.add(to_string(i+1)); //agrega el orden
        t.add(to_string(placa[i])); //agrega el PLACA
        t.add(motor[i]); //agrega el MOTOR
        t.add(modelo[i]); //agrega el MODELO
        t.add(to_string(year[i])); //agrega el AÑO
        t.add(nombre[i]);
        t.add(apellido[i]);
        t.add(to_string(dui[i]));
        t.add(to_string(licencia[i]));
        t.add(to_string(isss[i]));
        t.add(to_string(tel[i]));
        t.endOfRow();
    }

    t.setAlignment(2, InfoClass::Alignment::RIGHT);
    cout << t;
}

/* void printUserInputQueue(const queue<string>& userInputQueue) {
    InfoClass t('-', '|', '+');
    t.add("Order");
    t.add("Placa");
    t.add("Motor");
    t.add("Modelo");
    t.add("Año");
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
} */
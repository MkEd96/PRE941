#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<conio.h>
#include"Functions.hpp"
#include"InfoClass.h"
//#include"structs.hpp"
using namespace std;

int main(){

//structs
struct taxi{
    vector<int> anio;
    vector<int> placa;
    vector<int> motor;
    vector<string> tipo;
    vector<string> modelo;

    //Datos del conductor
    vector<string> nombre;
    vector<int> licencia;
    vector<int> telefono;
};

//Datos de vehículo Ejecutivo. Cola de espera

struct ejecutivo{
    vector<int> vectorAnioEjecutivo;
    vector<int> VectorPlacaEjecutivo;
    vector<int> VectorMotorEjecutivo;
    vector<string> VectorModeloEjecutivo;
    vector<string> VectorNombreEjecutivo;
    vector<string> VectortipoEjecutivo;
    vector<int> VectorLicenciaEjecutivo;
    vector<int> VectorTelefonoEjecutivo;
};

//Datos de vehículo Tradicional. Cola de espera

struct tradicional{
    vector<int> vectorAnioTradicional;
    vector<int> VectorPlacaTradicional;
    vector<int> VectorMotorTradicional;
    vector<string> VectorModeloTradicional;
    vector<string> VectorNombreTradicional;
    vector<string> VectortipoTradicional;
    vector<int> VectorLicenciaTradicional;
    vector<int> VectorTelefonoTradicional;
};

//Datos cuando los vehiculos ejecutivos realicen un viaje

struct ejecutivoViaje{
    vector<int> anioViajeEjecutivo;
    vector<int> placaViajeEjecutivo;
    vector<int> motorViajeEjecutivo;
    vector<string> modeloViajeEjecutivo;
    vector<string> nombreViajeEjecutivo;
    vector<string> tipoViajeEjecutivo;
    vector<int> licenciaViajeEjecutivo;
    vector<int> telefonoViajeEjecutivo;
    vector<string> DestinoEjecutivo;
};

//Datos cuando los vehiculos tradicionales realicen un viaje

struct tradicionalViaje{
    vector<int> anioViajeTradicional;
    vector<int> placaViajeTradicional;
    vector<int> motorViajeTradicional;
    vector<string> modeloViajeTradicional;
    vector<string> nombreViajeTradicional;
    vector<string> tipoViajeTradicional;
    vector<int> licenciaViajeTradicional;
    vector<int> telefonoViajeTradicional;
    vector<string> DestinoTradicional;
};

    //Variables de control
    int opciones;
    char continuar;

    //Inputs
    int anio;
    int placa;
    int motor;
    string modelo;
    //string tipo;    //Se clasifica de manera automática según la antiguedad del vehículo

    //Datos del conductor
    string nombre;
    int licencia;
    int telefono;

    //Variables creadas a partir de las estructuras definidas en Functions.h

    taxi T;                 //Datos generales de todos los taxis
    ejecutivo E;            //Datos de los taxis ejecutivos
    tradicional Tr;          //Datos de los taxis tradicionales
    ejecutivoViaje EV;      //Taxis ejecutivos en viaje
    tradicionalViaje TV;    //Taxis tracidionales en viaje
    
    //Opciones
    
    do{

    cout<<"Bienvenido a TrueDriver. Seleccione una opción."<<endl;
    cout<<"1. Ingresar un nuevo taxi."<<endl;
    cout<<"2. Ver lista de vehículos disponibles."<<endl;
    cout<<"3. Solicitar un viaje."<<endl;
    cout<<"4. Cancelar un viaje"<<endl;
    cout<<"5. Mostrar taxis en viaje"<<endl;
    cout<<"6. Buscar un taxi en viaje"<<endl;
    cout<<"7. Salir"<<endl;
    cin>>opciones;
    cout<<endl;

    switch(opciones){
        case 1:
        //Ingresar un nuevo vehículo

            do{
            cout<<"Ingrese el anio. No se permiten vehiculos anteriores al 2010: ";
            cin>>anio;
            T.anio.push_back(anio);
            }while(anio<2010);
            //Se define el tipo de vehículo en base a la antiguedad
            
            if(anio >= 2015){
                T.tipo.push_back("Ejecutivo");
                E.vectorAnioEjecutivo.push_back(anio);   
                cout<<"Ingresando vehiculo ejecutivo.."<<endl;

                //Ingresando datos de ejecutivo
                do{
                cout<<"Ingrese el numero de placa: ";
                cin>>placa;
                }while(CheckArrayInt(T.placa,placa));
                T.placa.push_back(placa);
                E.VectorPlacaEjecutivo.push_back(placa);
                cout<<endl;

                do{
                cout<<"Ingrese el # de motor: ";
                cin>>motor;
                }while(CheckArrayInt(T.motor,motor));
                T.motor.push_back(motor);
                E.VectorMotorEjecutivo.push_back(motor);
                cout<<endl;

                cout<<"Ingrese el modelo: ";
                cin>>modelo;
                T.modelo.push_back(modelo);
                E.VectorModeloEjecutivo.push_back(modelo);
                cout<<endl;

                //Datos del conductor
                do{
                cout<<"Ingrese el nombre del conductor: ";
                cin>>nombre;
                }while(CheckArrayString(T.nombre, nombre));
                T.nombre.push_back(nombre);
                E.VectorNombreEjecutivo.push_back(nombre);
                cout<<endl;

                do{
                cout<<"Ingrese el # de licencia: ";
                cin>>licencia;
                }while(CheckArrayInt(T.licencia, licencia));
                T.licencia.push_back(licencia);
                E.VectorLicenciaEjecutivo.push_back(licencia);
                cout<<endl;

                do{
                cout<<"Ingrese el # de telefono: ";
                cin>>telefono;
                }while(CheckArrayInt(T.telefono,telefono));
                T.telefono.push_back(telefono);
                E.VectorTelefonoEjecutivo.push_back(telefono);
                cout<<endl;

                cout<<"¿Desea continuar? (Y/N): ";
                cin>>continuar; 

            }
            if(anio < 2015){
                T.tipo.push_back("Tradicional");
                Tr.vectorAnioTradicional.push_back(anio);
                cout<<"Ingresando vehiculo tradicional.."<<endl;

                //Ingresando datos de vehiculo tradicional
                do{
                cout<<"Ingrese el numero de placa: ";
                cin>>placa;
                }while(CheckArrayInt(T.placa, placa));
                T.placa.push_back(placa);
                Tr.VectorPlacaTradicional.push_back(placa);
                cout<<endl;

                do{
                cout<<"Ingrese el # de motor: ";
                cin>>motor;
                }while(CheckArrayInt(T.motor, motor));
                T.motor.push_back(motor);
                Tr.VectorMotorTradicional.push_back(motor);
                cout<<endl;

                cout<<"Ingrese el modelo: ";
                cin>>modelo;
                T.modelo.push_back(modelo);
                Tr.VectorModeloTradicional.push_back(modelo);
                cout<<endl;

                //Datos del conductor
                do{
                cout<<"Ingrese el nombre del conductor: ";
                cin>>nombre;
                }while(CheckArrayString(T.nombre,nombre));
                T.nombre.push_back(nombre);
                Tr.VectorNombreTradicional.push_back(nombre);
                cout<<endl;

                do{
                cout<<"Ingrese el # de licencia: ";
                cin>>licencia;
                }while(CheckArrayInt(T.licencia,licencia));
                T.licencia.push_back(licencia);
                Tr.VectorLicenciaTradicional.push_back(licencia);
                cout<<endl;

                do{
                cout<<"Ingrese el # de telefono: ";
                cin>>telefono;
                }while(CheckArrayInt(T.telefono,telefono));
                T.telefono.push_back(telefono);
                Tr.VectorTelefonoTradicional.push_back(telefono);
                cout<<endl;

                cout<<"¿Desea continuar? (Y/N): ";
                cin>>continuar;
                cout<<endl;
            }
            
        break;
    
        case 2:
            //Lista de vehículos disponibles

            cout<<"Vehiculos Ejecutivos..."<<endl;
           

        break;
    
    }
  }while(continuar == 'Y' || continuar == 'y');
}
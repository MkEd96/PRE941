#include <string>
#include <vector>
#include <iostream>
#include "Functions.hpp"

//Verifica si el elemento ya existe dentro del vector, tanto en int como string

bool CheckArrayInt(const std::vector<int>& Lista, int Prueba){
    for(int i=0;  i < Lista.size(); i++){
        if (Lista[i] == Prueba){
            std::cout<<"No se permiten datos duplicados. Ingrese el dato nuevamente..."<<std::endl;
            return true;
        }
    }
    return false;
}

bool CheckArrayString(const std::vector<std::string>& Lista,const std::string& Prueba){
    for(int i=0;  i < Lista.size(); i++){
        if (Lista[i] == Prueba){
            std::cout<<"No se permiten datos duplicados. Ingrese el dato nuevamente..."<<std::endl;
            return true;
        }
    }
    return false;
}

//Imprime un vector mediante InfoClass

//void ShowVector(std::vector<int> anio, std::vector<int> placa, std::vector<int> motor, std::vector<std::string> modelo, )
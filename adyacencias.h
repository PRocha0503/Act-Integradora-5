#ifndef ADYACENCIAS_H
#define ADYACENCIAS_H
#include "incidencia.h"
#include<vector>
using std::vector;


struct Adyacencia{
    Ip origen;
    vector<Incidencia> adyacencias;
    Adyacencia(Ip);
    Adyacencia();
};

Adyacencia::Adyacencia(){
}

Adyacencia::Adyacencia(Ip i){
    origen = i;
}

bool operator>(Adyacencia entrada1, Adyacencia entrada2){
    if(entrada1.adyacencias.size()>entrada2.adyacencias.size()){
        return true;
    }
    return false;
}
bool operator<(Adyacencia entrada1, Adyacencia entrada2){
    if(entrada1.adyacencias.size()<entrada2.adyacencias.size()){
        return true;
    }
    return false;
}
struct Hash{
    Ip origen;
    vector<Incidencia> adyacencias;
    int ocupado;
    Hash();
    Hash(vector<Incidencia>);
};

Hash::Hash(){
    ocupado = -1;
}

#endif
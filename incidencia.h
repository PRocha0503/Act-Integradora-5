#ifndef INCIDENCIA_H
#define INCIDENCIA_H
#include "formatoHora.h"
#include "ip.h"

class Incidencia{
    private:
        formatoHora fecha;
        Ip ip;
        string falla;

    public:
        Incidencia();
        Incidencia(formatoHora,Ip,string);
        string sumUp();
};

Incidencia::Incidencia(){
    fecha = formatoHora();
    ip = Ip();
    falla = ""; 
}

Incidencia::Incidencia(formatoHora h,Ip i,string f){
    fecha = h;
    ip = i;
    falla = f; 
}

string Incidencia::sumUp(){
    string regreso = fecha.convertirDeRegreso()+" "+ std::to_string(fecha.dia) +" "+std::to_string(fecha.hora)+":"+std::to_string(fecha.minuto)+":" +std::to_string(fecha.segundo)+" "+ip.getSting()+" "+falla;
    return regreso;
}

#endif
#ifndef FORMATOHORA_H
#define FORMATOHORA_H
#include<string>
#include <sstream>
#include <algorithm>
#include<iostream>
using std::string;
using std::stringstream;

struct formatoHora{
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;

    formatoHora(string,int,string);
    formatoHora();
    void printHora();
    string convertirDeRegreso();
    private:
        int convertirMes(string);   
};

formatoHora::formatoHora(){
    mes = 0;
    dia = 0;
    hora = 0;
    minuto = 0;
    segundo = 0;
}

int formatoHora::convertirMes(string m)
{
    if (m == "Jan")
    {
        return 1;
    }
    else if (m == "Feb")
    {
        return 2;
    }
    else if (m == "Mar")
    {
        return 3;
    }
    else if (m == "Apr")
    {
        return 4;
    }
    else if (m == "May")
    {
        return 5;
    }
    else if (m == "Jun")
    {
        return 6;
    }
    else if (m == "Jul")
    {
        return 7;
    }
    else if (m == "Aug")
    {
        return 8;
    }
    else if (m == "Sep")
    {
        return 9;
    }
    else if (m == "Oct")
    {
        return 10;
    }
    else if (m == "Nov")
    {
        return 11;
    }
    else if (m == "Dec")
    {
        return 12;
    }
    return 0;
}




formatoHora::formatoHora(string m,int d,string h){
    mes = convertirMes(m);
    dia = d;
    int _hora;
    int _minuto;
    int _segundo;
    h.erase(remove(h.begin(), h.end(), ':'), h.end());
    string stringHora, stringMinuto, stringSegundo;
    stringHora = h.substr(0, 2);
    stringMinuto = h.substr(2, 2);
    stringSegundo = h.substr(4, 2);
    stringstream conv(stringHora);
    conv >> _hora;
    stringstream conv1(stringMinuto);
    conv1 >> _minuto;
    stringstream conv2(stringSegundo);
    conv2 >> _segundo;
    hora = _hora;
    minuto = _minuto;
    segundo = _segundo;
}

void formatoHora::printHora(){
    std::cout<<"Mes: "<<mes<<std::endl;
    std::cout<<"Dia: "<<dia<<std::endl;
    std::cout<<"Hora: "<<hora<<std::endl;
    std::cout<<"Minuto: "<<minuto<<std::endl;
    std::cout<<"Segundo: "<<segundo<<std::endl;
}
string formatoHora::convertirDeRegreso()
{
    if(mes==1){
        return "Jan";
    }
    else if(mes==2){
        return "Feb";
    }
    else if(mes==3){
        return "Mar";
    }
    else if(mes==4){
        return "Apr";
    }
    else if(mes==5){
        return "May";
    }
    else if(mes==6){
        return "Jun";
    }
    else if(mes==7){
        return "Jul";
    }
    else if(mes==8){
        return "Aug";
    }
    else if(mes==9){
        return "Sep";
    }
    else if(mes==10){
        return "Oct";
    }
    else if(mes==11){
        return "Nov";
    }
    else if(mes==12){
        return "Dec";
    }
    return "NADA";
}
#endif
#ifndef GRAFO_H
#define GRAFO_H
#include <iterator>
#include <vector>
#include <sstream>
#include <fstream>
#include "adyacencias.h"
using std::vector;
using std::ifstream;
using std::istringstream;

class Bitacora{
    private:
        vector<Adyacencia> adj;
        vector<Hash> hash;
        void heapify(int,int);
        void intercambiar(int,int);
        int binaria(Ip);
        int makeKey(int);
    public:
        Bitacora(string);
        void writeConections(string);
        void heapSort();
        void mostConections();
        void ordenada();
        void createHash();
        void getHashOut();
        vector<Incidencia> singleIp(string);
};

Bitacora::Bitacora(string archivo){
    //Varaibles para leer el archivo
    string line;
    string ipTemporal;
    string mes;
    int dia;
    string hora;
    string ipOrigen;
    string ipDestino;
    string razon;
    string razon1;
    string razon2;
    string razon3;
    string razon4;
    string razon5;
    //Para los for loops
    int numeroIps;
    int numeroIncidencias;
    ifstream bitacora(archivo);
    if (bitacora.is_open()){
        getline(bitacora,line);
        istringstream ss(line);
        ss>>numeroIps>>numeroIncidencias;
        for(int i = 0;i<numeroIps;i++){
            //Leer linea
            getline(bitacora,line);
            istringstream ss(line);
            ss >> ipTemporal;
            //Agregar a lista de ips
            Ip ipBasura(ipTemporal);
            Adyacencia adBasura(ipBasura);
            adj.push_back(adBasura);
        }
        for(int i = 0; i<numeroIncidencias;i++){
            getline(bitacora,line);
            istringstream ss(line);
            ss >>mes>>dia>>hora>>ipOrigen>>ipDestino>>razon >> razon1 >> razon2 >> razon3 >> razon4 >> razon5;
            string razonFinal;
            //Crear lo necesario para la incidencia
            razonFinal = razon + " " + razon1 + " " + razon2 + " " + razon3 + " " + razon4 + " " + razon5;
            formatoHora horaBasura(mes,dia,hora);
            Ip iDestino(ipDestino);
            //Crear una Incidencia con esos datos
            Incidencia nIncidencia(horaBasura,iDestino,razonFinal);
            //Encontar el ip de origen en el vector y agregarla en el vector de adyacencias
            Ip origen(ipOrigen);
            // int pos = binaria(origen);
            // adj[pos].adyacencias.push_back(nIncidencia);
            for(int j = 0;j<adj.size();j++){;
                // Ip origen(ipOrigen);
                if(origen.getNum() == adj[j].origen.getNum()){
                    adj[j].adyacencias.push_back(nIncidencia);
                    break;
                }
            }
            //Imprimir Progreso
            std::cout<<i <<" de "<< numeroIncidencias<<std::endl;
        }
        bitacora.close();
    };
}

void Bitacora::writeConections(string nombre){
    std::cout<<"Escribiendo en archvo"<<std::endl;
    std::ofstream outfile (nombre);
    for(int i = 0;i<adj.size();i++){
        outfile<<adj[i].origen.getSting()<<" :"<<std::endl;
        for(int j= 0;j<adj[i].adyacencias.size();j++){
            outfile <<adj[i].adyacencias[j].sumUp()<<std::endl;
        }
    }
    outfile.close();
}

void Bitacora::intercambiar(int i,int j){
    std::cout<<"Intercambiando"<<std::endl;
    Adyacencia temporal;
    temporal = adj[i];
    adj[i] = adj[j];
    adj[j] = temporal;
}

void Bitacora::heapify(int size,int i)
{
    
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < size && adj[l] < adj[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < size && adj[r] < adj[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        intercambiar(i, largest);
 
        // Recursively heapify the affected sub-tree
        heapify(size, largest);
    }
}


void Bitacora::heapSort()
{
    std::cout<<"Haciendo Heap Sort"<<std::endl;
    for (int i = adj.size() / 2 - 1; i >= 0; i--)
        heapify(adj.size(),i);
    for (int i = adj.size() - 1; i > 0; i--) { ;
        intercambiar(0, i);
        heapify(i,0);
    }
}


void Bitacora::mostConections(){
    std::cout<<"Buscando Maximo"<<std::endl;
    std::cout<<" El Ip con mas conexiones es: "<<adj[0].origen.getSting()<<" y tiene "<<adj[0].adyacencias.size()<< " conexiones "<<std::endl;
    for(int i = 0;i<5;i++){
        std::cout<<i<<" "<<adj[i].origen.getSting()<<" y tiene "<<adj[i].adyacencias.size()<< " conexiones "<<std::endl;
    }
}

int Bitacora::makeKey(int num){
    int key = (num) % adj.size();
    return key;
}

void Bitacora::createHash(){
    int col = 0;
    for(int i = 0; i<adj.size();i++){
        hash.push_back(Hash());
    }
    for(int i = 0;i<adj.size();i++){
        int num = adj[i].origen.getNum();
        int key = makeKey(num);
        if (hash[key].ocupado == -1){
            hash[key].ocupado = 1;
            hash[key].origen = adj[i].origen;
            hash[key].adyacencias = adj[i].adyacencias;
        }
        else{
            col++;
            for (int j = 0; j < adj.size(); j++)
            {
                int t = (key + j * j) % adj.size();
                
                if (hash[t].ocupado == -1)
                {
                    hash[t].ocupado = 1;
                    hash[t].origen = adj[i].origen;
                    hash[t].adyacencias = adj[i].adyacencias;
                    break;
                }
            }
        }
    }
    std::cout<<col<<std::endl;
}

void Bitacora::getHashOut(){
    std::cout<<"Escribiendo en archvo"<<std::endl;
    std::ofstream outfile ("Hash.txt");
    for(int i = 0;i<hash.size();i++){
        outfile<<hash[i].origen.getSting()<<" :"<<std::endl;
        for(int j= 0;j<hash[i].adyacencias.size();j++){
            outfile <<hash[i].adyacencias[j].sumUp()<<std::endl;
        }
    }
    outfile.close();
}
vector<Incidencia> Bitacora::singleIp(string find){
    Ip ipFind(find);
    int num = ipFind.getNum();
    int key = makeKey(num);
    if (hash[key].origen.getNum() == num){
        return hash[key].adyacencias;
    }
    else{
        for (int j = 0; j < hash.size(); j++){
            int t = (key + j * j) % hash.size();
            if (hash[key].origen.getNum() == num){
                return hash[key].adyacencias;
            }
        }
    }
}


// int Grafo::binaria(Ip k) {
//     int min = 0;
//     int max = adj.size()-1;
//     int mitad;
//     while(min < max){
//         mitad = (min+max)/2;
//         if(k.getNum()==adj[mitad].origen.getNum()){
//             std::cout<<k.getNum()<<"=="<<adj[mitad].origen.getNum()<<std::endl;
//             return mitad;
//         }
//         else if(k.getNum()<adj[mitad].origen.getNum()){
//             max = mitad -1;
//         }
//         else{
//             min = mitad + 1;
//         }
//     }
//     std::cout<<k.getNum()<<std::endl;
//     std::cout<<adj[mitad].origen.getNum()<<std::endl;
//     std::cout<<"Sin coincidencias"<<std::endl;
//     return 0;
// }

// void Grafo::ordenada(){
//     int contador = 0;
//     for(int i = 0;i<adj.size();i++){
//         if(adj[i].origen.getNum()<adj[i+1].origen.getNum()){
//             contador++;
//         }else{
//             std::cout<<adj[i].origen.getNum()<<" No es mas chico que"<<adj[i+1].origen.getNum()<<std::endl;
//             std::cout<<"Pos "<<i<<std::endl;
//         }
//     }
//     if(contador==adj.size()){
//         std::cout<<" Ordenada"<<std::endl;
//     }
//     std::cout<<contador<<std::endl;
// }

#endif
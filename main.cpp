#include "bitacora.h"
using namespace std;
int main(){
    Bitacora b("bitacoraGrafos.txt");
    b.writeConections("Conexiones.txt");
    b.heapSort();
    b.mostConections();
    b.createHash();
    b.getHashOut();
    vector<Incidencia> s = b.singleIp("36.29.138.97");
    for(int i = 0;i<s.size();i++){
        cout<<s[i].sumUp()<<std::endl;
    }
    return 0;
}
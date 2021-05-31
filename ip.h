#ifndef IP_H
#define IP_H
#include<iostream>
#include <string>
#include <algorithm>

using std::string;

class Ip
{
private:
    long numIp;
    string stringIp;
    long convertirIP(string);
public:
    Ip();
    Ip(string);
    string getSting();
    long getNum();
    void printIp();
};

Ip::Ip(){
    stringIp = "";
    numIp = 0;
}


long Ip::convertirIP(string ip){
    if(ip == ""){
        return 0;
    }
    ip = ip.substr(0, ip.find(":", 0));
    ip.erase(std::remove(ip.begin(), ip.end(), '.'), ip.end());
    long intip = stol(ip);
    return intip;
    } 

Ip::Ip(string sip){
    stringIp = sip;
    numIp = convertirIP(sip);
}

string Ip::getSting(){
    return stringIp;
}

long Ip::getNum(){
    return numIp;
}

void Ip::printIp(){
    std::cout<<"Ip original: "<<stringIp<<std::endl;
    std::cout<<"Ip num: "<<numIp<<std::endl;
}

#endif

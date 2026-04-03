#include <iostream>
#include "sensor.h"

using namespace std;

Sensor::Sensor(int id, string tipo, string localizacao, float ultimaLeitura ){
    this->id = id;
    this->tipo = tipo;
    this->localizacao = localizacao;
    this->ultimaLeitura = 0;
}

int Sensor::get_id(){
    return id;
}
string Sensor::get_tipo(){
    return tipo;
}
string Sensor::get_localizacao(){
    return localizacao;
}
float Sensor::get_ultimaLeitura(){
    return ultimaLeitura;
}

void Sensor::set_id(int id){
    this->id = id;
}
void Sensor::set_tipo(string tipo){
    this->tipo = tipo;
}
void Sensor::set_localizacao(string localizacao){
    this->localizacao = localizacao;
}
void Sensor::set_ultimaLeitura(float ultimaLeitura){
    this->ultimaLeitura = ultimaLeitura;
}

void Sensor::exibir(){

    cout<<"========\n id: " << get_id()<<endl;
    cout<<"tipo: " << get_tipo() <<endl;
    cout<<"localização: " << get_localizacao()<<endl;
    cout<<"última leitura: " << get_ultimaLeitura()<<"\n========"<<endl;
}
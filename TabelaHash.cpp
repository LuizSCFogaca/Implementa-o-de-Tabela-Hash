#include <iostream>
#include <ctime>
#include "tabelaHash.h"
using namespace std;

TabelaHash::TabelaHash(){
    for(int i= 0; i < 10000; i++){
        tabelaHash[i].set_id(-1);
    }
}

int TabelaHash::get_contCol(){
    return contCol;
}

void TabelaHash::insert(Sensor sensor){//insert na tabela utilizando o calculo de sondagem dupla
    int i = 0;
    while(i<10000){
        int M = 10000;
        int h1 = sensor.get_id() % M;
        int h2 = 1+(sensor.get_id() % (M -1));
        int pos = (h1 + i*h2) % M;
        if(tabelaHash[pos].get_id() == -1 || tabelaHash[pos].get_id() == -11){
            tabelaHash[pos] = sensor;
            return;
        }else{
            i++;
            contCol++;
        }
    }
    cout<<"Tabela cheia"<<endl<<endl;
}

bool TabelaHash::existeId(int id){
    int i = 0;
    while(i < 10000){
        int M = 10000;
        int h1 = id % M;
        int h2 = 1+(id % (M -1));
        int pos = (h1 + i*h2) % M;

        if(tabelaHash[pos].get_id() == id){
            return true;
        }else if(tabelaHash[pos].get_id() == -1)
            return false;
        else
            i++;
    }
    return false;
}

void TabelaHash::search(int id){
    int i = 0;
    while(i< 10000){
        int M = 10000;
        int h1 = id % M;
        int h2 = 1+ (id % (M -1));
        int pos = (h1 + i*h2) % M;

        if(tabelaHash[pos].get_id() == id){
            tabelaHash[pos].exibir();
            cout<<"pos:"<< pos<<endl<<endl;
            return;
        }else if(tabelaHash[pos].get_id() == -11)
            i++;
        else if(tabelaHash[pos].get_id() == -1){
            cout<<"Não há nenhum sensor com o id: "<<id<<endl<<endl;
            return;
        }else 
            i++;
    }
    cout<<"Não há nenhum sensor com o id: "<<id;
}

void TabelaHash::deletar(int id){
    int i =0;
    while(i< 10000){
        int M = 10000;
        int h1 = id % M;
        int h2 = 1+ (id % (M -1));
        int pos = (h1 + i*h2) % M;

        if(tabelaHash[pos].get_id() == id){
            tabelaHash[pos].set_id(-11);
            cout<<"sensor deletado com sucesso"<<endl<<endl;
            return;
        }else if(tabelaHash[pos].get_id() == -11)
            i++;
        else if(tabelaHash[pos].get_id() == -1){
            cout<<"Não há nenhum sensor com esse id"<<endl<<endl;
            return;
        }else
            i++;
    }
    cout<<"Não há nenhum sensor com esse id"<<endl<<endl;
}

void TabelaHash::atualizarInfo(int id, float leitura){
    int i = 0;
    while(i<10000){
        int M = 10000;
        int h1 = id % M;
        int h2 = 1+ (id % (M -1));
        int pos = (h1 + i*h2) % M;

        if(tabelaHash[pos].get_id() == id){
            tabelaHash[pos].set_ultimaLeitura(leitura);
            cout<<"sensor atualizado com sucesso"<<endl<<endl;
            return;
        }else if(tabelaHash[pos].get_id() == -11)
            i++;
        else if(tabelaHash[pos].get_id() == -1){
            cout<<"Não há nenhum sensor com esse id para atualizar"<<endl<<endl;
            return;
        }else
            i++;
    }
    cout<<"Não há nenhum sensor com esse id para atualizar"<<endl<<endl;
}

void TabelaHash::exibirTabelaHash(){
    for(int i = 0; i< 10000; i++){
        if(tabelaHash[i].get_id() != -1 && tabelaHash[i].get_id() != -11){
            cout <<"Sensor["<<i<<"]: "<< " id: "<<tabelaHash[i].get_id() <<" tipo: " << tabelaHash[i].get_tipo()<<
            " localização: "<<tabelaHash[i].get_localizacao()<< " última leitura: " << tabelaHash[i].get_ultimaLeitura()<< endl;
        }
    }
}
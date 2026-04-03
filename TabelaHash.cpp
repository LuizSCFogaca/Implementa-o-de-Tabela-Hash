#include <iostream>
#include <ctime>
#include "tabelaHash.h"

void TabelaHash::insert(Sensor sensor){//insert na tabela utilizando o calculo de sondagem dupla
    int i = 0;
    while(i < 1000){
        int M = 1000;
        int h1 = sensor.get_id() % M;
        int h2 = 1+(sensor.get_id() % (M -1));
        int pos = (h1 + i*h2) % M;

        if(tabelaHash[pos].get_id() == -1)
            tabelaHash[pos] = sensor;
        else
            i++;
    }
}

void TabelaHash::search(int id){
    for(int i = 0; i<1000; i++){
        int M = 1000;
        int h1 = id % M;
        int h2 = 1+ (id % (M -1));
        int pos = (h1 + i*h2) % M;

        if(tabelaHash[pos].get_id() == id){
            tabelaHash[pos].exibir();
            return;
        }
    }
    cout<<"Não há nenhum sensor com esse id"<<endl;
}

void TabelaHash::deletar(int id){
    for(int i = 0; i<1000; i++){
        int M = 1000;
        int h1 = id % M;
        int h2 = 1+ (id % (M -1));
        int pos = (h1 + i*h2) % M;

        if(tabelaHash[pos].get_id() == id){
            tabelaHash[pos].set_id(-1);
            cout<<"sensor deletado com sucesso"<<endl;
            return;
        }
    }
    cout<<"Não há nenhum sensor com esse id"<<endl;
}

void TabelaHash::atualizarInfo(int id){
    for(int i = 0; i<1000; i++){
        int M = 1000;
        int h1 = id % M;
        int h2 = 1+ (id % (M -1));
        int pos = (h1 + i*h2) % M;

        if(tabelaHash[pos].get_id() == id){
            time_t now = time(nullptr);
            tm *ltm = localtime(&now);

            int hours = ltm->tm_hour;
            int minutes = ltm->tm_min;

            float decimalTime = hours + (static_cast<float>(minutes) / 60.0f);

            tabelaHash[pos].set_ultimaLeitura(decimalTime);
            cout<<"sensor atualizado com última leitura com sucesso"<<endl;
            return;
        }
    }
    cout<<"Não há nenhum sensor com esse id para atualizar"<<endl;
}

void TabelaHash::exibirTabelaHash(){
    for(int i = 0; i< 1000; i++){
        if(tabelaHash[i].get_id() != -1){
            cout <<"Sensor["<<i<<"]: "<< " id: "<<tabelaHash[i].get_id() <<" tipo: " << tabelaHash[i].get_tipo()<<
            " localização: "<<tabelaHash[i].get_localizacao()<< " última leitura: " << tabelaHash[i].get_ultimaLeitura()<< endl;
        }
    }
}
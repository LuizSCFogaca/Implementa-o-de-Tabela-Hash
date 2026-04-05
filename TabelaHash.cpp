#include <iostream>
#include <ctime>
#include "tabelaHash.h"
using namespace std;

TabelaHash::TabelaHash(){//construtor inicializa todas as posições da tabela com -1, indicando pos vazia, pronta para inserção
    for(int i= 0; i < 10007; i++){
        tabelaHash[i].set_id(-1);
    }
}

int TabelaHash::get_contCol(){//retorna o contador de colisões
    return contCol;
}

void TabelaHash::insert(Sensor sensor){//insert na tabela utilizando o calculo de sondagem dupla
    int i = 0;
    while(i<10007){
        int M = 10007;
        int h1 = sensor.get_id() % M;
        int h2 = 1+(sensor.get_id() % (M -1));
        int pos = (h1 + i*h2) % M;
        if(tabelaHash[pos].get_id() == -1 || tabelaHash[pos].get_id() == -11){//insere na pos -1(vazia) ou na -11 onde foi deletado um sensor
            tabelaHash[pos] = sensor;
            return;
        }else{ //caso o id não seja -1 ou -11, a pos está ocupada com algum sensor
            i++; // aumenta o indice
            contCol++; //aconteceu colisão
        }
    }
    cout<<"Tabela cheia"<<endl<<endl;
}

bool TabelaHash::existeId(int id){//existeId verifica se já existe o id na tabelahash, ela não aceita repetidos, daria problema na hora da pesquisa
    int i = 0;
    while(i < 10007){
        int M = 10007;
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

void TabelaHash::search(int id){//search pesquisa o sensor pelo id, verifica se ele existe na tabela
    int i = 0;
    while(i< 10007){
        int M = 10007;
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

void TabelaHash::deletar(int id){//deletar, seta um sensor selecionado pelo usuario para ser deletado, não aparecer nas buscas nem nada
    int i =0;
    while(i< 10007){
        int M = 10007;
        int h1 = id % M;
        int h2 = 1+ (id % (M -1));
        int pos = (h1 + i*h2) % M;

        if(tabelaHash[pos].get_id() == id){
            tabelaHash[pos].set_id(-11);//não recebe -1 pois atrapalharia na pesquisa e nas outras função, com o -11 a função search 
            cout<<"sensor deletado com sucesso"<<endl<<endl; // sabe que antes havia um sensor aqui, com isso aumenta o indice para pesquisa
            return;                                         // sem isso não chegaria ao sensor na pesquisa ou pularia indice nas ourtas funções.
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

void TabelaHash::atualizarInfo(int id, float leitura){//atualizar info muda a medida da ultima leitura com base no input do usuário
    int i = 0;
    while(i<10007){
        int M = 10007;
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

void TabelaHash::exibirTabelaHash(){//Olha todas as 10007 posições da tabela e caso não tenha id -1 ou -11 ele retorna um cout
    for(int i = 0; i< 10007; i++){  //-1 e -11 são indicadores utilizados de sensores vazios ou deletados
        if(tabelaHash[i].get_id() != -1 && tabelaHash[i].get_id() != -11){
            cout <<"Sensor["<<i<<"]: "<< " id: "<<tabelaHash[i].get_id() <<" tipo: " << tabelaHash[i].get_tipo()<<
            " localização: "<<tabelaHash[i].get_localizacao()<< " última leitura: " << tabelaHash[i].get_ultimaLeitura()<< endl;
        }
    }
}
#ifndef TABELAHASH_H
#define TABELAHASH_H
#include "sensor.h"

using namespace std;
class TabelaHash{ //Estático com 1000 pags - fechado utiliza cálculo duplo
    private:
        Sensor tabelaHash[1000];
    public:
        TabelaHash();
        void insert(Sensor sensor);
        void search(int id);
        void deletar(int id);
        void atualizarInfo(int id);
        void exibirTabelaHash();
};


#endif
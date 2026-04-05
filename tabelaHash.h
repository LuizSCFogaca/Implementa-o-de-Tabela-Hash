#ifndef TABELAHASH_H
#define TABELAHASH_H
#include "sensor.h"

using namespace std;
class TabelaHash{ //Estático com 1000 pags - fechado utiliza cálculo duplo
    private:
        int contCol = 0;
        Sensor tabelaHash[10000];
    public:
        TabelaHash();
        void insert(Sensor sensor);
        void search(int id);
        void deletar(int id);
        void atualizarInfo(int id, float leitura);
        void exibirTabelaHash();
        int get_contCol();
        bool existeId(int id);
};


#endif
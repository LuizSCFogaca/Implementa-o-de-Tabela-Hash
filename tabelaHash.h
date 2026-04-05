#ifndef TABELAHASH_H
#define TABELAHASH_H
#include "sensor.h"

using namespace std;
class TabelaHash{ //Estático com 10007 pags - fechado utiliza cálculo duplo
    private:
        int contCol = 0;//contador de colisões
        Sensor tabelaHash[10007]; //tabela com tamanho primo, com par da problema na hora do cálculo, se a pos livre for par e o id impar
                                //ele nunca conseguiria entrar caso o tamanho da tabela não fosse primo. Array de Sensor com 10007 posições.
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
#include <iostream>
#include <random>
#include <string>
#include <chrono>
#include "tabelaHash.h"
#include "sensor.h"
using namespace std;

void inserir1000(TabelaHash& tabelaHash){
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<> distr(1, 100000);
    
    auto inicio = chrono::high_resolution_clock::now();

    for(int i = 0; i < 1000; i++){
        int numId = distr(gen);
        while (tabelaHash.existeId(numId) == true) {
            numId = distr(gen);
        }
        //cout<<numId<<endl;
        Sensor sensor (numId, "ar", "sul", 0.0);
        tabelaHash.insert(sensor);
    }
    
    auto fim = std::chrono::high_resolution_clock::now();
    chrono::duration<double> duracao = fim - inicio; 
    
    cout<<"Tempo de inserção(sec): "<< duracao.count() <<endl;
    cout<<"Quantidade de colisões: "<<tabelaHash.get_contCol()<<endl<<endl;
}

int main(){
    TabelaHash tabelaHash;
    bool rodar = true;

    while(rodar){
        int operacao;
        cout<<"1.Inserir 1000 elementos automaticamente na Tabela\n"
        "2.Exibir elementos da tabela\n"
        "3.Deletar algum elemento pelo id\n"
        "4.Pesquisar algum id na tabela\n"
        "5.Inserir um sensor específico na tabela\n"
        "6.Atualizar a ultima leitura de algum Sensor pelo id(será alterado para o momento atual)\n"
        "Qualquer outro valor para sair\n"<<endl;
        cout<<"Operação desejada: ";
        cin>>operacao;

        switch (operacao){
            case 1:{
                inserir1000(tabelaHash);
                break;
            }
            case 2:{
                tabelaHash.exibirTabelaHash();
                break;
            }
            case 3:{
                int idDel;
                cout<<"Digite o id que deseja deletar: ";
                cin>>idDel;
                tabelaHash.deletar(idDel);
                break;
            }
            case 4:{
                int idSearch;
                cout<<"Digite o id para pesquisar: ";
                cin>>idSearch;

                auto inicio = chrono::high_resolution_clock::now();
                tabelaHash.search(idSearch);
                auto fim = std::chrono::high_resolution_clock::now();
                chrono::duration<double> duracao = fim - inicio;
                cout<<"Tempo de pesquisa(sec): "<<duracao.count()<<endl;
                break;
            }
            case 5:{
                int idIns;
                string tipoIns, localizacaoIns;
                cout<<"Digite o id, o tipo e a localização do sensor: ";
                cin>>idIns>>tipoIns>>localizacaoIns;
                Sensor sensorNovo(idIns, tipoIns, localizacaoIns, 0.0);
                tabelaHash.insert(sensorNovo);
                break;
            }
            case 6:{
                int idAtu;
                cout<<"Digite o id do sensor que deseja atualizar: ";
                cin>>idAtu;
                tabelaHash.atualizarInfo(idAtu);
                break;
            }
            default:{
                rodar = false;
                break;
            }
        }
    }

    return 0;
}
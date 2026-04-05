#include <iostream>
#include <random>
#include <string>
#include <chrono>
#include "tabelaHash.h"
#include "sensor.h"
using namespace std;

void inserir1000(TabelaHash& tabelaHash){//gerador automático de 1000 inserções
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
        //Menu
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
            case 1:{//chama a função insert de 1000 sensores
                inserir1000(tabelaHash);
                break;
            }
            case 2:{//chama a função exibirTabelaHash mostrando todos os sensores que não tem id -1 ou -11
                tabelaHash.exibirTabelaHash();
                break;
            }
            case 3:{//recebe o id do sensor que deseja que seja deletado
                int idDel;
                cout<<"Digite o id que deseja deletar: ";
                cin>>idDel;
                tabelaHash.deletar(idDel);
                break;
            }
            case 4:{//recebe o id do sensor que deseja que seja pesquisado e calcula o tempo que demora para ser feito a pesquisa
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
            case 5:{//recebe o id, tipo e localização do sensor que deseja que seja inserido e calcula o tempo que demora para ser feito a inserção
                int idIns;
                string tipoIns, localizacaoIns;
                cout<<"Digite o id, o tipo e a localização do sensor: ";
                cin>>idIns>>tipoIns>>localizacaoIns;
                Sensor sensorNovo(idIns, tipoIns, localizacaoIns, 0.0);
                tabelaHash.insert(sensorNovo);
                break;
            }
            case 6:{//recebe o id e o valor da ultima leitura com base no input do usuário
                int idAtu;
                float atualizacao;
                cout<<"Digite o id do sensor que deseja atualizar e o valor medido(float): ";
                cin>>idAtu>>atualizacao;
                tabelaHash.atualizarInfo(idAtu, atualizacao);
                break;
            }
            default:{//qualquer outro valor diferente de 1 a 6 cancela a operação
                rodar = false;
                break;
            }
        }
    }

    return 0;
}
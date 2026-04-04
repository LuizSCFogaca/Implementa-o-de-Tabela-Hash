#include <iostream>
#include <random>
#include <chrono>
#include "tabelaHash.h"
#include "sensor.h"
using namespace std;

void inserir1000(TabelaHash& tabelaHash){
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<> distr(1, 100);
    
    auto inicio = chrono::high_resolution_clock::now();

    for(int i = 0; i < 100; i++){
        int numId = distr(gen);
        cout<<numId<<endl;
        Sensor sensor (numId, "ar", "sul", 0.0);
        tabelaHash.insert(sensor);
    }
    
    auto fim = std::chrono::high_resolution_clock::now();
    chrono::duration<double> duracao = fim - inicio; 
    
    cout<<"Tempo de inserção(sec): "<< duracao.count() <<endl;
}

int main(){
    TabelaHash tabelaHash;

    inserir1000(tabelaHash);

    cout<<"Exibir tabela:"<<endl;
    
    tabelaHash.exibirTabelaHash();
    
    cout<<"Quantidade de colisões: " << tabelaHash.get_contCol()<<endl<<endl;

    auto inicio = chrono::high_resolution_clock::now();
    tabelaHash.search(58);
    auto fim = std::chrono::high_resolution_clock::now();
    chrono::duration<double> duracao = fim - inicio;
    cout<<"Tempo de pesquisa(sec): "<<duracao.count()<<endl;


    auto inicio1 = chrono::high_resolution_clock::now();
    tabelaHash.search(555);
    auto fim1 = std::chrono::high_resolution_clock::now();
    chrono::duration<double> duracao1 = fim1 - inicio1;
    cout<<"Tempo de pesquisa(sec): "<<duracao1.count()<<endl;

    return 0;
}
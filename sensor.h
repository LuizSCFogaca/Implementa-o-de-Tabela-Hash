#ifndef SENSOR_H
#define SENSOR_H

#include <string>
using namespace std;

class Sensor{
    private:
        int id;
        string tipo;
        string localizacao;
        float ultimaLeitura;
    public:
        //Construtor
        Sensor(int id, string tipo, string localizacao, float ultimaLeitura);

        //Get
        int get_id();
        string get_tipo();
        string get_localizacao();
        float get_ultimaLeitura();

        //Set
        void set_id(int id);
        void set_tipo(string tipo);
        void set_localizacao(string localizacao);
        void set_ultimaLeitura(float ultimaLeitura);

};

#endif
//
// Created by Asus on 11/2/2021.
//

#ifndef TP_POO_TRABALHADOR_H
#define TP_POO_TRABALHADOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


class Trabalhador{

private:
    float id;
    static int contador;
    int n_dia; // numero de dias em que foi contratado
    string tipo;
    int custo;
    int prob;  //probabilidade de ir embora

public:

    Trabalhador(const string &tipo, int dia, int custo, int prob);
    Trabalhador(){};
    virtual ~Trabalhador();
    virtual bool trabalha() = 0;
    //sets
    void setId(float id);
    void setCusto(int custo);
    void setProb(int prob);

    int getNDia() const;

    void setNDia(int nDia);

    //gets
    float getId() const;
    int getCusto() const;
    int getProb() const;

    const string &getTipo() const;
    int get_prob(int prob);
    void contrata(int &dinheiro) const;
    virtual bool despedir(string &tipo_zona) {
        return false;
    };
    virtual Trabalhador* duplica() const = 0;
    virtual string print_abreviatura()  = 0;
    string info_trabalhadores();
    virtual bool verifica(const int &dinheiro) = 0;


};

#endif //TP_POO_TRABALHADOR_H

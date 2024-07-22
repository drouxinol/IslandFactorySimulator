//
// Created by Asus on 11/5/2021.
//

#ifndef TP_POO_RECURSO_H
#define TP_POO_RECURSO_H

#include <string>
#include <sstream>
#include <iostream>

class Edificio;

using namespace std;

class Recurso{

protected:
    string nome;
    float quantidade;

public:

    Recurso();
    virtual ~Recurso();
    void save(Recurso *other);

    const string &getNome() const;
    int getQuantidade() const;

    void setQuantidade(float quantidade);
    virtual Recurso* duplica() const = 0;
    string print_info();
    virtual void vende(int valor, int &dinheiro) = 0; //tira do vetor da ilha apenas e aumenta o dinheiro
    virtual int remove_recurso(Edificio *atual, int quantidade) { return quantidade; };

};

#endif //TP_POO_RECURSO_H

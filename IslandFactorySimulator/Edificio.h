//
// Created by Asus on 11/5/2021.
//

#ifndef TP_POO_EDIFICIO_H
#define TP_POO_EDIFICIO_H

#include <iostream>
#include "Trabalhador.h"
#include "Recurso.h"
#include <sstream>
#include <vector>
using namespace std;
class Zona;

class Edificio{

protected:
    string nome;
    string recurso_produzido;//recurso armazenado
    int producao; // quanto produz
    int armazenamento_max; //quanto pode armazenar
    int armazenamento_atual;
    int custo_construcao;
    int nivel; //nivel do edificio
    bool ligado;

public:
    Edificio();
    virtual ~Edificio();
    void save(Edificio *other);

    //Gets
    string getNome() const;
    bool isLigado() const;
    int getNivel() const;

    const string &getRecursoProduzido() const;

    int getCustoConstrucao() const;

    void setArmazenamentoMax(int armazenamentoMax);

    void setArmazenamentoAtual(int armazenamentoAtual);

    //Sets
    void setNivel(int nivel);


    void add_armazenamento(int quantidade);
    int getArmazenamentoMax() const;
    int getArmazenamentoAtual() const;
    void Liga();
    void desliga();
    virtual bool desaba() { return false; };
    virtual Recurso* gera_recurso(vector<Recurso*> &recursos_ilha, Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona * zona, vector<Trabalhador*> &trabalhadores) = 0;
    virtual int check_recursos(Edificio* edificio, int &dinheiro) { return 0; };
    virtual void vende_edificio(int *dinheiro) = 0;
    virtual void vende_recurso_todos(int &dinheiro, vector<Recurso*> &recursos_ilha) = 0;
    virtual int vende_recurso(int &dinheiro, int &quantidade) = 0;
    virtual Edificio* duplica() const = 0;
    virtual string print_abreviatura() = 0;
    virtual bool upgrade(int &dinheiro) { return false; };
    virtual bool check_dinheiro(int &dinheiro) { return false; };
    string print_info();
    virtual bool verifica(int &dinheiro,vector<Recurso*> recursos_ilha) = 0;

};


#endif //TP_POO_EDIFICIO_H

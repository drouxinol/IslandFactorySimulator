//
// Created by Daniel on 12/1/2021.
//

#ifndef TP_POO_CELETRICA_H
#define TP_POO_CELETRICA_H

#include "Edificio.h"
#include "Eletricidade.h"
#include "Zona.h"

class CEletrica :public Edificio{

public:
    CEletrica();
    Zona* check_floresta(Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda);
    Zona* check_bateria(Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda);
    Recurso * gera_recurso(vector<Recurso*> &recursos_ilha, Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda, Zona * zona, vector<Trabalhador *> &trabalhadores) override;
    bool check_dinheiro(int &dinheiro) override;
    void vende_edificio(int *dinheiro) override;
    void vende_recurso_todos(int &dinheiro,vector<Recurso*> &recursos_ilha) override;
    int vende_recurso(int &dinheiro, int &quantidade) override;
    Edificio* duplica() const override;
    string print_abreviatura() override;
    bool verifica(int &dinheiro, vector<Recurso *> recursos_ilha) override;
};


#endif //TP_POO_CELETRICA_H

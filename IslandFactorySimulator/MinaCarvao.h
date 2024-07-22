//
// Created by Daniel on 12/1/2021.
//

#ifndef TP_POO_MINACARVAO_H
#define TP_POO_MINACARVAO_H

#include "Edificio.h"
#include "Zona.h"
#include "Carvao.h"

class MinaCarvao : public Edificio{

public:
    MinaCarvao();
    Recurso * gera_recurso(vector<Recurso*> &recursos_ilha, Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona * zona, vector<Trabalhador *> &trabalhadores) override;
    int check_recursos(Edificio* edificio,int &dinheiro) override;
    void vende_edificio(int *dinheiro) override;
    void vende_recurso_todos(int &dinheiro,vector<Recurso*> &recursos_ilha) override;
    int vende_recurso(int &dinheiro, int &quantidade) override;
    Edificio* duplica() const override;
    string print_abreviatura() override;
    bool desaba() override;
    bool upgrade(int &dinheiro) override;
    bool verifica(int &dinheiro, vector<Recurso *> recursos_ilha) override;
};


#endif //TP_POO_MINACARVAO_H

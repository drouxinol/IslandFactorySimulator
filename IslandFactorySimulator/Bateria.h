//
// Created by Daniel on 12/1/2021.
//

#ifndef TP_POO_BATERIA_H
#define TP_POO_BATERIA_H

#include "Edificio.h"
#include "Eletricidade.h"

class Bateria : public Edificio{

public:
    Bateria();
    Recurso * gera_recurso(vector<Recurso*> &recursos_ilha, Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona * zona, vector<Trabalhador *> &trabalhadores) override;
    void vende_edificio(int *dinheiro) override;
    int check_recursos(Edificio *edificio, int &dinheiro) override;
    void vende_recurso_todos(int &dinheiro,vector<Recurso*> &recursos_ilha) override;
    int vende_recurso(int &dinheiro, int &quantidade) override;
    Bateria * duplica() const override;
    string print_abreviatura() override;
    bool upgrade(int &dinheiro) override;
    bool verifica(int &dinheiro, vector<Recurso *> recursos_ilha) override;
};


#endif //TP_POO_BATERIA_H

//
// Created by Daniel on 12/1/2021.
//

#ifndef TP_POO_FUNDICAO_H
#define TP_POO_FUNDICAO_H

#include "Edificio.h"
#include "Zona.h"
#include "BarraAco.h"

class Fundicao : public Edificio{

public:
    Fundicao();
    Recurso * gera_recurso(vector<Recurso*> &recursos_ilha, Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona* zona,
                           vector<Trabalhador *> &trabalhadores) override;
    bool check_dinheiro(int &dinheiro) override;
    void vende_edificio(int *dinheiro) override;
    bool check(Zona* zona, string &nome);
    Zona* check_mina_ferro(Zona* acima,Zona* abaixo, Zona* direita, Zona* esquerda);
    Zona* check_mina_carvao(Zona* acima,Zona* abaixo, Zona* direita, Zona* esquerda);
    Zona* check_celetrica(Zona* acima,Zona* abaixo, Zona* direita, Zona* esquerda);
    void vende_recurso_todos(int &dinheiro,vector<Recurso*> &recursos_ilha) override;
    int vende_recurso(int &dinheiro, int &quantidade) override;
    Edificio* duplica() const override;
    string print_abreviatura() override;
    bool verifica(int &dinheiro, vector<Recurso *> recursos_ilha) override;
};


#endif //TP_POO_FUNDICAO_H

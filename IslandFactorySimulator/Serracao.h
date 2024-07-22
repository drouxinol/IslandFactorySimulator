//
// Created by Asus on 1/11/2022.
//

#ifndef TP_POO_SERRACAO_H
#define TP_POO_SERRACAO_H

#include "Edificio.h"
#include "VigasMadeira.h"
#include "Zona.h"

class Serracao : public Edificio{

public:
    Serracao();
    Recurso * gera_recurso(vector<Recurso*> &recursos_ilha, Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona* zona, vector<Trabalhador *> &trabalhadores) override;
    int produz(vector<Recurso*> &recursos_ilha, Zona *atual);
    bool check_dinheiro(int &dinheiro) override;
    void vende_edificio(int *dinheiro) override;
    void vende_recurso_todos(int &dinheiro,vector<Recurso*> &recursos_ilha) override;
    int vende_recurso(int &dinheiro, int &quantidade) override;
    Edificio* duplica() const override;
    string print_abreviatura() override;
    bool verifica(int &dinheiro, vector<Recurso *> recursos_ilha) override;
};


#endif //TP_POO_SERRACAO_H

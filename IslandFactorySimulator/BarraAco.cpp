//
// Created by Daniel on 12/1/2021.
//

#include "BarraAco.h"

BarraAco::BarraAco(const int &quantidade) {
    nome = "b_aco";
    this->quantidade = quantidade;
}

Recurso *BarraAco::duplica() const {
    BarraAco *aux = new BarraAco();
    aux->nome = nome;
    aux->quantidade = quantidade;
    return aux;
}

void BarraAco::vende(int valor, int &dinheiro) {
    dinheiro += 2*valor;
    this->quantidade -= valor;
}

int BarraAco::remove_recurso(Edificio *atual, int quantidade) {
    if(atual->getNome() == "fundicao"){
        if(atual->getArmazenamentoAtual() >= quantidade){
            atual->setArmazenamentoAtual(atual->getArmazenamentoAtual() - quantidade);
            return quantidade;
        }
        else {
            int aux = atual->getArmazenamentoAtual();
            atual->setArmazenamentoAtual(0);
            return aux;
        }
    }
    return 0;
}

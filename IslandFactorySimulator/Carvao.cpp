//
// Created by Daniel on 12/1/2021.
//

#include "Carvao.h"

Carvao::Carvao(const int &quantidade) {
    nome = "carvao";
    this->quantidade = quantidade;
}

Recurso *Carvao::duplica() const {
    Carvao *aux = new Carvao();
    aux->nome = nome;
    aux->quantidade = quantidade;
    return aux;
}

void Carvao::vende(int valor, int &dinheiro) {
    dinheiro += 1*valor;
    this->quantidade -= valor;
}

int Carvao::remove_recurso(Edificio *atual, int quantidade) {
    if(atual->getNome() == "mina de carvao" || atual->getNome() == "central eletrica"){
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

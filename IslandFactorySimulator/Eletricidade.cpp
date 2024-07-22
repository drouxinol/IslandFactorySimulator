//
// Created by Daniel on 12/1/2021.
//

#include "Eletricidade.h"

Eletricidade::Eletricidade(const int &quantidade) {
    nome = "eletricidade";
    this->quantidade = quantidade;
}

Recurso *Eletricidade::duplica() const {
    Eletricidade *aux = new Eletricidade();
    aux->nome = nome;
    aux->quantidade = quantidade;
    return aux;
}

void Eletricidade::vende(int valor, int &dinheiro) {
    dinheiro += 1.5*valor;
    this->quantidade -= valor;
}

int Eletricidade::remove_recurso(Edificio *atual, int quantidade) {
    if(atual->getNome() == "bateria"){
        if(atual->getArmazenamentoAtual() >= quantidade){
            atual->setArmazenamentoAtual(atual->getArmazenamentoAtual() - quantidade);
            return quantidade;
        }

        int aux = atual->getArmazenamentoAtual();
        atual->setArmazenamentoAtual(0);
        return aux;
    }
    return 0;
}

//
// Created by Daniel on 12/1/2021.
//

#include "Ferro.h"

Ferro::Ferro(const float &quantidade) {
    nome = "ferro";
    this->quantidade = quantidade;
}

Recurso *Ferro::duplica() const {
    Ferro *aux = new Ferro();
    aux->nome = nome;
    aux->quantidade = quantidade;
    return aux;
}

void Ferro::vende(int valor, int &dinheiro) {
    dinheiro += 1*valor;
    this->quantidade -= valor;
}

int Ferro::remove_recurso(Edificio *atual, int quantidade) {
    if(atual->getNome() == "mina de ferro"){
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

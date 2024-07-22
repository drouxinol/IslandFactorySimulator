//
// Created by Asus on 1/14/2022.
//

#include "Ouro.h"

Ouro::Ouro(const int &quantidade) {
    nome = "ouro";
    this->quantidade = quantidade;
}

Recurso *Ouro::duplica() const {
    Ouro *aux = new Ouro();
    aux->nome = nome;
    aux->quantidade = quantidade;
    return aux;
}

void Ouro::vende(int valor, int &dinheiro) {
    dinheiro += 3*valor;
    this->quantidade -= valor;
}

int Ouro::remove_recurso(Edificio *atual, int quantidade) {
    if(atual->getNome() == "mina de ouro"){
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

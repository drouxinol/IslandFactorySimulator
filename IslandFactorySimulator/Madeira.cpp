//
// Created by Daniel on 12/1/2021.
//

#include "Madeira.h"

Madeira::Madeira(int quantidade) {
    nome = "madeira";
    this->quantidade = quantidade;
}

Recurso *Madeira::duplica() const {
    Madeira *aux = new Madeira();
    aux->nome = nome;
    aux->quantidade = quantidade;
    return aux;
}

void Madeira::vende(int valor, int &dinheiro) {
    dinheiro += 1*valor;
    this->quantidade -= valor;
}



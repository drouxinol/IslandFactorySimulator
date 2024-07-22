//
// Created by Daniel on 12/1/2021.
//

#include "VigasMadeira.h"

VigasMadeira::VigasMadeira(const int &quantidade) {
    nome = "viga_madeira";
    this->quantidade = quantidade;
}

Recurso *VigasMadeira::duplica() const {
    VigasMadeira *aux = new VigasMadeira();
    aux->nome = nome;
    aux->quantidade = quantidade;
    return aux;
}

void VigasMadeira::vende(int valor, int &dinheiro) {
    dinheiro += 2*valor;
    this->quantidade -= valor;
}

int VigasMadeira::remove_recurso(Edificio *atual, int quantidade) {
    if(atual->getNome() == "serracao"){
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

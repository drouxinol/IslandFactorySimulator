//
// Created by Daniel on 12/1/2021.
//

#include "CEletrica.h"

CEletrica::CEletrica() {
    nome = "central eletrica";
    producao = 1;
    recurso_produzido = "carvao";
    armazenamento_max = 100; // ate 100kg de carvao
    nivel = 1;
    custo_construcao = 15;
    ligado = false;
    armazenamento_atual = 0;
}

Recurso *CEletrica::gera_recurso(vector<Recurso*> &recursos_ilha, Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona * zona, vector<Trabalhador*> &trabalhadores) {

    Zona *aux = check_bateria(acima, abaixo, direita, esquerda);
    Zona *floresta = check_floresta(acima, abaixo, direita, esquerda);
    bool flag = false;
    bool is_operario = false;
    int aux2;

    for(auto i : trabalhadores){
        if(i->getTipo() == "operario"){
            is_operario = true;
        }
    }
    if (floresta != nullptr && is_operario) {

        for(auto i:recursos_ilha){
            if(i->getNome() == "madeira" && i->getQuantidade() >= 1) {
                aux2 = i->getQuantidade();
                i->setQuantidade(0);
                flag = true;
            }
        }
        if(flag && armazenamento_atual < armazenamento_max) {
            armazenamento_atual += aux2;
            if (aux != nullptr) {
                if (aux->get_edificio()->getArmazenamentoAtual() <= aux->get_edificio()->getArmazenamentoMax()) { //posso tirar?
                    aux->get_edificio()->add_armazenamento(aux2); //adiciona ao armazenamento da bateria
                }
            }
            return new Carvao(producao);
        }
    }
    return nullptr;
}

bool CEletrica::check_dinheiro(int &dinheiro) {
    if(dinheiro >= 15){
        return true;
    }
    return false;
}

Zona* CEletrica::check_floresta(Zona *acima, Zona *abaixo, Zona *direita, Zona *esquerda) {

    if(acima != nullptr) {
        if (acima->get_tipo() == "floresta") {
            return acima;
        }
    }
    if(abaixo != nullptr){
        if(abaixo->get_tipo() == "floresta"){
            return abaixo;
        }
    }

    if(direita != nullptr){
        if(direita->get_tipo() == "floresta"){
            return direita;
        }
    }
    if(esquerda != nullptr){
        if (esquerda->get_tipo() == "floresta"){
            return esquerda;
        }
    }
    return nullptr;
}

Zona *CEletrica::check_bateria(Zona *acima, Zona *abaixo, Zona *direita, Zona *esquerda) {


    if(acima != nullptr){
        if(acima->get_edificio() != nullptr){
            if(acima->get_edificio()->getNome() == "bateria" &&
               acima->get_edificio()->getArmazenamentoAtual() < acima->get_edificio()->getArmazenamentoMax())
                return acima;
        }
    }

     if(abaixo != nullptr){
        if(abaixo->get_edificio() != nullptr){
            if(abaixo->get_edificio()->getNome() == "bateria" &&
               abaixo->get_edificio()->getArmazenamentoAtual() < abaixo->get_edificio()->getArmazenamentoMax())
                return abaixo;
        }
    }

     if(direita != nullptr){
        if(direita->get_edificio() != nullptr){
            if(direita->get_edificio()->getNome() == "bateria" &&
               direita->get_edificio()->getArmazenamentoAtual() < direita->get_edificio()->getArmazenamentoMax())
                return direita;
        }
    }

     if(esquerda != nullptr){
        if(esquerda->get_edificio() != nullptr) {
            if(esquerda->get_edificio()->getNome() == "bateria" &&
               esquerda->get_edificio()->getArmazenamentoAtual() < esquerda->get_edificio()->getArmazenamentoMax())
                return esquerda;
        }
    }


    return nullptr;
}

void CEletrica::vende_edificio(int *dinheiro) {

    *dinheiro += custo_construcao;
}

void CEletrica::vende_recurso_todos(int &dinheiro,vector<Recurso*> &recursos_ilha) {

    dinheiro += 1*armazenamento_atual;
    armazenamento_atual = 0;
    for(auto i:recursos_ilha){
        if(i->getNome() == "carvao"){
            i->setQuantidade(0);
        }
    }
}

int CEletrica::vende_recurso(int &dinheiro, int &quantidade) {

    if(quantidade <= armazenamento_atual){
        armazenamento_atual -= quantidade;
        dinheiro += 1.5*quantidade;
        return quantidade;
    }
    else {
        dinheiro += 1.5*armazenamento_atual;
        int aux = armazenamento_atual;
        armazenamento_atual = 0;
        return (quantidade - aux); //retorna o que falta
    }
}

Edificio *CEletrica::duplica() const {

    CEletrica *aux = new CEletrica();
    aux->armazenamento_atual = armazenamento_atual;
    aux->ligado = ligado;
    aux->nivel = nivel;
    aux->custo_construcao = custo_construcao;
    aux->producao = producao;
    aux->nome = nome;
    aux->armazenamento_max = armazenamento_max;

    return aux;
}

string CEletrica::print_abreviatura() {
    return "elec";
}

bool CEletrica::verifica(int &dinheiro, vector<Recurso *> recursos_ilha) {
    if(dinheiro >= 15){
        return true;
    }
    return false;
}





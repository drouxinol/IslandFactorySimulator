//
// Created by Asus on 1/11/2022.
//

#include "Serracao.h"

Serracao::Serracao() {
    nome = "serracao";
    producao = 0;
    recurso_produzido = "viga_madeira";
    armazenamento_max = 100;
    armazenamento_atual = 0;
    custo_construcao = 20;
    nivel = 1;
    ligado = false;
}

Recurso *Serracao::gera_recurso(vector<Recurso*> &recursos_ilha, Zona *acima, Zona *abaixo, Zona *direita, Zona *esquerda, Zona *zona, vector<Trabalhador *> &trabalhadores) {
    bool is_operario;
    for(auto i:trabalhadores){
        if(i->getTipo() == "operario") {
            is_operario = true;
            break;
        }
    }
    if(armazenamento_atual <= armazenamento_max && is_operario){
        producao = produz(recursos_ilha,zona);
        if(producao == 0){
            return nullptr;
        }
        armazenamento_atual += producao;
    }
    else{
        return nullptr;
    }

    return new VigasMadeira(producao);
}

int Serracao::produz(vector<Recurso*> &recursos_ilha, Zona *atual) {
    int produzido = 0;
    for(auto i:recursos_ilha){
        if(i->getNome() == "madeira"){
            if(i->getQuantidade() % 2 == 0){
                produzido = i->getQuantidade() / 2;
                i->setQuantidade(0);
            }
        }
    }
    return produzido;
}

bool Serracao::check_dinheiro(int &dinheiro) {
    if(dinheiro >= 20){
        return true;
    }
    return false;
}

void Serracao::vende_edificio(int *dinheiro) {
    *dinheiro += custo_construcao;
}

void Serracao::vende_recurso_todos(int &dinheiro,vector<Recurso*> &recursos_ilha) {
    dinheiro += 2*armazenamento_atual;
    armazenamento_atual = 0;
    for(auto i:recursos_ilha){
        if(i->getNome() == "viga_madeira"){
            i->setQuantidade(0);
        }
    }
}

int Serracao::vende_recurso(int &dinheiro, int &quantidade) {

    if(quantidade <= armazenamento_atual){
        armazenamento_atual -= quantidade;
        dinheiro += 2*quantidade;
        return quantidade;
    }
    else {
        dinheiro += 2*armazenamento_atual;
        int aux = armazenamento_atual;
        armazenamento_atual = 0;
        return (quantidade - aux); //retorna o que falta
    }
}

Edificio *Serracao::duplica() const {

    Serracao *aux = new Serracao();
    aux->armazenamento_atual = armazenamento_atual;
    aux->ligado = ligado;
    aux->custo_construcao = custo_construcao;
    aux->nivel = nivel;
    aux->producao = producao;
    aux->nome = nome;
    aux->armazenamento_max = armazenamento_max;

    return aux;
}

string Serracao::print_abreviatura() {
    return "ser";
}

bool Serracao::verifica(int &dinheiro, vector<Recurso *> recursos_ilha) {

    if(dinheiro > 20){
        return true;
    }
    return false;
}

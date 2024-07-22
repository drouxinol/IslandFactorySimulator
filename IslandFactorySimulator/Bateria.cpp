//
// Created by Daniel on 12/1/2021.
//

#include "Bateria.h"

Bateria::Bateria() {
    nome = "bateria";
    recurso_produzido = "eletricidade";
    producao = 2;
    armazenamento_max = 100;
    armazenamento_atual = 0;
    nivel = 1;
    custo_construcao = 10;
    ligado = false;
}

Recurso *Bateria::gera_recurso(vector<Recurso*> &recursos_ilha, Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona * zona, vector<Trabalhador*> &trabalhadores) {
    return nullptr;
}

void Bateria::vende_edificio(int *dinheiro) {

    *dinheiro += custo_construcao;
}

void Bateria::vende_recurso_todos(int &dinheiro,vector<Recurso*> &recursos_ilha) {

    dinheiro += 1.5*armazenamento_atual;
    armazenamento_atual = 0;
    for(auto i:recursos_ilha){
        if(i->getNome() == "eletricidade"){
            i->setQuantidade(0);
        }
    }
}

int Bateria::vende_recurso(int &dinheiro, int &quantidade) {

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

Bateria *Bateria::duplica() const {

    Bateria *aux = new Bateria();
    aux->armazenamento_atual = armazenamento_atual;
    aux->ligado = ligado;
    aux->nivel = nivel;
    aux->custo_construcao = custo_construcao;
    aux->producao = producao;
    aux->nome = nome;
    aux->armazenamento_max = armazenamento_max;

    return aux;
}

string Bateria::print_abreviatura() {
    return "bat";
}

bool Bateria::upgrade(int &dinheiro) {
    if(dinheiro >= 5){
        dinheiro -= 5;
        cout << "[BATERIA] Edificio aumentou de nivel..." << endl;
        return true;
    }
    cout << "[BATERIA] Nao tem dinheiro suficiente..." << endl;
    return false;
}

int Bateria::check_recursos(Edificio *edificio, int &dinheiro) {
    if(edificio->getRecursoProduzido() == "viga_madeira" && edificio->getArmazenamentoAtual() >= 10 && dinheiro >= 10){
        edificio->setArmazenamentoAtual(edificio->getArmazenamentoAtual() - 10);
        return 10;
    }
    else if(edificio->getRecursoProduzido() == "viga_madeira" && edificio->getArmazenamentoAtual() < 10 && dinheiro >= 10){
        int aux = edificio->getArmazenamentoAtual();
        edificio->setArmazenamentoAtual(0);
        return aux;
    }
    else {
        return 0;
    }
}

bool Bateria::verifica(int &dinheiro, vector<Recurso *> recursos_ilha) {
    if(dinheiro >= 10){
        for(auto i:recursos_ilha){
            if(i->getNome() == "viga_madeira" && i->getQuantidade() >= 10){
                return true;
            }
        }
    }
    return false;
}




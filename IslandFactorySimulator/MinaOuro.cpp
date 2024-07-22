//
// Created by Daniel on 12/1/2021.
//

#include "MinaOuro.h"


MinaOuro::MinaOuro() {
    nome = "mina de ouro";
    producao = 2;
    recurso_produzido = "ouro";
    armazenamento_max = 0;
    armazenamento_atual = 0;
    custo_construcao = 0;
    nivel = 1;
    ligado = false;
}

Recurso *MinaOuro::gera_recurso(vector<Recurso*> &recursos_ilha, Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona * zona, vector<Trabalhador*> &trabalhadores) {
    bool is_mineiro;
    for(auto i:trabalhadores){
        if(i->getTipo() == "mineiro") {
            is_mineiro = true;
            break;
        }
    }
    if(armazenamento_atual <= armazenamento_max && is_mineiro){
        switch (nivel) {
            case 1: armazenamento_atual += 2;
                producao = 2;
                break;
            case 2: armazenamento_atual += 3;
                producao = 3;
                break;
            case 3: armazenamento_atual += 4;
                producao = 4;
                break;
            case 4: armazenamento_atual += 5;
                producao = 5;
                break;
            case 5: armazenamento_atual += 6;
                producao = 6;
                break;
        }
        if(zona->get_tipo() == "deserto"){
            producao /= 2;
        }
       return new Ouro(producao);
    }
    return nullptr;
}

int MinaOuro::check_recursos(Edificio* edificio, int &dinheiro) {
    if(edificio->getRecursoProduzido() == "viga_madeira" && edificio->getArmazenamentoAtual() >= 10){
        edificio->setArmazenamentoAtual(edificio->getArmazenamentoAtual() - 10);
        return 10;
    }
    else if(edificio->getRecursoProduzido() == "viga_madeira" && edificio->getArmazenamentoAtual() < 10){
        int aux = edificio->getArmazenamentoAtual();
        edificio->setArmazenamentoAtual(0);
        return aux;
    }
    else {
        return 0;
    }
}

void MinaOuro::vende_edificio(int *dinheiro) {

    *dinheiro += custo_construcao;
}

void MinaOuro::vende_recurso_todos(int &dinheiro,vector<Recurso*> &recursos_ilha) {
    dinheiro += 2.5*armazenamento_atual;
    armazenamento_atual = 0;
    for(auto i:recursos_ilha){
        if(i->getNome() == "ouro"){
            i->setQuantidade(0);
        }
    }
}

int MinaOuro::vende_recurso(int &dinheiro, int &quantidade) {
    int aux;
    if(quantidade <= armazenamento_atual){
        armazenamento_atual -= quantidade;
        dinheiro += 2.5*quantidade;
        return quantidade;
    }
    else {
        dinheiro += 2.5*armazenamento_atual;
        aux = armazenamento_atual;
        armazenamento_atual = 0;
        return (quantidade - aux); //retorna o que falta

    }
}

Edificio *MinaOuro::duplica() const {
    MinaOuro *aux = new MinaOuro();
    aux->armazenamento_atual = armazenamento_atual;
    aux->ligado = ligado;
    aux->custo_construcao = custo_construcao;
    aux->nivel = nivel;
    aux->producao = producao;
    aux->nome = nome;
    aux->armazenamento_max = armazenamento_max;

    return aux;
}

string MinaOuro::print_abreviatura() {
    return "mnO";
}

bool MinaOuro::desaba() {
    int numero = rand() % 100;
    if (numero >= 0 && numero <=30){
        cout << "[MINAOURO] Desabou..." << endl;
        return true;
    }
    return false;
}

bool MinaOuro::upgrade(int &dinheiro) {
    if(dinheiro >= 20){
        dinheiro -=20;
        cout << "[MINAOURO] Edificio aumentou de nivel..." << endl;
        return true;
    }
    cout << "[MINAOURO] Nao tem dinheiro suficiente..." << endl;
    return false;
}

bool MinaOuro::verifica(int &dinheiro, vector<Recurso *> recursos_ilha) {

    for(auto i:recursos_ilha){
        if(i->getNome() == "viga_madeira" && i->getQuantidade() >= 10){
            return true;
        }
    }
    return false;
}

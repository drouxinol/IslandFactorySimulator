//
// Created by Daniel on 12/1/2021.
//

#include "MinaCarvao.h"


MinaCarvao::MinaCarvao() {
    nome = "mina de carvao";
    producao = 0;
    armazenamento_max = 100;
    recurso_produzido = "carvao";
    armazenamento_atual = 0;
    custo_construcao = 0;
    nivel = 1;
    ligado = false;

}

Recurso* MinaCarvao::gera_recurso(vector<Recurso*> &recursos_ilha, Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona* zona, vector<Trabalhador*> &trabalhadores) {

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
            producao *= 0.5;
        }
        return new Carvao(producao);
    }
    return nullptr;
}

int MinaCarvao::check_recursos(Edificio* edificio, int &dinheiro) {
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

void MinaCarvao::vende_edificio(int *dinheiro) {
    *dinheiro += custo_construcao;
}

void MinaCarvao::vende_recurso_todos(int &dinheiro,vector<Recurso*> &recursos_ilha) {
    dinheiro += 1*armazenamento_atual;
    armazenamento_atual = 0;
    for(auto i:recursos_ilha){
        if(i->getNome() == "carvao"){
            i->setQuantidade(0);
        }
    }

}

int MinaCarvao::vende_recurso(int &dinheiro, int &quantidade) {
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

Edificio *MinaCarvao::duplica() const {
    MinaCarvao *aux = new MinaCarvao();
    aux->armazenamento_atual = armazenamento_atual;
    aux->ligado = ligado;
    aux->custo_construcao = custo_construcao;
    aux->nivel = nivel;
    aux->producao = producao;
    aux->nome = nome;
    aux->armazenamento_max = armazenamento_max;

    return aux;
}

string MinaCarvao::print_abreviatura() {
    return "mnC";
}

bool MinaCarvao::desaba() {
    int numero = rand() % 100;
    if (numero >= 0 && numero <=10){
        cout << "[MINACARVAO] Desabou..." << endl;
        return true;
    }
    return false;
}

bool MinaCarvao::upgrade(int &dinheiro) {
    if(dinheiro >= 10){
        dinheiro -= 10;
        cout << "[MINACARVAO] Edificio aumentou de nivel..." << endl;
        return true;
    }
    cout << "[MINACARVAO] Nao tem dinheiro suficiente..." << endl;
    return false;
}

bool MinaCarvao::verifica(int &dinheiro, vector<Recurso *> recursos_ilha) {
    for(auto i:recursos_ilha){
        if(i->getNome() == "viga_madeira" && i->getQuantidade() >= 10){
            return true;
        }
    }
    return false;
}


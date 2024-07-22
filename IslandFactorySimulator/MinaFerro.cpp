//
// Created by Daniel on 12/1/2021.
//

#include "MinaFerro.h"


MinaFerro::MinaFerro() {
    nome = "mina de ferro";
    producao = 0;
    recurso_produzido = "ferro";
    armazenamento_max = 100;
    armazenamento_atual = 0;
    custo_construcao = 0;
    nivel = 1;
    ligado = false;
}

Recurso *MinaFerro::gera_recurso(vector<Recurso*> &recursos_ilha, Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona* zona, vector<Trabalhador*> &trabalhadores) {

    bool is_mineiro;
    for(auto i:trabalhadores){
        if(i->getTipo() == "mineiro") {
            is_mineiro = true;
            break;
        }
    }
    if(armazenamento_atual <= armazenamento_max && is_mineiro){
        switch (nivel) {
            case 1: producao = 2;
                break;
            case 2: producao = 3;
                break;
            case 3: producao = 4;
                break;
            case 4: producao = 5;
                break;
            case 5: producao = 6;
                break;
        }
        if(zona->get_tipo() == "deserto"){
            producao /= 2;
        }
        armazenamento_atual += producao;
        return new Ferro(producao);
    }
    return nullptr;
}

int MinaFerro::check_recursos(Edificio *edificio, int &dinheiro) {
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

void MinaFerro::vende_edificio(int *dinheiro) {

    *dinheiro += custo_construcao;

}

void MinaFerro::vende_recurso_todos(int &dinheiro,vector<Recurso*> &recursos_ilha) {
    dinheiro += 1*armazenamento_atual;
    armazenamento_atual = 0;
    for(auto i:recursos_ilha){
        if(i->getNome() == "ferro"){
            i->setQuantidade(0);
        }
    }

}

int MinaFerro::vende_recurso(int &dinheiro, int &quantidade) {
    if(quantidade <= armazenamento_atual){
        armazenamento_atual -= quantidade;
        dinheiro += 1*quantidade;
        return quantidade;
    }
    else {
        dinheiro += 1*armazenamento_atual;
        int aux = armazenamento_atual;
        armazenamento_atual = 0;
        return (quantidade - aux); //retorna o que falta
    }
}

Edificio *MinaFerro::duplica() const {

    MinaFerro *aux = new MinaFerro;
    aux->armazenamento_atual = armazenamento_atual;
    aux->ligado = ligado;
    aux->custo_construcao = custo_construcao;
    aux->nivel = nivel;
    aux->producao = producao;
    aux->nome = nome;
    aux->armazenamento_max = armazenamento_max;

    return aux;
}

string MinaFerro::print_abreviatura() {
    return "mnF";
}

bool MinaFerro::desaba() {
    int numero = rand() % 100;
    if (numero >= 0 && numero <=15){
        cout << "[MINAFERRO] Desabou..." << endl;
        return true;
    }
    return false;
}

bool MinaFerro::upgrade(int &dinheiro) {
   if(dinheiro >= 15){
       dinheiro -=15;
       cout << "[MINAFERRO] Edificio aumentou de nivel..." << endl;
       return true;
   }
    cout << "[MINAFERRO] Nao tem dinheiro suficiente..." << endl;
   return false;
}

bool MinaFerro::verifica(int &dinheiro, vector<Recurso *> recursos_ilha) {

    for(auto i:recursos_ilha){
        if(i->getNome() == "viga_madeira" && i->getQuantidade() >= 10){
            return true;
        }
    }
    return false;
}



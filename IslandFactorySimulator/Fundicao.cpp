//
// Created by Daniel on 12/1/2021.
//

#include "Fundicao.h"

Fundicao::Fundicao() {
    nome = "fundicao";
    producao = 2;
    recurso_produzido = "b_aco";
    armazenamento_max = 0;
    armazenamento_atual = 0;
    nivel = 1;
    custo_construcao = 10;
    ligado = false;
}
bool Fundicao::check(Zona* zona, string &nome){

    if(zona != nullptr && zona->get_edificio() != nullptr) {
        if (zona->get_edificio()->getNome() == nome) {
            return true;
        }
    }
        return false;
}
Zona* Fundicao::check_mina_ferro(Zona* acima,Zona* abaixo, Zona* direita, Zona* esquerda){

    string str = "mina de ferro";

    if(check(acima,str)){
        return acima;
    }
    if(check(abaixo,str)) {
        return abaixo;
    }
    if(check(direita,str)){
        return direita;
    }
    if(check(esquerda,str)){
        return esquerda;
    }
    return nullptr;
}
Zona* Fundicao::check_mina_carvao(Zona* acima,Zona* abaixo, Zona* direita, Zona* esquerda){

    string str = "mina de carvao";

    if(check(acima,str)){
        return acima;
    }
    if(check(abaixo,str)) {
        return abaixo;
    }
    if(check(direita,str)){
        return direita;
    }
    if(check(esquerda,str)){
        return esquerda;
    }
    return nullptr;
}
Zona* Fundicao::check_celetrica(Zona* acima,Zona* abaixo, Zona* direita, Zona* esquerda){

    string str = "celetrica";

    if(check(acima,str)){
        return acima;
    }
    if(check(abaixo,str)) {
        return abaixo;
    }
    if(check(direita,str)){
        return direita;
    }
    if(check(esquerda,str)){
        return esquerda;
    }
    return nullptr;
}


Recurso *Fundicao::gera_recurso(vector<Recurso*> &recursos_ilha, Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda, Zona * zona, vector<Trabalhador*> &trabalhadores) {

    bool is_operario = false;
    Zona *mF = check_mina_ferro(acima,abaixo,direita,esquerda);
    Zona *mC = check_mina_carvao(acima,abaixo,direita,esquerda);
    Zona *Ce = check_celetrica(acima,abaixo,direita,esquerda);
    for(auto i:trabalhadores){
        if(i->getTipo() == "operario") {
            is_operario = true;
            break;
        }
    }
    if(is_operario && mF != nullptr && mF->get_edificio()->getArmazenamentoAtual() >= 1.5
        && (mC != nullptr && mC->get_edificio()->getArmazenamentoAtual() >= 0.5 || Ce != nullptr && Ce->get_edificio()->getArmazenamentoAtual() >= 0.5)){

        mF->get_edificio()->setArmazenamentoAtual(mF->get_edificio()->getArmazenamentoAtual() - 1.5);
        if(mC != nullptr){
            mC->get_edificio()->setArmazenamentoAtual(mF->get_edificio()->getArmazenamentoAtual() - 0.5);
        }
        else {
            Ce->get_edificio()->setArmazenamentoAtual(mF->get_edificio()->getArmazenamentoAtual() - 0.5);
        }
        armazenamento_atual += 1;
        return new BarraAco(1);
    }

    return nullptr;
}

bool Fundicao::check_dinheiro(int &dinheiro) {
    if(dinheiro >= 10){
        return true;
    }
    return false;
}

void Fundicao::vende_edificio(int *dinheiro) {

    *dinheiro += custo_construcao;
}

void Fundicao::vende_recurso_todos(int &dinheiro,vector<Recurso*> &recursos_ilha) {
    dinheiro+= 1.5*armazenamento_atual;
    armazenamento_atual = 0;
    for(auto i:recursos_ilha){
        if(i->getNome() == "b_aco"){
            i->setQuantidade(0);
        }
    }
}

int Fundicao::vende_recurso(int &dinheiro, int &quantidade) {
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

Edificio *Fundicao::duplica() const {
    Fundicao *aux = new Fundicao();
    aux->armazenamento_atual = armazenamento_atual;
    aux->ligado = ligado;
    aux->custo_construcao = custo_construcao;
    aux->nivel = nivel;
    aux->producao = producao;
    aux->nome = nome;
    aux->armazenamento_max = armazenamento_max;

    return aux;
}

string Fundicao::print_abreviatura() {
    return "fun";
}

bool Fundicao::verifica(int &dinheiro, vector<Recurso *> recursos_ilha) {

    if(dinheiro >= 10){
        return true;
    }
    return false;
}


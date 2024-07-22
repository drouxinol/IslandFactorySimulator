//
// Created by Asus on 11/5/2021.
//

#include "Edificio.h"


Edificio::Edificio(){}

Edificio::~Edificio() {}

//Gets
string Edificio::getNome() const {
    return nome;
}
int Edificio::getNivel() const {
    return nivel;
}

//Sets
void Edificio::setNivel(int nivel) {
    this->nivel = nivel;
}

bool Edificio::isLigado() const {

    if(this->ligado)
        return true;

    return false;
}

void Edificio::Liga() {
    this->ligado = true;
}
void Edificio::desliga() {
    this->ligado = false;
}

void Edificio::add_armazenamento(int quantidade) {
    armazenamento_atual += quantidade;
}

int Edificio::getArmazenamentoMax() const {
    return armazenamento_max;
}

int Edificio::getArmazenamentoAtual() const {
    return armazenamento_atual;
}

void Edificio::save(Edificio *other) {

    other->ligado = ligado;
    other->armazenamento_atual = armazenamento_atual;
    other->armazenamento_max = armazenamento_max;
    other->nome = nome;
    other->nivel = nivel;
    other->recurso_produzido = recurso_produzido;
    other->custo_construcao = custo_construcao;
    other->producao = producao;
}

void Edificio::setArmazenamentoMax(int armazenamentoMax) {
    this->armazenamento_max = armazenamentoMax;
}

string Edificio::print_info() {
    ostringstream oss;
    string aux;

    if(ligado){
        aux = "Ligado";
    }
    else if(!ligado){
        aux = "Desligado";
    }

    oss << "\nNome do edificio: " << nome << "\nNivel do edificio: " << nivel << "\nEdificio encontra-se: " << aux << "\nArmazenamento atual: " << armazenamento_atual << endl;

    return oss.str();
}

int Edificio::getCustoConstrucao() const {
    return custo_construcao;
}

void Edificio::setArmazenamentoAtual(int armazenamentoAtual) {
    this->armazenamento_atual = armazenamentoAtual;
}

const string &Edificio::getRecursoProduzido() const {
    return recurso_produzido;
}
















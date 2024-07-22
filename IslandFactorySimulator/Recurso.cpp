//
// Created by Asus on 11/5/2021.
//

#include "Recurso.h"


using namespace std;

Recurso::Recurso() {}
Recurso::~Recurso() {}

const string &Recurso::getNome() const {
    return nome;
}

int Recurso::getQuantidade() const {
    return quantidade;
}

void Recurso::setQuantidade(float quantidade) {
    this->quantidade = quantidade;
}

void Recurso::save(Recurso *other) {

    other->quantidade = quantidade;
    other->nome = nome;
}

string Recurso::print_info() {
    ostringstream oss;

    oss << "\nNome do recurso: " << nome << "\nQuantidade: " << quantidade << endl;

    return oss.str();
}










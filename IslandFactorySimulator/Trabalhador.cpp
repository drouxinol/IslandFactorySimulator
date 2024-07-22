//
// Created by Asus on 11/2/2021.
//

#include "Trabalhador.h"

using namespace std;

int Trabalhador::contador = 0;

Trabalhador::Trabalhador(const string &tipo,int dia, int custo, int prob) {
    contador++;
    this->tipo = tipo;
    n_dia = 1;
    id = contador + (float)dia/(float)10;
    this->custo = custo;
    this->prob = prob;
}

Trabalhador::~Trabalhador() {}

float Trabalhador::getId() const {
    return id;
}

int Trabalhador::getCusto() const {
    return custo;
}
int Trabalhador::getProb() const {
    return prob;
}

void Trabalhador::setId(float id) {
    this->id= id;
}
void Trabalhador::setCusto(int custo) {
    this->custo = custo;
}
void Trabalhador::setProb(int prob) {
    this->prob = prob;
}

const string &Trabalhador::getTipo() const {
    return tipo;
}

int Trabalhador::get_prob(int prob) {
        float probabilidade = (float)prob / 100;
        int casos_fav;
        int casos_poss = 100;

        casos_fav = probabilidade * casos_poss;
        return casos_fav;
}

void Trabalhador::contrata(int &dinheiro) const {
    dinheiro -= custo;
}

int Trabalhador::getNDia() const {
    return n_dia;
}

void Trabalhador::setNDia(int nDia) {
    n_dia = nDia;
}

string Trabalhador::info_trabalhadores() {
    ostringstream oss;

    oss << "\nID do trabalhador: " << id << "\nTipo de trabalhador: " << tipo << "\nDia de contrato: " << n_dia << endl;
    return oss.str();
}










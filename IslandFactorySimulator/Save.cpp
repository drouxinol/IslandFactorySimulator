//
// Created by Daniel on 12/27/2021.
//

#include "Save.h"

const string &Save::getNome() const {
    return nome;
}

void Save::setNome(const string &nome) {

    this->nome = nome;
}

GameData *Save::getGd() const {
    return gD;
}

void Save::setGd(GameData *gD) {
    this->gD = gD;
}

Save::Save(const string &nome, GameData *gD) : nome(nome), gD(new GameData(*gD)) {}

Save::~Save() {
    delete gD;
}

//
// Created by Daniel on 12/27/2021.
//

#ifndef TP_POO_SAVE_H
#define TP_POO_SAVE_H

using namespace std;

#include <iostream>
#include "GameData.h"

class Save {

private:
    string nome;
    GameData *gD;

public:

    Save(const string &nome, GameData *gD);
    ~Save();

    const string &getNome() const;

    void setNome(const string &nome);

    GameData *getGd() const;

    void setGd(GameData *gD);

};


#endif //TP_POO_SAVE_H

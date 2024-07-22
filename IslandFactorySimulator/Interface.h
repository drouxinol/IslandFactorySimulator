//
// Created by Daniel on 12/28/2021.
//

#ifndef TP_POO_INTERFACE_H
#define TP_POO_INTERFACE_H

#include <iostream>
#include <sstream>
#include "Save.h"
#include "GameData.h"
using namespace std;

class Interface {

private:
    GameData *gD;
    vector<Save *> saves;

    int verificaComando(const string &comando);
    void get_linha_coluna(int *l, int *c);
    void exec(string &ficheiro);
    void save(string &nome);
    void apaga(string &nome);
    void load(string &nome);
    void print(string &s);

public:

    Interface(GameData *gD);
    void print_ilha(const int l,const int c);
    void run();

    ~Interface();
};


#endif //TP_POO_INTERFACE_H

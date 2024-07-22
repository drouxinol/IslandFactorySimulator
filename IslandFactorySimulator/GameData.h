//
// Created by Daniel on 12/4/2021.
//

#ifndef TP_POO_GAMEDATA_H
#define TP_POO_GAMEDATA_H

#include "Ilha.h"
#include <ctime>
#include <fstream>
#include "Operario.h"

class GameData {

private:
    int dinheiro = 500; //dinheiro inicial do jogador
    Ilha *ilha;

public:
    GameData();
    GameData(const GameData &other);
    ~GameData();
    bool verifica_jogo();
    void quit();

    void initIlha(const int *l,const int *c);

    void cons(const int &linha, const int &coluna,string &tipo);
    void next();
    void liga_edificios(int l, int c);
    void debkill(float &id);
    void cont(string &tipo);
    void desliga_edificios(int l, int c);
    void getZonaPasto(int &l, int &c);
    void vende_edificio(int &l, int &c);
    void upgrade(int l, int c);
    string get_tipo_zona(int l,int c);
    string get_trabalhadores(int l, int c);
    string get_edificio(int l, int c);
    int get_n_trabalhadores(int l, int c);
    string list(int l, int c);

    void debed(const int &linha, const int &coluna,string &tipo);
    void move(float &id, const int &linha, const int &coluna);
    void vende_recurso(string &recurso,int &quantidade);

    int getDinheiro() const;
    void setDinheiro(int &valor);

};


#endif //TP_POO_GAMEDATA_H

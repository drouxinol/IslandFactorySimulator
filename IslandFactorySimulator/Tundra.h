//
// Created by Daniel on 12/1/2021.
//

#ifndef TP_POO_TUNDRA_H
#define TP_POO_TUNDRA_H

#include "Zona.h"
using namespace std;

class Tundra : public Zona{

public:
    Tundra();
    string get_tipo() override;
    void gera_recursos_edificios(vector<Recurso*> &recursos_ilha,Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona* zona,
                                 Edificio * edificio_zona, vector<Trabalhador *> &trabalhadores) override;
    void despede() override;
    Tundra * duplica()  override;
    string get_abreviatura() override;
    void adiciona_edificio(const string &tipo_edificio, int custo, int &dinheiro) override;
    void desaba(const int &dia) override;

};


#endif //TP_POO_TUNDRA_H

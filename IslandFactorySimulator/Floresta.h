//
// Created by Daniel on 12/1/2021.
//

#ifndef TP_POO_FLORESTA_H
#define TP_POO_FLORESTA_H

#include "Zona.h"
#include "Madeira.h"
using namespace std;

class Floresta : public Zona{

    int n_arvores;

public:
    Floresta();
    Recurso* gera_recursos(int &dia) override;
    string get_tipo() override;
    void gera_recursos_edificios(vector<Recurso*> &recursos_ilha,Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona* zona,
                                 Edificio * edificio_zona, vector<Trabalhador *> &trabalhadores) override;
    void despede() override;
    void adiciona_edificio(const string &tipo_edificio, int custo, int &dinheiro) override;

    int getNArvores() const;

    void setNArvores(int nArvores);

    Floresta * duplica()  override;
    string get_abreviatura() override;
    void desaba(const int &dia) override;
    bool verifica() override;
};


#endif //TP_POO_FLORESTA_H

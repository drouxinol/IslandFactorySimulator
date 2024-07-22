//
// Created by Daniel on 12/1/2021.
//

#ifndef TP_POO_MINEIRO_H
#define TP_POO_MINEIRO_H

#include "Trabalhador.h"

class Mineiro : public Trabalhador {

public:

    Mineiro(const int &dia);
    Mineiro();
    bool trabalha() override;
    bool despedir(string &tipo_zona) override;
    Trabalhador * duplica() const override;
    string print_abreviatura() override;
    bool verifica(const int &dinheiro) override;


};
#endif //TP_POO_MINEIRO_H

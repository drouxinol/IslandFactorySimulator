//
// Created by Daniel on 12/1/2021.
//

#ifndef TP_POO_LENHADOR_H
#define TP_POO_LENHADOR_H

#include "Trabalhador.h"

class Lenhador : public Trabalhador{

public:
    Lenhador(const int &dia);
    Lenhador();
    bool trabalha() override;
    bool despedir(string &tipo_zona) override;
    Trabalhador * duplica() const override;
    string print_abreviatura() override;
    bool verifica(const int &dinheiro) override;
};


#endif //TP_POO_LENHADOR_H

//
// Created by Asus on 1/14/2022.
//

#ifndef TP_POO_OURO_H
#define TP_POO_OURO_H

#include "Recurso.h"
#include "Edificio.h"

class Ouro : public Recurso {

public:
    Ouro(const int &quantidade = 0);
    Recurso * duplica() const override;
    void vende(int valor, int &dinheiro) override;
    int remove_recurso(Edificio *atual, int quantidade) override;
};


#endif //TP_POO_OURO_H

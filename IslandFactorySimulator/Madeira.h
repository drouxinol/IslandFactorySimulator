//
// Created by Daniel on 12/1/2021.
//

#ifndef TP_POO_MADEIRA_H
#define TP_POO_MADEIRA_H

#include "Recurso.h"
#include "Edificio.h"

class Madeira : public Recurso{

public:
    Madeira(int quantidade = 0);
    Recurso * duplica() const override;
    void vende(int valor, int &dinheiro) override;
};


#endif //TP_POO_MADEIRA_H

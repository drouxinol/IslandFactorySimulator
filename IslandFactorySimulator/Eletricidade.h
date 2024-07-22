//
// Created by Daniel on 12/1/2021.
//

#ifndef TP_POO_ELETRICIDADE_H
#define TP_POO_ELETRICIDADE_H

#include "Recurso.h"
#include "Edificio.h"

class Eletricidade : public Recurso{

public:
    Eletricidade(const int &quantidade = 0);
    Recurso * duplica() const override;
    void vende(int valor, int &dinheiro) override;
    int remove_recurso(Edificio *atual, int quantidade) override;
};


#endif //TP_POO_ELETRICIDADE_H

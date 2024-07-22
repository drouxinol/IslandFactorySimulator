//
// Created by Daniel on 12/1/2021.
//

#ifndef TP_POO_VIGASMADEIRA_H
#define TP_POO_VIGASMADEIRA_H

#include "Recurso.h"
#include "Edificio.h"

class VigasMadeira : public Recurso{

public:
    VigasMadeira(const int &quantidade = 0);
    Recurso * duplica() const override;
    void vende(int valor, int &dinheiro) override;
    int remove_recurso(Edificio *atual, int quantidade) override;
};


#endif //TP_POO_VIGASMADEIRA_H

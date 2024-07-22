//
// Created by Daniel on 12/1/2021.
//

#include "Operario.h"

Operario::Operario(const int &dia) : Trabalhador("operario",dia,15,5) {
}

bool Operario::despedir(string &tipo_zona) {
    float numero = rand() % 100 + 1;

    if(tipo_zona == "montanha"){
        setProb(10);
    }

    if(tipo_zona == "pantano" && getNDia() == 10){
        cout << "Fartei-me, vou me embora!" << endl;
        return true;
    }
    else if(numero <= get_prob(getProb()) && getProb() > 0 && getNDia() >= 10 && tipo_zona != "pastagem"){ // 5% de probabilidade
        cout << "<Operario " << getId() << ">" << "Fartei-me, vou me embora!" << endl;
        return true;
    }
    setNDia(getNDia() + 1);
    return false;
}

Trabalhador *Operario::duplica() const {

    return new Operario(*this);
}

bool Operario::trabalha() {
    return true;
}

string Operario::print_abreviatura() {
    return "O";
}

Operario::Operario() {

}

bool Operario::verifica(const int &dinheiro) {
    if(dinheiro >= 15){
        return true;
    }
    return false;
}

//
// Created by Daniel on 12/1/2021.
//

#include "Lenhador.h"

Lenhador::Lenhador(const int &dia) : Trabalhador("lenhador",dia,20,0) {
}

bool Lenhador::despedir(string &tipo_zona) {
    float numero = rand() % 100 + 1;

    if(tipo_zona == "montanha"){
        setProb(5);
    }

    if(tipo_zona == "pantano" && getNDia() == 10){
        cout << "Fartei-me, vou me embora!" << endl;
        setNDia(getNDia() + 1);
        return true;
    }
    else if(numero <= get_prob(getProb()) && getProb() > 0 && tipo_zona == "montanha"){
        cout << "<Lenhador " << getId() << ">" << "Fartei-me, vou me embora!" << endl;
        setNDia(getNDia() + 1);
        return true;
    }
    setNDia(getNDia() + 1);
    return false;
}

Trabalhador *Lenhador::duplica() const {
    return new Lenhador(*this);
}

bool Lenhador::trabalha() {
    if(getNDia() % 5 == 0){
        return false;
    }
    return true;
}

string Lenhador::print_abreviatura() {
    return "L";
}

Lenhador::Lenhador() {

}

bool Lenhador::verifica(const int &dinheiro) {
    if(dinheiro >= 20){
        return true;
    }
    return false;
}



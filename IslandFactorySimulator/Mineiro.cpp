//
// Created by Daniel on 12/1/2021.
//

#include "Mineiro.h"

Mineiro::Mineiro(const int &dia) : Trabalhador("mineiro",dia,10,10){

}


bool Mineiro::despedir(string &tipo_zona) {
    int numero = rand() % 100 + 1;

    if(tipo_zona == "montanha") {
        setProb(15);
    }

    if(tipo_zona == "pantano" && getNDia() == 10){
        cout << "Fartei-me, vou me embora!" << endl;
        return true;
    }
    else if(numero <= get_prob(getProb()) && getProb() > 0 && getNDia() >= 2 && tipo_zona != "pastagem"){ // 10% de probabilidade
       cout << "<Mineiro " << getId() << ">" <<"Fartei-me, vou me embora!" << endl;
        return true;
    }
    setNDia(getNDia() + 1);
    return false;
}

Trabalhador *Mineiro::duplica() const {

    return new Mineiro(*this);
}

bool Mineiro::trabalha() {
    return true;
}

string Mineiro::print_abreviatura() {
    return "M";
}

Mineiro::Mineiro() {

}

bool Mineiro::verifica(const int &dinheiro) {
    if(dinheiro >= 10){
        return true;
    }
    return false;
}




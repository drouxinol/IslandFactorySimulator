//
// Created by Daniel on 12/1/2021.
//

#include "Pantano.h"

Pantano::Pantano() {

}

string Pantano::get_tipo() {
    return "pantano";
}

void Pantano::gera_recursos_edificios(vector<Recurso*> &recursos_ilha,Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona* zona, Edificio * edificio_zona, vector<Trabalhador *> &trabalhadores) {

    Recurso* aux;
    if(edificio_zona != nullptr)
        if(edificio_zona->isLigado()){
            aux = edificio_zona->gera_recurso(recursos_ilha, acima, abaixo, direita, esquerda, zona, trabalhadores);
            if (aux != nullptr) {
                add_recurso(recursos_ilha, aux);
            }
        }
}

void Pantano::despede() {
    for(auto i: trabalhadores){
        string tipo_zona = get_tipo();
        if(i->despedir(tipo_zona)){
            float aux = i->getId();
            elimina_trabalhador(aux);
        }
    }
}

Pantano *Pantano::duplica()  {

    return (new Pantano(*this));
}

string Pantano::get_abreviatura() {
    return "pnt";
}

void Pantano::adiciona_edificio(const string &tipo_edificio, int custo, int &dinheiro) {
    if(tipo_edificio == "minaferro") {
        edificio = new MinaFerro();
        dinheiro -= custo;
    }
    else if(tipo_edificio == "minacarvao"){
        edificio = new MinaCarvao();
        dinheiro -= custo;
    }
    else if(tipo_edificio == "celetrica"){
        edificio = new CEletrica();
        dinheiro -= custo;
    }
    else if(tipo_edificio == "bateria"){
        edificio = new Bateria();
        dinheiro -= custo;
    }
    else if(tipo_edificio == "fundicao"){
        edificio = new Fundicao();
        dinheiro -= custo;
    }
    else if(tipo_edificio == "minaouro"){
        edificio = new MinaOuro();
        dinheiro -= custo;
    }
    else if(tipo_edificio == "serracao"){
        edificio = new Serracao();
        dinheiro -= custo;
    }
}

void Pantano::desaba(const int &dia) {
        bool aux;

        if(edificio != nullptr && dia >= 10){
            edificio = nullptr;
            cout << "[PANTANO] Edificio desabou...\n";
            return;
        }

        if(edificio != nullptr){
            aux = edificio->desaba();
            if(aux){
                edificio = nullptr;
            }
        }
}


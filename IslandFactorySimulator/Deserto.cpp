//
// Created by Asus on 11/30/2021.
//

#include "Deserto.h"

Deserto::Deserto() {

}

string Deserto::get_tipo()  {
    return "deserto";
}

void Deserto::gera_recursos_edificios(vector<Recurso*> &recursos_ilha,Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona* zona, Edificio * edificio_zona, vector<Trabalhador *> &trabalhadores) {

    Recurso *aux;
    if(edificio_zona != nullptr){
        if(edificio_zona->isLigado()){
            aux = edificio_zona->gera_recurso(recursos_ilha,acima,abaixo,direita,esquerda,zona,trabalhadores);
            if(aux != nullptr)
                add_recurso(recursos_ilha,aux);
        }
    }
}

void Deserto::despede() {
    for(auto i: trabalhadores){
        string tipo_zona = get_tipo();
        if(i->despedir(tipo_zona)){
            float aux = i->getId();
            elimina_trabalhador(aux);
        }
    }
}

Deserto * Deserto::duplica() {

    return (new Deserto(*this));
}

string Deserto::get_abreviatura() {
    return "drs";
}

void Deserto::adiciona_edificio(const string &tipo_edificio, int custo, int &dinheiro) {
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

void Deserto::desaba(const int &dia) {
    int aux;
    if(edificio != nullptr){
        aux = edificio->desaba();
        if(aux){
            edificio = nullptr;
        }
    }
}



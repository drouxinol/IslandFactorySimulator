//
// Created by Daniel on 12/1/2021.
//

#include "Montanha.h"


Montanha::Montanha() {

}
string Montanha::get_tipo(){
    return "montanha";
}
Recurso* Montanha::gera_recursos(int &dia) {
    float aux=0.0;
    for(int i=0;i<getTrabalhadores().size();i++){
        if(getTrabalhadores()[i]->trabalha()){
                aux += 0.1;
        }
    }
    //add_recurso(new Ferro(aux));
    cout << "[MONTANHA] Gerei " << aux << "Kg de Ferro\n";
    if(aux != 0) {
        return new Ferro(aux);
    }
    return nullptr;
}
void Montanha::gera_recursos_edificios(vector<Recurso*> &recursos_ilha,Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona* zona, Edificio* edificio_zona, vector<Trabalhador*> &trabalhadores) {
    Recurso *aux;
    if (edificio_zona != nullptr)
        if (edificio_zona->isLigado()) {
            aux = edificio_zona->gera_recurso(recursos_ilha, acima, abaixo, direita, esquerda, zona, trabalhadores);
            if (aux != nullptr) {
                add_recurso(recursos_ilha, aux);
            }
        }
}
void Montanha::despede() {
    for(auto i: trabalhadores){
        string tipo_zona = get_tipo();
        if(i->despedir(tipo_zona)){
            float aux = i->getId();
            elimina_trabalhador(aux);
        }
    }
}

Montanha *Montanha::duplica() {
    return  (new Montanha(*this));
}

string Montanha::get_abreviatura() {
    return "mnt";
}

void Montanha::adiciona_edificio(const string &tipo_edificio, int custo, int &dinheiro) {
    custo *= 2;
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

void Montanha::desaba(const int &dia) {
    int aux;
    if(edificio != nullptr){
        aux = edificio->desaba();
        if(aux){
            edificio = nullptr;
        }
    }
}

bool Montanha::verifica() {
    for(int i=0;i<getTrabalhadores().size();i++){
        if(getTrabalhadores()[i]->getTipo() == "lenhador"){
            return true;
        }
    }
    return false;
}


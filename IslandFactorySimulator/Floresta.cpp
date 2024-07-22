//
// Created by Daniel on 12/1/2021.
//

#include "Floresta.h"

Floresta::Floresta() {
    n_arvores = rand() % 40 + 20;
}

string Floresta::get_tipo() {
    return "floresta";
}

Recurso* Floresta::gera_recursos(int &dia) {
    int aux=0;
    for(int i=0;i<getTrabalhadores().size();i++){
        if(getTrabalhadores()[i]->getTipo() == "lenhador" && getTrabalhadores()[i]->trabalha()){
            aux += 1;
        }
    }

    if(dia % 2 == 0 && edificio == nullptr){
        setNArvores(getNArvores() + 2);
    }

    if(edificio != nullptr){
        setNArvores(getNArvores() - 1);
    }
    if(n_arvores >= aux && aux != 0){
        cout << "[FLORESTA] Gerei " << aux << "Kg de Madeira\n";
        setNArvores(getNArvores() - aux);
        return new Madeira(aux);
    }
    return nullptr;
}

void Floresta::gera_recursos_edificios(vector<Recurso*> &recursos_ilha,Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda,Zona* zona, Edificio * edificio_zona, vector<Trabalhador *> &trabalhadores) {

    Recurso *aux;
    if (edificio_zona != nullptr)
        if (edificio_zona->isLigado()) {
            aux = edificio_zona->gera_recurso(recursos_ilha, acima, abaixo, direita, esquerda, zona, trabalhadores);
            if (aux != nullptr) {
                add_recurso(recursos_ilha, aux);
            }
        }
}

void Floresta::despede() {
    for(auto i: trabalhadores){
        string tipo_zona = get_tipo();
        if(i->despedir(tipo_zona)){
            float aux = i->getId();
            elimina_trabalhador(aux);
        }
    }
}

Floresta *Floresta::duplica()  {
    return (new Floresta(*this));
}

string Floresta::get_abreviatura() {
    return "flr";
}

int Floresta::getNArvores() const {
    return n_arvores;
}

void Floresta::setNArvores(int nArvores) {
    this->n_arvores = nArvores;
}

void Floresta::adiciona_edificio(const string &tipo_edificio, int custo, int &dinheiro) {
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

void Floresta::desaba(const int &dia) {
    int aux;
    if(edificio != nullptr){
        aux = edificio->desaba();
        if(aux){
            edificio = nullptr;
        }
    }
}

bool Floresta::verifica() {
        for(int i=0;i<getTrabalhadores().size();i++){
            if(getTrabalhadores()[i]->getTipo() == "lenhador"){
                if(n_arvores == 0){
                    return true;
                }
            }
        }
        return false;
}



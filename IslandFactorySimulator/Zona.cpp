//
// Created by Asus on 11/5/2021.
//

#include "Zona.h"

using namespace std;

int Zona::id_zona = 1;

Zona::Zona() {
    id = id_zona;
    id_zona++;
    edificio = nullptr;
}
Zona::~Zona() {
    delete edificio;
    for(auto i: trabalhadores){
        delete i;
    }
}
void Zona::adiciona_edificio_debed(const string &tipo_edificio){
    if(tipo_edificio == "minaferro") {
        edificio = new MinaFerro();
    }
    else if(tipo_edificio == "minacarvao"){
        edificio = new MinaCarvao();
    }
    else if(tipo_edificio == "celetrica"){
        edificio = new CEletrica();
    }
    else if(tipo_edificio == "bateria"){
        edificio = new Bateria();
    }
    else if(tipo_edificio == "fundicao"){
        edificio = new Fundicao();
    }
    else if(tipo_edificio == "minaouro"){
        edificio = new MinaOuro();
    }
    else if(tipo_edificio == "serracao"){
        edificio = new Serracao();
    }
}
void Zona::adiciona_trabalhador(Trabalhador *trabalhador) {
    trabalhadores.emplace_back(trabalhador);
}
void Zona::liga_edificio(){
    if(edificio != nullptr){
        edificio->Liga();
    }
       cout << "Nao existe nenhum edicifio nessa zona" << endl;
}
void Zona::desliga_edificio(){
    if(edificio != nullptr){
        edificio->desliga();
    }
    cout << "Nao existe nenhum edicifio nessa zona" << endl;
}


vector<Trabalhador*> Zona::getTrabalhadores() const {
    return trabalhadores;
}

bool Zona::verifica_trabalhador(const float &id){

    for(int i=0;i<trabalhadores.size();i++){
        if(trabalhadores.at(i)->getId() == id){
           return true;
        }
    }
    return false;
}
void Zona::elimina_trabalhador(float &id) {
    int cont = 0;
    for(int i=0;i<trabalhadores.size();i++){
        if(trabalhadores.at(i)->getId() == id){
            break;
        }
        cont++;
    }
    trabalhadores.erase(trabalhadores.begin() + cont);
}

void Zona::add_recurso(vector<Recurso*> &vetor, Recurso* recurso) {

    if(recurso != nullptr) {
        for (auto i: vetor) {
            if (recurso->getNome() == i->getNome()) {
                i->setQuantidade(i->getQuantidade() + recurso->getQuantidade());
                return;
            }
        }
    }
    if(recurso != nullptr) {
        vetor.push_back(recurso);
    }
}
Edificio* Zona::get_edificio(){
    if(edificio != nullptr)
        return edificio;

    return nullptr;
}

Trabalhador *Zona::get_trabalhador(float &id) {
    Trabalhador* aux;
    for(int i=0;i<trabalhadores.size();i++){
        if(trabalhadores.at(i)->getId() == id){
            aux = trabalhadores.at(i);
            return aux;
        }
    }
    return nullptr;
}

bool Zona::check_dinheiro(Edificio* edificio, int &dinheiro) {
    if(edificio->check_dinheiro(dinheiro)){
        return true;
    }
    return false;
}

void Zona::vende_edificio(int &dinheiro,vector<Recurso*> &recursos_ilha) {

    if(edificio != nullptr){
        edificio->vende_recurso_todos(dinheiro,recursos_ilha);
        edificio->vende_edificio(&dinheiro);
        edificio = nullptr;
    }
    else {
        cout << "Nao existe nenhum edificio nessa zona." << endl;
    }
}

bool Zona::check_recurso(string &nome) {

    return false;
}

Zona::Zona(const Zona &other) {

    id = other.id;

    if(other.edificio != nullptr) {
        edificio = other.edificio->duplica();
    }
    else {
        edificio = nullptr;
    }
    for(auto i : other.trabalhadores){
        trabalhadores.push_back(i->duplica());
    }
}

int Zona::getId() const {
    return id;
}

void Zona::upgrade(int &dinheiro) {
   edificio->upgrade(dinheiro);
}

bool Zona::is_edificio() {
    if(edificio != nullptr){
        return true;
    }
    return false;
}










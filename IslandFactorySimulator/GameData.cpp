//
// Created by Daniel on 12/4/2021.
//

#include "GameData.h"


using namespace std;

GameData::GameData(const GameData &other) {
    this->dinheiro = other.dinheiro;
    this->ilha = new Ilha(*other.ilha);
}

GameData::GameData(){
}

void GameData::initIlha(const int *l,const int *c) {

    int aux_l = *l;
    int aux_c = *c;

    ilha = new Ilha(aux_l,aux_c);
}

int GameData::getDinheiro() const {
    return dinheiro;
}

void GameData::setDinheiro(int &valor) {
    this->dinheiro = valor;
}

void GameData::getZonaPasto(int &l, int &c){
    ilha->getZonaPasto(l,c);
}
GameData::~GameData() {
    delete ilha;
}

void GameData::next() {
    ilha->next();
    ilha->despede();
    ilha->desaba();
}

void GameData::liga_edificios(int l, int c) {
    ilha->liga_edificio(l,c);
}


void GameData::desliga_edificios(int l, int c) {
    ilha->desliga_edificio(l,c);
}

void GameData::debkill(float &id) {
    Trabalhador* trabalhador = ilha->elimina_trabalhador(id);
    if(trabalhador == nullptr){
        cout << "Erro ao eliminar trabalhador." << endl;
    }
}

void GameData::move(float &id, const int &linha, const int &coluna){
    ilha->move(linha, coluna,id);
}

void GameData::cons(const int &linha, const int &coluna,string &tipo) {
    Edificio *aux = nullptr;

    if(tipo == "minaferro"){
        aux = new MinaFerro();
    }
    else if(tipo == "minacarvao"){
        aux = new MinaCarvao();
    }
    else if(tipo == "minaouro"){
        aux = new MinaOuro();
    }
    else if(tipo == "celetrica"){
        aux = new CEletrica();
    }
    else if(tipo == "bateria"){
        aux = new Bateria();
    }
    else if(tipo == "fundicao"){
        aux = new Fundicao();
    }
    else if(tipo == "serracao"){
        aux = new Serracao();
    }

    if(aux != nullptr) {
        if (!ilha->is_edificio(linha, coluna)) {
            if (ilha->check_recursos(aux, dinheiro)) {
                ilha->adiciona_edificio(linha, coluna, tipo, aux->getCustoConstrucao(), dinheiro);
            } else {
                cout << "\nErro ao criar edificio!" << endl;
            }
        }
    }
    delete aux;
}

void GameData::cont(string &tipo){

        int l = 0;
        int c = 0;
        getZonaPasto(l,c);
        ilha->adiciona_trabalhador(l,c,tipo,dinheiro);

}
void GameData::debed(const int &linha, const int &coluna,string &tipo){

   ilha->adiciona_edificio_debed(linha,coluna,tipo);

}

void GameData::vende_recurso(string &recurso, int &quantidade) {

    Recurso* aux = nullptr;
    if(recurso == "ferro"){
        aux = new Ferro();
    }
    if(recurso == "carvao"){
        aux = new Carvao();
    }
    if(recurso == "viga"){
        aux = new VigasMadeira();
    }
    if(recurso == "mad"){
        aux = new Madeira();
    }
    if(recurso == "aco"){
        aux = new BarraAco();
    }
    if(recurso == "ouro"){
        aux = new Ouro();
    }
    if(recurso == "eletr"){
        aux = new Eletricidade();
    }

    ilha->vende_recurso(aux, quantidade,dinheiro);
}

void GameData::vende_edificio(int &l, int &c) {
    ilha->vende_edificio(l,c,dinheiro);
}

void GameData::upgrade(int l, int c) {
    ilha->upgrade(l,c,dinheiro);
}

string GameData::get_tipo_zona(int l, int c) {
    string aux = ilha->print_zona(l,c);
    return aux;
}

string GameData::get_trabalhadores(int l, int c) {
    string aux = ilha->print_trabalhadores(l,c);
    return aux;
}

string GameData::get_edificio(int l, int c) {
    string aux = ilha->print_edificio(l,c);
    return aux;
}

int GameData::get_n_trabalhadores(int l, int c) {
    int aux = ilha->print_n_trabalhadores(l,c);
    return aux;
}

string GameData::list(int l, int c) {
    string aux = ilha->list(l,c);
    if(aux == "null"){
        return "null";
    }
    cout << "Dinheiro: " << dinheiro << endl;
    return aux;
}

bool GameData::verifica_jogo() {

    if(!ilha->verifica_jogo(dinheiro)){
        cout << "Acabou o jogo... Nao tem recursos sufucientes nem dinheiro para continuar..." << endl;
        return false;
    }
    return true;
}

void GameData::quit() {
    ilha->quit();
}











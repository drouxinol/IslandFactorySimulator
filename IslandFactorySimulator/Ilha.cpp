//
// Created by Asus on 11/5/2021.
//
#include "Ilha.h"

using namespace std;

Ilha::Ilha(int l , int c) {

    dia = 1;
    colunas = c;
    linhas = l;

    matriz = new Zona ** [l];

    int n = 1;

    for(int i=0;i<l;i++){
            matriz[i] = new Zona * [c];
            for(int k = 0;k<c;k++){

                if(n == 1) {
                    matriz[i][k] = new Deserto;
                }
                else if(n == 2){
                    matriz[i][k] = new Pantano;
                }
                else if(n == 3){
                    matriz[i][k] = new Tundra; //Zona-X
                }
                else if(n == 4){
                    matriz[i][k] = new Montanha;
                }
                else if(n == 5){
                    matriz[i][k] = new Floresta;
                }
                else if(n == 6){
                    matriz[i][k] = new Pastagem;
                }
                else{
                    int cont = rand() % 6 + 1;
                    if(cont == 1) {
                        matriz[i][k] = new Deserto;
                    }
                    else if(cont == 2){
                        matriz[i][k] = new Pantano;
                    }
                    else if(cont == 3){
                        matriz[i][k] = new Tundra; //Zona-X
                    }
                    else if(cont == 4){
                        matriz[i][k] = new Montanha;
                    }
                    else if(cont == 5){
                        matriz[i][k] = new Floresta;
                    }
                    else if(cont == 6){
                        matriz[i][k] = new Pastagem;
                    }
                }
                n++;

            }
    }
}

void Ilha::adiciona_edificio(int l, int c,string &tipo_ed,int custo ,int &dinheiro){

    if(l>linhas || l< 0 || c > colunas || c<0){
        cout << "Out of bounds..." << endl;
        return;
    }

    matriz[l][c]->adiciona_edificio(tipo_ed,custo,dinheiro);
}

void Ilha::move(int l, int c,float &id) {
    if(l>linhas || l< 0 || c > colunas || c<0){
        cout << "Out of bounds..." << endl;
        return;
    }
    Trabalhador* trabalhador = elimina_trabalhador(id);
    if(trabalhador != nullptr){
        matriz[l][c]->adiciona_trabalhador(trabalhador);
    }
}

void Ilha::adiciona_trabalhador(int l, int c,string &tipo_trabalhador, int &dinheiro) {

    Trabalhador *aux = nullptr;

    if(tipo_trabalhador == "oper"){
        aux = new Operario(dia);
        aux->contrata(dinheiro);
    }
    else if(tipo_trabalhador == "len"){
        aux = new Lenhador(dia);
        aux->contrata(dinheiro);
    }
    else if(tipo_trabalhador == "miner"){
        aux = new Mineiro(dia);
        aux->contrata(dinheiro);
    }

    if(aux != nullptr) {
        matriz[l][c]->adiciona_trabalhador(aux);
    }
    else {
        cout << "Erro ao criar trabalhador." << endl;
    }

}

void Ilha::liga_edificio(int l, int c){

    if(l>linhas || l< 0 || c > colunas || c<0){
        cout << "Out of bounds..." << endl;
        return;
    }
    matriz[l][c]->liga_edificio();
}

void Ilha::desliga_edificio(int l, int c) {

    if(l>linhas || l< 0 || c > colunas || c<0){
        cout << "Out of bounds..." << endl;
        return;
    }
    matriz[l][c]->desliga_edificio();
}

void Ilha::next() {
    vector<Trabalhador*> trabalhadores_na_zona; //trabalhadores em cada zona
    for(int i=0;i<linhas;i++){
        for(int k = 0;k<colunas;k++) {
            Recurso* aux = matriz[i][k]->gera_recursos(dia);
            if(aux != nullptr){
                add_recurso(recursos_ilha,aux);
            }
            trabalhadores_na_zona = matriz[i][k]->getTrabalhadores(); //trabalhadores que estao na zona
            matriz[i][k]->gera_recursos_edificios(recursos_ilha,verifica_acima(i,k), verifica_abaixo(i,k), verifica_direita(i,k),
                                                  verifica_esquerda(i,k),matriz[i][k],
                                                  matriz[i][k]->get_edificio(),trabalhadores_na_zona); //gera recursos dos edificios ligados da zona
        }
    }
    dia++;
}

int Ilha::get_n_zonasPasto(){ //achar quantas zonas de pasto existem na ilha
    int cont=0;
    for (int i = 0; i < linhas; i++) {
        for (int k = 0; k < colunas; k++) {
            if (matriz[i][k]->get_tipo() == "pastagem") {
                cont++;
            }
        }
    }
    return cont;
}

int Ilha::getZonaPasto(int &l, int &c) {
    int cont = get_n_zonasPasto();
    int random_number = -1;

    if (cont > 1) {
        do {
            for (int i = 0; i < linhas; i++) {
                for (int k = 0; k < colunas; k++) {
                    random_number = rand() % 3;
                    if (matriz[i][k]->get_tipo() == "pastagem") {
                        if (random_number == 0) {
                            l = i;
                            c = k;
                            return 0;
                        }
                    }
                }
            }
        } while (true);
    }
    else {
        for (int i = 0; i < linhas; i++) {
            for (int k = 0; k < colunas; k++) {
                if (matriz[i][k]->get_tipo() == "pastagem") {
                    l = i;
                    c = k;
                    return 0;
                }
            }
        }
    }

    return 1;
}

void Ilha::vende_edificio(int l, int c, int &dinheiro){

    if(l>linhas || l< 0 || c > colunas || c<0){
        cout << "Out of bounds..." << endl;
        return;
    }

    matriz[l][c]->vende_edificio(dinheiro,recursos_ilha);
}

Trabalhador* Ilha::elimina_trabalhador(float &id) {

    Trabalhador* aux;
    for (int i = 0; i < linhas; i++) {
        for (int k = 0; k < colunas; k++) {
                if (matriz[i][k]->verifica_trabalhador(id)) { //Se o ponteiro para trabalhador que a funcao get_trabalhador retorna for igual ao id
                    aux = matriz[i][k]->get_trabalhador(id);
                    matriz[i][k]->elimina_trabalhador(id);
                    return aux;
                }
        }
    }
    cout << "Nao foi encontrado nenhum trabalhador com esse ID." << endl;

    return nullptr;
}

bool Ilha::check_recursos(Edificio *tipo_edificio, int &dinheiro) {
    if(tipo_edificio->getNome() == "mina de ferro" || tipo_edificio->getNome() == "mina de carvao"
        || tipo_edificio->getNome() == "mina de ouro" || tipo_edificio->getNome() == "bateria") {
        bool flag = false;
        int quantidade = 0;

        for(auto i:recursos_ilha){
            if(i->getNome() == "viga_madeira" && i->getQuantidade() >= 10){
                i->setQuantidade(i->getQuantidade() - 10);
                flag = true;
            }
        }

        if(flag) {
            for (int i = 0; i < linhas; i++) {
                for (int k = 0; k < colunas; k++) {
                    if (matriz[i][k]->get_edificio() != nullptr) {
                         quantidade += tipo_edificio->check_recursos(matriz[i][k]->get_edificio(), dinheiro);
                        if (quantidade == 10) {
                            return true;
                        } else {
                            continue;
                        }
                    }
                }
            }
        }
    }
    else {
        if(tipo_edificio->check_dinheiro(dinheiro))
        return true;
    }

    return false;
}

void Ilha::despede() {

    for (int i = 0; i < linhas; i++) {
        for (int k = 0; k < colunas; k++) {
            matriz[i][k]->despede();
        }
    }
}

Zona *Ilha::verifica_acima(int l, int c) {
    if(l != 0){
        return matriz[l-1][c];
    }
    return nullptr;
}

Zona *Ilha::verifica_abaixo(int l, int c) {
    if(l != linhas-1){
        return matriz[l+1][c];
    }
    return nullptr;
}

Zona *Ilha::verifica_direita(int l, int c) {
    if(c != colunas-1){
        return matriz[l][c+1];
    }
    return nullptr;
}

Zona *Ilha::verifica_esquerda(int l, int c) {
    if(c != 0){
        return matriz[l][c-1];
    }
    return nullptr;
}

void Ilha::vende_recurso(Recurso* recurso, int quantidade,int &dinheiro) {

    int aux = 0;
    bool flag = false;
    for(auto i:recursos_ilha){
        if(i->getNome() == recurso->getNome() && i->getQuantidade() >= quantidade){
            flag = true;
            i->vende(quantidade,dinheiro);
        }
    }

    if(flag){
        for(int i=0;i<linhas;i++){
            for(int k=0;k<colunas;k++){
                if(matriz[i][k]->get_edificio() != nullptr) {
                    aux += recurso->remove_recurso(matriz[i][k]->get_edificio(), quantidade);
                    if (aux == quantidade) {
                        return;
                    } else {
                        continue;
                    }
                }
            }
        }

    }
    else {
        cout << "Nao tem recursos suficientes para vender." << endl;
    }

}

Ilha::~Ilha() {

    for(int i=0;i<linhas;i++){
        for(int k=0;k<colunas;k++){
            delete matriz[i][k];
        }
        delete[] matriz[i];
    }
    delete[] matriz;

    for(auto i:recursos_ilha){
        delete i;
    }
}

Ilha::Ilha(const Ilha &other) { //other = atual
    colunas = other.colunas;
    linhas = other.linhas;
    dia = other.dia;

    matriz = new Zona **[linhas];

    for (int i = 0; i < linhas; i++) {
        matriz[i] = new Zona *[colunas];
        for (int k = 0; k < colunas; k++) {

            matriz[i][k] = other.matriz[i][k]->duplica();
        }
    }
    for(auto i:other.recursos_ilha){
        recursos_ilha.push_back(i->duplica());
    }

}

void Ilha::upgrade(int l, int c, int &dinheiro) {
    matriz[l][c]->upgrade(dinheiro);
}

string Ilha::print_zona(int l, int c) {
    return matriz[l][c]->get_abreviatura();
}

string Ilha::print_edificio(int l, int c) {
    if(matriz[l][c]->get_edificio() != nullptr ){
        return matriz[l][c]->get_edificio()->print_abreviatura();
    }
    return "   ";
}

string Ilha::print_trabalhadores(int l, int c) {
    string aux = " ";
    int cont = 1;
    for(auto i : matriz[l][c]->getTrabalhadores()){
        if(cont<=3) {
            cont++;
            aux += i->print_abreviatura();
        }
    }
    if(aux != " "){

        return aux;
    }
    return "    ";
}

int Ilha::print_n_trabalhadores(int l, int c) {
    int aux=0;
    for(auto i : matriz[l][c]->getTrabalhadores()){
            aux++;
    }
    return aux;
}

string Ilha::list(int l, int c) {

    if(l>linhas || l< 0 || c > colunas || c<0){
        return "null";
    }

    ostringstream oss;

    oss << "ID da zona: " << matriz[l][c]->getId() << endl;

    for(auto i:matriz[l][c]->getTrabalhadores()){
        oss << i->info_trabalhadores();
    }

    if(matriz[l][c]->get_edificio() != nullptr) {
        oss << matriz[l][c]->get_edificio()->print_info();
    }

    return oss.str();
}

void Ilha::desaba() {
    for(int i=0;i<linhas;i++){
        for(int k=0;k<colunas;k++){
            matriz[i][k]->desaba(dia);
        }
    }
}

void Ilha::adiciona_edificio_debed(int l, int c, string &tipo_ed) {

    if(l>linhas || l< 0 || c > colunas || c<0){
        cout << "Out of bounds..." << endl;
        return;
    }

    if(matriz[l][c]->is_edificio()) {
        cout << "Ja existe um edidicio nessa zona...\n";
        return;
    }
    matriz[l][c]->adiciona_edificio_debed(tipo_ed);
}

bool Ilha::is_edificio(int l, int c) {

    if(l>linhas || l< 0 || c > colunas || c<0){
        return false;
    }

    if(matriz[l][c]->is_edificio()) {
        cout << "Ja existe um edidicio nessa zona...\n";
        return true;
    }
    return false;
}

void Ilha::add_recurso(vector<Recurso *> &vetor, Recurso *&recurso) {
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

void auxiliares(MinaCarvao* mC, MinaFerro* mF,MinaOuro* mO,Fundicao* fu,Serracao* se,Bateria* bat, CEletrica* cel){
    delete mC;
    delete mF;
    delete mO;
    delete fu;
    delete se;
    delete bat;
    delete cel;
}

bool Ilha::verifica_jogo(const int &dinheiro) {

    bool flag_ed = false;
    bool flag_zona = false;
    bool flag_tr = false;
    auto* mC = new MinaCarvao();
    auto* mF = new MinaFerro();
    auto* mO = new MinaOuro();
    auto* fu = new Fundicao();
    auto* se = new Serracao();
    auto* bat = new Bateria();
    auto* cel = new CEletrica();

    auto* mn = new Montanha();
    auto* fl = new Floresta();

    auto* op = new Operario();
    auto* len = new Lenhador();
    auto* min = new Mineiro();

    flag_ed = verifica_construcao_edificios(dinheiro,mC,mF,mO,fu,se,bat,cel);
    flag_zona = verifica_zona(mn,fl);
    flag_tr = verifica_trabalhador(op,len,min,dinheiro);

    auxiliares(mC,mF,mO,fu,se,bat,cel);
    delete mn;
    delete fl;
    delete op;
    delete len;
    delete min;

    if(!flag_ed && !flag_zona && !flag_tr){ //nao se consegue construir mais edificios e as zonas nao geram mais
        return false;
    }
    return true;
}

bool Ilha::verifica_construcao_edificios(int dinheiro,MinaCarvao* mC, MinaFerro* mF,MinaOuro* mO,Fundicao* fu,Serracao* se,Bateria* bat, CEletrica* cel){
    bool flag1 = mC->verifica(dinheiro,recursos_ilha);
    bool flag2 = mF->verifica(dinheiro,recursos_ilha);
    bool flag3 = mO->verifica(dinheiro,recursos_ilha);
    bool flag4 = fu->verifica(dinheiro,recursos_ilha);
    bool flag5 = se->verifica(dinheiro,recursos_ilha);
    bool flag6 = bat->verifica(dinheiro,recursos_ilha);
    bool flag7 = cel->verifica(dinheiro,recursos_ilha);

    if(!flag1 && !flag2 && !flag3 && !flag4 && !flag5 && !flag6 && !flag7){
        return false;
    }
    return true;
}
bool Ilha::verifica_zona(Montanha* mn, Floresta* fl){

    if(!mn->verifica() && !fl->verifica()){
        return false;
    }
    return true;
}
bool Ilha::verifica_trabalhador(Operario* op, Lenhador* len, Mineiro* min,const int &dinheiro){
    if(!op->verifica(dinheiro) && !len->verifica(dinheiro) && !min->verifica(dinheiro)){
        return false;
    }
    return true;
}

void Ilha::quit() {

    for(int i=0;i<linhas;i++){
        for(int k=0;k<colunas;k++){
            delete matriz[i][k];  //eliminou-se a zona
        }
        delete[] matriz[i]; //eliminou-se o vetor da coluna
    }
    delete[] matriz; //eliminou-se vetor da linha

    for(auto i:recursos_ilha){
        delete i;
    }

}




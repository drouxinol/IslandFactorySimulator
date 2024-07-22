//
// Created by Daniel on 12/28/2021.
//

#include "Interface.h"


Interface::Interface(GameData *gD) {
    this->gD = gD;
}

Interface::~Interface() {
    delete gD;
    for(auto i :saves){
        delete i;
    }
}

void Interface::get_linha_coluna(int *l, int *c) {
    do{
        cout << "Numero de linhas da ilha: ";
        cin >> *l;
        if(*l > 8 || *l < 3){
            cout << "Numero de linhas invalidas" << endl;
        }
    }while(*l > 8 || *l < 3);

    do{
        cout << "Numero de colunas da ilha: ";
        cin >> *c;
        if(*c > 16 || *c < 3){
            cout << "Numero de colunas invalidas" << endl;
        }
    }while(*c > 16 || *c < 3);
}

void Interface::exec(string &ficheiro){

    ifstream file;
    string str;

    ficheiro = "../" + ficheiro;

    file.open(ficheiro);

    if(file.fail()){
        cout << "Erro ao abrir ficheiro de texto!\n";
        return;
    }

    while(getline(file,str)){
        cout << str << endl;
        verificaComando(str);
    }

    file.close();

}

void Interface::apaga(string &nome) {
    int cont = 1;
    for(auto i: saves){
        if(i->getNome() == nome){
            break;
        }
        else{
            cont++;
        }
    }
    if(cont < 1){
        cout << "Houve um erro a apagar o save.\n";
    }
    else if(cont >= 1){
        delete (saves.at(cont - 1));
        saves.erase(saves.begin() + cont - 1);
        cout << "Save eliminado com sucesso.\n";
    }

}

void Interface::save(string &nome) {

    saves.push_back(new Save(nome,gD));
    cout << "Jogo salvo com sucesso!" << endl;
}

void Interface::load(string &nome) {

    for(auto i:saves){
        if(i->getNome() == nome){
            GameData *aux = i->getGd();
            gD = new GameData(*aux);
            cout << "Load feito com sucesso!" << endl;
            return;
        }
    }
    cout << "[ERRO] Nao foi encontrado nenhum save com esse nome." << endl;
}

int Interface::verificaComando(const string &comando) {

        string comando1;

        istringstream iss(comando);

        iss >> comando1;

        if(comando1 == "exec"){

            string ficheiro;
            iss >> ficheiro;

            if(!iss){
                cout << "ERRO DE SINTAXE! " << "<" << comando1 << "> <NomeFicheiro>" <<endl;
                return 1;
            }
            exec(ficheiro);
        }
        else if(comando1 == "cons" || comando1 == "debed"){
            int linhas, colunas;
            string tipo;

            iss >> tipo >> linhas >> colunas;
            if(!iss) {
                cout << "ERRO DE SINTAXE!\n" << "<" << comando1 << "> <tipo> <linha> <coluna>" << endl;
                return 1;
            }
            if(comando1 == "cons")
                gD->cons(linhas,colunas,tipo);
            else if(comando1 == "debed"){
                gD->debed(linhas,colunas,tipo);
            }
        }
        else if(comando1 == "liga" || comando1 == "des" || comando1 == "list"){

            int linhas, colunas;

            iss >> linhas >> colunas;
            if(!iss){
                cout << "ERRO NA SINTAXE! " << "<" << comando1 << "> <linha> <coluna>" << endl;
                return 1;
            }
            if(comando1 == "liga"){
                gD->liga_edificios(linhas,colunas);
            }
            else if(comando1 == "des"){
                gD->desliga_edificios(linhas,colunas);
            }
            if(comando1 == "list"){
                string aux = gD->list(linhas,colunas);
                if(aux == "null"){
                    cout << "Out of bounds..." << endl;
                }
                print(aux);
            }
        }
        else if(comando1 == "move"){
            float id;
            int linhas,colunas;

            iss >> id >> linhas >> colunas;
            if(!iss){
                cout << "ERRO DE SINTAXE! " << "<" << comando1 << "> <id> <linha> <coluna>" << endl;
                return 1;
            }
            gD->move(id,linhas,colunas);
        }
        else if(comando1 == "cont"){
            string tipo;

            iss >> tipo;

            if(!iss){
                cout << "ERRO DE SINTAXE! " << "<" << comando1 << "> <tipo>" << endl;
                return 1;
            }
            gD->cont(tipo);
        }
        else if(comando1 == "save" || comando1 == "load" || comando1 == "apaga"){
            string nome;

            iss >> nome;
            if(!iss){
                cout << "ERRO DE SINTAXE! " << "<" << comando1 << "> <nome>" << endl;
                return 1;
            }

            if(comando1 == "save"){
                save(nome);
            }
            else if(comando1 == "load"){
                load(nome);
            }
            else if(comando1 == "apaga"){
                apaga(nome);
            }
        }
        else if(comando1 == "config"){
            string ficheiro;

            iss >> ficheiro;
            if(!iss){
                cout << "ERRO DE SINTAXE! " << "<" << comando1 << "> <ficheiro>" << endl;
                return 1;
            }
        }
        else if(comando1 == "debcash"){
            int valor;

            iss >> valor;
            if(!iss){
                cout << "ERRO DE SINTAXE! " << "<" << comando1 << "> <valor>" << endl;
                return 1;
            }

            int aux = gD->getDinheiro() + valor;
            gD->setDinheiro(aux);
        }
        else if(comando1 == "debkill"){
            float id;

            iss >> id;
            if(!iss){
                cout << "ERRO DE SINTAXE! " << "<" << comando1 << "> <id>" << endl;
                return 1;
            }
            gD->debkill(id);
        }
        else if(comando1 == "next"){
            gD->next();
        }
        else if(comando1 == "vende"){
            int linha,coluna;

            iss >> linha >> coluna;

            if(!iss){
                string tipo;
                int quantidade;

                iss.clear();
                iss >> tipo >> quantidade;

                if(!iss){
                    cout << "ERRO DE SINTAXE" << endl;
                    return 1;
                }
                else {
                    gD->vende_recurso(tipo,quantidade);
                }
            }
            else if(iss){
                gD->vende_edificio(linha,coluna);
            }

        }
        else if(comando1 == "upgrade"){
            int l,c;

            iss >> l >> c;

            if(!iss){
                cout << "ERRO DE SINTAXE <upgrade> <linha> <coluna>" << endl;
                return 1;
            }
            gD->upgrade(l,c);
        }
        else if(comando1 == "quit"){
            gD->quit();
            return 0;
        }
        else {
            cout << "\nComando Invalido!\n" << endl;
            return 1;
        }
        return 0;
}

void Interface::run() {

        srand(time(NULL));
        int l,c;
        string comando;

        get_linha_coluna(&l,&c);
        cin.ignore();

        gD->initIlha(&l,&c);

        do{

            print_ilha(l,c);

            if(!gD->verifica_jogo()){
                gD->quit();
                return;
            }

            cout << "Comando: ";
            getline(cin,comando);
            verificaComando(comando);

            if(comando == "quit"){
                cout << "Saindo..." << endl;
                return;
            }

        }while(comando != "fim");
}

void Interface::print_ilha(const int l,const int c) {
    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            cout << "*******";
        }

        cout << endl;

        for(int k=0;k<c;k++){
            cout << "* ";
            cout << gD->get_tipo_zona(i,k);
            cout << "  ";
        }
        cout << "*" << endl;
        for(int k=0;k<c;k++){
            cout << "*  ";
            cout << gD->get_edificio(i,k);
            cout << " ";
        }
        cout << "*" << endl;
        for(int k=0;k<c;k++){
            cout << "* ";
            cout << gD->get_trabalhadores(i,k);
            cout << " ";
        }
        cout << "*" << endl;
        for(int k=0;k<c;k++){
            cout << " *   ";
            cout << gD->get_n_trabalhadores(i,k);
        }
        cout << " *" << endl;
    }
}

void Interface::print(string &s) {
    cout << s;
}










//
// Created by Asus on 11/5/2021.
//
#ifndef TP_POO_ILHA_H
#define TP_POO_ILHA_H

#include "Zona.h"
#include <vector>
#include <sstream>
#include "Deserto.h"
#include "Operario.h"
#include "Lenhador.h"
#include "Mineiro.h"
#include "Pantano.h"
#include "Tundra.h"
#include "Floresta.h"
#include "Pastagem.h"
#include "Montanha.h"

using namespace std;

class Ilha{

   Zona ***matriz;
   int colunas,linhas;
   int dia;
   vector<Recurso*> recursos_ilha;

public:

    Ilha(int l , int c);
    Ilha(const Ilha &other);
    ~Ilha();

    void quit();
    bool verifica_jogo(const int &dinheiro);
    bool verifica_zona(Montanha* mn, Floresta* fl);
    bool verifica_trabalhador(Operario* op, Lenhador* len, Mineiro* min,const int &dinheiro);
    bool verifica_construcao_edificios(int dinheiro,MinaCarvao* mC, MinaFerro* mF,MinaOuro* mO,Fundicao* fu,Serracao* se,Bateria* bat, CEletrica* cel);
    void adiciona_edificio(int l, int c,string &tipo_ed,int custo,int &dinheiro);
    void adiciona_edificio_debed(int l, int c,string &tipo_ed);
    int get_n_zonasPasto();
    void add_recurso(vector<Recurso*> &vetor, Recurso* &recurso);
    Trabalhador* elimina_trabalhador(float &id);
    int getZonaPasto(int &l, int &c);
    void liga_edificio(int l, int c);
    void desliga_edificio(int l, int c);
    void despede();
    bool is_edificio(int l, int c);
    bool check_recursos(Edificio *tipo_edificio, int &dinheiro);
    void adiciona_trabalhador(int l, int c,string &tipo_trabalhador, int &dinheiro);
    void move(int l, int c,float &id);
    void vende_edificio(int l, int c,int &dinheiro);
    void vende_recurso(Recurso* recurso, int quantidade, int &dinheiro);
    void upgrade(int l,int c, int &dinheiro);
    Zona* verifica_acima(int l, int c);
    Zona* verifica_abaixo(int l, int c);
    Zona* verifica_direita(int l, int c);
    Zona* verifica_esquerda(int l, int c);
    void desaba();
    string list(int l, int c);
    string print_zona(int l,int c);
    string print_edificio(int l,int c);
    string print_trabalhadores(int l,int c);
    int print_n_trabalhadores(int l,int c);

    void next();

};

#endif //TP_POO_ILHA_H

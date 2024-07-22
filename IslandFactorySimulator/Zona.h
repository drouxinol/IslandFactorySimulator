//
// Created by Asus on 11/5/2021.
//

#ifndef TP_POO_ZONA_H
#define TP_POO_ZONA_H


#include "Recurso.h"
#include "Operario.h"
#include "Trabalhador.h"
#include "MinaFerro.h"
#include "MinaCarvao.h"
#include "CEletrica.h"
#include "Bateria.h"
#include "Fundicao.h"
#include "MinaOuro.h"
#include "Serracao.h"
#include <sstream>
#include <vector>

class Zona {

private:
    int id;
    static int id_zona;
    string tipo_zona;

protected:
    Edificio* edificio;
    vector<Trabalhador*> trabalhadores;

public:

    Zona();
    Zona(const Zona &other);
    virtual ~Zona();

    int getId() const;

    Trabalhador* get_trabalhador(float &id);
    bool is_edificio();
    virtual void adiciona_edificio(const string &tipo_edificio,int custo, int &dinheiro) = 0;
    void adiciona_edificio_debed(const string &tipo_edificio) ;
    void adiciona_trabalhador(Trabalhador *trabalhador);
    void elimina_trabalhador(float &id);
    bool verifica_trabalhador(const float &id);
    void liga_edificio();
    void desliga_edificio();
    void upgrade(int &dinheiro);
    virtual void despede() {};
    void add_recurso(vector<Recurso*> &vetor, Recurso* recurso);
    virtual void gera_recursos_edificios(vector<Recurso*> &recursos_ilha,Zona* acima, Zona* abaixo, Zona* direita, Zona* esquerda, Zona* zona,
                                         Edificio* edificio_zona, vector<Trabalhador*> &trabalhadores) = 0;
    void vende_edificio(int &dinheiro, vector<Recurso*> &recursos_ilha);
    Edificio* get_edificio();
    vector<Trabalhador*> getTrabalhadores() const;
    bool check_recurso(string &nome);
    virtual Recurso* gera_recursos(int &dia) {return nullptr;};
    virtual string get_tipo() = 0;
    bool check_dinheiro(Edificio* edificio, int &dinheiro);
    virtual Zona* duplica()  = 0 ;
    virtual string get_abreviatura() = 0;
    virtual void desaba(const int &dia) = 0;
    virtual bool verifica() {return false;};
};

#endif //TP_POO_ZONA_H

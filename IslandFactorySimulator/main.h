//
// Created by Asus on 11/2/2021.
//

#ifndef TP_POO_MAIN_H
#define TP_POO_MAIN_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Ilha.h"


using namespace std;

void abrefich(){

    fstream file;
    // abre ficheiro text.txt
    // file.open("text.txt",ios::in);

    if (!file) {
        cout << "File not created!";
    }
    else {
        cout << "File created successfully!";
        file.close();
    }
}

#endif //TP_POO_MAIN_H

#include <iostream>
#include <time.h>
#include "Interface.h"
#include "GameData.h"
using namespace std;

int main() {

    srand(time(NULL));
    auto *gD = new GameData();

    Interface i(gD);
    i.run();

    //return 0; nao funciona
    exit(0);
}

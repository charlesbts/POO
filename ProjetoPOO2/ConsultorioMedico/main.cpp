/*
 * File:   main.cpp
 * Author: Kelvin EC
 *
 * Created on 9 de Janeiro de 2013, 22:59
 */

#include <cstdlib>
#include "InterfaceUsuario/Headers/classeInterfaceUsuario.h"
using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
InterfaceUsuario *iu;
iu->cadastra_medico();
iu->procura_pessoa();
    return 0;
}


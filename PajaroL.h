#ifndef PAJAROL_H
#define PAJAROL_H

#include <iostream>
#include <vector>

#include <AvionL.h>
#include <PajaroG.h>

using namespace std;

class PajaroL{
    public:
        PajaroL(int);
        int numeroPajaros;
        int contadorPajaros;
        int maximoPajaros = 10;
        vector<PajaroG*> pajaros;

        void trasladarPajaros(vector<PajaroG*>);
        void crearPajaros(vector<PajaroG*> &_pajaros, int &_numeroPajaros);
        void matarAvion(AvionL &avion);
};


#endif // PAJAROL_H

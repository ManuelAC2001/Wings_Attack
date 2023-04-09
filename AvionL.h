#ifndef AVIONL_H
#define AVIONL_H

#include <iostream>
#include <cstdlib>
#include <gl\glut.h>

#include <iostream>
#include <vector>

//Efectos graficos
#include <AvionG.h>
#include <BalaG.h>
#include <CorazonG.h>

using namespace std;

class PajaroL;

class AvionL{
    public:
        AvionL();
        AvionG avionG;
        bool estaVivo = true;
        int it = -1; //este contador limitara el numero de balas cada que disparamos
        int numBalas = 4;
        int numeroVidas = 3;
        float puntaje = 0;
        CorazonG vidas[3];
        vector<BalaG*> balas;

        void disparar();
        void mover( int key, int PosX, int PosY );
        void keyboard(unsigned char key, int x, int y);
        void mostrarVidas();
        void matarPajaros(PajaroL &pajaroL);
};

#endif // AVIONL_H

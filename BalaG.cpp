#include "BalaG.h"
#include <windows.h>
#include <gl\glut.h>

BalaG::BalaG(){

}

void BalaG::graficar(float _x, float _y){

    x = _x;
    y = _y;

    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,disparo_rojo);

    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,disparo_naranja);

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,disparo_blanco);
}




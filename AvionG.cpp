#include "AvionG.h"
#include <windows.h>
#include <gl\glut.h>

AvionG::AvionG(){
    //ctor
}

void AvionG::graficar(float _x, float _y){
    x = _x;
    y = _y;

    //Contorno del avion
    glColor3f(0.0,0.0,0.0);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,avion_negro);

    //ventanas del avion
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,avion_azul);

    //color del avion
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,avion_amarillo);

    //sombras del avion
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glRasterPos2f(x, y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,avion_sombras);
}



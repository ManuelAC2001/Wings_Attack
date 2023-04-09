#include "CorazonG.h"
#include <windows.h>
#include <gl\glut.h>

CorazonG::CorazonG(){

}

void CorazonG::graficar(float _x, float _y){
    x = _x;
    y = _y;

    //contorno negro de la figura
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,contorno);

    //dibujado el color rojo
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,corazon_entero);

}


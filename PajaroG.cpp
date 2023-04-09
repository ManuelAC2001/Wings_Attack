#include "PajaroG.h"
#include <windows.h>
#include <gl\glut.h>

PajaroG::PajaroG(){

}

void PajaroG::graficar(float _x, float _y){
    x = _x;
    y = _y;

    //Contorno del pajaro
    glColor3f(0.0,0.0,0.0);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,contorno);


    //piel del pajaro verde
    glColor3f(0.08f, 0.6f, 0.007f);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,capa_verde);

    //reflejo del pajaro
    glColor3f(0.3f, 0.69f, 0.32f);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,reflejo_verde);

    //reflejo del pajaro
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,ojo);

    //pico del pajaro
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,pico_pajaro);

    //pata del pajaro
    glColor3f(1.0f, 0.5f, 0.0f);
    glRasterPos2f(x,y);
    glBitmap(64,60  ,0.0,0.0,0.0,0.0,pata_pajaro);
}

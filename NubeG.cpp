#include "NubeG.h"
#include <windows.h>
#include <gl\glut.h>

NubeG::NubeG(){
    //ctor
}

void NubeG::graficar(float _x, float _y){
    x = _x;
    y = _y;
    glColor3f(0.0,0.0,0.0);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,contornoNube);

    glColor3f(0.1f, 0.1f, 0.1f);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,sombraNube);

    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(x,y);
    glBitmap(64,60,0.0,0.0,0.0,0.0,blancoNubes);
}



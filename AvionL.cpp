#include "AvionL.h"
#include <PajaroL.h>
#include <stdlib.h>


AvionL::AvionL(){

}

void AvionL::disparar(){

    if(balas.size() > 0){
        balas[it]->graficar(balas[it]->x, balas[it]->y);
        balas[it]->x += 0.2;

        if(it > 0){
            for(int i=1; i<balas.size(); i++){
                balas[i-1]->graficar(balas[i-1]->x, balas[i-1]->y);
                balas[i-1]->x += 0.2;
            }
        }

    }
}



void AvionL::mover(int key, int PosX, int PosY){

    //movimientos del avion
    switch ( key ) {
        case GLUT_KEY_UP:
            if(avionG.y<=80){
                avionG.y+=1.5;
            }
        break;

        case GLUT_KEY_DOWN:
            if(avionG.y>=5){
                avionG.y-=1.5;
            }
        break;

        case GLUT_KEY_LEFT:
            if(avionG.x>1){
                avionG.x-=1.5;
            }
        break;

        case GLUT_KEY_RIGHT:
            if(avionG.x<40){
                avionG.x+=1.5;
            }
        break;
    }
}

void AvionL::keyboard(unsigned char key, int x, int y){

    if(key == 'F' || key== 'f'){
        //el avion va a disparar

        if(it < numBalas-1){
            it++;
            balas.push_back(new BalaG());
            balas[it]->x = avionG.x+8;
            balas[it]->y = avionG.y-1;
        }
        else{
            balas.clear();
            it = -1;
        }
    }
}

void AvionL::mostrarVidas(){
    //aqui graficamos los corazones que representan las vidas del jugador
    int _x = 95;
    for(int i=0; i<numeroVidas; i++){
        vidas[i].graficar(_x, 90);
        _x -= 5;
    }
}

void AvionL::matarPajaros(PajaroL &pajaroL){

    //calculo para la bala
    float cantidad_coordenadas = 100;
    float cantidad_pixeles = 800; //ancho de la ventana en pixeles
    float px_cd = cantidad_coordenadas/cantidad_pixeles;

    float resultadoX = (25 * px_cd);

    //coordenadas en y
    cantidad_pixeles = 600; //alto de la ventana en pixeles
    px_cd = cantidad_coordenadas/cantidad_pixeles;
    float resultadoY_S = ((600-565) * px_cd);
    float resultadoY_I = ((600-570) * px_cd);


    //calculo para el pajaro
    cantidad_pixeles = 600; //alto de la ventana en pixeles
    px_cd = cantidad_coordenadas/cantidad_pixeles;
    float P_resultadoY_S = ((600-555) * px_cd);
    float P_resultadoY_I = ((600-570) * px_cd);

    if(it > 0){ //entramos a la condicion porque el usuario puede disparar

        //revisamos bala por bala
        for(int j=0; j<pajaroL.pajaros.size(); j++){
            if(balas[it]->x + resultadoX >= pajaroL.pajaros[j]->x && ( (balas[it]->y + resultadoY_S <= pajaroL.pajaros[j]->y + P_resultadoY_S) && (balas[it]->y + resultadoY_I >= pajaroL.pajaros[j]->y + P_resultadoY_I) ) ){
                pajaroL.pajaros[j]->x = -1; //mandamos al pajaro al final del eje x para que sea eliminado
                pajaroL.pajaros.erase(pajaroL.pajaros.begin() + j);
                puntaje += 10;
                return;
            }
        }

    }

}



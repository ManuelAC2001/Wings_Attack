#include "PajaroL.h"
#include <stdlib.h>

void PajaroL::crearPajaros(vector<PajaroG*> &_pajaros, int &_numeroPajaros){
    for(int i=0; i<_numeroPajaros; i++){
            _pajaros.push_back(new PajaroG());
            _pajaros[i]->y = (rand()%70) + 1;
            _pajaros[i]->x = (rand()%100) + 70;
        }
}

PajaroL::PajaroL(int _numeroPajaros){
    numeroPajaros = _numeroPajaros;
    crearPajaros(pajaros, numeroPajaros);
}

void PajaroL::trasladarPajaros(vector<PajaroG*> pajaro){

    if(pajaro.size() <= 0){
        numeroPajaros++;

        //condicion para determinar el maximo de enemigos en pantalla
        if(numeroPajaros >= maximoPajaros){
            numeroPajaros = maximoPajaros;
        }
        crearPajaros(pajaro, numeroPajaros);
    }


    for(int i=0; i<pajaro.size(); i++){
        if(pajaro[i]->x >= -1){
            pajaro[i]->x -= 0.05;
        }else if(pajaro[i]->x <= -1){
            pajaro.erase(pajaro.begin()+i);
        }
    }
    pajaros = pajaro;
}

void PajaroL::matarAvion(AvionL &avion){

    if(avion.numeroVidas <= 0){
        avion.estaVivo = false;
        return;
    }

    //Codigo para detectar la colision entre pixeles
    float cantidad_coordenadas = 100;
    float cantidad_pixeles = 800; //ancho de la ventana en pixeles
    float px_cd = cantidad_coordenadas/cantidad_pixeles;

    float resultadoX = (63 * px_cd);

    //coordenadas en y
    cantidad_pixeles = 600; //alto de la ventana en pixeles
    px_cd = cantidad_coordenadas/cantidad_pixeles;
    float resultadoY_S = ((600-548) * px_cd);
    float resultadoY_I = ((600-585) * px_cd);


    //calculo para el pajaro
    cantidad_pixeles = 600; //alto de la ventana en pixeles
    px_cd = cantidad_coordenadas/cantidad_pixeles;
    float P_resultadoY_S = ((600-560) * px_cd);
    float P_resultadoY_I = ((600-570) * px_cd);

    for(int i=0; i<pajaros.size(); i++){
        if(pajaros[i]->x <= avion.avionG.x + resultadoX && (pajaros[i]->y  + P_resultadoY_S <= avion.avionG.y + resultadoY_S && pajaros[i]->y + P_resultadoY_I > avion.avionG.y + resultadoY_I)){

            if(pajaros[i]->x >= avion.avionG.x){
                //cambiamos la direccion en X del pajaro para evitar multiples colisiones
                pajaros[i]->x = -1;

                //hacemos algun codigo para representar la vida
                avion.numeroVidas--;
            }
        }
    }
}































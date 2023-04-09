#include "NubeL.h"
#include <NubeG.h>
#include <stdlib.h>

NubeL::NubeL(){
    for(int i=0; i<numeroNubes; i++){
            nubes[i].x = (rand()%90) + 1;
            nubes[i].y = (rand()%100) + 1;
    }

}

void NubeL::trasladarNube(NubeG* nube){

    for(int i= 0; i<numeroNubes; i++){
        if(nube[i].x >= -1){
            nube[i].x -= 0.01;
        }
        else if(nube[i].x <= -1){
            nube[i].x = 90;
            nube[i].y = (rand()%100) + 1;
        }
    }
}



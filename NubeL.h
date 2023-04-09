#ifndef NUBEL_H
#define NUBEL_H
#include <NubeG.h>

class NubeL{
    public:
        NubeL();
        //Propiedades para manejar la logica de las nubes
        static const int numeroNubes = 20;
        NubeG nubes[numeroNubes];
        void trasladarNube(NubeG*);

};

#endif // NUBEL_H

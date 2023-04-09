#include <windows.h>
#include <time.h>
#include <stdio.h>

//Elementos del juego
#include <PajaroL.h>
#include <AvionL.h>
#include <NubeL.h>

using namespace std;

//Propiedades para manejar la logica del avion
AvionL av1;

//Propiedades para manejar la logica de las nubes
NubeL nubeL;

//Propiedades para manejar la logica de los pajaros
PajaroL pajaroL = NULL;



void Inicializa(void){
    glClearColor (0.28, 0.89, 0.92, 0.0);    // Color de la ventana
    glMatrixMode (GL_PROJECTION);         // Parametros de proyeccion
    gluOrtho2D (0.0, 100.0, 0.0, 100.0);


    nubeL = NubeL();
    pajaroL = PajaroL(1);
}

void mover( int key, int PosX, int PosY ){
    //movimientos del avion
    av1.mover(key, PosX, PosY);
}

void Letras(int tipoletra, int PosX, int PosY, char *s){

    unsigned int i;
    glRasterPos2i(PosX,PosY);
    for ( i=0; i<strlen(s); i++)
        switch ( tipoletra ){
            case 1:
                glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);
                break;
            case 2:
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, s[i]);
                break;
            case 3:
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
                break;
            case 4:
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, s[i]);
                break;
            case 5:
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
                break;
            case 6:
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
                break;
        }
}

void contarPuntos(float puntaje){
    // lETRAS DE VIDA
    char Int_a_CHAR[20] ={0};
    sprintf(Int_a_CHAR, "%lf", puntaje);
    Letras(6,5,95,"PUNTOS : ");
    glColor3f(0.0,0.062,0.16);
    Letras(6,17,95,Int_a_CHAR);
}

void keyboard(unsigned char key, int x, int y){
    av1.keyboard(key, x, y);
}


void MatrizBitMap(void){
  glClear (GL_COLOR_BUFFER_BIT);


  //Contamos los puntos del personaje
  contarPuntos(av1.puntaje);

  //Manejando la logica del movimiento de las nubes con la clase NubeL
  for(int i=0; i<nubeL.numeroNubes; i++){
    nubeL.nubes[i].graficar(nubeL.nubes[i].x, nubeL.nubes[i].y);
  }
  nubeL.trasladarNube(nubeL.nubes);
  //Terminando de manejar la logica del movimiento de las nubes con la clase NubeL

  if(!av1.estaVivo){
    glColor3f(1.0,0.0,0.0);
    Letras(3,35,50,"JUEGO TERMINADO");
    glutPostRedisplay(); // Hace que los cuadros se le permitan morver muevan
    glFlush();
    return;
  }

  //graficando los corazones
  av1.mostrarVidas();


  //graficamos al avion

  av1.avionG.graficar(av1.avionG.x, av1.avionG.y);
  av1.disparar();
  av1.matarPajaros(pajaroL);
  //hacemos algo para que el programa deje de ejecutarse(??


  //pajaros
  pajaroL.matarAvion(av1);
  pajaroL.trasladarPajaros(pajaroL.pajaros);
  for(int i=0; i<pajaroL.numeroPajaros; i++){
    pajaroL.pajaros[i]->graficar(pajaroL.pajaros[i]->x , pajaroL.pajaros[i]->y);
  }

  //aumenta el puntaje
  av1.puntaje += 0.0050;

  glutPostRedisplay(); // Hace que los cuadros se le permitan morver muevan
  glFlush();
}

int main(int argc, char *argv[]){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB );

  //con esta funcion nos saldran vqalores (objetos diferentes)
  srand(time(NULL));

  glutInitWindowPosition (50, 100);
  glutInitWindowSize (800,600);
  glutCreateWindow ("WINGS ATTACK!");
  Inicializa();

  glutDisplayFunc(MatrizBitMap);
  glutSpecialFunc(mover);
  glutKeyboardFunc(keyboard);
  glutMainLoop();

  system("PAUSE");
  return EXIT_SUCCESS;
}





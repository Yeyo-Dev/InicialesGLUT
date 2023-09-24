/*
Equipo 2:
-Diaz Cruz Esteban David
-Echeverria Valencia Greta Alitzel
-Gomez Almazan Mart�n
-Serafin Velazquez Andrea Lizeth
-Torres Gallardo Angel Gabriel
-Vargas Hernandez Luis Abraham
*/
#include <cstdlib>
#include <iostream>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#include <gl\glut.h>
#else
#include <GL/freeglut.h>
#endif

using namespace std;

void Inicializa(void){
    glClearColor (1.0, 1.0, 1.0, 0.0); // Color de la ventana
    glMatrixMode (GL_PROJECTION); // Parametros de proyeccion
    gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

void lineasDivisoras (void){
    glVertex2i (100,155);
    glVertex2i (100, 0);

    glVertex2i (200,100);
    glVertex2i (0, 100);

    glVertex2i (200,50);
    glVertex2i (0, 50);
}

void lineaH(int x, int y, int largo){
    glVertex2i (x,y);
    glVertex2i (x+largo, y);
}
void lineaV(int x, int y, int largo){
    glVertex2i (x,y);
    glVertex2i (x,y+ largo);
}
void lineaDiagonalID(int x, int y, int largo){ // Diagonal asi /
    glVertex2i (x,y);
    glVertex2i (x+largo,y+ largo);
}
void lineaDiagonalDI(int x, int y, int largo){ /* Diagonal asi \ */
    glVertex2i (x,y+largo);
    glVertex2i (x+largo,y);
}


void letraA(int x, int y ){
    //Pata izquierda
    lineaV(x,y,12);
    lineaH(x,y,6);
    lineaV(x+6,y,6);

    lineaDiagonalID(x,y+12,4);
    lineaDiagonalDI(x+12,y+12,4);

    //Lineas del medio
    lineaH(x+6,y+6,4);
    lineaH(x+4,y+16,8);
    lineaH(x+6,y+9,4);
    lineaV(x+6,y+9,4);
    lineaV(x+10,y+9,4);
    lineaH(x+6,y+13,4);

    //Pata derecha
    lineaV(x+10,y,6);
    lineaH(x+10,y,6);
    lineaV(x+16,y,12);
}

void letraL(int x, int y ){
    lineaV(x,y,16);
    lineaV(x+6,y+5,11);
    lineaH(x,y,16);
    lineaH(x+6,y+5,10);
    lineaH(x,y+16,6);
    lineaV(x+16,y,5);
}

void letraE(int x, int y ){
    lineaV(x,y,16);
    lineaV(x+4,y+4,2); //Vertical de dentro
    lineaV(x+4,y+10,2); //Vertical de dentro
    lineaV(x+16,y+12,4);
    lineaH(x+4,y+12,12);

    lineaH(x+4,y+10,10);
    lineaV(x+14,y+6,4);
    lineaH(x+4,y+6,10);

    lineaH(x,y,16);
    lineaH(x+4,y+4,12);
    lineaH(x,y+16,16);
    lineaV(x+16,y,4);
}

void letraH(int x, int y){
    lineaV(x,y,16);
    lineaH(x,y,6);
    lineaH(x,y+16,6);

    lineaH(x+6,y+10,4);
    lineaH(x+6,y+6,4);
    lineaV(x+6,y,6);
    lineaV(x+6,y+10,6);

    lineaV(x+10,y,6);
    lineaV(x+10,y+10,6);

    lineaH(x+10,y,6);
    lineaH(x+10,y+16,6);
    lineaV(x+16,y,16);

}

void letraV(int x, int y ){

    lineaDiagonalDI(x,y,6);
    lineaV(x,y+6,10);
    lineaH(x,y+16,5);
    lineaV(x+5,y+7,9);
    lineaDiagonalDI(x+5,y+4,3);

    lineaH(x+6,y,4);

    lineaDiagonalID(x+8,y+4,3);
    lineaV(x+11,y+7,9);
    lineaDiagonalID(x+10,y,6);
    lineaV(x+16,y+6,10);
    lineaH(x+11,y+16,5);
}

void letraC(int x, int y) {
    lineaV(x, y+2, 12);          // Borde izquierdo vertical
    lineaDiagonalID(x,y+14,2);
    lineaH(x+2, y + 16, 12);     // Borde inferior horizontal
    lineaDiagonalDI(x+14,y+14,2);



    lineaH(x + 4, y + 12, 7);  // Borde inferior interno horizontal
    lineaV(x+16,y+10,4); //borde vertical hacia arriba de enfrente

    lineaV(x+11,y+10,2);//borde vertical de en medio hacia enfrente
    lineaH(x + 11, y + 10, 5);

    lineaH(x + 4, y + 4, 7);   // Borde superior interno horizontal
    lineaV(x + 4, y + 4, 8);   // Borde izquierdo interno vertical

    lineaV(x+11,y+4,2);//borde vertical de abajo hacia enfrente
    lineaH(x + 11, y + 6, 5);

    lineaDiagonalID(x+14,y,2);
    lineaV(x+16,y+2,4);// borde vertical de abajo hacia el frente
    lineaDiagonalDI(x,y,2);
    lineaH(x+2,y,12);

}

void letraD(int x, int y) {
    lineaV(x, y, 16);          // Borde izquierdo vertical
    lineaH(x, y + 16, 12);     // Borde inferior horizontal

    lineaDiagonalDI(x+12,y+12,4); //Diagonal de enfrete
    lineaV(x, y, 4);

    lineaH(x + 4, y + 12, 6);  // Borde inferior interno horizontal

    lineaDiagonalDI(x+10,y+10,2); //Diagonal de enfrete
     lineaV(x + 12, y + 6, 4);
    lineaDiagonalID(x+10,y+4,2);

    lineaH(x + 4, y + 4, 6);   // Borde superior interno horizontal
    lineaV(x + 4, y + 4, 8);   // Borde izquierdo interno vertical

    lineaDiagonalID(x+12,y,4);
    lineaH(x,y,12);
    lineaV(x + 16, y + 4, 8);
}

void letraG(int x, int y){

    lineaV(x,y+2,12);//Linea central
    lineaDiagonalID(x,y+14.5,2);
    lineaH(x+2,y+16,14);
    lineaV(x+16,y+12,4);
    lineaH(x+5,y+12,11);
    lineaV(x+5,y+4,8);
    lineaH(x+5,y+4,7);
    lineaV(x+12,y+4,3);
    lineaH(x+8,y+7,4);
    lineaV(x+8,y+7,3);

    lineaH(x+8,y+10,8);
    lineaV(x+16,y,10);
    lineaDiagonalDI(x,y,2);
    lineaH(x+2,y,14);

}

void letraM(int x, int y ){
    lineaV(x,y,16);
    lineaH(x,y+16,5);
    lineaH(x,y,5);
    lineaV(x+5,y,9);
    lineaDiagonalDI(x+5,y+13,3);
    lineaDiagonalID(x+8,y+13,3);

    lineaV(x+16,y,16);
    lineaH(x+11,y+16,5);
    lineaDiagonalDI(x+5,y+6,3);
    lineaDiagonalID(x+8,y+6,3);
    lineaV(x+11,y,9);
    lineaH(x+11,y,5);
}

void letraS(int x, int y){
    lineaV(x+16,y+12,4);
    lineaH(x+4,y+16,12);
    lineaH(x+6,y+12,10);
    lineaDiagonalID(x,y+12,4);
    lineaDiagonalID(x+4,y+10,2);

    lineaV(x,y+7,5);
    //lineaV(x+4,y+9,1);
    lineaDiagonalDI(x,y+6,1);

    lineaH(x+1,y+6,10);
    lineaH(x+4,y+10,11);
    lineaDiagonalDI(x+11,y+5, 1);
    lineaDiagonalDI(x+15,y+9,1);

    lineaV(x+12,y+4,1);
    //lineaV(x+15,y+7,1);
    lineaV(x+16,y+2,7);
    lineaH(x,y+4,12);
    lineaH(x,y,14);
    lineaDiagonalID(x+14,y,2);
    lineaV(x,y,4);

}

void letraT(int x, int y ){
    lineaV(x,y+11,5);
    lineaH(x,y+16,16);

    lineaV(x+11,y,11);
    lineaV(x+5,y,11);

    lineaH(x,y+11,5);
    lineaH(x+11,y+11,5);
    lineaH(x+5,y,6);
    lineaV(x+16,y+11,5);

}

void LetrasIniciales(void){
    int fila[] = {120,70,15};
    int columna[] = {10, 27, 44, 61};
    glClear (GL_COLOR_BUFFER_BIT); // Borra la ventana
    glColor3f (1.0, 0.0, 0.0 ); // Fija color rojo
    glBegin(GL_LINES);
        lineasDivisoras();
        //Las letras son de 16 x 16
        //Establece las coordenadas entre ellas con diferencia de 18

        //Diaz Cruz Esteban David
        glColor3f (0.0, 0.0, 0.0 ); // Fija color rojo
        letraD(columna[0]+8,fila[0]);
        letraC(columna[1]+8,fila[0]);
        letraE(columna[2]+8,fila[0]);
        letraD(columna[3]+8,fila[0]);

        //Echeverria Valencia Greta Alitzel
        glColor3f (1.0, 0.2, 0.6 ); // Fija color rojo
        letraE(columna[0] + 105,fila[0]);
        letraV(columna[1] + 105,fila[0]);
        letraG(columna[2] + 105,fila[0]);
        letraA(columna[3] + 105,fila[0]);

        //Gomez Almazan Mart�n
        glColor3f (0.3,0.0,0.6 ); // Fija color rojo
        letraG(columna[0]+15,fila[1]);
        letraA(columna[1]+15,fila[1]);
        letraM(columna[2]+15,fila[1]);

        //Seraf�n Velazquez Andrea Lizeth
        glColor3f (0.34, 0.77, 0.8 ); // Fija color rojo
        letraS(columna[0] + 105,fila[1]);
        letraV(columna[1] + 105,fila[1]);
        letraA(columna[2] + 105,fila[1]);
        letraL(columna[3] + 105,fila[1]);

        //Torres Gallardo Angel Gabriel
        glColor3f (0.0, 0.8, 0.8 ); // Fija color rojo
        letraT(columna[0] + 8,fila[2]);
        letraG(columna[1] + 8,fila[2]);
        letraA(columna[2] + 8,fila[2]);
        letraG(columna[3] + 8,fila[2]);

        //Vargas Hernandez Luis Abraham
        glColor3f (0.8, 0.2, 0.4 ); // Fija color rojo
        letraV(columna[0] + 105,fila[2]);
        letraH(columna[1] + 105,fila[2]);
        letraL(columna[2] + 105,fila[2]);
        letraA(columna[3] + 105,fila[2]);

    glEnd();
    glFlush(); // Procesa la rutina tan r�pido
    // como sea posible
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv); // Inicializa glut
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB ); // Establece el modo de
    // visualizacion
    glutInitWindowPosition (200, 100);
    glutInitWindowSize (800, 600); // Establece alto y ancho de la
    // ventana
    glutCreateWindow ("Iniciales del equipo 2");
    Inicializa();
    glutDisplayFunc(LetrasIniciales);
    glutMainLoop();
    system("PAUSE");
    return EXIT_SUCCESS;
}

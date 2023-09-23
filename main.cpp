//#include <GL/freeglut.h>
#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <gl\glut.h>
#include <string.h>

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
    lineaV(x+4,y+4,12);
    lineaH(x,y,16);
    lineaH(x+4,y+4,12);
    lineaH(x,y+16,4);
    lineaV(x+16,y,4);
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
    lineaV(x, y, 16);          // Borde izquierdo vertical
    lineaH(x, y + 16, 16);     // Borde inferior horizontal



    lineaH(x + 4, y + 12, 7);  // Borde inferior interno horizontal
    lineaV(x+16,y+10,6); //borde vertical hacia arriba de enfrente

    lineaV(x+11,y+10,2);//borde vertical de en medio hacia enfrente
    lineaH(x + 11, y + 10, 5);

    lineaH(x + 4, y + 4, 7);   // Borde superior interno horizontal
    lineaV(x + 4, y + 4, 8);   // Borde izquierdo interno vertical

    lineaV(x+11,y+4,2);//borde vertical de abajo hacia enfrente
    lineaH(x + 11, y + 6, 5);

    lineaV(x+16,y,6);// borde vertical de abajo hacia el frente
    lineaH(x,y,16);

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

void Letras(void){
int fila1=120,fila2=70,fila3=15;
int columna[] = {10, 27, 44, 61};
glClear (GL_COLOR_BUFFER_BIT); // Borra la ventana
glColor3f (1.0, 0.0, 0.0 ); // Fija color rojo
glBegin(GL_LINES);
    lineasDivisoras();
    //Las letras son de 16 x 16
    //Establece las coordenadas entre ellas con diferencia de 18

    //Diaz Cruz Esteban David
    glColor3f (0.0, 0.0, 0.0 ); // Fija color rojo
    letraD(columna[0],fila1);
    letraC(columna[1],fila1);
    letraE(columna[2],fila1);
    letraD(columna[3],fila1);

    //Echeverria Valencia Greta Alitzel
    glColor3f (1.0, 0.2, 0.6 ); // Fija color rojo
    letraE(columna[0] + 100,fila1);
    letraV(columna[1] + 100,fila1);
    letraG(columna[2] + 100,fila1);
    letraA(columna[3] + 100,fila1);

    //Gomez Almazan Martín
    glColor3f (0.3,0.0,0.6 ); // Fija color rojo
    letraG(columna[0],fila2);
    letraA(columna[1],fila2);
    letraM(columna[2],fila2);

    //Serafín Velazquez Andrea Lizeth
    glColor3f (0.34, 0.77, 0.8 ); // Fija color rojo
    //letraS(columna[0] + 100,fila2);
    letraV(columna[1] + 100,fila2);
    letraA(columna[2] + 100,fila2);
    letraL(columna[3] + 100,fila2);

    //Torres Gallardo Angel Gabriel
    glColor3f (0.0, 0.8, 0.8 ); // Fija color rojo
    //letraT(columna[0],fila3);
    letraG(columna[1],fila3);
    letraA(columna[2],fila3);
    letraG(columna[3],fila3);

    //Vargas Hernandez Luis Abraham
    glColor3f (0.8, 0.2, 0.4 ); // Fija color rojo
    letraV(columna[0] + 100,fila3);
    letraH(columna[1] + 100,fila3);
    letraL(columna[2] + 100,fila3);
    letraA(columna[3] + 100,fila3);

glEnd();
glFlush(); // Procesa la rutina tan rápido
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
glutDisplayFunc(Letras);
glutMainLoop();
system("PAUSE");
return EXIT_SUCCESS;
}

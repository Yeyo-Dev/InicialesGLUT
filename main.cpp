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
    //letraD(columna[0],fila1);
    //letraC(columna[1],fila1);
    letraE(columna[2],fila1);
    //letraD(columna[3],fila1);

    //Echeverria Valencia Greta Alitzel
    letraE(columna[0] + 100,fila1);
    letraV(columna[1] + 100,fila1);
    //letraG(columna[2] + 100,fila1);
    letraA(columna[3] + 100,fila1);

    //Gomez Almazan Martín
    //letraG(columna[0],fila2);
    letraA(columna[1],fila2);
    //letraM(columna[2],fila2);

    //Serafín Velazquez Andrea Lizeth
    //letraS(columna[0] + 100,fila2);
    letraV(columna[1] + 100,fila2);
    letraA(columna[2] + 100,fila2);
    letraL(columna[3] + 100,fila2);

    //Torres Gallardo Angel Gabriel
    //letraT(columna[0],fila3);
    //letraG(columna[1],fila3);
    letraA(columna[2],fila3);
    //letraG(columna[3],fila3);

    //Vargas Hernandez Luis Abraham
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
glutCreateWindow ("Iniciales del equipo");
Inicializa();
glutDisplayFunc(Letras);
glutMainLoop();
system("PAUSE");
return EXIT_SUCCESS;
}

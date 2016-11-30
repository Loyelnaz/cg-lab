#ifdef __APPLE__

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#else

#include <GL/gl.h>
#include <GL/glut.h>

#endif

#include <iostream>
using namespace std;

#define CAR 1

float car_points[8][3] = {
                            {0.0, 25.0, 0.0},
                            {90.0, 25.0, 0.0},
                            {90.0, 55.0, 0.0},
                            {80.0, 55.0, 0.0},
                            {80.0, 75.0, 0.0},
                            {20.0, 75.0, 0.0},
                            {20.0, 55.0, 0.0},
                            {0.0, 55.0, 0.0}
                        };

void carlist() {
    glNewList(CAR, GL_COMPILE);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
            for(int i = 0; i < 8; i++)
                glVertex3fv(car_points[i]);
        glEnd();
    glEndList();
}

void myKeyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 't': glutPostRedisplay();
                  break;
        case 'q': exit(0);
        default: break;
    }
}

void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(0.0, 110.0, 0.0, 100.0, 0.0, 100.0);
}

void draw_wheel() {
    glColor3f(0.0, 1.0, 1.0);
    glutSolidSphere(10, 25, 25);
}

void draw_body_wheel() {
    glTranslatef(5, 0.0, 0.0);
    glCallList(CAR);
    glPushMatrix();
    glTranslatef(25.0, 25.0, 0.0);
    draw_wheel();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(75.0, 25.0, 0.0);
    draw_wheel();
    glPopMatrix();
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    carlist();
    draw_body_wheel();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Car Design");
    myInit();
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(myKeyboard);
    glutMainLoop();
}

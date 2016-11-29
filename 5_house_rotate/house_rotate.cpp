#ifdef __APPLE__

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#else

#include <GL/gl.h>
#include <GL/glut.h>

#endif

#include <iostream>
#include <math.h>
using namespace std;

float theta, h, k;
float house[2][9] = {{100.0, 100.0, 250.0, 250.0, 175.0, 150.0, 150.0, 200.0, 200.0},
                     {100.0, 300.0, 300.0, 100.0, 400.0, 100.0, 150.0, 150.0, 100.0}
                    };

void draw_house() {
    glBegin(GL_LINE_LOOP);
        glVertex2f(house[0][0], house[1][0]);
        glVertex2f(house[0][1], house[1][1]);
        glVertex2f(house[0][2], house[1][2]);
        glVertex2f(house[0][3], house[1][3]);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(house[0][5], house[1][5]);
        glVertex2f(house[0][6], house[1][6]);
        glVertex2f(house[0][7], house[1][7]);
        glVertex2f(house[0][8], house[1][8]);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(house[0][1], house[1][1]);
        glVertex2f(house[0][4], house[1][4]);
        glVertex2f(house[0][2], house[1][2]);
    glEnd();
}

void myInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-200.0, 500.0, -200.0, 500.0);
    glColor3f(1.0, 0.0, 0.0);
}

void rotate() {
    glPushMatrix();
    glTranslatef(h, k, 0.0);
    glRotatef(theta, 0.0, 0.0, 1.0);
    glTranslatef(-h, -k, 0.0);
    draw_house();
    glPopMatrix();
}

void myDisplay() {
    draw_house();
    rotate();
    glFlush();
}

int main(int argc, char **argv) {
    cout << "Enter the rotation angle : ";
    cin >> theta;
    cout << "Enter the pivot point position : ";
    cin >> h >> k;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("House Rotation");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}

#ifdef __APPLE__

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <math.h>
#include <iostream>

using namespace std;

float house[2][9]={ {100.0, 100.0, 250.0, 250.0, 175.0, 150.0, 150.0, 200.0, 200.0},
                    {100.0, 300.0, 300.0, 100.0, 400.0, 100.0, 150.0, 150.0, 100.0}
                  };

float theta, m, c;

void draw_house() {
    glBegin(GL_LINE_LOOP);
        glVertex2f(house[0][0],house[1][0]);
        glVertex2f(house[0][1],house[1][1]);
        glVertex2f(house[0][2],house[1][2]);
        glVertex2f(house[0][3],house[1][3]);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(house[0][5],house[1][5]);
        glVertex2f(house[0][6],house[1][6]);
        glVertex2f(house[0][7],house[1][7]);
        glVertex2f(house[0][8],house[1][8]);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(house[0][1],house[1][1]);
        glVertex2f(house[0][4],house[1][4]);
        glVertex2f(house[0][2],house[1][2]);
    glEnd();
}

void myInit() {
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-300, 500.0, -300, 500.0);
    glColor3f(1.0, 0.0, 0.0);
}

void reflect() {
    float x1 = 0, x2 = 500;
    float y1 = m * x1 + c;
    float y2 = m * x2 + c;

    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    glTranslatef(0, c, 0);
    glRotatef(theta, 0, 0, 1);
    glScalef(1, -1, 1);
    glRotatef(-theta, 0, 0, 1);
    glTranslatef(0,-c, 0);
    draw_house();
}

void myDisplay() {
    draw_house();
    reflect();
    glFlush();
}

int main(int argc, char* argv[]) {
    cout << "Enter the slope(m) and intercept(c): ";
    cin >> m >> c;
    theta = atan(m);
    theta = theta * 180 / 3.14159265;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("house rotation");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}

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

float theta, thetar, h, k;
float house[3][9] = {{100.0, 100.0, 250.0, 250.0, 175.0, 150.0, 150.0, 200.0, 200.0},
                     {100.0, 300.0, 300.0, 100.0, 400.0, 100.0, 150.0, 150.0, 100.0},
                     {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}
                    };
float rotate_matrix[3][3] = {{0}, {0}, {0}};
float result[3][9] = {{0}, {0}, {0}};

void multiply() {
	int i,j,l;
	for(i = 0; i < 3; i++) {
	   for(j = 0; j < 9; j++) {
	       result[i][j] = 0;
	       for(l = 0; l < 3; l++)
		         result[i][j] = result[i][j] + rotate_matrix[i][l] * house[l][j];
	    }
    }
}

void rotate() {
	float m,n;
	m = h * (1 - cos(thetar)) + k * (sin(thetar));
	n = -k * (1 - cos(thetar)) - h * (sin(thetar));
	rotate_matrix[0][0] = cos(thetar);
	rotate_matrix[0][1] = -sin(thetar);
	rotate_matrix[0][2] = m;
	rotate_matrix[1][0] = sin(thetar);
	rotate_matrix[1][1] = cos(thetar);
	rotate_matrix[1][2] = n;
	rotate_matrix[2][0] = 0;
	rotate_matrix[2][1] = 0;
	rotate_matrix[2][2] = 1;
	multiply();
}

void draw_house() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(house[0][0], house[1][0]);
        glVertex2f(house[0][1], house[1][1]);
        glVertex2f(house[0][2], house[1][2]);
        glVertex2f(house[0][3], house[1][3]);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(house[0][5], house[1][5]);
        glVertex2f(house[0][6], house[1][6]);
        glVertex2f(house[0][7], house[1][7]);
        glVertex2f(house[0][8], house[1][8]);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(house[0][1], house[1][1]);
        glVertex2f(house[0][4], house[1][4]);
        glVertex2f(house[0][2], house[1][2]);
    glEnd();
}

void draw_rotated_house() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(result[0][0], result[1][0]);
        glVertex2f(result[0][1], result[1][1]);
        glVertex2f(result[0][2], result[1][2]);
        glVertex2f(result[0][3], result[1][3]);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(result[0][5], result[1][5]);
        glVertex2f(result[0][6], result[1][6]);
        glVertex2f(result[0][7], result[1][7]);
        glVertex2f(result[0][8], result[1][8]);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(result[0][1], result[1][1]);
        glVertex2f(result[0][4], result[1][4]);
        glVertex2f(result[0][2], result[1][2]);
    glEnd();
}

void myInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void myDisplay() {
    draw_house();
    rotate();
    draw_rotated_house();
    glFlush();
}

int main(int argc, char **argv) {
    cout << "Enter the rotation angle : ";
    cin >> theta;
    cout << "Enter the pivot point position : ";
    cin >> h >> k;
    thetar = theta * 3.141 / 180;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("House Rotation");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}

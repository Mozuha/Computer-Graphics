/*
CS 330 ‐ Assignment KEY

  1.  Scroll through the source code below.  Take particular note of the
‐ Point2 and Color 3 vectors
‐ delta and deltaT variables
‐ TWEEN vector
‐ note how the IDLE function, CalcTween, calculates the new vertices and then posts a redisplay
‐ note how the display function simply renders the 6 vertices of the TWEEN vector
‐ note that the clipping volume is (‐100,‐100) to (100,100)

  2.  Fill in the x‐y values for 6 vertices of some 2‐D shape, in the shape1 vector

  3.  Fill in the x‐y values for 6 vertices of some 2‐D shape, in the shape2 vector

  4.  Define your two colors in color1 and color2 vectors

  5.  fill in the code to calculate the interpolated colors

  6.  fill‐in the code to calculate the interpolated vertices
*/

#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
using namespace std;

#define WINDOWSIZE 400
//  defining a type "point," of size 2
typedef GLfloat Point2[2];
//  defining a type "color," of size 3
typedef GLfloat Color3[3];
#define NUMPOINTS 12

// define a 2‐d shape, using 12 vertices
Point2 shape1[NUMPOINTS] = { 
  {-25,-25}, {25,-25}, {25,50}, {50,50}, {50,25}, {50,-25}, {50,-50}, {-50,-50}, {-50,-25}, {-50,25}, {-50,50}, {-25,50} 
};

// define another 2‐d shape, using 12 vertices
Point2 shape2[NUMPOINTS] = {
  {-25,50}, {25,50}, {25,25}, {13,25}, {13,-25}, {25,-25}, {25,-50}, {-25,-50}, {-25,-25}, {-13,-25}, {-13,25}, {-25,25} 
};

// array used for the points beTWEEN shapes
Point2 tween[NUMPOINTS];

// define your first color
//orange
Color3 color1 = { 1 , 0.5  , 0 };

// define your second color
//blue
Color3 color2 = { 0 , 0  , 1 };

// define the parameters
GLfloat t = 0.0;

// MAKE deltaI LARGER OR SMALLER IF THE MORPHING HAPPENS TOO SLOWLY OR QUICKLY
GLfloat deltaT = 0.0005;

void myInit() {
  // initialize the beTWEEN array
  GLint i, j;
  for (i = 0; i < NUMPOINTS; i++) {
    for (j = 0; j < 2; j++) {
      tween[i][j] = shape1[i][j];
    }
  }

  glClearColor(1.0, 1.0, 1.0, 0.0);

  // initialize the color
  glColor3f(color1[0], color1[1], color1[2]);
  glLineWidth(4.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-100, 100, -100, 100);
  glMatrixMode(GL_MODELVIEW);
}

void display() {
  GLint i;
  glClear(GL_COLOR_BUFFER_BIT);

  // render the morphed shape
  glBegin(GL_LINE_LOOP);
  for (i = 0; i < NUMPOINTS; i++) {
    glVertex2fv(tween[i]);
  }
  glEnd();

  glutSwapBuffers();
}

void CalcTween() {
  GLint i, j;
  t += deltaT;

  // calculate the morphed color
  glColor3f(color1[0] + t * (color2[0] - color1[0]), color1[1] + t * (color2[1] - color1[1]), color1[2] + t * (color2[2] - color1[2]));

  // calculate the morphed shape
  for (i = 0; i < NUMPOINTS; i++) {
    for (j = 0; j < 2; j++) {
      tween[i][j] = shape1[i][j] + t * (shape2[i][j] - shape1[i][j]);
    }
  }

  if (t >= 1.0 || t <= 0.0) deltaT = -deltaT;
  glutPostRedisplay();
}

void mouse(GLint btn, GLint state, GLint x, GLint y) {
  if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    glutIdleFunc(CalcTween);
  }

  if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
    glutIdleFunc(NULL);
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(WINDOWSIZE, WINDOWSIZE);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Interpolation");
  myInit();
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;
}
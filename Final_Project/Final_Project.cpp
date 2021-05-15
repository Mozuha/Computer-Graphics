#include <cstdlib>
#include <GL/glut.h>
#include "Object/Icosahedron/Icosahedron.h"
#include "Object/Sundial/Sundial.h"
#include "Object/Gate/Gate.h"
#include "Object/Lantern/Lantern.h"
#include "Object/Wall/Wall.h"
#include "Object/Road/Road.h"
#include "Object/Light/Light.h"
#include "Material/Material_types.h"

// light position
GLfloat xl = -20.0, yl = 25.0, zl = 25.0;

// initial camera position
GLfloat eyex = 0, eyey = 5, eyez = 25;

// for axis rotation
static GLfloat theta[] = { 0.0, 0.0, 0.0 };
static GLint axis = 2;

// for rotating object
GLfloat ico_theta_r = 0.0;
GLfloat ico_theta_t = 0.0;
GLfloat sd_theta = 0.0;
GLfloat gate_theta = 0.0;
GLfloat lant_theta = 0.0;
bool ico_turn = false;
bool lant_turn = false;

// construct objects
Icosahedron icosahedron = Icosahedron();
Sundial sundial = Sundial();
Gate gate = Gate();
Lantern lantern = Lantern();
Wall ground = Wall(GROUND);
Wall wall = Wall(WALL);
Road road = Road();
Light sunlight = Light(xl, yl, zl, SUN_LIGHT);

void myInit() {
	glClearColor(0.62500, 0.69531, 0.72656, 1.0);  // crowdy

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	// light
	//glEnable(GL_LIGHT0);
	GLfloat light_position[] = { xl, yl, zl, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat light_specular[] = { 0.7, 0.7, 0.7, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	// fog
	glEnable(GL_FOG);
	GLfloat fogColor[4] = { 0.62500, 0.69531, 0.72656, 1.0 };
	glFogi(GL_FOG_MODE, GL_EXP2);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, 0.05);
	glHint(GL_FOG_HINT, GL_DONT_CARE);
	glFogf(GL_FOG_START, 1.0);
	glFogf(GL_FOG_END, -25.0);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80, 1, 5, 60);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// placing camera
	gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
	glRotatef(theta[0], 1.0, 0.0, 0.0);  // x-axis
	glRotatef(theta[1], 0.0, 1.0, 0.0);  // y-axis
	glRotatef(theta[2], 0.0, 0.0, 1.0);  // z-axis

	/*glPushMatrix();
	sunlight.render();
	glPopMatrix();*/

	// icosahedron
	glPushMatrix();
	glTranslatef(-3.5+ico_theta_t, 1.3, 18.0);
	glRotatef(ico_theta_r, 0.0, 0.0, 1.0);
	icosahedron.render();
	glPopMatrix();

	// sundial
	glPushMatrix();
	glTranslatef(0.0, 0.25, 15.0);
	glRotatef(sd_theta, 0.0, 1.0, 0.0);
	sundial.render();
	glPopMatrix();

	// gates
	for (GLint i = 10; i > -20; i -= 4) {
		glPushMatrix();
		glTranslatef(0.0, 0.0, GLfloat(i));
		glRotatef(gate_theta, 0.0, 1.0, 0.0);
		gate.render();
		glPopMatrix();
	}

	// lanterns
	for (GLint i = 8; i > -20; i -= 4) {
		glPushMatrix();
		glTranslatef(-5.0, 0.0, GLfloat(i));
		glRotatef(lant_theta, 0.0, 0.0, 1.0);
		lantern.render();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(5.0, 0.0, GLfloat(i));
		glRotatef(lant_theta, 0.0, 0.0, 1.0);
		lantern.render();
		glPopMatrix();
	}

	// walls
	glPushMatrix();
	ground.render();
	glTranslatef(15.0, 7.5, 0.0);
	glScalef(1.0, 0.5, 1.0);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	wall.render();
	glTranslatef(0.0, 15.0, -20.0);
	glScalef(1.0, 0.75, 1.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	wall.render();
	glPopMatrix();

	// road
	glPushMatrix();
	glTranslatef(0.0, 0.5, -4.0);
	road.render();
	glPopMatrix();

	glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y) {
	// change camera position
	if (key == '1') { eyex += 0.2;glutPostRedisplay(); }
	if (key == '2') { eyex -= 0.2;glutPostRedisplay(); }
	if (key == '5') { eyey += 0.2;glutPostRedisplay(); }
	if (key == '6') { eyey -= 0.2;glutPostRedisplay(); }
	if (key == '9') { eyez += 0.2;glutPostRedisplay(); }
	if (key == '0') { eyez -= 0.2;glutPostRedisplay(); }

	// rotate around x-, y-, or z-axis
	if (key == 'x') { axis = 0; theta[axis] += 2.0; glutPostRedisplay(); }  // rotate around x-axis
	if (key == 'X') { axis = 0; theta[axis] -= 2.0; glutPostRedisplay(); }  // rotate around x-axis
	if (key == 'y') { axis = 1; theta[axis] += 2.0; glutPostRedisplay(); }  // rotate around y-axis
	if (key == 'Y') { axis = 1; theta[axis] -= 2.0; glutPostRedisplay(); }  // rotate around y-axis
	if (key == 'z') { axis = 2; theta[axis] += 2.0; glutPostRedisplay(); }  // rotate around z-axis
	if (key == 'Z') { axis = 2; theta[axis] -= 2.0; glutPostRedisplay(); }  // rotate around z-axis
	if (theta[axis] > 360.0) theta[axis] -= 360.0;

	if (key == 'q' || key == 'Q') exit(0);
}

void spinObject() {
	sd_theta -= 0.2;
	gate_theta += 0.02;

	ico_turn == true ? ico_theta_t += 0.005 : ico_theta_t -= 0.005;
	ico_turn == true ? ico_theta_r -= 0.2 : ico_theta_r += 0.2;
	if (ico_theta_t < -9.0) ico_turn = true;
	if (ico_theta_t > -1.0) ico_turn = false;

	lant_turn == true ? lant_theta -= 0.1 : lant_theta += 0.1;
	if (lant_theta < -70.0) lant_turn = false;
	if (lant_theta > 70.0) lant_turn = true;

	glutPostRedisplay();
}

void mouse(GLint btn, GLint state, GLint x, GLint y) {
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		glutIdleFunc(spinObject);
	}

	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		glutIdleFunc(NULL);
	}
}

void myReshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (double)w / h, 1, 20);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Final_Project");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST);

	myInit();

	glutMainLoop();
}

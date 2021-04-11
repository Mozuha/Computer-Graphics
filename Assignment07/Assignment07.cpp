/*
* Mizuki Hashimoto
* Mar 31, 2021
*
* Render a box man utilizing OpenGL transformations (glTranslatef, glRotatef, glScalef) and glutWireCube.
* Each component (torso, head, left arm, left leg, right arm, right leg) is separately rotatable.
* All components are "child" of torso, and so when torso rotate, other components rotate as well.
* The components dependencies are considered using scene graph.
* Using gluPerspective for projection and gluLookAt to place the camera.
*/

#define TORSO_WIDTH 3.0
#define TORSO_HEIGHT 5.0

#define HEAD_WIDTH 1.0
#define HEAD_HEIGHT 1.0

#define ARM_WIDTH 0.5
#define ARM_HEIGHT 3.0

#define LEG_WIDTH 1.0
#define LEG_HEIGHT 3.0

#include <GL/glut.h>
#include <cstdlib>

GLint tDegree = 0, hDegree = 0, laDegree = 180, raDegree = 180, llDegree = 180, rlDegree = 180;

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(105, 1, 3, 15);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	gluLookAt(4, 6, 8, 0, 0, 0, 0, 1, 0);
}

void torso() {
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(0, 0.5 * TORSO_HEIGHT, 0);
	glScalef(TORSO_WIDTH, TORSO_HEIGHT, TORSO_WIDTH);
	glutWireCube(1.0);
	glPopMatrix();
}

void head() {
	glColor3f(0.99, 0.08, 0.57);
	glPushMatrix();
	glTranslatef(0, 0.5 * HEAD_HEIGHT, 0);
	glScalef(HEAD_WIDTH, HEAD_HEIGHT, HEAD_WIDTH);
	glutWireCube(1.0);
	glPopMatrix();
}

void arm() {
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0, 0.5 * ARM_HEIGHT, 0);
	glScalef(ARM_WIDTH, ARM_HEIGHT, ARM_WIDTH);
	glutWireCube(1.0);
	glPopMatrix();
}

void leg() {
	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(0, 0.5 * LEG_HEIGHT, 0);
	glScalef(LEG_WIDTH, LEG_HEIGHT, LEG_WIDTH);
	glutWireCube(1.0);
	glPopMatrix();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(4, 6, 8, 0, 0, 0, 0, 1, 0);

	// torso & head
	glRotatef(tDegree, 0, 1, 0);
	glPushMatrix();
	torso();
	glTranslatef(0, TORSO_HEIGHT, 0);
	glRotatef(hDegree, 0, 1, 0);
	head();
	glPopMatrix();

	// left arm
	glPushMatrix();
	glTranslatef(-((0.5 * TORSO_WIDTH) + (0.5 * ARM_WIDTH)), TORSO_HEIGHT, 0);
	glRotatef(laDegree, 1, 0, 0);
	arm();
	glPopMatrix();

	// left leg
	glPushMatrix();
	glTranslatef(-(0.25 * TORSO_WIDTH), 0, 0);
	glRotatef(llDegree, 1, 0, 0);
	leg();
	glPopMatrix();

	// right arm
	glPushMatrix();
	glTranslatef((0.5 * TORSO_WIDTH) + (0.5 * ARM_WIDTH), TORSO_HEIGHT, 0);
	glRotatef(raDegree, 1, 0, 0);
	arm();
	glPopMatrix();

	// right leg
	glPushMatrix();
	glTranslatef((0.25 * TORSO_WIDTH), 0, 0);
	glRotatef(rlDegree, 1, 0, 0);
	leg();
	glPopMatrix();

	glFlush();
}

void keyboard(unsigned char key, GLint x, GLint y)
{
	switch (key)
	{
	case 't':
		tDegree = (tDegree + 4);
		glutPostRedisplay();
		break;

	case 'T':
		tDegree = (tDegree - 4) % 360;
		glutPostRedisplay();
		break;

	case 'h':
		hDegree = (hDegree + 4);
		glutPostRedisplay();
		break;

	case 'H':
		hDegree = (hDegree - 4) % 360;
		glutPostRedisplay();
		break;

	case 'l':
		laDegree = (laDegree + 4);
		glutPostRedisplay();
		break;

	case 'L':
		laDegree = (laDegree - 4) % 360;
		glutPostRedisplay();
		break;

	case 'r':
		raDegree = (raDegree + 4) % 360;
		glutPostRedisplay();
		break;

	case 'R':
		raDegree = (raDegree - 4) % 360;
		glutPostRedisplay();
		break;

	case 'k':
		llDegree = (llDegree + 4) % 360;
		glutPostRedisplay();
		break;

	case 'K':
		llDegree = (llDegree - 4) % 360;
		glutPostRedisplay();
		break;

	case 'e':
		rlDegree = (rlDegree + 4) % 360;
		glutPostRedisplay();
		break;

	case 'E':
		rlDegree = (rlDegree - 4) % 360;
		glutPostRedisplay();
		break;

	case 'q':
		exit(0);

	}

	glutPostRedisplay();

	return;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Box Man");
	myInit();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}
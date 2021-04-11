/*
* Mizuki Hashimoto
* Feb 23, 2021
*
* Output analog clock face with hour handle and minute handle.
* Hour and minute are settable at compile time.
* Minute increment by left clicking.
* Quit application by press 'q' or 'Q'.
* 
* Q. Do you have problems with aliasing?
* A. Yes, I can see jaggy lines.
*/

#include <GL/glut.h>
#include <cstdlib>

#define WINDOW 600
#define PI 3.141592654f

GLint innerBorder = 0.05 * WINDOW;
GLint clockSize = WINDOW - innerBorder * 2;
GLfloat center = WINDOW / 2;
GLfloat radius = clockSize / 2;

GLfloat hrTickStart = 0.93 * radius;
GLfloat hrTickStop = 0.77 * radius;
GLfloat minTickStart = 0.93 * radius;
GLfloat minTickStop = 0.88 * radius;
GLfloat hrHandleStart = 0.6 * radius;
GLfloat minHandleStart = 0.85 * radius;

GLint hr = 23;
GLint min = 55;
GLfloat hrAngle, minAngle;

void myInit(void) {
	// attributes
	glClearColor(0.96470, 0.95686, 0.96078, 0.0);  // #F6F4F5
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(6.0);

	//set up viewing
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WINDOW, 0.0, WINDOW);
	glMatrixMode(GL_MODELVIEW);
}

void clockFace(GLfloat xcenter, GLfloat ycenter, GLfloat radius) {

	// center dot
	glBegin(GL_POINTS);
		glColor3f(0.31765f, 0.45098f, 0.47451f);  // #517379
		glVertex2f(xcenter, ycenter);
	glEnd();

	// draw hour ticks
	glBegin(GL_LINES);
		glColor3f(0.85098f, 0.65490f, 0.72549f);  // #D9A7B9
		for (GLint i = 1; i <= 12; i++) {
			GLfloat angle = (PI * i) / 6.0;
			glVertex2f(xcenter + sin(angle) * hrTickStart, ycenter + cos(angle) * hrTickStart);
			glVertex2f(xcenter + sin(angle) * hrTickStop, ycenter + cos(angle) * hrTickStop);
		}
	glEnd();

	// draw minute ticks
	glBegin(GL_LINES);
		glColor3f(0.61569f, 0.55686f, 0.74902f);  // #9D8EBF
		for (GLint i = 1; i <= 60; i++) {
			if (i % 5 == 0) continue;
			GLfloat angle = (PI * i) / 30.0;
			glVertex2f(xcenter + sin(angle) * minTickStart, ycenter + cos(angle) * minTickStart);
			glVertex2f(xcenter + sin(angle) * minTickStop, ycenter + cos(angle) * minTickStop);
		}
	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	// border around the clock
	glBegin(GL_LINE_LOOP);
		glColor3f(0.27451f, 0.19608f, 0.54902f);  // #46328C
		glVertex2f(innerBorder, innerBorder);
		glVertex2f(WINDOW - innerBorder, innerBorder);
		glVertex2f(WINDOW - innerBorder, WINDOW - innerBorder);
		glVertex2f(innerBorder, WINDOW - innerBorder);
	glEnd();

	// clock face
	clockFace(center, center, clockSize/2);

	// hour handle
	glBegin(GL_LINES);
		glColor3f(0.57647f, 0.38431f, 0.85098f);  // #9362D9
		hrAngle = (PI / 6.0) * ((hr % 12) + (min % 60) / 60.0);
		glVertex2f(center + sin(hrAngle) * hrHandleStart, center + cos(hrAngle) * hrHandleStart);
		glVertex2f(center, center);
	glEnd();

	// minute handle
	glBegin(GL_LINES);
		glColor3f(0.57647f, 0.38431f, 0.85098f);  // #9362D9
		minAngle = (PI * (min % 60)) / 30.0;
		glVertex2f(center + sin(minAngle) * minHandleStart, center + cos(minAngle) * minHandleStart);
		glVertex2f(center, center);
	glEnd();

	glFlush();
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		min++;
		if (min % 60 == 0) hr++;
		display();
	}
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'q' || key == 'Q') exit(0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW, WINDOW);
	glutInitWindowPosition(90, 90);
	glutCreateWindow("Analog clock");
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
}
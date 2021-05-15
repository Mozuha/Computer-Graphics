/*
* Mizuki Hashimoto
* Mar 24, 2021
*
* Morph from 3D "T" to "K" and morph back.
* Each figure is composed of four boxes.
* Each face (top, bottom, left side, right side, front, back) is differently colored.
* Rotatable about x, y, and z-axis.
*/

#include <GL/glut.h>
#include <cstdlib>

#define NUMVERTICES 32  // 4 boxes

GLfloat t = 0.0;  // interpolation factor (where on the way of morphing)
GLfloat deltaT = 0.0005;  // change in t per once
static GLfloat theta[] = { 0.0, 0.0, 0.0 };
static GLint axis = 2;

GLfloat Tvertices[][3] = {
	{-1.5, 0.5, -0.5}, {-0.5, 0.5, -0.5},
	{-0.5, 1.5, -0.5}, {-1.5, 1.5, -0.5},
	{-1.5, 0.5, 0.5}, {-0.5, 0.5, 0.5},
	{-0.5, 1.5, 0.5}, {-1.5, 1.5, 0.5},

	{-0.5, 0.5, -0.5}, {0.5, 0.5, -0.5},
	{0.5, 1.5, -0.5}, {-0.5, 1.5, -0.5},
	{-0.5, 0.5, 0.5}, {0.5, 0.5, 0.5},
	{0.5, 1.5, 0.5}, {-0.5, 1.5, 0.5},

	{0.5, 0.5, -0.5}, {1.5, 0.5, -0.5},
	{1.5, 1.5, -0.5}, {0.5, 1.5, -0.5},
	{0.5, 0.5, 0.5}, {1.5, 0.5, 0.5},
	{1.5, 1.5, 0.5}, {0.5, 1.5, 0.5},

	{-0.5, -1.5, -0.5}, {0.5, -1.5, -0.5},
	{0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5},
	{-0.5, -1.5, 0.5}, {0.5, -1.5, 0.5},
	{0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5}
};

GLfloat Kvertices[][3] = {
	{-1.4, -1.5, -0.5}, {-0.5, -1.5, -0.5},
	{-0.5, 1.5, -0.5}, {-1.4, 1.5, -0.5},
	{-1.4, -1.5, 0.5}, {-0.5, -1.5, 0.5},
	{-0.5, 1.5, 0.5}, {-1.4, 1.5, 0.5},

	{-0.5, -0.5, -0.5}, {0.3, -0.1, -0.5},
	{0.3, 0.1, -0.5}, {-0.5, 0.5, -0.5},
	{-0.5, -0.5, 0.5}, {0.3, -0.1, 0.5},
	{0.3, 0.1, 0.5}, {-0.5, 0.5, 0.5},

	{-0.5, 0.5, -0.5}, {0.3, 0.1, -0.5},
	{1.5, 1.5, -0.5}, {0.6, 1.5, -0.5},
	{-0.5, 0.5, 0.5}, {0.3, 0.1, 0.5},
	{1.5, 1.5, 0.5}, {0.6, 1.5, 0.5},

	{0.6, -1.5, -0.5}, {1.5, -1.5, -0.5},
	{0.3, -0.1, -0.5}, {-0.5, -0.5, -0.5},
	{0.6, -1.5, 0.5}, {1.5, -1.5, 0.5},
	{0.3, -0.1, 0.5}, {-0.5, -0.5, 0.5}
};

GLfloat tween[][3] = {
	{-1.5, 0.5, -0.5}, {-0.5, 0.5, -0.5},
	{-0.5, 1.5, -0.5}, {-1.5, 1.5, -0.5},
	{-1.5, 0.5, 0.5}, {-0.5, 0.5, 0.5},
	{-0.5, 1.5, 0.5}, {-1.5, 1.5, 0.5},

	{-0.5, 0.5, -0.5}, {0.5, 0.5, -0.5},
	{0.5, 1.5, -0.5}, {-0.5, 1.5, -0.5},
	{-0.5, 0.5, 0.5}, {0.5, 0.5, 0.5},
	{0.5, 1.5, 0.5}, {-0.5, 1.5, 0.5},

	{0.5, 0.5, -0.5}, {1.5, 0.5, -0.5},
	{1.5, 1.5, -0.5}, {0.5, 1.5, -0.5},
	{0.5, 0.5, 0.5}, {1.5, 0.5, 0.5},
	{1.5, 1.5, 0.5}, {0.5, 1.5, 0.5},

	{-0.5, -1.5, -0.5}, {0.5, -1.5, -0.5},
	{0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5},
	{-0.5, -1.5, 0.5}, {0.5, -1.5, 0.5},
	{0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5}
};

GLfloat colors[][3] = {
	{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, 
	{1.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, 
	{0.0, 0.0, 1.0}, {1.0, 0.0, 1.0},
	{1.0, 1.0, 1.0}, {0.0, 1.0, 1.0}
};

void polygon(int a, int b, int c, int d) {
	glBegin(GL_POLYGON);
	glVertex3fv(tween[a]);
	glVertex3fv(tween[b]);
	glVertex3fv(tween[c]);
	glVertex3fv(tween[d]);
	glEnd();
}

void coloring(void) {
	GLint i;

	for (i = 0; i < 4; i++) {
		glColor3fv(colors[7]);  // back, light blue
		polygon(0 + 8 * i, 3 + 8 * i, 2 + 8 * i, 1 + 8 * i);
		glColor3fv(colors[1]);  // top, red
		polygon(2 + 8 * i, 3 + 8 * i, 7 + 8 * i, 6 + 8 * i);
		glColor3fv(colors[2]);  // left side, yellow
		polygon(0 + 8 * i, 4 + 8 * i, 7 + 8 * i, 3 + 8 * i);
		glColor3fv(colors[3]);  // right side, green
		polygon(1 + 8 * i, 2 + 8 * i, 6 + 8 * i, 5 + 8 * i);
		glColor3fv(colors[4]);  // front, blue
		polygon(4 + 8 * i, 5 + 8 * i, 6 + 8 * i, 7 + 8 * i);
		glColor3fv(colors[5]);  // bottom, pink
		polygon(0 + 8 * i, 1 + 8 * i, 5 + 8 * i, 4 + 8 * i);
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);  // x-axis
	glRotatef(theta[1], 0.0, 1.0, 0.0);  // y-axis
	glRotatef(theta[2], 0.0, 0.0, 1.0);  // z-axis

	coloring();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glLineWidth(4);
	glBegin(GL_LINES);
	// x-axis
	glVertex3f(0, 0, 0);
	glVertex3f(5, 0, 0);
	// y-axis
	glVertex3f(0, 0, 0);
	glVertex3f(0, 5, 0);
	// z-axis
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 5);
	glEnd();
	glPopMatrix();

	glutSwapBuffers();
}

void morph() {
	GLint i, j;

	t += deltaT;

	for (i = 0; i < NUMVERTICES; i++) {
		for (j = 0; j < 3; j++) {
			tween[i][j] = Tvertices[i][j] + t * (Kvertices[i][j] - Tvertices[i][j]);
		}
	}

	if (t >= 1.0 || t <= 0.0) deltaT = -deltaT;

	glutPostRedisplay();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-4.0, 4.0, -4.0 * (GLfloat)h / (GLfloat)w,
			4.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-4.0 * (GLfloat)w / (GLfloat)h,
			4.0 * (GLfloat)w / (GLfloat)h, -4.0, 4.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'x' || key == 'X') { axis = 0; glutPostRedisplay(); }  // rotate about x-axis
	if (key == 'y' || key == 'Y') { axis = 1; glutPostRedisplay(); }  // rotate about y-axis
	if (key == 'z' || key == 'Z') { axis = 2; glutPostRedisplay(); }  // rotate about z-axis
	if (key == 'g' || key == 'G') { glutIdleFunc(morph); }						// start morph
	if (key == 's' || key == 'S') { glutIdleFunc(NULL); }							// stop morph
	if (key == 'q' || key == 'Q') exit(0);

	if (key == 'x' || key == 'X' || key == 'y' || key == 'Y' || key == 'z' || key == 'Z') {
		theta[axis] += 2.0;  // change in angle by one keyboard stroke
		if (theta[axis] > 360.0) theta[axis] -= 360.0;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3D_morph");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
}
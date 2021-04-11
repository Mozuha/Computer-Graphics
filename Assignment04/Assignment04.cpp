/*
* Mizuki Hashimoto
* Mar 11, 2021
*
* This game is the combination of Connect Four and Othello, and so called Connect Four Othello.
* An objective of this game is to make a sequence of four identical discs horizontally, vertically, 
* or diagonally, just like in the original Connect Four. However, when a disc is surrounded by another
* type of disc, that disc will change to another type, just like in the original Othello.
* 
* Click on a column to drop a disc into that column. 
* Right click to quit.
* Background color will be green if "x" won. 
* Background color will be red if "o" won.
* 
* (* I did not implement the \"computer\" algorithm since this is not a tic-tac-toe.) 
*/

#include <GL/glut.h>
#include <iostream>
using namespace std;

#define WINDOW 600
#define PI 3.141592654f

const int row = 6, col = 4;
char board[row][col] = { {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, 
	{' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '} };
enum types { Cross = 'x', Circle = 'o', Empty = ' ', Draw = '-'};
enum types disc, result;
bool oneP = true;  // 1P, use cross

GLfloat boardLen = WINDOW - 50;
GLfloat boardWid = (boardLen / 6) * 4;
GLfloat leftEdge = (WINDOW - boardWid) / 2;    // left edge of board
GLfloat rightEdge = leftEdge + boardWid;       // right edge of board
GLfloat bottomEdge = (WINDOW - boardLen) / 2;  // bottom edge of board
GLfloat topEdge = bottomEdge + boardLen;       // top edge of board

GLfloat squareLen = boardLen / 6;  // length of each square in board
GLfloat innerSquareLen = squareLen * 0.9;  // length of inner square in square above
GLfloat squareLeftEdge = (squareLen - innerSquareLen) / 2;     // left edge of inner square
GLfloat squareRightEdge = squareLeftEdge + innerSquareLen;  // right edge of inner square
GLfloat squareBottomEdge = (squareLen - innerSquareLen) / 2;   // bottome edge of inner square
GLfloat squareTopEdge = squareBottomEdge + innerSquareLen;  // top edge of inner square



////////////////////   MODEL   ////////////////////////

// check whether a column is fully filled, return current top index of a column if not
int checkStack(int j) {
	int top = -1;
	for (int i = row - 1; i >= 0; i--) {
		if (board[i][j] == Empty) {
			top = i;
			break;
		}
	}
	if (top == -1) return -1;  // cannot drop a disc anymore at this column
	else return top;  // top index of this column
}

// ensure it fits the range and check the disc type in a square
bool checkASquare(int i, int j, enum types disc) {
	return 0 <= i && i < row && 0 <= j && j < col && board[i][j] == disc;
}

// count the number of discs surrounded by same disc type for one direction out of eight
int countDisc(int i, int j, int di, int dj, enum types disc) {
	int i1 = i + di;
	int j1 = j + dj;
	int numDisc = 0;

	enum types opponent = Cross;
	if (disc == Cross) opponent = Circle;
	else if (disc == Circle) opponent = Cross;

	// count the number of discs while encounter same disc type
	while (checkASquare(i1, j1, opponent)) {
		i1 += di;
		j1 += dj;
		numDisc++;
	}

	if (checkASquare(i1, j1, disc)) return numDisc;
	else return 0;
}

// count the number of all discs surrounded by same disc type for eight directions
int countDisc(int i, int j, enum types disc) {
	int numDisc = 0;

	numDisc += countDisc(i, j, -1, 0, disc);   // top
	numDisc += countDisc(i, j, -1, 1, disc);   // top right
	numDisc += countDisc(i, j, 0, 1, disc);    // right
	numDisc += countDisc(i, j, 1, 1, disc);    // bottom right
	numDisc += countDisc(i, j, 1, 0, disc);    // bottom
	numDisc += countDisc(i, j, 1, -1, disc);   // bottom left
	numDisc += countDisc(i, j, 0, -1, disc);   // left
	numDisc += countDisc(i, j, -1, -1, disc);  // top left

	return numDisc;
}

// flip surrounded discs for one direction
void flip(int i, int j, int di, int dj, enum types disc) {
	int numFlippableDisc = countDisc(i, j, di, dj, disc);

	for (int k = 1; k <= numFlippableDisc; k++) {
		board[i + (di * k)][j + (dj * k)] = disc;
	}
}

// flip surrounded discs for eight direction
void flip(int i, int j, enum types disc) {
	flip(i, j, -1, 0, disc);   // top
	flip(i, j, -1, 1, disc);   // top right
	flip(i, j, 0, 1, disc);    // right
	flip(i, j, 1, 1, disc);    // bottom right
	flip(i, j, 1, 0, disc);    // bottom
	flip(i, j, 1, -1, disc);   // bottom left
	flip(i, j, 0, -1, disc);   // left
	flip(i, j, -1, -1, disc);  // top left
}

// put a disc and flip surrounded opponent discs as needed
void putDisc(int i, int j, enum types disc) {
	if (checkASquare(i, j, Empty)) {
		board[i][j] = disc;
		countDisc(i, j, disc);
		flip(i, j, disc);
	}
}

// check whether four disc sequence formed
bool check(enum types disc) {
	// horizontal check
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col - 3; j++) {
			if (board[i][j] == disc && board[i][j + 1] == disc
				&& board[i][j + 2] == disc && board[i][j + 3] == disc) {
				result = disc;
				return true;
			}
		}
	}

	// vertical check
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row - 3; j++) {
			if (board[j][i] == disc && board[j + 1][i] == disc
				&& board[j + 2][i] == disc && board[j + 3][i] == disc) {
				result = disc;
				return true;
			}
		}
	}

	// diagonal check, bottom left to top right
	for (int i = 3; i < row; i++) {
		for (int j = 0; j < col - 3; j++) {
			if (board[i][j] == disc && board[i - 1][j + 1] == disc
				&& board[i - 2][j + 2] == disc && board[i - 3][j + 3] == disc) {
				result = disc;
				return true;
			}
		}
	}

	// diagonal check, bottom right to top left
	for (int i = 3; i < row; i++) {
		for (int j = 3; j < col; j++) {
			if (board[i][j] == disc && board[i - 1][j - 1] == disc
				&& board[i - 2][j - 2] == disc && board[i - 3][j - 3] == disc) {
				result = disc;
				return true;
			}
		}
	}

	return false;
}

// if all squares of grid are filled without four disc sequence, then the result is draw
bool checkDraw() {
	int count = 0;

	for (int j = 0; j < col; j++) {
		if (board[0][j] != Empty) count++;
	}
	if (count == col) {
		result = Draw;
		return true;
	}
	else return false;
}

//////////////////   MODEL END   //////////////////////



void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WINDOW, 0, WINDOW);
	glMatrixMode(GL_MODELVIEW);
}

void drawGrid() {
	for (GLfloat i = 0; i <= boardLen; i += squareLen) {
		glBegin(GL_LINES);
		// row lines
		glVertex2f(leftEdge, bottomEdge + i);
		glVertex2f(rightEdge, bottomEdge + i);

		// column lines
		if (i < (boardLen / 6) * 5) {
			glVertex2f(leftEdge + i, bottomEdge);
			glVertex2f(leftEdge + i, topEdge);
		}
		glEnd();
	}
}

void drawCross(GLfloat x, GLfloat y) {  // x and y coord. of left bottom of a square
	glBegin(GL_LINES);
	glVertex2f(x + squareLeftEdge, y + squareBottomEdge);
	glVertex2f(x + squareRightEdge, y + squareTopEdge);

	glVertex2f(x + squareLeftEdge, y + squareTopEdge);
	glVertex2f(x + squareRightEdge, y + squareBottomEdge);
	glEnd();
}

void drawCircle(GLfloat x, GLfloat y) {  // x and y coord. of left bottom of a square
	GLfloat xcenter = x + squareLen / 2;
	GLfloat ycenter = y + squareLen / 2;
	GLfloat radius = innerSquareLen / 2;
	GLint partition = 100;

	glBegin(GL_LINE_LOOP);
	for (GLint i = 0; i <= partition; i++) {
		GLfloat rad = 2.0f * PI * GLfloat(i) / GLfloat(partition);
		glVertex2f(xcenter + cos(rad) * radius, ycenter + sin(rad) * radius);
	}
	glEnd();
}

// receive mouse click position, put current player's disc into chosen column
bool updateBoard(GLfloat x, enum types disc) {
	int colPos = 0;

	// which column clicked position fall in?
	if (leftEdge < x && x < leftEdge + squareLen) colPos = 0;
	else if (leftEdge + squareLen < x && x < leftEdge + squareLen * 2) colPos = 1;
	else if (leftEdge + squareLen * 2 < x && x < leftEdge + squareLen * 3) colPos = 2;
	else if (leftEdge + squareLen * 3 < x && x < leftEdge + squareLen * 4) colPos = 3;

	int top = checkStack(colPos);
	if (top == -1) return false;
	else putDisc(top, colPos, disc);

	check(disc);
	checkDraw();
	return true;
}

// draw current situation of board
void drawGame() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == Cross) drawCross(leftEdge + squareLen * j, topEdge - squareLen * (i + 1));
			if (board[i][j] == Circle) drawCircle(leftEdge + squareLen * j, topEdge - squareLen * (i + 1));
		}
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, WINDOW, WINDOW);

	drawGrid();
	drawGame();
	if (result == Cross) glClearColor(0.0, 1.0, 0.0, 0.0);  // 1P (x) won
	else if (result == Circle) glClearColor(1.0, 0.0, 0.0, 0.0);  // 2P (o) won

	glFlush();
}

void mouse(int btn, int state, int x, int y)
{
	bool inRange = leftEdge < x && x < rightEdge && bottomEdge < y && y < topEdge;

	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (result != NULL) exit(0);

		// 1P's turn (cross); turn will not proceed if outside of board is clicked or a column is full
		else if (oneP && inRange && updateBoard(x, Cross)) {
			display(); 
			oneP = false;  // switch turn
		}

		// 2P's turn (circle); turn will not proceed if outside of board is clicked or a column is full
		else if (!oneP && inRange && updateBoard(x, Circle)) {
			display(); 
			oneP = true;  // switch turn
		}
	}

	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
	  exit(0);
	}
}

int main(int argc, char** argv)
{
	cout << "Welcome to Connect Four Othello.\n\nThis game is the combination of Connect Four and Othello.\n\n"
		<< "An objective of this game is to make a sequence of four identical discs horizontally, vertically, "
		<< "or diagonally, just like in the original Connect Four.\nHowever, when a disc is surrounded by another "
		<< "type of disc, that disc will change to another type, just like in the original Othello.\n\n"
		<< "Click on a column to drop a disc into that column.\nRight click to quit.\n" 
		<< "Background color will be green if \"x\" won.\nBackground color will be red if \"o\" won."
		<< "\n\n(* I did not implement the \"computer\" algorithm since this is not a tic-tac-toe.)"
		<< endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW, WINDOW);
	glutInitWindowPosition(100.0, 100.0);
	glutCreateWindow("Connect Four Othello");
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();

	return 0;
}
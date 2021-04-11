/*
* Mizuki Hashimoto
* Feb 9, 2021
* 
* Prompt for hour and minute, then output a clock face.
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

const int N = 50;  // clock array size
char clock[N][N] = { 0 };  // clock array

void clock_face() {
	double hr_tmp;
	int col_offset, row_offset;

	for (int hr = 1; hr <= 12; hr++) {
		hr_tmp = M_PI * hr / 6.0;
		col_offset = (N / 2) + round(sin(hr_tmp) * (N / 2 - 2));
		row_offset = (N / 2) + round(-cos(hr_tmp) * (N / 2 - 2));
		clock[row_offset][col_offset] = (char)hr % 10 + 48;
		if (hr >= 10) clock[row_offset][col_offset - 1] = '1';
	}
}

void draw_hr_handle(int hr, int min) {
	double ha, dx, dy, slope, col, row;

	ha = (M_PI / 6.0) * (hr + (min / 60.0));
	dx = sin(ha) * (N / 2 - 12);  // x2 - x1
	dy = cos(ha) * (N / 2 - 12);  // y2 - y1
	slope = dy / dx;
	ha = (ha >= (2 * M_PI)) ? ha - (2 * M_PI) : ha;

	if (ha == M_PI) {  // 6:00 or 18:00
		for (row = N / 2; row <= N - 12; row++) clock[(int)row][N / 2] = 'x';
	}
	else if (ha == 0) {  // 0:00 or 12:00
		for (row = 12; row <= N / 2; row++) clock[(int)row][N / 2] = 'x';
	}
	else if (ha < M_PI) {  // 0:01-5:59 or 12:01-17:59
		row = N / 2;
		for (col = N / 2; col <= N / 2 + dx; col++) {
			row -= slope;
			clock[(int)round(row)][(int)col] = 'x';
		}
	}
	else if (ha > M_PI) {  // 6:01-11:59 or 18:01-23:59
		row = N / 2 - dy;
		for (col = N / 2 + dx; col <= N / 2; col++) {
			row -= slope;
			clock[(int)round(row)][(int)col] = 'x';
		}
	}
}

void draw_min_handle(int min) {
	double ma, dx, dy, slope, col, row;

	ma = M_PI * min / 30.0;
	dx = sin(ma) * (N / 2 - 5);  // x2 - x1
	dy = cos(ma) * (N / 2 - 5);  // y2 - y1
	slope = dy / dx;

	if (min == 30) {  // ??:30; idk why but (ma==M_PI) did not work
		for (row = N / 2; row <= N - 5; row++) clock[(int)row][N / 2] = 'x';
	}
	else if (ma == 0) {  // ??:00
		for (row = 5; row <= N / 2; row++) clock[(int)row][N / 2] = 'x';
	}
	else if (ma < M_PI) {  // ??:01-??:29
		row = N / 2;
		for (col = N / 2; col <= N / 2 + dx; col++) {
			row -= slope;
			clock[(int)round(row)][(int)col] = 'x';
		}
	}
	else if (ma > M_PI) {  // ??:31-??:59
		row = N / 2 - dy;
		for (col = N / 2 + dx; col <= N / 2; col++) {
			row -= slope;
			clock[(int)round(row)][(int)col] = 'x';
		}
	}
}

int main() {
	int hr, min;

	clock_face();  // draw clock face

	cout << "Enter hour: "; cin >> hr;
	cout << "Enter minute: "; cin >> min;

	draw_hr_handle(hr, min);  // draw hour handle
	draw_min_handle(min);     // draw minute handle

	// set empty arrays to '.' to make the clock easier to see
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (clock[i][j] == 0) clock[i][j] = '.';

	// print clock
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cout << clock[i][j] << " \n"[j == N - 1];
}


/*  KEY
#include <iostream>
using namespace std;
#include <cstdlib>
#include <cmath>

#define SIZE 50
#define HALF SIZE/2
#define PI 3.141592654

int round(double x) {return floor(x+0.5);}

int main() {
	int hours, minutes;
	double hourAngle, minuteAngle;
	int minLen = HALF - 5;
	int hrLen = HALF - 11;
	char clock[SIZE][SIZE];
	int row, col;
	double a, b;

	// set up the clockface
	for (row = 0; row < SIZE; row++) { for (col = 0; col < SIZE; col++) { clock[row][col] = ' '; } }
	clock[HALF][HALF] = 'O';
	for (int i = 1; i <= 12; i++) {
		double angle = PI * i / 6.0; a = (HALF - 1) * cos(angle); b = (HALF - 1) * sin(angle);
		clock[round(HALF+a)][round(HALF+b)] = i % 10 + 48;
		if (i >= 10) clock[round(HALF+a)][round(HALF+b)] = '1';
	}

	// get the time
	cout << "Enter the hours: " << endl;
	cin >> hours;
	hours %= 12;
	cout << "Enter the minutes: " << endl;
	cin >> minutes;
	minutes %= 60;
	minuteAngle = PI * minutes / 30.0; 
	hourAngle = (PI/6.0)*(hours+minutes/60.0);

	// draw the hands
	a = HALF; b = HALF;
	for (int i = 0; i < minLen; i++) { a = a + cos(minuteAngle); b = b + sin(minuteAngle); clock[round(a)][round(b)] = 'm'; }
	
	a = HALF; b = HALF;
	for (int i = 0; i < hrLen; i++) { a = a + cos(hourAngle); b = b + sin(hourAngle); clock[round(a)][round(b)] = 'h'; }

	// print the clockface
	for (row = SIZE - 1; row >= 0; row--) { for (col = 0; col < SIZE; col++) { cout << clock[row][col]; } cout << endl; }

}
*/
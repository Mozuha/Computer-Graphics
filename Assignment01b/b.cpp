/*
* Mizuki Hashimoto
* Feb 2, 2021
* 
* Prompt for hour and minute, then output the angles for the hour hand and minute hand on a clock.
* Hour angle = (pi / 6) * (hour + (minute / 60))
* Minute angle = pi * minute / 30
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int hour, minute;
	double ha, ma;

	cout << "Enter hour: "; cin >> hour;
	cout << "Enter minute: "; cin >> minute;

	ha = (M_PI / 6.0) * (hour + (minute / 60.0));  // hour angle
	ma = M_PI * minute / 30.0;  // minute angle
	// hand pointing straight up at the 12 would have an angle of 0 rad, so reset to 0 if the value reached 2 pi
	cout << "Hour angle: " << ((ha >= (2 * M_PI)) ? ha - (2 * M_PI) : ha) << endl;
	cout << "Minute angle: " << ma << endl;
}

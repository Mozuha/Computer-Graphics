/*
* Mizuki Hashimoto
* Feb 2, 2021
* 
* Prompt for the size of the matrix (row = col), fill two matrices with random integers between -10 and 10,
* then output the product of two matrices.
*/

#include <iostream>
#include <vector>
#include <random>
using namespace std;

int main() {
	int n;
	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<> rand20(-10, 10);  // random integers between -10 and 10

	cout << "Enter size of square (row=col): "; cin >> n;
	vector<vector<int>> mat1(n, vector<int>(n)), mat2(n, vector<int>(n)), res(n, vector<int>(n));  // instantiate n*n matrices

	// fill matrices with random integers between -10 and 10
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			mat1[i][j] = rand20(mt);
			mat2[i][j] = rand20(mt);
		}

	// print matrix 1
	cout << "[matrix 1]" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << mat1[i][j] << " \n"[j == n - 1];
		}

	// print matrix 2
	cout << endl << "[matrix 2]" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << mat2[i][j] << " \n"[j == n - 1];
		}

	// matlix-matlix multiplication
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				res[i][j] += mat1[i][k] * mat2[k][j];

	// print matrix 1 * matrix 2
	cout << endl << "[matrix 1 * matrix 2]" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << " \n"[j == n - 1];
		}
}
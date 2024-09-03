#include <iostream>
using namespace std;

void transpose(int** mat, int e, int m) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < e; ++j)
			cout << mat[j][i] << " ";
		cout << endl;
	}
}

void employeeScores(int** mat, int e, int m) {
	for (int i = 0; i < e; ++i) {
		int total = 0;
		for (int j = 0; j < m; ++j)
			total += mat[i][j];
		cout << "Employee " << i + 1 << ": " << total << endl;
	}
}

void monthScores(int** mat, int e, int m) {
	for (int i = 0; i < m; ++i) {
		int total = 0;
		for (int j = 0; j < e; ++j)
			total += mat[j][i];
		cout << "Month " << i + 1 << ": " << total << endl;
	}
}

int main() {
	int e, m;
	cin >> e >> m;
	int** mat = new int*[e];
	for (int i = 0; i < e; ++i) {
		mat[i] = new int[m];
		for (int j = 0; j < m; ++j)
			cin >> mat[i][j];
	}

	transpose(mat, e, m);
	employeeScores(mat, e, m);
	monthScores(mat, e, m);

	for (int i = 0; i < e; ++i)
		delete[] mat[i];
	delete[] mat;
	return 0;
}

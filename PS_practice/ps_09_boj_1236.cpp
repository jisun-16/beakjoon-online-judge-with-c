#include<iostream>
#include<algorithm>

using namespace std;

char castel[50][50];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> castel[i][j];
		}
	}

	int row = 0, col = 0;

	for (int i = 0; i < n; i++) {
		bool empty = true;
		for (int j = 0; j < m; j++)
			if (castel[i][j] == 'X')
				empty = false;

		if (empty) row++;
	}

	for (int i = 0; i < m; i++) {
		bool empty = true;
		for (int j = 0; j < n; j++)
			if (castel[j][i] == 'X')
				empty = false;

		if (empty) col++;
	}

	cout << max(row, col) << endl;
}
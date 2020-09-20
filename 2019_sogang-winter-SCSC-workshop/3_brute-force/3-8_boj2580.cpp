#include<iostream>
#include<cstring>
#include<bitset>

using namespace std;
using pii = pair<int, int>;

int sdo[9][9], n;
pii blank[81];
bool possible[10];

bitset<10> calc_possible(int i, int j) {
	bitset<10> possible;
	possible.flip();

	int x = (i / 3) * 3, y = (j / 3) * 3;

	for (int k = 0; k < 9; k++) {
		possible[sdo[i][k]] = false;
		possible[sdo[k][j]] = false;
	}

	for (int k = x; k < x + 3; k++) {
		for (int l = y; l < y + 3; l++) {
			possible[sdo[k][l]] = false;
		}
	}

	return possible;
}

bool dfs(int i) {
	if (i == n) {
		for (int x = 0; x < 9; x++) {
			for (int y = 0; y < 9; y++) {
				cout << sdo[x][y] << ' ';
			}
			cout << '\n';
		}
		return true;
	}

	int x = blank[i].first;
	int y = blank[i].second;

	bitset<10> possible = calc_possible(x, y);

	for (int z = 1; z <= 9; z++) {
		if (possible[z]) {
			sdo[x][y] = z;
			bool A = dfs(i + 1);
			if (A) return true;
			sdo[x][y] = 0;
		}
	}

	return false;
}

int main() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> sdo[i][j];
			if (!sdo[i][j]) {
				blank[n] = pii(i, j);
				n++;
			}
		}

	bool ans = dfs(0);
}
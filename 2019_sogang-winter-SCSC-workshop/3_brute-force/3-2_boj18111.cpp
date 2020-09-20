#include<iostream>
#include<algorithm>

using namespace std;

int n, m, b;
int hei[501][501];

int main() {
	cin >> n >> m >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> hei[i][j];
	}

	int rem, ins;
	int mint=100000000, height;
	for (int h = 256; h >= 0; h--) {
		rem = 0, ins = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (hei[i][j] > h) rem += hei[i][j] - h;
				if (hei[i][j] < h) ins += h - hei[i][j];
			}
		}

		if (b + rem < ins) continue;

		int time = rem * 2 + ins;
		if (mint > time) {
			mint = time;
			height = h;
		}
	}


	
	cout << mint << ' ' << height << endl;

	return 0;
}
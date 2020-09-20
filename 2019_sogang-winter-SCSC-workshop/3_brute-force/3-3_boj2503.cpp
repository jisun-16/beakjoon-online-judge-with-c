#include<iostream>

using namespace std;

int n, ans, x[3], y[3];

struct Q {
	int num;
	int str;
	int ball;
} qry[101];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> qry[i].num >> qry[i].str >> qry[i].ball;
	}

	for (int i = 123; i <= 987; i++) {
		int cnt = 0;
		x[0] = i / 100;
		x[1] = (i / 10) % 10;
		x[2] = i % 10;

		if (!x[1] || !x[2] || x[0] == x[1] || x[1] == x[2] || x[0] == x[2]) continue;

		for (int j = 0; j < n; j++) {
			int str = 0, ball = 0, temp = qry[j].num;
			y[0] = temp / 100;
			y[1] = (temp / 10) % 10;
			y[2] = temp % 10;

			for (int k = 0; k < 3; k++) {
				if (y[k] == x[k]) str++;
				if (y[k] == x[(k + 1) % 3] || y[k] == x[(k + 2) % 3]) ball++;
			}

			if (qry[j].str == str && qry[j].ball == ball) cnt++;
		}

		if (cnt == n) {
			ans++;
		}
	}

	cout << ans << endl;
}
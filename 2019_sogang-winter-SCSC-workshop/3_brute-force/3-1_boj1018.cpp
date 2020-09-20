#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string B[50];

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> B[i];

	int ans = 64;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int black = 0, white = 0;

			for (int a = 0; a < 8; a++) {
				for (int b = 0; b < 8; b++) {
					if ((a + b) % 2 == 0) {
						if (B[a + i][b + j] != 'B') black++;
					}
					else {
						if (B[a + i][b + j] != 'W') black++;
					}
				}
			}

			for (int a = 0; a < 8; a++) {
				for (int b = 0; b < 8; b++) {
					if ((a + b) % 2 == 0) {
						if (B[a + i][b + j] != 'W') white++;
					}
					else {
						if (B[a + i][b + j] != 'B') white++;
					}
				}
			}

			int temp = min(black, white);
			ans = min(ans, temp);

		}
	}

	cout << ans << endl;
}
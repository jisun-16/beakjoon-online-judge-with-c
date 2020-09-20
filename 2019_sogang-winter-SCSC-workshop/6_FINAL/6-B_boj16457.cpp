#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, k, q[100][10];
int used[21];
bool check[21];

int solve(int pos, int cnt) {
	if (n * 2 - pos < n - cnt) return 0;

	int res = 0;
	if (pos == 2 * n) {
		for (int i = 0; i < m; ++i) {
			bool temp = true;
			for (int j = 0; j < k; ++j) {
				if (!check[q[i][j]]) {
					temp = false;
					break;
				}
			}
			if (temp) ++res;
		}
		return res;
	}

	res = solve(pos + 1, cnt);
	if (cnt < n) {
		check[pos] = true;
		res = max(solve(pos + 1, cnt + 1), res);
		check[pos] = false;
	}

	return res;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> q[i][j];
			--q[i][j];
		}
	}

	cout << solve(0, 0) << endl;
}

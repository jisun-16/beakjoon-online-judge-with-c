#include<iostream>
#include<algorithm>
#define inf 987654321
using namespace std;

int n, m, dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 }, coin_cnt = 0, ans = inf;
pair<int, int> coin[2];
char board[21][21];

void solve(int x1, int y1, int x2, int y2, int cnt) {
	if (cnt > 10) return;
	if (x1 == x2 && y1 == y2) return;

	//cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << cnt << '\n';

	for (int d = 0; d < 4; d++) {
		int n_x1 = x1 + dx[d], n_y1 = y1 + dy[d];
		int n_x2 = x2 + dx[d], n_y2 = y2 + dy[d];
		bool coin1 = (n_x1 < 0 || n_y1 < 0 || n_x1 >= n || n_y1 >= m);
		bool coin2 = (n_x2 < 0 || n_y2 < 0 || n_x2 >= n || n_y2 >= m);
		if ((coin1 && !coin2) || (!coin1 && coin2)) {
			ans = min(ans, cnt);
		}
		if (!coin1 && !coin2) {
			if (board[n_x1][n_y1] != '#' && board[n_x2][n_y2] != '#')
				solve(n_x1, n_y1, n_x2, n_y2, cnt + 1);
			else if (board[n_x1][n_y1] != '#')
				solve(n_x1, n_y1, x2, y2, cnt + 1);
			else if (board[n_x2][n_y2] != '#')
				solve(x1, y1, n_x2, n_y2, cnt + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				coin[coin_cnt++] = make_pair(i, j);
			}
		}
	}
	solve(coin[0].first, coin[0].second, coin[1].first, coin[1].second, 1);
	if (ans != inf) cout << ans << '\n';
	else cout << -1 << '\n';
}
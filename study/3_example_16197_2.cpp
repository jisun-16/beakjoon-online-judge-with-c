#include<iostream>
#include<algorithm>
#include<queue>

#define inf 987654321

using namespace std;

int n, m, dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 }, coin_cnt = 0, ans;
bool visited[21][21][21][21];
pair<int, int> coin[2];
char board[21][21];

int solve() {
	//bfs
	int ans = 0;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {coin[0].first, coin[0].second}, {coin[1].first, coin[1].second} });

	while (!q.empty()) {
		int k = q.size();
		while (k--) {
			int x1 = q.front().first.first, y1 = q.front().first.second, x2 = q.front().second.first, y2 = q.front().second.second;
			q.pop();

			if (ans > 10) return -1;

			bool fall1 = (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m);
			bool fall2 = (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m);

			if (fall1 && fall2) continue;
			else if ((fall1 && !fall2) || (!fall1 && fall2)) return ans;

			if (visited[x1][y1][x2][y2]) continue;
			visited[x1][y1][x2][y2] = true;

			for (int d = 0; d < 4; d++) {
				int nx1 = x1 + dx[d], ny1 = y1 + dy[d], nx2 = x2 + dx[d], ny2 = y2 + dy[d];
				if (board[nx1][ny1] == '#') {
					nx1 = x1; ny1 = y1;
				}
				if (board[nx2][ny2] == '#') {
					nx2 = x2; ny2 = y2;
				}
				q.push({ {nx1,ny1},{nx2,ny2} });
			}
		}
		ans++;
	}

	return -1;
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

	cout << solve() << '\n';
}
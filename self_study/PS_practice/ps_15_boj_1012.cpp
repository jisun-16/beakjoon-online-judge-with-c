#include<iostream>

using namespace std;

int t, m, n, k;
int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
bool map[50][50], visit[50][50];

void dfs(int x, int y) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if(map[ny][nx] && !visit[ny][nx]) dfs(nx, ny);
	}
}

int main() {
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visit[i][j] = false;
				map[i][j] = false;
			}
		}

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = true;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] && !visit[i][j]) {
					dfs(j, i);
					cnt++;
				}
			}
		}

		cout << cnt << endl;
	}
}
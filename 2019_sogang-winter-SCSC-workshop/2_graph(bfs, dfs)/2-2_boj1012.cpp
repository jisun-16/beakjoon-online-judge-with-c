#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
using pii = pair<int, int>;

int map[50][50];
bool visit[50][50];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));

		int M, N, K;
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			int r, c;
			cin >> r >> c;
			map[r][c] = 1;
		}

		int cnt = 0;
		queue<pii> q;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) continue;
				if (visit[i][j]) continue;
				visit[i][j] = true;
				q.emplace(pii(i, j));
				cnt++;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int d = 0; d < 4; d++) {
						int nx = x + dx[d];
						int ny = y + dy[d];
						if (nx >= M || nx < 0) continue;
						if (ny >= N || ny < 0) continue;

						if (visit[nx][ny]) continue;
						if (map[nx][ny] == 0) continue;
						visit[nx][ny] = true;
						q.emplace(pii(nx, ny));
					}
				}
			}
		}

		cout << cnt << "\n";
	}
}
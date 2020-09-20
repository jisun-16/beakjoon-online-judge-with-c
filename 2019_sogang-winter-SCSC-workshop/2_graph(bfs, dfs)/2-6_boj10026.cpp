#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
using pii = pair<int, int>;

bool visit[101][101];
char graph[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int N;

int bfs(char xx, char yy) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) visit[i][j] = false;
	}

	int cnt = 0;
	queue<pii> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] != xx && graph[i][j] != yy) continue;
			if (visit[i][j]) continue;

			cnt++;
			visit[i][j] = true;
			q.emplace(pii(i, j));
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int d = 0; d < 4; d++) {
					int nx = x + dx[d];
					int ny = y + dy[d];
					if (nx < 0 || nx >= N) continue;
					if (ny < 0 || ny >= N) continue;
					if (visit[nx][ny]) continue;
					if (graph[nx][ny] != xx && graph[nx][ny] != yy) continue;
					visit[nx][ny] = true;
					q.emplace(pii(nx, ny));
				}
			}
		}
	}

	return cnt;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	int cnt1 = 0, cnt2 = 0;
	cnt1 = bfs('R', 'R') + bfs('G', 'G') + bfs('B', 'B');
	cnt2 = bfs('R', 'G') + bfs('B', 'B');

	cout << cnt1 << " " << cnt2;
}
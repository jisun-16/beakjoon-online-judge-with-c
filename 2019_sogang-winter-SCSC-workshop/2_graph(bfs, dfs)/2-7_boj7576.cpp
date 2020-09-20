#include<iostream>
#include<vector>
#include<queue>
#define max 10000000;
using namespace std;
using pii = pair<int, int>;

int M, N;
int graph[1001][1001];
int day[1001][1001];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
	cin >> M >> N;

	queue<pii> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) day[i][j] = max;
			if (graph[i][j] == -1) day[i][j] = 0;
			if (graph[i][j] == 1) {
				q.emplace(pii(i, j));
				day[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N) continue;
			if (ny < 0 || ny >= M) continue;

			if (day[x][y] + 1 < day[nx][ny]) {
				day[nx][ny] = day[x][y] + 1;
				q.emplace(pii(nx, ny));
			}
		}
	}

	int minday = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (day[i][j] > 1000000) {
				minday = -1;
				break;
			}
			if (minday < day[i][j]) {
				minday = day[i][j];
			}
		}
		if (minday < 0) break;
	}

	cout << minday << endl;

	return 0;
}
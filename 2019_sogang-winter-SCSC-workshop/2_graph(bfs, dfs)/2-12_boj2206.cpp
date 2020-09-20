#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
using pii = pair<int, int>;

int N, M;
int map[1001][1001];
int ans[1001][1001][2];//마지막이 0이면 벽뚫기 불가능, 1이면 가능
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int bfs() {
	queue<pair<pii, int>> q;
	q.push({ pii(1,1),1 });
	ans[1][1][1] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop();

		if (x == N && y == M) {
			return ans[x][y][block];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
				if (map[nx][ny] == 1 && block == 1) {
					ans[nx][ny][0] = ans[x][y][1] + 1;
					q.push({ pii(nx,ny),0 });
				}
				else if (map[nx][ny] == 0 && ans[nx][ny][block] == 0) {
					ans[nx][ny][block] = ans[x][y][block] + 1;
					q.push({ pii(nx,ny),block });
				}
			}
		}
	}

	return -1;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;

		for (int j = 0; j < M; j++) {
			map[i+1][j+1] = temp[j] - '0';
		}
	}

	cout << bfs() << endl;

	return 0;
}
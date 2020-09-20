#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int cheese[101][101];
bool check[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int m, n, lastcnt = 0;

void preair_to_air() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (cheese[i][j] == 2) cheese[i][j] = 3;
		}
	}
}

bool allmelt() {
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if (cheese[i][j] == 1) cnt++;
		}
	}

	if (cnt) lastcnt = cnt;
	return cnt ? false : true;
}

void bfs1() {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) check[i][j] = false;

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if ((!check[nx][ny]) && (!cheese[nx][ny] || cheese[nx][ny] == 3)) {
					cheese[nx][ny] = 3;
					q.push({ nx,ny });
					check[nx][ny] = true;
				}
			}
		}
	}
}

void bfs2() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && !check[nx][ny]) {
				if (cheese[nx][ny] == 3) {
					q.push({ nx,ny });
					check[nx][ny] = true;
				}
				if (cheese[x][y] == 3 && cheese[nx][ny] == 1) {
					cheese[nx][ny] = 2;
					q.push({ nx,ny });
					check[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> cheese[i][j];

	int time = 0;

	while (1) {
		if (allmelt()) break;
		bfs1();
		bfs2();
		preair_to_air();
		time++;
	}

	cout << time << '\n';
	cout << lastcnt << '\n';

	return 0;
}
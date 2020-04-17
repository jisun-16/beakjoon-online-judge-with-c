#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;

typedef struct T {
	int height;
	int x;
	int y;
}T;

int m, n, h;
int tomato[101][101][101];//height, row, col
int dx[6] = { -1,0,1,0,0,0 }, dy[6] = { 0,-1,0,1,0,0 }, dh[6] = { 0,0,0,0,-1,1 };
queue<T> q;

int main() {
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					T temp;
					temp.height = i;
					temp.x = j;
					temp.y = k;
					q.push(temp);
				}
			}
		}
	}

	while (!q.empty()) {
		T now = q.front();
		q.pop();

		for (int d = 0; d < 6; d++) {
			int nh = now.height + dh[d], nx = now.x + dx[d], ny = now.y + dy[d];
			if (nh < 0 || nh >= h) continue;
			if (nx < 0 || nx >= n) continue;
			if (ny < 0 || ny >= m) continue;
			if (tomato[nh][nx][ny]) continue; // 1 or -1

			tomato[nh][nx][ny] = tomato[now.height][now.x][now.y] + 1;
			q.push({ nh,nx,ny });
		}
	}

	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (tomato[i][j][k] == 0) {
					cout << -1 << '\n';
					return 0;
				}
				if (ans < tomato[i][j][k]) ans = tomato[i][j][k];
			}
		}
	}

	cout << ans - 1<< '\n'; //첫날은 제외한다.
}
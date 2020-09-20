#include<iostream>
#include<cstring>
using namespace std;

int R, C, ans;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
bool alp[26];
char B[20][20];

void dfs(int cnt, int x, int y) {
	if (cnt > ans) ans = cnt;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
		if (!alp[B[nx][ny]-'A']) {
			alp[B[nx][ny]-'A'] = true;
			dfs(cnt + 1, nx, ny);
			alp[B[nx][ny] - 'A'] = false;
		}
	}	
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> B[i];
	}

	memset(alp, 0, sizeof(alp));
	alp[B[0][0] - 'A'] = true;
	dfs(1, 0, 0);

	cout << ans;
}
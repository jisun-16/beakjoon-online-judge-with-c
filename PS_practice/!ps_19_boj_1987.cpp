#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int r, c, ans;
int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
int board[21][21];
bool check[26] = { false };

void dfs(int x, int y, int cnt) {
	if (ans < cnt) ans = cnt;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (!check[board[nx][ny]]) {
            check[board[nx][ny]] = true;
			dfs(nx, ny, cnt + 1);
            check[board[nx][ny]] = false;
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char temp;
			cin >> temp;
			board[i][j] = temp - 'A';
		}
	}
    check[board[0][0]]=true;
	dfs(0, 0, 1);
	cout << ans;
}
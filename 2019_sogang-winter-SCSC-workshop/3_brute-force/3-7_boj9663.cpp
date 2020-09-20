#include<iostream>
#include<cstring>

using namespace std;

int N;
int used[16], ans = 0;

void dfs(int col) {
	if (col == N) {
		ans++;
		return;
	}

	bool dis[16];
	memset(dis, false, sizeof(dis));

	for (int i = 0; i < col; i++) {
		int j = used[i];
		dis[j] = true;
		int up = j - i + col, down = j + i - col;
		if (up >= 0 && up < N) dis[up] = true;
		if (down >= 0 && down < N) dis[down] = true;
	}

	for (int i = 0; i < N; i++) {
		if (dis[i]) continue;
		used[col] = i;
		dfs(col + 1);
		used[col] = -1;
	}
}

int main() {
	cin >> N;
	memset(used, -1, sizeof(used));
	dfs(0);
	cout << ans;
}
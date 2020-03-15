#include<iostream>
#include<vector>

using namespace std;

int n, m, ans = -1;
bool visit[101];
vector<int> computer[101];

void dfs(int start) {
	visit[start] = true;
	ans++;

	for (int v : computer[start]) {
		if (visit[v]) continue;
		dfs(v);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		computer[a].push_back(b);
		computer[b].push_back(a);
	}

	dfs(1);
	cout << ans << endl;
}
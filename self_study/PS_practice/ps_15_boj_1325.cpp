#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int n, m, cnt;
bool visit[10001];
vector<int> computer[10001];

void dfs(int start) {
	visit[start] = true;
	cnt++;
	for (int v : computer[start]) {
		if (!visit[v]) dfs(v);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		computer[b].push_back(a);
	}

	vector<int> ans;
	int max = 0;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		memset(visit, false, sizeof(visit));

		dfs(i);

		if (cnt > max) {
			max = cnt;
			vector<int> empty;
			ans = empty;
			ans.push_back(i);
		}
		else if (cnt == max)
			ans.push_back(i);
	}

	sort(ans.begin(), ans.end());
	for (int x : ans)
		cout << x << ' ';
}
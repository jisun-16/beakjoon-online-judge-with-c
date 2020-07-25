#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n, m, v;
vector<int> graph[1001];
bool visit[1001];

void dfs(int u) {
	visit[u] = true;
	cout << u << ' ';
	for (int v : graph[u]) {
		if (!visit[v]) {
			dfs(v);
		}
	}
}

void bfs(int u) {
	visit[u] = true;
	queue<int> q;
	q.push(u);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << ' ';
		for (int next : graph[v]) {
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << '\n';
	memset(visit, 0, sizeof(visit));
	bfs(v);
}
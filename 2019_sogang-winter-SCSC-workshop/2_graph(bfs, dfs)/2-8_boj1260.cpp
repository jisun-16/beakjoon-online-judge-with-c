#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> graph[1001];
bool visit[1001];
int M, N;

void dfs(int start) {
	visit[start] = true;
	cout << start << " ";
	for (int v : graph[start]) {
		if (!visit[v]) dfs(v);
	}
}

void bfs(int start) {
	queue<int> q;
	q.emplace(start);
	visit[start] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cout << u << " ";
		for (int v : graph[u]) {
			if (visit[v]) continue;
			visit[v] = true;
			q.emplace(v);
		}
	}
	cout << "\n";
}

int main() {
	int V;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i < N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V);
	cout << "\n";
	memset(visit, 0, sizeof(visit));
	bfs(V);
}
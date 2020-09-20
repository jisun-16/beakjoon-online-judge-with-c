#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> graph[1001];
int visit[1001];
int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 1) continue;

		cnt++;

		queue<int> q;
		q.emplace(i);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v : graph[u]) {
				if (visit[v] == 1) continue;
				visit[v] = 1;
				q.emplace(v);
			}
		}
	}

	cout << cnt << endl;
}
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> graph[101];
bool visit[101];

int main() {
	int n, net;
	cin >> n;
	cin >> net;

	for (int i = 0; i < net; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}

	int cnt = 0;
	queue<int> q;
	visit[1] = true;
	q.emplace(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cnt++;
		for (int v : graph[u]) {
			if (visit[v]) continue;
			visit[v] = true;
			q.emplace(v);
		}
	}
	cout << cnt - 1;
	return 0;
}
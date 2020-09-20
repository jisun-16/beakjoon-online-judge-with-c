#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
using pii = pair<int, int>;

int inf = 100000000;
int N, M, A, B;
int dist[1001];
vector<pii> graph[1001];

int main() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].emplace_back(pii(v, w));
	}
	cin >> A >> B;

	for (int i = 1; i <= N; i++) {
		dist[i] = inf;
	}
	dist[A] = 0;

	priority_queue<pii, vector<pii>, greater<>> pq;
	pq.emplace(pii(A, 0));
	while (!pq.empty()) {
		int u = pq.top().first, d = pq.top().second;
		pq.pop();

		if (dist[u] < d) continue;
		for (pii v : graph[u]) {
			if (dist[u] + v.second > dist[v.first]) continue;
			dist[v.first] = dist[u] + v.second;
			pq.emplace(pii(v.first, dist[v.first]));
		}
	}

	cout << dist[B] << endl;
}
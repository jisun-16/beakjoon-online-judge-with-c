#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
using pii = pair<int, int>;

int inf = 100000000;
int V, E, K;
int dist[20001];
vector<pii> graph[20001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
	cin >> V >> E;
	cin >> K;
	
	for (int i = 1; i <= V; i++) dist[i] = inf;
	dist[K] = 0;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].emplace_back(pii(v, w));
	}

	priority_queue<pii, vector<pii>, greater<>> pq;
	pq.emplace(pii(0, K));
	while (!pq.empty()) {
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (dist[u] < d) continue;
		for (pii v : graph[u]) {
			if (dist[u] + v.second >= dist[v.first]) continue;
			dist[v.first] = dist[u] + v.second;
			pq.emplace(pii(dist[v.first], v.first));
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == inf) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
}
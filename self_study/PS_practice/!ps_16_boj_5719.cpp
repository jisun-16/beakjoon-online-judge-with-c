#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
using pii = pair<int, int>;

int dist[501];
bool visit[501][501];
vector<pii> graph[501], r_graph[501];

void dijkstra(int s, int d) {
	for (int i = 0; i < 501; i++) {
		dist[i] = 1e9;
	}

	priority_queue<pii> pq;
	pq.push(pii(0, s));
	dist[s] = 0;

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		for (pii v:graph[u]) {
			int nei = v.first, neicost = dist[u] + v.second;
			if (visit[u][nei]) continue;
			if (dist[nei] > neicost) {
				dist[nei] = neicost;
				pq.push(pii(-neicost, nei));
			}
		}
	}
}

void Delete(int s, int d) {
	queue<int> q;
	q.push(d);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == s) continue;
		for (pii v : r_graph[u]) {
			int nei = v.first, neicost = dist[nei] + v.second;
			if (neicost == dist[u]) {
				visit[nei][u] = true;
				q.push(nei);
			}
		}
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	while (1) {
		for (int i = 0; i < 501; i++) {
			graph[i].clear();
			r_graph[i].clear();
			for (int j = 0; j < 501; j++)
				visit[i][j] = false;
		}

		int n, m, s, d;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		cin >> s >> d;

		for (int i = 0, u, v, p; i < m; i++) {
			cin >> u >> v >> p;
			graph[u].push_back(pii(v, p));
			r_graph[v].push_back(pii(u, p));
		}

		dijkstra(s, d);
		Delete(s, d);
		dijkstra(s, d);

		if (dist[d] == 1e9) cout << -1 << '\n';
		else cout << dist[d] << '\n';
	}
}
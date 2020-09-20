#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
using pii = pair<int, int>;

int inf = 987654321;
int n, m, s, d;
int dist[501];
int visit[501][501];
vector<pii> graph[501], r_graph[501];

void dijkstra() {
	for (int i = 0; i < n; i++) dist[i] = inf;
	dist[s] = 0;

	priority_queue<pii, vector<pii>, greater<>> pq;
	pq.push(pii(s, 0));

	while (!pq.empty()) {
		int u = pq.top().first;
		int d = pq.top().second;
		pq.pop();

		if (dist[u] < d) continue;

		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i].first;
			int cost = graph[u][i].second + d;

			if (visit[u][v]) continue;
			if (dist[v] > cost) {
				dist[v] = cost;
				pq.push(pii(v, cost));
			}
		}
	}
}

void del() {
	queue<int> q;
	q.push(d);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == s) continue;
		for (int i = 0; i < r_graph[cur].size(); i++) {
			int v = r_graph[cur][i].first;
			if (dist[v] + r_graph[cur][i].second == dist[cur]) {
				visit[v][cur] = 1;
				q.push(v);
			}
		}
	}
}

int main() {
	while (1) {
		for (int i = 0; i < 501; i++) {
			dist[i] = 0;
			graph[i].clear();
			r_graph[i].clear();
			for (int j = 0; j < 501; j++) {
				visit[i][j] = 0;
			}
		}

		cin >> n >> m;
		if (n == 0 && m == 0) break;

		cin >> s >> d;
		for (int i = 0; i < m; i++) {
			int u, v, p;
			cin >> u >> v >> p;
			graph[u].push_back(pii(v, p));
			r_graph[v].push_back(pii(u, p));
		}

		dijkstra();
		del();
		dijkstra();

		if (dist[d] == inf) cout << -1 << endl;
		else cout << dist[d] << endl;
	}
}
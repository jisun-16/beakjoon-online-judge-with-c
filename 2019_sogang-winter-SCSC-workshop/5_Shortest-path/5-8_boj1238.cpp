#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
using pii = pair<int, int>;

int N, M, X;
int inf = 987654321;
vector<pii> graph[1001];

vector<int> dijkstra(int start) {
	vector<int> dist(N + 1, inf); 
	dist[start] = 0;

	priority_queue<pii, vector<pii>, greater<>> pq;
	pq.emplace(pii(start, 0));
	while (!pq.empty()) {
		int u = pq.top().first, d = pq.top().second;
		pq.pop();

		if (dist[u] < d) continue;
		for (pii v : graph[u]) {
			if (dist[v.first] <= dist[u] + v.second) continue;
			dist[v.first] = dist[u] + v.second;
			pq.emplace(v.first, dist[v.first]);
		}
	}

	return dist;
}

int main() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int s, f, t;
		cin >> s >> f >> t;
		graph[s].emplace_back(pii(f, t));
	}

	int ans = 0;
	vector<int> dist = dijkstra(X);
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		vector<int> dist2 = dijkstra(i);
		if (dist[i] + dist2[X] > ans) ans = dist[i] + dist2[X];
	}

	cout << ans << endl;
}
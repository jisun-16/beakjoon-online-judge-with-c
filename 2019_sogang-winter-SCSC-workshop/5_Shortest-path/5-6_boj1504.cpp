#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
using pii = pair<int, int>;

int inf = 100000000;
int N, E, A, B;
vector<pii> graph[801];

vector<int> dijkstra(int start) {
	vector<int> dist(N+1, inf);
	dist[start] = 0;
	
	priority_queue<pii, vector<pii>, greater<>> pq;
	pq.emplace(pii(start, 0));
	while (!pq.empty()) {
		int u = pq.top().first, d = pq.top().second;
		pq.pop();

		if (d > dist[u]) continue;
		for (pii v : graph[u]) {
			if (dist[u] + v.second > dist[v.first]) continue;
			dist[v.first] = dist[u] + v.second;
			pq.emplace(pii(v.first, dist[v.first]));
		}
	}

	return dist;
}

int main() {
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	cin >> A >> B;

	vector<int> start1 = dijkstra(1);
	vector<int> startA = dijkstra(A);
	vector<int> startB = dijkstra(B);

	int ans = min(start1[A]+startA[B]+startB[N], start1[B]+startB[A]+startA[N]);
	if (ans >= inf) cout << -1;
	else cout << ans;
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using pii = pair<int, int>;

int inf = 987654321;
int T, N, M, W;
int dist[501];

int main() {
	cin >> T;
	while (T--) {
		cin >> N >> M >> W;
		
		for (int i = 1; i <= N; i++) dist[i] = inf;
		dist[1] = 0;

		vector<pii> graph[501];
		for (int i = 0; i < M; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			graph[s].emplace_back(pii(e, t));
			graph[e].emplace_back(pii(s, t));
		}
		for (int i = 0; i < W; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			graph[s].emplace_back(pii(e, -t));
		}

		for (int k = 0; k < N; k++) {
			for (int u = 1; u <= N; u++) {
				if (dist[u] == inf) continue;
				for (pii v : graph[u]) {
					dist[v.first] = min(dist[v.first], dist[u] + v.second);
				}
			}
		}

		bool ans = false;
		for (int u = 1; u <= N; u++) {
			if (dist[u] == inf) continue;
			for (pii v : graph[u]) {
				if (dist[v.first] > dist[u] + v.second) {
					ans = true;
					break;
				}
			}
			if (ans) break;
		}

		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
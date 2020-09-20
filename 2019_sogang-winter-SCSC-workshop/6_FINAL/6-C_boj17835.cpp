#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
using pll = pair<long, long>;
using pii = pair<int, int>;

long long N, M, K, dist[100001], inf=1000000000000000000;
vector<pll> graph[100001];
vector<int> city;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		long long u, v, c;
		cin >> u >> v >> c;
		graph[v].emplace_back(pll (u, c));
	}

	for (int i = 1; i <= N; i++) dist[i] = inf;

	priority_queue<pll, vector<pll>, greater<>> pq;
	for (int i = 1; i <= K; i++) {
		int c;
		cin >> c;
		city.emplace_back(c);
		dist[c] = 0;
		pq.emplace(pll(c,0));
	}

	while (!pq.empty()) {
		long long u = pq.top().first, d = pq.top().second;
		pq.pop();
		if (dist[u] < d) continue;
		for (pll v : graph[u]) {
			long long nei = v.first, neicost = v.second + dist[u];
			if (dist[nei] > neicost) {
				dist[nei] = neicost;
				pq.emplace(pll(nei, dist[nei]));
			}
		}
	}

	long long mxi = 0, mx = 0;
	for (int i = 1; i <= N; i++) {
		if (mx < dist[i]) {
			mx = dist[i];
			mxi = i;
		}
	}

	cout << mxi << "\n" << mx << endl;

	return 0;
}
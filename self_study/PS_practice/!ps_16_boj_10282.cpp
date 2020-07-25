#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
using pii = pair<int, int>;

int t, n, d, c;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n >> d >> c;

		vector<vector<pii>> com(n+1);

		for (int i = 0; i < d; i++) {
			int a, b, s; 
			cin >> a >> b >> s;
			com[b].push_back(pii(a, s));
		}
		
		vector<int> dist(n + 1, 1e9);
		dist[c] = 0;

		vector<bool> visit(n + 1, false);

		priority_queue<pii> pq;
		pq.emplace(pii(0, c));

		while (!pq.empty()) {
			int u;
			do {
				u = pq.top().second;
				pq.pop();
			} while (!pq.empty() && visit[u]);

			if (visit[u]) break;
			visit[u] = true;

			for (pii v : com[u]) {
				int nei = v.first, neicost = dist[u] + v.second;
				if (dist[nei] > neicost) {
					dist[nei] = neicost;
					pq.push(pii(-neicost, nei));
				}
			}
		}

		int num = 0, sec = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] != 1e9) {
				num++;
				sec = max(sec, dist[i]);
			}
		}

		cout << num << ' ' << sec << '\n';
	}
}
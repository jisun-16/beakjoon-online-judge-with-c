#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int edge[503][503];
int dist[503]; 
int MAX = 1e9;

typedef pair<int, int> pii;

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int n, m, w;
		cin >> n >> m >> w;
		for (int i = 1; i <= n; i++) {
			dist[i] = MAX;
			for (int j = 1; j <= n; j++)
				edge[i][j] = MAX;
		}
		dist[1] = 0;

		while (m--) {
			int s, e, t;
			cin>>s>>e>>t;
			edge[s][e] = min(edge[s][e], t);
			edge[e][s] = min(edge[e][s], t);
		}

		while (w--) {
			int s, e, t;
			cin >> s >> e >> t;
			edge[s][e] = min(edge[s][e], -t);
		}

		vector<pii> graph[501]; 
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (edge[i][j] < MAX)
					graph[i].push_back({ j, edge[i][j] });
			}
		}

		bool cycle = false;
		for (int k = 1; k <= n + 1; k++) {
			for (int u = 1; u <= n; u++) {
				for (auto v : graph[u]) {
					if (dist[u] + v.second < dist[v.first]) {
						dist[v.first] = dist[u] + v.second;
						if (k == n + 1)
							cycle = true;
					}
				}
			}
		}

		if (cycle)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
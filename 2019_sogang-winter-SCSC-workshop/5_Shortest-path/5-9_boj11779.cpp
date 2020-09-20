#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;
using pii = pair<int, int>;

int n, m, start, des, cnt = 0;
int cost[1001];
vector<pii> graph[1001];
vector<int> ans;
int path[1001];
int inf = 987654321;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, d, c;
		cin >> s >> d >> c;
		graph[s].emplace_back(pii(d, c));
	}
	cin >> start >> des;

	for (int i = 1; i <= n; i++) cost[i] = inf;
	cost[start] = 0;

	priority_queue<pii, vector<pii>, greater<>> pq;
	pq.emplace(pii(start, 0));
	while (!pq.empty()) {
		int u = pq.top().first, d = pq.top().second;
		pq.pop();

		if (d > cost[u]) continue;
		for (pii v : graph[u]) {
			if (cost[v.first] <= cost[u] + v.second) continue;

			cost[v.first] = cost[u] + v.second;
			pq.emplace(pii(v.first, cost[v.first]));
			path[v.first] = u;
		}
	}
	
	int p=des;
	while (p) {
		ans.push_back(p);
		p = path[p];
	}

	cout << cost[des] << endl;
	cout << ans.size() << endl;
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";

	return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include<cstring>
#include<algorithm>
using namespace std;

int t;
int n, k, w;
int dist[1001] = { 0 }, indegree[1001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> k;

		memset(dist, 0, sizeof(dist));
		memset(indegree, 0, sizeof(indegree));
		vector<int> time(n + 1);
		vector<int> p[1001];

		for (int i = 1; i <= n; i++) {
			cin >> time[i];
		}
		for (int i = 0; i < k; i++) {
			int u, v;
			cin >> u >> v;
			p[u].push_back(v);
			indegree[v]++;
		}
		cin >> w;

		queue<int> q;
		for (int i = 1; i < n + 1; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				dist[i] = time[i];
			}
		}//시작점을 큐에 넣는다

		while (!q.empty()) {
			int now = q.front();
			q.pop();
			if (now == w) break;

			for (int next : p[now]) {
				if (--indegree[next] == 0)
					q.push(next);
				if (dist[next] < dist[now] + time[next]) {
					dist[next] = dist[now] + time[next];
				}//먼저 지어져야 하는 건물이 있으므로 최대값을 저장
			}
		}
		cout << dist[w] << '\n';
	}
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
using pii = pair<int, int>;//목적지, 가능 무게
int n, m, start, finish, ans;
vector<pii> graph[10001];
bool visit[10001];

bool bfs(int wei){
	memset(visit, false, sizeof(visit));
	queue<pii> q;
	q.push(pii(start, 0));
	visit[start] = true;
	while (!q.empty()) {
		int u = q.front().first, w = q.front().second;
		q.pop();
		for (pii v : graph[u]) {
			int next = v.first, nwei = v.second;
			if (visit[next] || nwei < wei) continue;
			visit[next] = true;
			q.push(pii(next, nwei));
		}
	}
	return visit[finish];
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].emplace_back(pii(b, c));
		graph[b].emplace_back(pii(a, c));
	}
	cin >> start >> finish;
	
	int mn = 1, mx = 1000000000, mid;
	ans = mn;
	while(mn <= mx) {
		mid = (mn + mx) / 2;
		if (bfs(mid)) {
			ans = mid;
			mn = mid + 1;
		}
		else {
			mx = mid - 1;
		}
	}

	cout << ans << endl;
}//dfs이용하면 시간초과
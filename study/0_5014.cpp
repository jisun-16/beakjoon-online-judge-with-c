#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
using pii = pair<int, int>;

bool visit[1000001];

int main() {
	int f, s, g, u, d, ans = -1;

	cin >> f >> s >> g >> u >> d;
	queue<pii> q;

	visit[s] = true;
	q.push(pii(s, 0));

	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == g) {
			ans = cnt;
			break;
		}

		if (now + u <= f && !visit[now+u]) {
			visit[now + u] = true;
			q.push(pii(now + u, cnt + 1));
		}
		if (now - d >= 1 && !visit[now-d]) {
			visit[now - d] = true;
			q.push(pii(now - d, cnt + 1));
		}
	}

	if (ans == -1) cout << "use the stairs";
	else cout << ans;
}
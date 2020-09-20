#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<int> frd[101];
int N, M, dist[101];

int bacon(int person) {
	memset(dist, 0, sizeof(dist));
	int sum = 0;

	queue<int> q;
	q.emplace(person);
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : frd[u]) {
			if (dist[v] > 0) continue;
			if (v == person) continue;
			dist[v] = dist[u] + 1;
			q.emplace(v);
		}
	}

	for (int i = 1; i <= N; i++) sum += dist[i];

	return sum;
}
int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		frd[a].emplace_back(b);
		frd[b].emplace_back(a);
	}

	int min = 1000000000, minfrd = -1;

	for (int i = 1; i <= N; i++) {
		int bac = bacon(i);
		if (min > bac) {
			min = bac;
			minfrd = i;
		}
	}

	cout << minfrd;

	return 0;
}
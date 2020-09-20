#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int graph[101][101];
int visit[101];
int adj[101][101];
int N;

void adjmat(int start) {
	memset(visit, 0, sizeof(visit));
	queue<int> q;
	q.emplace(start);
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < N; v++) {
			if (graph[u][v] == 0) continue;
			if (visit[v] == 1) continue;
			visit[v] = 1;
			q.emplace(v);
			adj[start][v] = 1;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> graph[i][j];
	}

	for (int i = 0; i < N; i++) {
		adjmat(i);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << adj[i][j] << " ";
		cout << "\n";
	}
}
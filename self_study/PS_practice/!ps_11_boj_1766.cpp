#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int n, m;
int indegree[32001];
vector<int> order[32001];
priority_queue<int> pq;

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);//a->b
		indegree[b]++;
		order[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) pq.push(-i);

	while (!pq.empty()) {
		int now = -pq.top();
		printf("%d ", now);
		pq.pop();
		for (int i = 0; i < order[now].size(); i++) {
			indegree[order[now][i]]--;
			if (indegree[order[now][i]] == 0) {
				pq.push(-order[now][i]);
			}
		}
	}
}
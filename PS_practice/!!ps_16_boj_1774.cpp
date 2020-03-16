#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#define MAX 1001

using namespace std;
using pii = pair<int, int>;

int n, m, parent[MAX];
double cost = 0;
pii planet[MAX];

class Edge {
public:
	int x, y;
	double dist;
	Edge(int x, int y, double dist) : x(x), y(y), dist(dist) {}
	bool operator <(const Edge& edge) const {
		return this->dist < edge.dist;
	}
};
vector<Edge> tunnel;

double getDist(pii a, pii b) {
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

bool union_(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return true;
	else {
		if (u < v) parent[v] = u;
		else parent[u] = v;
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		planet[i] = pii(a, b);
		parent[i] = i;
	}

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			tunnel.push_back(Edge(i, j, getDist(planet[i], planet[j])));
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a = find(a); b = find(b);
		parent[max(a, b)] = min(a, b);
	}

	sort(tunnel.begin(), tunnel.end());

	for (Edge e : tunnel) {
		int x = find(e.x), y = find(e.y);
		if (x != y) {
			cost += e.dist;
			parent[max(x, y)] = min(x, y);
		}
	}

	printf("%.2lf\n", cost);
}
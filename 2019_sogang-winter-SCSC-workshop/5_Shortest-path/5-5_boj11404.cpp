#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int cost[101][101];
int inf = 100000000;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cost[i][j] = inf;
		}
		cost[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cost[a][b] = min(cost[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (cost[i][j] > cost[i][k] + cost[k][j]) cost[i][j] = cost[i][k] + cost[k][j];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] == inf) cout << 0<<" ";
			else cout << cost[i][j]<<" ";
		}
		cout << "\n";
	}
}
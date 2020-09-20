#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
using pii = pair<int, int>;

int t, n;

bool dist(int x1, int y1, int x2, int y2) {
	if (abs(x1 - x2) + abs(y1 - y2) > 1000) return false;
	return true;
}

int main() {
	cin >> t;
	while (t--) {
		int map[105][105] = {0};

		cin >> n;
		vector<pii> coordinate;
		for (int i = 0; i < n + 2; i++) {
			int u, v;
			cin >> u >> v;
			coordinate.emplace_back(pii(u, v));
		}

		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < n + 2; j++) {
				int x1 = coordinate[i].first, y1 = coordinate[i].second;
				int x2 = coordinate[j].first, y2 = coordinate[j].second;
				if (dist(x1, y1, x2, y2)) map[i][j] = 1;
			}
		}

		for (int k = 0; k < n + 2; k++) {
			for (int i = 0; i < n + 1; i++) {
				for (int j = 1; j < n + 2; j++) {
					if (map[i][j]) continue;
					if (map[i][k] + map[k][j] == 2) map[i][j] = 1;
				}
			}
		}

		if (map[0][n + 1]) cout << "happy" << endl;
		else cout << "sad" << endl;
	}
}
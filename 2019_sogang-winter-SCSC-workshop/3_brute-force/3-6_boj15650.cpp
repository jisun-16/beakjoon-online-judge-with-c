#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> used;

void dfs(int cnt, int find_from) {
	if (cnt==m) {
		for (int i = 0; i < m; i++) {
			cout << used[i] << ' ';
		}
		cout << '\n';

		return;
	}
	else {
		for (int j = find_from ; j <= n; j++) {
			used.push_back(j);
			dfs(cnt + 1, j + 1);
			used.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(0, 1);
}
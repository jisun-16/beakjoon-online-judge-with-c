#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int k, s[13];
int ans[6];

void dfs(int index, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = index; i < k; i++) {
			ans[cnt] = s[i];
			dfs(i + 1, cnt + 1);
		}
	}
}

int main() {
	while (1) {
		cin >> k;
		if (k == 0) break;

		memset(s, 0, sizeof(s));

		for (int j = 0; j < k; j++) cin >> s[j];

		dfs(0, 0);
		cout << '\n';
	}

}
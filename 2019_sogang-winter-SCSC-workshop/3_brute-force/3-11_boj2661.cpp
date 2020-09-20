#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int N;
char ans[81];

bool isavail(int start) {
	int len = (start+1) / 2;
	for (int l = 1; l <= len; l++) {
		bool avail = false;
		for (int j = 0; j < l; j++) {
			if (ans[start - j] != ans[start - l - j]) {
				avail = true;
				break;
			}
		}

		if (!avail) return false;
	}
	return true;
}

int dfs(int start) {
	
	if (start == N) {
		return 0;
	}

	for (int i = '1'; i < '1' + 3; i++) {
		ans[start] = i;
		if (isavail(start)) {
			int res = dfs(start + 1);
			if (res != -1) return res;
		}
	}

	return -1;
}

int main() {
	cin >> N;
	dfs(0);
	cout << ans;
	return 0;
}
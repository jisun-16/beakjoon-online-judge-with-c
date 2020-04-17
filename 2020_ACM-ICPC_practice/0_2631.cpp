#include<iostream>
#include<algorithm>

using namespace std;

int n;
int child[201], len[201];
int ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> child[i];
	}

	len[0] = 1;
	for (int i = 1; i < n; i++) {
		len[i] = 1;
		for (int j = i; j >= 0; j--) {
			if (child[j] < child[i]) len[i] = max(len[i], len[j] + 1);
		}
	}

	for (int i = 0; i < n; i++) {
		if (len[i] > ans) ans = len[i];
	}

	ans = n - ans;

	cout << ans << endl;
}
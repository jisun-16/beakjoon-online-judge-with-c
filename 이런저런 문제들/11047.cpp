#include<iostream>
#include<algorithm>

using namespace std;

int n, k, coin[11];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	int ans = 0, i = n;
	while (k) {
		if (k >= coin[i]) {
			k -= coin[i];
			ans++;
		}
		else
			i--;
	}

	cout << ans << endl;
}
#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int n, a[1001], dp[1001], ans, index = -1, track[1001];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		track[i] = -1;
	}

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if ((a[j] < a[i]) && (dp[i] < dp[j] + 1)) {
				dp[i] = dp[j] + 1;
				track[i] = j;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (dp[i] > ans) {
			ans = dp[i];
			index = i;
		}
	}

	stack<int> arr;
	while (index != -1) {
		arr.push(a[index]);
		index = track[index];
	}

	cout << ans << '\n';
	while (!arr.empty()) {
		cout << arr.top() << ' ';
		arr.pop();
	}
}
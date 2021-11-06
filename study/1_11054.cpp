#include<iostream>

using namespace std;

int n, arr[1001], dp1[1001], dp2[1001];
//dp1은 왼쪽에서 오른쪽으로 증가, dp2는 오른쪽에서 왼쪽으로 증가

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		dp1[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp1[i] < dp1[j] + 1)
				dp1[i] = dp1[j] + 1;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		dp2[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j] && dp2[i] < dp2[j] + 1)
				dp2[i] = dp2[j] + 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (dp1[i] + dp2[i] - 1 > ans)
			ans = dp1[i] + dp2[i] - 1;
	}

	cout << ans << '\n';
}
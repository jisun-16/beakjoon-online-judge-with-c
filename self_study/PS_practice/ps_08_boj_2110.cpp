#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, c;
	cin >> n >> c;
	vector<long long> home;
	for (int i = 0; i < n; i++) {
		long long temp;
		scanf("%lld", &temp);
		home.push_back(temp);
	}
	sort(home.begin(), home.end());

	long long start = 1, end = home[n - 1] - home[0], mid;
	long long ans = 0;

	while (start <= end)
	{
		mid = (start + end) / 2;
		long long value = home[0];
		int cnt = 1;

		for (int i = 1; i < n; i++) {
			if (home[i] >= value + mid) {
				value = home[i];
				cnt++;
			}
		}

		if (cnt >= c) {
			start = mid + 1;
			ans = mid;
		}
		else
			end = mid - 1;
	}

	cout << ans << endl;
}
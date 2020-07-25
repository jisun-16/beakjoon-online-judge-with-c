#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, k;
int sensor[10001], dist[10001];

bool cmp(int a, int b) { return a > b; }

int main() {
	int ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> sensor[i];
	}
	sort(sensor, sensor + n);

	for (int i = 0; i < n-1; i++) {
		dist[i] = sensor[i + 1] - sensor[i];
		ans += dist[i];
	}
	sort(dist, dist + n - 1, cmp);

	for (int i = 0; i < k - 1; i++)
		ans -= dist[i];

	cout << ans << endl;
}
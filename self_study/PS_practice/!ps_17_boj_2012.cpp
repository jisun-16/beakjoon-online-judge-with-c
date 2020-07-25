#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n;
	long long ans = 0;
	cin >> n;

	vector<int> a;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++)
		ans += abs(a[i] - i - 1);

	cout << ans << endl;
}
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int N, liq[100000], liq1, liq2;
bool compare(int a, int b) {
	return abs(a) > abs(b);
}
int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) cin >> liq[i];

	sort(liq, liq + N, compare);

	int min = 2000000000;
	for (int i = 0; i < N-1; i++) {
		if (abs(liq[i] + liq[i + 1]) < min) {
			min = abs(liq[i] + liq[i + 1]);
			if (liq[i] < liq[i + 1]) {
				liq1 = liq[i];
				liq2 = liq[i + 1];
			}
			else {
				liq1 = liq[i + 1];
				liq2 = liq[i];
			}
		}
	}

	cout << liq1 << ' ' << liq2 << endl;
}
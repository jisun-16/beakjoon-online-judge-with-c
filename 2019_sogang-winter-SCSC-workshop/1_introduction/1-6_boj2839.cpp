#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int ans = -1;

	for (int i = N / 5; i >= 0; i--) {
		if ((N - 5 * i) % 3 == 0) {
			ans = i + (N - 5 * i) / 3;
			break;
		}
	}

	cout << ans;
}
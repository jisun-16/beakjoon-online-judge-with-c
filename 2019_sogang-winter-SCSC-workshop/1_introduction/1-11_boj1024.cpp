#include<iostream>
using namespace std;
int main() {
	int N, L;
	cin >> N >> L;

	for (int i = L; i <= 100; i++) {
		int y = N - i * (i + 1) / 2;
		if (y % i == 0) {
			int x = y / i + 1;
			if (x >= 0) {
				for (int j = 0; j < i; j++) cout << x + j << " ";
				cout << "\n";
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
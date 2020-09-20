#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;

	int cnt = 0, i;
	for (i = 666;; i++) {
		int temp = i;
		while (temp) {
			if (temp % 1000 == 666) {
				cnt++;
				break;
			}
			temp /= 10;
		}
		if (cnt == N) break;
	}

	cout << i << endl;
}
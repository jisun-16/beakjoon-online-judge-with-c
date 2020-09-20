#include<iostream>
using namespace std;
int X[1000];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, max=-1000;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> X[i];
		}
		for (int i = 0; i < N; i++) {
			int maxi = 0;
			for (int j = i; j < N; j++) {
				maxi += X[j];
				if (maxi > max) max = maxi;
			}
		}
		cout << max << endl;
	}
}
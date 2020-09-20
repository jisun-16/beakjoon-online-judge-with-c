#include<iostream>
using namespace std;
int card[100];
int main() {
	int N, M;
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++) cin >> card[i];

	int sum, min=M, ans=-1;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = card[i] + card[j] + card[k];
				if (M - sum >= 0 && min > (M - sum)) {
					ans = sum;
					min = M - sum;
				}
			}
		}
	}

	cout << ans << endl;
}
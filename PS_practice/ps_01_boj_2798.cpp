#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, m,card[100];
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> card[i];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (card[i] + card[j] + card[k] > m) continue;
				if (m - ans <= m - card[i] - card[j] - card[k]) continue;
				ans = card[i] + card[j] + card[k];
			}
		}
	}

	cout << ans << endl;
}
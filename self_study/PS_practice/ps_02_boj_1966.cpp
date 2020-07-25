#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using pii = pair<int, int>;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, ans = 0, max=0;
		queue<pii> print;

		cin >> n >>m;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			print.push(pii(i, x));
			if (x > max) max = x;
		}

		while (true) {
			if (print.front().second == max) {
				if (print.front().first == m) {
					ans++;
					break;
				}
				ans++;
				print.pop();
				max = 0;
				int size = print.size();
				for (int i = 0; i < size; i++) {
					int temp1 = print.front().first, temp2 = print.front().second;
					print.pop();
					if (temp2 > max) max = temp2;
					print.push(pii(temp1, temp2));
				}
				continue;
			}
			int temp1 = print.front().first, temp2 = print.front().second;
			print.pop();
			print.push(pii(temp1, temp2));
		}

		cout << ans << '\n';
	}
}
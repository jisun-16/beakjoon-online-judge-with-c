#include<iostream>
#include<string.h>
using namespace std;
int main() {
	int N, cnt=0;
	cin >> N;
	while (N--) {
		char x[102];
		cin >> x;
		int n = strlen(x);
		bool check = true;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (x[j] == x[i] && x[j] != x[j - 1]) {
					check = false;
					break;
				}
			}
			if (!check) break;
		}
		if (check) cnt++;
	}
	cout << cnt << endl;
}
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int op[9];//0=' ', 1='+', 2='-'
char oper[3] = { ' ','+','-' };

void dfs(int key) {
	if (key == n) {
		int sum = 0, val = 1, sign = 1;
		for (int i = 1; i < n; i++) {
			if (op[i] == 1) {
				sum += sign * val;
				val = i + 1;
				sign = 1;
			}
			else if (op[i] == 2) {
				sum += sign * val;
				val = i + 1;
				sign = -1;
			}
			else {
				val = val * 10 + i + 1;
			}
		}
		sum += sign * val;

		if (sum == 0) {
			for (int i = 1; i < n; i++) {
				cout << i << oper[op[i]];
			}
			cout << n << '\n';
		}

		return;
	}

	for (int i = 0; i < 3; i++) {
		op[key] = i;
		dfs(key + 1);
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		dfs(1);
		cout << '\n';
	}
}//완전탐색
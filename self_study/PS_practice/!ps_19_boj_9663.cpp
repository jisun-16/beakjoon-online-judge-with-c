#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int row[15], ans, n;

bool check(int x) {
	for (int i = 0; i < x; i++) {//위쪽에 있는 퀸들을 검정
		if (row[x] == row[i]) return false;
		if (abs(row[x] - row[i]) == x - i) return false;
	}
	return true;
}

void dfs(int x) {
	if (x == n) ans++;
	else {
		for (int i = 0; i < n; i++) {//x번째 행의 i번째 열에 퀸을 놓는다고 가정
			row[x] = i;
			if (check(x)) dfs(x + 1);
		}
	}
}

int main() {
	cin >> n;
	dfs(0);
	cout << ans << endl;
}
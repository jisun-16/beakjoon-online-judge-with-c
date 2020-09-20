#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int L, C;
char temp[15], ans[15];

void dfs(int start, int cnt) {
	if (cnt == L) {
		int a = 0, b = 0;//모음, 자음
		for (int i = 0; i < L; i++) {
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') a++;
			else b++;
		}

		if (a < 1 || b < 2) return;

		for (int i = 0; i < L; i++) {
			cout << ans[i];
		}
		cout << endl;
		return;
	}

	for (int i = start; i < C; i++) {
		ans[cnt] = temp[i];
		dfs(i + 1, cnt + 1);
	}
}

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) cin >> temp[i];
	sort(temp, temp + C);
	dfs(0, 0);
}
#include<iostream>
#include<algorithm>
using namespace std;

int l, c;
char arr[16];
bool check[16];

void dfs(int start, int cntvow, int cntcon, string pw) {//모음의 개수, 자음의 개수
	if (cntvow + cntcon == l) {
		if (cntvow >= 1 && cntcon >= 2) {
			cout << pw << '\n';
			return;
		}
	}
	for (int i = start; i < c; i++) {
		if (!check[i]) {
			check[i] = true;
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
				dfs(i + 1, cntvow + 1, cntcon, pw + arr[i]);
			}
			else {
				dfs(i + 1, cntvow, cntcon + 1, pw + arr[i]);
			}
			check[i] = false;
		}
	}
}
int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + c);
	dfs(0, 0, 0, "");
}
#include<iostream>
#include<algorithm>
using namespace std;
int coin[6] = { 500,100,50,10,5,1 };
int main() {
	int n, ans = 0;
	cin >> n;
	n = 1000 - n;
	for (int i = 0; i < 6; i++) {
		if (n >= coin[i]) {
			ans += n / coin[i];
			n %= coin[i];
		}
	}
	cout << ans << endl;
}
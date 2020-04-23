#include<iostream>
#include<algorithm>

using namespace std;
long long a, b, c, ans=1;

int main() {
	cin >> a >> b >> c;

	while (b) {
		if (b % 2)//2진수로 처리
			ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	cout << ans%c << endl;
}
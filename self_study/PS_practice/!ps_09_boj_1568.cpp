#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;

	int ans = 0, bird = 1;
	while (n) {
		ans++;
		if (n < bird)
			bird = 1;
		n = n - bird;
		bird++;
	}

	cout << ans << endl;
}//뜬금없이 헷갈려버림..
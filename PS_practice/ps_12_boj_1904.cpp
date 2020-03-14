#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int n1 = 1, n2 = 1, sum = 1;
	for (int i = 2; i <= n; i++) {
		sum = (n1 + n2) % 15746;
		n1 = n2;
		n2 = sum;
	}

	cout << sum << '\n';
}
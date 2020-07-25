#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int num(int n, int r, int c) {
	if (n == 0) return 0;
	if (n == 1) {
		if (r == 0 && c == 0) return 0;
		if (r == 0 && c == 1) return 1;
		if (r == 1 && c == 0) return 2;
		if (r == 1 && c == 1) return 3;
	}
	int p = pow(2, n - 1);
	if (r < p && c < p) return num(n - 1, r, c);
	if (r < p && c >= p) return pow(2,2*(n-1)) + num(n - 1, r, c - p);
	if (r >= p && c < p) return 2 * pow(2, 2 * (n - 1)) + num(n - 1, r - p, c);
	if (r >= p && c >= p) return 3 * pow(2, 2 * (n - 1)) + num(n - 1, r - p, c - p);
}
int main() {
	int n, r, c;
	cin >> n >> r >> c;
	cout << num(n, r, c);
}
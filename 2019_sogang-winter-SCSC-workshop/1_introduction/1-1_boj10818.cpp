#include<iostream>
using namespace std;
int main() {
	int N;
	int min = 1000000, max = -1000000, x;
	cin >> N;
	while (N--) {
		cin >> x;
		if (x > max) max = x;
		if (x < min) min = x;
	}
	cout << min << ' ' << max << endl;
}
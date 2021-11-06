#include<iostream>
#include<cmath>

using namespace std;

int m, n;

int main() {
	cin >> m >> n;

	int temp = -1;
	int sum = 0;
	for (int i = m; i <= n; i++) {
		if (i == pow((int)sqrt(i), 2)) {
			if (temp == -1) temp = i;
			sum += i;
		}
	}

	if(temp!=-1) cout << sum << endl;
	cout << temp << endl;
}
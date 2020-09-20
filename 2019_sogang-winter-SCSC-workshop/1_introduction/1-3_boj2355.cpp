#include<iostream>
using namespace std;
int main() {
	long long A, B, max, min;
    long long sum;
	cin >> A;
	cin >> B;
	
	if (A > B) {
		max = A;
		min = B;
	}
	else {
		max = B;
		min = A;
	}

	if (min > 0) {
		sum = max * (max + 1) / 2 - min * (min - 1) / 2;
	}
	else if (max * min < 0) {
		sum = max * (max + 1) / 2 - min * (min - 1) / 2;
	}
	else {
		sum = max * (max + 1) / 2 - min * (min - 1) / 2;
	}
	
	cout << sum << endl;
}
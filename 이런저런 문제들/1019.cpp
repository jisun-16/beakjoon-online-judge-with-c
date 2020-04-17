#include<iostream>
#include<cmath>

using namespace std;

long long cnt[10];

int main() {
	long long n;
	cin >> n;

	int exp = 0;
	int temp = 0;
	while (n) {
		int a = n / 10, b = n % 10;
		for (int i = 0; i < 10; i++) {
			if (i < b)
				cnt[i] += pow(10, exp) * (a + 1);
			else if (i == b)
				cnt[i] += pow(10, exp) * a + temp + 1;
			else 
				cnt[i] += pow(10, exp) * a;
		}
		cnt[0] -= pow(10, exp);//가장 앞에 0이 위치할경우 세지 않는다
		temp += pow(10, exp) * b;
		exp++;
		n /= 10;
	}

	for (int i = 0; i < 10; i++) cout << cnt[i] << ' ';
}
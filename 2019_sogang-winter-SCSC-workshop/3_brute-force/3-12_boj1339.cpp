#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string word[10];
int N, ans, alp[26];

bool compare(int a, int b) {
	return a > b;
}

void calc(){
	for (int i = 0; i < N; i++) {
		string x = word[i];
		int len = x.length();
		int pow = 1;
		for (int j = len - 1; j >= 0; j--) {
			int temp = x[j] - 'A';
			alp[temp] += pow;
			pow *= 10;
		}
	}

	sort(alp, alp + 26, compare);

	for (int i = 0; i < 10; i++) {
		ans += alp[i] * (9 - i);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> word[i];

	calc();

	cout << ans;

	return 0;
}
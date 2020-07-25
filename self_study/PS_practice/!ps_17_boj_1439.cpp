#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int cnt0 = 0, cnt1 = 0;
	string s;
	cin >> s;
	if (s[0] == '0') cnt1++;
	if (s[0] == '1') cnt0++;
	for (int i = 1; i < s.length(); i++) {
		if (s[i - 1] != s[i]) {
			if (s[i] == '0') cnt1++;
			if (s[i] == '1') cnt0++;
		}
	}
	cout << min(cnt0, cnt1) << endl;
}
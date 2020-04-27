#include<iostream>
#include<cstring>
#define MOD 100000
using namespace std;

int n;
long long dp[1001][1001];
string arr;
char op[3] = { '(','{','[' }, clo[3] = { ')','}',']' };

long long solve(int start, int end) {
	if (start > end) return 1;
	long long& result = dp[start][end];

	if (result != -1)
		return result;

	result = 0;
	for (int i = start + 1; i <= end; i += 2) {
		for (int j = 0; j < 3; j++) {
			if (arr[start] == op[j] || arr[start] == '?') {
				if (arr[i] == clo[j] || arr[i] == '?') {
					long long temp = solve(start + 1, i - 1) * solve(i + 1, end);
					result += temp;
					if (result >= MOD) result = MOD + result % MOD;
				}
			}
		}
	}

	return result;
}

int main() {
	cin >> n;
	cin >> arr;

	memset(dp, -1, sizeof(dp));
	long long ans = solve(0, n - 1);

	if (ans >= MOD) printf("%05lld\n", ans % MOD);
	else cout << ans % MOD << '\n';

	return 0;
}
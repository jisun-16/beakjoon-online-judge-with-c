#include<stdio.h>
#define mod 10007
int main() {
	int N;
	int up[1001][10] = {0};
	scanf("%d", &N);
	for (int i = 0; i < 10; i++) up[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++)
				up[i][j] = (up[i][j] + up[i - 1][k]) % mod;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) sum = (sum + up[N][i]) % mod;
	printf("%d", sum % mod);
	return 0;
}
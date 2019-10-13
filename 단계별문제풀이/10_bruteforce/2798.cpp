#include<stdio.h>
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	
	int x[100] = { 0 };
	for (int i = 0; i < N; i++) {
		scanf("%d", &x[i]);
	}

	int min = M, sum = 0, ans = 0;
	for (int i = N-1; i >= 2; i--) {
		for (int j = i-1; j >=1; j--) {
			for (int k = j-1; k >= 0; k--) {
				sum = x[i] + x[j] + x[k];
				if (sum <= M) {
					if (sum== M) {
						printf("%d", sum);
						return 0;
					}
					else {
						if (M - sum < min) {
							min = M - sum;
							ans = sum;
						}
					}
				}
			}
		}
	}

	printf("%d", ans);
}
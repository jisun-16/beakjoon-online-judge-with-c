#include<stdio.h>
int main() {
	int N, tyle[1001];
	scanf("%d", &N);
	tyle[0] = 1; 
	tyle[1] = 1; 
	tyle[2] = 2;
	for (int i = 3; i <= N; i++) {
		tyle[i] = (tyle[i - 1] + tyle[i - 2])%10007;
	}
	printf("%d", tyle[N]);
	return 0;
}
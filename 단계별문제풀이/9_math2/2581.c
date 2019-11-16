#include<stdio.h>
int check(int x) {
	if (x == 1) return 0;
	for (int i = 2; i <= x / 2; i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}
int main()
{
	int M, N, sum = 0, min = 10000;
	scanf("%d", &M);
	scanf("%d", &N);

	for (int i = M; i <= N; i++) {
		if (check(i) == 1) sum += i;
	}

	for (int i = M; i <= N; i++) {
		if (check(i) == 1) {
			min = i;
			break;
		}
	}

	if (sum > 0) printf("%d\n%d", sum, min);
	else printf("-1");
}
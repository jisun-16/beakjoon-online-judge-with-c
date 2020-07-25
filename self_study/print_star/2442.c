#include<stdio.h>
int main() {
	int N, cnt = 0, i;
	scanf("%d", &N);
	while (cnt != N) {
		for (i = 0; i < N-1 - cnt; i++) printf(" ");
		for (; i < N - 1; i++) printf("*");
		printf("*");
		for (i = 0; i < cnt; i++) printf("*");
		printf("\n");
		cnt++;
	}
	return 0;
}
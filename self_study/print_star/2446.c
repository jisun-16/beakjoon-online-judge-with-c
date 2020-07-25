#include<stdio.h>
int main() {
	int N, cnt = 0, cnt2, i;
	scanf("%d", &N);
	while (cnt!=2*N-1) {
		cnt++;
		if (cnt <= N) {
			for (i = 1; i < cnt; i++) printf(" ");
			for (; i <= N; i++) printf("*");
			for (; i <= 2 * N - cnt; i++) printf("*");
		}
		else {
			cnt2 = 2*N-cnt;
			for (i = 1; i < cnt2; i++) printf(" ");
			for (; i <= N; i++) printf("*");
			for (; i <= 2 * N - cnt2; i++) printf("*");
		}
		printf("\n");
	}
	return 0;
}
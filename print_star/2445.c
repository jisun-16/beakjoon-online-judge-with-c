#include<stdio.h>
int main() {
	int N, cnt = 0, cnt2, i;
	scanf("%d", &N);
	while (cnt!=2*N) {
		cnt++;
		if (cnt <= N) {
			for (i = 0; i < cnt; i++) printf("*");
			for (; i < 2 * N - cnt; i++) printf(" ");
			for (; i < 2 * N; i++) printf("*");
		}
		else {
			cnt2 = 2*N-cnt;
			for (i = 0; i < cnt2; i++) printf("*");
			for (; i < 2 * N - cnt2; i++) printf(" ");
			for (; i < 2 * N; i++) printf("*");
		}
		printf("\n");
	}
	return 0;
}
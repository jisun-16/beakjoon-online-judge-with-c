#include<stdio.h>
int main() {
	int N, cnt = 0, cnt2, i;
	scanf("%d", &N);
	while (cnt!=2*N-1) {
		cnt++;
		if (cnt < N) {
			for (i = 0; i < N - cnt; i++) printf(" ");
			for (; i < N; i++) printf("*");
		}
		else if (cnt == N) {
			for (i = 0; i < N; i++) printf("*");
		}
		else {
			cnt2 = 2*N-cnt;
			for (i = 0; i < N - cnt2; i++) printf(" ");
			for (; i < N; i++) printf("*");
		}
		printf("\n");
	}
	return 0;
}
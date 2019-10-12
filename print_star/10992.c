#include<stdio.h>
int main() {
	int N, cnt = 0, i;
	scanf("%d", &N);
	while (cnt < N-1) {
		for (i = N - 1; i > cnt; i--) {
			printf(" ");
		}
		if(cnt > 0) printf("*");
		for (i = 0; i < 2*cnt-1; i++) printf(" ");
		printf("*\n");
		cnt++;
	}
	for (i = 0; i < 2 * N - 1; i++) printf("*");
	return 0;
}
#include<stdio.h>
int main() {
	int N;
	scanf("%d", &N);

	int ans = 0, cal;
	for (int i = 0; i < N; i++) {
		cal = i;
		
		for (int j = i; j > 0;) {
			cal += j%10;
			j /= 10;
		}

		//printf("%d\n", cal);
		if (cal == N) {
			printf("%d", i);
			return 0;
		}
	}

	printf("%d", ans);
}
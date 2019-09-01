#include<stdio.h>
int main()
{
	int N, x[51], y[51], rank[51];
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}

	for (int i = 0; i < N; i++) {
		rank[i] = 1;
		for (int j = 0; j < N; j++) {
			if (x[j] > x[i] && y[j] > y[i]) rank[i]++;
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", rank[i]);
	}
}
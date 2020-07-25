#include<stdio.h>
int main()
{
	int N, a[1001], temp;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", a[i]);
	}
}
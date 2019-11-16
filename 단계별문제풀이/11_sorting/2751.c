#include<stdio.h>
#include<stdlib.h>
int *sorted = NULL;
int* a = NULL;
void marge(int* a, int m, int mid, int n) {
	int i = m, j = mid + 1, k = m;

	while (i <= mid && j <= n) {
		if (a[i] < a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}

	if (i > mid) {//i배열이 먼저 끝났을 경우
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sorted[k] = a[t];
			k++;
		}
	}

	for (int t = m; t <= n; t++) a[t] = sorted[t];
}
void margesort(int* a, int m, int n) {
	if (m < n) {
		int mid = (m + n) / 2;
		margesort(a, m, mid);
		margesort(a, mid + 1, n);
		marge(a, m, mid, n);
	}
	else return;
}
int main()
{
	int N;
	scanf("%d", &N);

	a = (int*)malloc(sizeof(int) * N);
	sorted = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) scanf("%d", &a[i]);

	margesort(a, 0, N - 1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", a[i]);
	}

	free(a);
	free(sorted);


}
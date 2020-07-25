#include<stdio.h>
int main()
{
	int n, x;
	scanf_s("%d %d", &n, &x);
	int a[10000];
	for (int i = 0; i < n; i++) scanf_s("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		if (a[i] < x) printf("%d ", a[i]);
	}
	printf("\n");
}
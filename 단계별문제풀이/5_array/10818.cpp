#include<stdio.h>
int main()
{
	int n, a, max=-1000000, min=1000000;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a);
		if (a > max) max = a;
		if (a < min) min = a;
	}
	printf("%d %d\n", min, max);
}
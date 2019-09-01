#include<stdio.h>
int main()
{
	int n, sum=0;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		sum = sum + i;
	}
	printf("%d", sum);
}
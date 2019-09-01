#include<stdio.h>
int main()
{
	int a[10], check[42] = {0, }, count=0;
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &a[i]);
		check[a[i] % 42]++;
	}
	for (int i = 0; i < 42; i++) {
		if (check[i] != 0) count++;
	}
	printf("%d\n", count);
}
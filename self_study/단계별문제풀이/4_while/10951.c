#include<stdio.h>
int main()
{
	int a = 1, b = 1;
	while (scanf_s("%d %d", &a, &b) != EOF) {
		printf("%d\n", a + b);
	}
}
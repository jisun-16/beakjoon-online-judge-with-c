#include<stdio.h>
int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j < n)printf(" ");
			else printf("*");
		}
		printf("\n");
	}
}
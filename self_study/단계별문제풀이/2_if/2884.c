#include<stdio.h>
int main()
{
	int h, m;
	scanf_s("%d %d", &h, &m);
	if (m > 45) printf("%d %d\n", h, m - 45);
	else if (h > 0) printf("%d %d\n", h - 1, m + 15);
	else printf("23 %d\n", m + 15);
}

#include<stdio.h>
int main()
{
	int n,i=1;
	scanf_s("%d", &n);
	int a = (n / 10 + n % 10) % 10;
	int b = 10 * (n % 10) + a;
	while (b != n) {
		a = (b/ 10 + b % 10) % 10;
		b = 10 * (b % 10) + a;
		i++;
	}
	printf("%d\n", i);
}
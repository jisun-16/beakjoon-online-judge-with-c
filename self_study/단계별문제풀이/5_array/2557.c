#include<stdio.h>
int main()
{
	int a, b, c, x, l=1;
	int count[10] = {0,};

	scanf_s("%d\n%d\n%d", &a, &b, &c);
	x = a * b * c;

	int y = x;
	while (y >=10) {
		l++;
		y /= 10;
	}

	for (int i = 0; i < l; i++) {
		count[x % 10]++;
		x /= 10;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", count[i]);
	}
}
#include<stdio.h>
int main()
{
	int a[9], i, max=0, num=0;
	for (i = 0; i < 9; i++) {
		scanf_s("%d", &a[i]);
		if (a[i] > max) {
			max = a[i];
			num = i+1;
		}
	}
	printf("%d\n%d\n", max, num);
}
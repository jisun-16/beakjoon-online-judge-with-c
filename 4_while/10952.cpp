#include<stdio.h>
int main()
{
	int a=1, b=1;
	while (a!=0||b!=0) {
		scanf_s("%d %d", &a, &b);
		if(a!=0||b!=0)printf("%d\n", a + b);
	}
}
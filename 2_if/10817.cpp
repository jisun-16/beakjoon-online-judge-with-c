#include<stdio.h>
int main()
{
	int a, b, c;
	scanf_s("%d %d %d", &a, &b, &c);
	if (a >= b)
		if (b >= c) printf("%d\n", b);//a b c
		else if (c >= a) printf("%d\n", a);//c a b
		else printf("%d\n", c);
	else//b a
		if (c >= b) printf("%d\n", b);//c b a
		else if (c <= a) printf("%d\n", a);//b a c
		else printf("%d\n", c);
}
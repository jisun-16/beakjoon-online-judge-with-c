#include<stdio.h>
int main()
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	
	int a[4] = { x, y, w - x, h - y }, min = x;

	for (int i = 0; i < 4; i++) {
		if (a[i] < min) min = a[i];
	}

	printf("%d", min);
}
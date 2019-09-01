#include<stdio.h>
int main()
{
	int A, B, a[3], b[3];

	scanf("%3d %3d", &A, &B);

	for (int i = 0; i < 3; i++) {
		a[i] = A % 10;
		b[i] = B % 10;
		A /= 10;
		B /= 10;
	}

	if (a[0] > b[0]) printf("%d%d%d", a[0], a[1], a[2]);
	else if (a[0] < b[0])printf("%d%d%d", b[0], b[1], b[2]);
	else {
		if(a[1]>b[1])printf("%d%d%d", a[0], a[1], a[2]);
		else if(a[1]<b[1])printf("%d%d%d", b[0], b[1], b[2]);
		else {
			if(a[2]>b[2])printf("%d%d%d", a[0], a[1], a[2]);
			else printf("%d%d%d", b[0], b[1], b[2]);
		}
	}
}
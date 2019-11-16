#include<stdio.h>
int main()
{
	int r;
	scanf("%d", &r);

	printf("%.6f ", r * r * 3.14159265359);//유클리드 기하학
	printf("%.6f", 2.0 * r * r);
}
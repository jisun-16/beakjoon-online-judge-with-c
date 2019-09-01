#include<stdio.h>
int main()
{
	int n;
	scanf_s("%d", &n);

	double a[1000], max=0;
	for (int i = 0; i < n; i++) {
		scanf_s("%lf", &a[i]);
		if (a[i] > max) max = a[i];
	}
	
	double x = 0;
	for (int i = 0; i < n; i++) {
		a[i] = (a[i] / max)*100.0;
		x = x + a[i];
	}//새로운 점수, 합 계산

	printf("%.3lf\n", x/(double)n);
}
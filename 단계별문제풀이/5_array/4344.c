#include<stdio.h>
int main()
{
	int C, N, count=0;
	scanf_s("%d", &C);

	double sum=0, ave=0;

	for (int i = 0; i < C; i++) {
		scanf_s("%d", &N);
		double n[1000];
		for (int j = 0; j < N; j++) {
			scanf_s("%lf", &n[j]);
			sum += n[j];
		}

		ave = sum / (double)N;
		for (int j = 0; j < N; j++) {
			if (n[j] > ave) count++;
		}
		printf("%.3lf%%\n", ((double)count / (double)N)*100);
		count = 0;
		sum = 0;
	}
}
#include<stdio.h>
int main()
{
	int N;
	scanf("%d", &N);

	int n = N / 5, cnt = -1;

	for (int i = n; i >= 0; i--) {
		if ((N - 5 * i) % 3 == 0) {
			cnt = i + (N - 5 * i) / 3;
			break;
		}
	}

	printf("%d", cnt);
}
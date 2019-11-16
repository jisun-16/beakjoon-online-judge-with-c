#include<stdio.h>
int main()
{
	int N, i=1, a, b;
	scanf("%d", &N);

	//n*(n-1)/2<N<=n*(n+1)/2
	while (1) {
		if (N == 1) {
			a = 1;
			b = 1;
			break;
		}
		else if (N > i * (i - 1) / 2 && N <= i * (i+1) / 2) {
			int x = N - i * (i - 1) / 2;
			if (i % 2 == 1) {
				a = i - x + 1;
				b = x;
				break;
			}
			else {
				b = i - x + 1;
				a = x;
				break;
			}
		}
		i++;
	}

	printf("%d/%d", a, b);
}
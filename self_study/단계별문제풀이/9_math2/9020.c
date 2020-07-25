#include<stdio.h>
int main()
{
	int T;
	scanf("%d", &T);

	int x[10001] = { 0 };
	x[1] = 1;
	for (int i = 2; i < 10001; i++) {
		if (x[i] == 0) {
			for (int j = 2; j * i < 10001; j++) x[i * j] = 1;
		}
	}
	
	for (int i = 0; i < T; i++) {
		int n, p1=0, p2=0, d;
		scanf("%d", &n);

		d = n;

		for (int j = 2; j <= n/2; j++) {

			if (x[j] == 0 && x[n - j] == 0) {

				if (n - 2 * j < d) {
					p1 = j;
					p2 = n - j;
					d = p2 - p1;
				}
			}
		}

		printf("%d %d\n", p1, p2);
	}
}
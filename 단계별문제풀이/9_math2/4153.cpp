#include<stdio.h>
int main()
{
	while (1) {
		int a[3];
		scanf("%d %d %d", &a[0], &a[1], &a[2]);
		if (a[0] == 0) break;

		int max = a[0], cnt = 0, cal = 0;
		for (int i = 0; i < 3; i++) {
			if (a[i] > max) {
				max = a[i];
				cnt = i;
			}
		}

		for (int i = 0; i < 3; i++) {
			if (i != cnt) cal = cal + a[i] * a[i];
		}

		if (max * max == cal) printf("right\n");
		else printf("wrong\n");
	}
}
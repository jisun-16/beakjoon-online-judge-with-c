#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	double sum = 0;
	scanf("%d", &n);

	int cnt[8001] = { 0 };

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		sum = sum + x;
		cnt[4000 + x]++;
	}

	printf("%d\n", (int)floor(sum/n+0.5));

	int i = 0, j = 0;
	while (1) {
		if (cnt[i] > 0) {
			j=j+cnt[i];
		}
		if (j >= n / 2 + 1) {
			printf("%d\n", i - 4000);
			break;
		}
		i++;
	}

	int mo[2] = { -1,-1 }, max = 0, k = 0;
	for (int i = 0; i < 8001; i++) {
		if (cnt[i] > max) max = cnt[i];
	}
	for (int i = 0; i < 8001; i++) {
		if (cnt[i] == max) {
			mo[k] = i;
			k++;
		}
		if (k == 2) break;
	}
	if (mo[1] >= 0) printf("%d\n", mo[1]-4000);
	else printf("%d\n", mo[0]-4000);


	int M, m;
	for (int i = 0; i < 8001; i++) {
		if (cnt[i] > 0) {
			m = i;
			break;
		}
	}
	for (int i = 8000; i >= 0; i--) {
		if (cnt[i] > 0) {
			M = i;
			break;
		}
	}
	printf("%d\n", M - m);
}
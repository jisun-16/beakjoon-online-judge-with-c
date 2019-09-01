#include<stdio.h>
int main()
{
	int N, cnt = 0, ans;
	scanf("%d", &N);

	for (int i = 666;; i++) {
		for (int j = i; j > 600;) {
			if (j % 1000 == 666) {
				cnt++;
				break;
			}
			j /= 10;
		}
		//printf("%d: %d\n", i, cnt);
		if (cnt == N) {
			ans = i;
			break;
		}
	}

	printf("%d", ans);
}
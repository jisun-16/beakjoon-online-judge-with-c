#include<stdio.h>
int main()
{

	int  check[123456 * 2 + 1] = { 0 };//0이면 소수
	check[1] = 1;//1은 소수가 아님

	while (1) {
		int n, cnt = 0;

		scanf("%d", &n);
		if (n == 0) break;//0을 입력하면 종료

		for (int i = 1; i <= 2 * n; i++) {
			if (check[i] == 0) {
				if (i > n) cnt++;
				for (int j = 2; j * i <= 2 * n; j++) check[j * i] = 1;
			}
		}

		printf("%d\n", cnt);
	}
}
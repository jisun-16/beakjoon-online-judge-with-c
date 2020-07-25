#include<stdio.h>
int check(int x) {
	if (x == 1) return 0;

	for (int i = 2; i <= x / 2; i++) {
			if (x % i == 0) return 0;
	}

	return 1;
}
int main()
{
	int N, cnt = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		if (check(x) == 1) cnt++;
		//printf("%d\n", cnt);
	}

	printf("%d", cnt);


}
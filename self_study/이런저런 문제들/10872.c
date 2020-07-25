#include<stdio.h>
int fac(int n)
{
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
	}
	return ans;
}
int main()
{
	int N, ans;
	scanf("%d", &N);
	ans = fac(N);
	printf("%d\n", ans);
	return 0;
}
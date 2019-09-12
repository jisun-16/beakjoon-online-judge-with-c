#include<stdio.h>
/*int fibo(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fibo(n - 1) + fibo(n - 2);
}*/
int main()
{//0 1 1 2 3 5 8 13...
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);
		int f1 = 0, f2=1;
		int sum = 0;
		for (int i = 0; i <= n; i++) {
			f1 = f2;
			f2 = sum;
			sum = f1 + f2;
		}
		if (n == 0) printf("1 0\n");
		else printf("%d %d\n", f1, f2);
	}
}
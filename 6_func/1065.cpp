#include<stdio.h>
int count(int n) {
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (i < 100) c++;
		else {
			if (i/100-i/10%10==i/10%10-i%10) c++;
		}
	}//123 2==2
	return c;
}
int main()
{
	int N, C;
	scanf_s("%d", &N);
	C = count(N);
	printf("%d\n", C);
	return 0;
}
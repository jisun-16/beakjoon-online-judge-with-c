#include<stdio.h>
#define N 10001//ū �� �̸� ����
int arr[N];
int dn(int n) {
	int d = n;
	while (n) {
		d = d + n % 10;
		n /= 10;
	}
	return d;
}
//� ���� n�� �����ڷ� �� ���� ���
int main()
{
	for (int i = 0; i < N; i++) {
		arr[i] = 1;
	}
	for (int i = 0; i < N;i++) {
		if(dn(i)<N) arr[dn(i)] = 0;
		if (arr[i] == 1) printf("%d\n", i);
	}
	return 0;
}
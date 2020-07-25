#include<stdio.h>
#define N 10001//큰 수 미리 정의
int arr[N];
int dn(int n) {
	int d = n;
	while (n) {
		d = d + n % 10;
		n /= 10;
	}
	return d;
}
//어떤 숫자 n을 생성자로 한 숫자 출력
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
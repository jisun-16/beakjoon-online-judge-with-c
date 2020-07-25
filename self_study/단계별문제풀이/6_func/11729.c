#include<stdio.h>
int count(int n) {
	int c = 1;
	for (int i = 0; i < n; i++) {
		c = c * 2;
	}
	return c - 1;
}
void func(int n, int a, int b){
	if (n == 1) {
		printf("%d %d\n", a, b);
		return;
	}

	int c = 6 - a - b;

	func(n - 1, a, c);//먼저 n-1개를 남는 공간에 옮기고
	printf("%d %d\n", a, b);//가장 큰 것을 b로 옮긴 다음

	func(n - 1, c, b);//남는 공간에 옮긴 것을 최종 목적지로 이동
}//a에서 b로 이동시키는 함수
int main()
{
	int N;
	scanf_s("%d", &N);
	printf("%d\n", count(N));
	func(N, 1, 3);
	return 0;
}
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

	func(n - 1, a, c);//���� n-1���� ���� ������ �ű��
	printf("%d %d\n", a, b);//���� ū ���� b�� �ű� ����

	func(n - 1, c, b);//���� ������ �ű� ���� ���� �������� �̵�
}//a���� b�� �̵���Ű�� �Լ�
int main()
{
	int N;
	scanf_s("%d", &N);
	printf("%d\n", count(N));
	func(N, 1, 3);
	return 0;
}
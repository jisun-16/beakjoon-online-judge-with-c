#include<stdio.h>

int num(int a, int b) {
	int sum = 0;
	if (a == 1) {
		sum = b * (b + 1) / 2;
		//printf("%d %d %d\n", a, b, sum);
		return sum;
	}

	for (int i = 1; i <= b; i++) {
		sum = sum + num(a - 1, i);
	}
	//a���� b���� ȣ���鵵 �� �������� ���� ������
	//printf("%d %d %d\n", a, b, sum);
	return sum;
}
int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		//for (int j = 1; j <= 5; j++) printf("%d��%dȣ: %d��\n", i, j, num(i, j, 0));
		int k, n;
		scanf("%d", &k);//k�� 0~14, ��
		scanf("%d", &n);//n�� 0~14, ȣ

		printf("%d\n", num(k, n));
	}
	
	/*for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			printf("%d�� %dȣ %d��\n", i, j, num(i, j));
		}
	}*/
	
	
}
/*
5�� 1 7
4�� 1 6
3�� 1 5
2�� 1 4 10 20
1�� 1 3 6 10... i(i+1)/2
o�� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 


*/
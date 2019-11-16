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
	//aÃşÀÇ bÀÌÀü È£¼öµéµµ ´Ù ´õÇØÁö´Â °ÍÀÌ ¹®Á¦ÀÓ
	//printf("%d %d %d\n", a, b, sum);
	return sum;
}
int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		//for (int j = 1; j <= 5; j++) printf("%dÃş%dÈ£: %d¸í\n", i, j, num(i, j, 0));
		int k, n;
		scanf("%d", &k);//k´Â 0~14, Ãş
		scanf("%d", &n);//nÀº 0~14, È£

		printf("%d\n", num(k, n));
	}
	
	/*for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			printf("%dÃş %dÈ£ %d¸í\n", i, j, num(i, j));
		}
	}*/
	
	
}
/*
5Ãş 1 7
4Ãş 1 6
3Ãş 1 5
2Ãş 1 4 10 20
1Ãş 1 3 6 10... i(i+1)/2
oÃş 1 2 3 4 5 6 7 8 9 10 11 12 13 14 


*/
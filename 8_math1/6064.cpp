#include<stdio.h>
int year(int M, int N, int x, int y) {

	int k = -1;
	for (int i = 0; i < N; i++) {
		if (y == N) {
			if ((M * i + x) % N == 0) {
				k = M * i + x;
				//printf("%d: %d\n", i, k);
				break;
			}
		}
		if (y == (M * i + x) % N) {
			k = M * i + x;
			//printf("%d: %d\n", i, k);
			break;
		}
	}

	return k;
}
int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int M, N, x, y;
		scanf("%d %d %d %d", &M, &N, &x, &y);
		int k;
		printf("%d\n", year(M, N, x, y));
	}

	/*for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 12; j++) {
			printf("%d: <%d, %d>\n", year(10, 12, i, j), i, j);
		}
	}*/
}
//<a,b> x=z%m, y=z%n; z의 값을 구하려면?
//k==m*i+x==n*j+y가 될 때까지 i를 증가시킴
#include<stdio.h>
#define max(x,y) (((x)>(y))?(x):(y))
int main() {
	int T, n;
	scanf("%d", &T);
	while (T) {
		T--;
		scanf("%d", &n);

		int** arr = (int**)malloc(2 * sizeof(int*));
		int** cmp = (int**)malloc(2 * sizeof(int*));
		for (int i = 0; i < 2; i++) {
			arr[i] = (int*)malloc(n * sizeof(int)); 
			cmp[i] = (int*)malloc(n * sizeof(int));
		}

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);

		cmp[0][0] = arr[0][0], cmp[1][0] = arr[1][0];
		cmp[0][1] = cmp[1][0] + arr[0][1];
		cmp[1][1] = cmp[0][0] + arr[1][1];
		for (int i = 2; i < n; i++) {
			cmp[0][i] = max(cmp[1][i - 1], cmp[1][i - 2]) + arr[0][i];
			cmp[1][i] = max(cmp[0][i - 1], cmp[0][i - 2]) + arr[1][i];
			
		}
		int MAX = max(cmp[0][n - 1], cmp[1][n - 1]);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++)printf("%d ", cmp[i][j]);
			printf("\n");
		}

		printf("%d\n", MAX);
	}
}
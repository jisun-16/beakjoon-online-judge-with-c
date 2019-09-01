#include<stdio.h>
#include<string.h>
int main() {
	int N;
	scanf("%d", &N);

	char x[105][105];
	for (int i = 0; i < N; i++) {
		scanf("%s", x[i]);
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		//i번째 단어 체크
		int check = 1;
		int n = strlen(x[i]);

		for (int j = 0; j < n; j++) {
			for (int k = j; k < n; k++) {
				if (x[i][j] == x[i][k]) {
					if (k != j&& x[i][k - 1] != x[i][j]) check = 0;
				}
			}
		}

		if (check == 1) cnt++;
	}

	printf("%d", cnt);
}
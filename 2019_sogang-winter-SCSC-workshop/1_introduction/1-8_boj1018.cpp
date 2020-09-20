#include<stdio.h>
int main()
{
	int N, M;
	char c[51][51];
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", c[i]);
	}

	int min = 64;

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int cnt_b = 0, cnt_w = 0;

			for (int b1 = i; b1 < i + 8; b1++) {
				for (int b2 = j; b2 < j + 8; b2++) {
					if ((b1 - i + b2 - j) % 2 == 0) {
						if (c[b1][b2] != 'B') cnt_b++;
					}
					else {
						if (c[b1][b2] != 'W') cnt_b++;
					}
				}
			}

			for (int w1 = i; w1 < i + 8; w1++) {
				for (int w2 = j; w2 < j + 8; w2++) {
					if ((w1 - i + w2 - j) % 2 == 0) {
						if (c[w1][w2] != 'W') cnt_w++;
					}
					else {
						if (c[w1][w2] != 'B') cnt_w++;
					}
				}
			}

			if (cnt_b < min) min = cnt_b;
			if (cnt_w < min) min = cnt_w;
		}
	}

	printf("%d", min);
}
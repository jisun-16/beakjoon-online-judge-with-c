#include<stdio.h>
void room(int H, int W, int N) {
	int n = N % H, m = N / H;

	if (n == 0) {
		printf("%d", H);
	}
	else {
		printf("%d", n);
		m++;
	}

	if (m < 10) printf("0%d\n", m);
	else printf("%d\n", m);
}
int main()
{
	int T, H, W, N;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &H, &W, &N);
		room(H, W, N);
	}

	return 0;
}
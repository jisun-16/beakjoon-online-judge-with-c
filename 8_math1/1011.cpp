#include<stdio.h>
#include<math.h>
int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		int dis = y - x;
		int z = sqrt(dis);

		if (dis < 4) printf("%d\n", dis);
		else if (z * z == dis) printf("%d\n", 2 * z - 1);
		else if (dis > (z + 1) * z)printf("%d\n", 2 * z + 1 );
		else printf("%d\n", 2 * z);
	}
}
/*int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		int n = y - x;
		int j = 0, cnt;
		while (1) {
			if (n < 0) break;
			j++;
			n = n - 2 * j;
		}
		if (n + 2 * j > j) cnt = 2 * (j - 1) + 2;
		else if (n + 2 * j > 0) cnt = 2 * (j - 1) + 1;
		else cnt = 2 * (j - 1);
		printf("%d\n", cnt);
	}
}왜 틀렸지... 어쨌든 for문 쓰지 않고 직접 계산 ㄱ*/
#include<stdio.h>
#include<math.h>
int max(int m, int n) {
	if (m > n) return m;
	else return n;
}
int min(int m, int n) {
	if (m < n) return m;
	else return n;
}
int main()
{
	int x1, x2, y1, y2, T, r1, r2;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		double dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		int m = max(r1, r2), n = min(r1, r2);
		
		if (dis == 0) {
			if (r1 == r2) printf("-1\n");
			else printf("0\n");
		}
		else {
			if (r1 + r2 < dis) {
				printf("0\n");
			}
			else if (r1 + r2 == dis) {
				printf("1\n");
			}
			else {//r1+r2>dis
				if (m > n + dis) printf("0\n");
				else if (m == n + dis) printf("1\n");
				else printf("2\n");
			}
		}
	}
}

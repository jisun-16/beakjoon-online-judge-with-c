#include<stdio.h>
int main()
{
	int x[4], y[4], cnt_x = 0, cnt_y = 0, m, n;

	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &x[i], &y[i]);
		if (x[i] == x[0]) cnt_x++;
		else m = x[i];
		if (y[i] == y[0]) cnt_y++;
		else n = y[i];
	}

	if (cnt_x == 1) printf("%d ", x[0]);
	else printf("%d ", m);

	if (cnt_y == 1) printf("%d", y[0]);
	else printf("%d", n);


}
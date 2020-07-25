#include<stdio.h>
#include<stdlib.h>
typedef struct data {
	int x;
	int y;
}data;
int compare(const void* a, const void* b) {
	data* p1 = (data *) a;
	data* p2 = (data*) b;

	if (p1->y > p2->y) return 1;
	else if (p1->y < p2->y) return -1;
	else {
		if (p1->x > p2->x) return 1;
		else if (p1->x < p2->x) return -1;
		else return 0;
	}
}
int main()
{
	int N;
	scanf("%d", &N);

	data* p = (data*)malloc(sizeof(data) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	qsort(p, N, sizeof(data), compare);

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", p[i].x, p[i].y);
	}
}
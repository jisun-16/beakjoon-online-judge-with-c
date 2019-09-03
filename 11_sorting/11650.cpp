#include<stdio.h>
#include<stdlib.h>

typedef struct data {
	int x;
	int y;
}data;

int compare(const void* a, const void* b) {
	data* pa = (data*)a;
	data* pb = (data*)b;

	if (pa->x > pb->x) return 1;
	else if(pa->x < pb->x) return -1;
	else {
		if (pa->y > pb->y) return 1;
		else if (pa->y < pb->y) return -1;
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

	for (int i = 0; i < N; i++) printf("%d %d\n", p[i].x, p[i].y);

	free(p);
}
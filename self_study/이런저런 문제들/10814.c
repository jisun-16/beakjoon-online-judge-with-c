#include<stdio.h>
#include<stdlib.h>
typedef struct data {
	int num;
	int age;
	char name[101];
} data;
int compare(const void* a, const void* b) {
	data* p1 = (data*)a;
	data* p2 = (data*)b;

	if (p1->age > p2->age)return 1;
	else if (p1->age < p2->age) return -1;
	else {
		if (p1->num > p2->num) return 1;
		else if (p1->num < p2->num) return -1;
		else return 0;
	}
}
int main()
{
	int N;
	scanf("%d", &N);

	data* P = (data*)malloc(sizeof(data) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d %s", &P[i].age, P[i].name);
		P[i].num = i;
	}
	
	qsort(P, N, sizeof(data), compare);

	for (int i = 0; i < N; i++) printf("%d %s\n", P[i].age, P[i].name);

	free(P);
}
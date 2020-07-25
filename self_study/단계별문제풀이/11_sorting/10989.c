#include<stdio.h>
int main()
{
	int N, temp;
	int sort[10001] = { 0 };
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		sort[temp]++;
	}

	for (int i = 0; i < 10001; i++) {
		while (sort[i] > 0) {
			printf("%d\n", i);
			sort[i]--;
		}
	}
}
#include<stdio.h>
#include<string.h>
int main() {
	char x[20];
	scanf("%s", x);

	int n = strlen(x);
	int time = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] == 'Z' || x[i] == 'Y') time += 10;
		else if(x[i] < 'S') time = time + (x[i] - 'A') / 3 + 3;
		else time = time + (x[i] -1 - 'A') / 3 + 3;
	}

	printf("%d", time);
}
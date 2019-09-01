#include<stdio.h>

int main() {
	int n, sum = 0;
	char x[101] = {0};

	scanf_s("%d", &n);
	scanf_s("%s", &x, n);

	for (int i = n-1; i >= 0; i--) sum += x[i]-'0';

	printf("%d\n", sum);
	return 0;
}//맞았다고 나오는데 값이 제대로 안뜸...
#include<stdio.h>
int main() {
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);
	int n = (v - b) / (a - b);
	if (v - b == n * (a - b)) printf("%d\n", n);
	else printf("%d\n", n + 1);
}
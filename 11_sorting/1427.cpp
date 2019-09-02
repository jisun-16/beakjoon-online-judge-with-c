#include<stdio.h>
void sorting(int* a) {
	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			if (a[i] < a[j]) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
int main()
{
	long long n;
	int a[10];
	scanf("%lld", &n);

	for (int j = 0; j < 10; j++) a[j] = -1;

	int i = 0;
	while (1) {
		if (n == 0) break;
		a[i] = n % 10;
		i++;
		n = n / 10;
	}

	sorting(a);

	for (int j = 0; j < 10; j++) {
		if (a[j] >= 0) printf("%d", a[j]);
	}
}
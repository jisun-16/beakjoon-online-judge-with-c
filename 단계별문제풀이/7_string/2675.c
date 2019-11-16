#include<stdio.h>

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);

		char s[25], P[200];
		scanf("%s", s);

		int j = 0;
		while(1) {
			if (s[j] == '\0') break;
			for (int k = 0; k < n; k++) {
				P[j*n+k] = s[j];
				printf("%c", P[j * n + k]);
			}
			j++;
		}
		printf("\n");
	}
}//맞았으나 scanf실행이 안됨..
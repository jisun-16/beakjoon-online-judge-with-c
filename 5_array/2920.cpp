#include<stdio.h>
int main()
{
	int a[8], i, k=0;
	for (i = 0; i < 8; i++) {
		scanf_s("%d", &a[i]);
		if (a[i] == i + 1) k++;
		else if (a[i] == 8 - i) k--;
		else k = k;
	}
	if (k == 8) printf("ascending\n");
	else if (k == -8) printf("descending\n");
	else printf("mixed\n");
}
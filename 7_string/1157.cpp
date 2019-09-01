#include<stdio.h>
int main()
{
	char s[1000000], check[52];
	scanf("%s", s);

	int count[26] = { 0, };

	for (int i = 0; i < 26; i++) {
		check[i] = 'A' + i;
	}

	for (int i = 26; i < 52; i++) {
		check[i] = 'a' + (i-26);
	}

	for (int i = 0; i < 26; i++) {
		int j = 0;
		while (1) {
			if (s[j] == '\0') break;
			if (s[j] == check[i] || s[j] == check[i + 26]) count[i]++;
			j++;
		}
	}

	int max = 0;

	for (int i = 0; i < 26; i++) {
		if (count[i] > max) max = count[i];
		//printf("count[%d]: %d, %d\n", i, count[i], max);
	}

	int c2=0, p;
	for (int i = 0; i < 26; i++) {
		if (count[i] == max) {
			p = i;
			c2++;
		}
	}

	if (c2 > 1) printf("?\n");
	else printf("%c\n", check[p]);
}
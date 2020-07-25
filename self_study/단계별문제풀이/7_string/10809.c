#include<stdio.h>
int main()
{
	char s[105], y[26];
	int x[26];

	for (int i = 0; i < 26; i++) {
		x[i] = -1;
		y[i] = i + 97;
	}

	scanf("%s", s);

	for (int i = 0; i < 26; i++) {
		int j = 0;
		while (1) {
			if (s[j] == y[i]) {
				x[i] = j;
				break;
			}
			if (s[j] == '\0') break;
			j++;
		}
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", x[i]);
	}
}

/*

#include<stdio.h>
int main()
{
	char s[105];
	int x[26], y[26];

	for (int i = 0; i < 26; i++) {
		x[i] = -1;
		y[i] = i + 97;
	}

	scanf("%s", s);

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 26; j++) {
			if (s[i] == y[j]) {
				if (x[j] == -1) x[j] = i;

			}

		}
	}

	for (int i = 0; i < 25; i++) {
		printf("%d ", x[i]);
	}
	printf("%d", x[25]);
}

왜 틀렸는지 모르겠음;
*/
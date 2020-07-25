#include<stdio.h>
#include<string.h>
int main()
{
	char x[105];
	scanf("%[^\n]s", x);

	int n = strlen(x);
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (x[i]<'a' || x[i]>'z') continue;
		else if (i > 0 && x[i] == 'z') {
			if (x[i - 1] == 'd' && x[i + 1] == '=') continue;
		}
		else if (i > 0 && x[i] == 'j') {
			if (x[i - 1] == 'l' || x[i - 1] == 'n') continue;
		}

		count++;
	}

	printf("%d", count);
}
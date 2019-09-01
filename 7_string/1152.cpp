#include<stdio.h>
#include<string.h>
int main()
{
	//32
	//공백을 카운트해서 단어의 갯수 세기 문자열 마지막에 공백이 들어가 있을 경우를 제외
	char x[1000005];
	scanf("%[^\n]s", x);

	int n = strlen(x);

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] == ' ' && i == 0) continue;
		if (x[i] != ' ' && x[i + 1] == ' ') count++;
	}

	if (x[n - 1] == ' ') printf("%d", count);
	else printf("%d", count+1);
}
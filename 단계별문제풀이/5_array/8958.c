#include<stdio.h>
#include<string.h>
int score_func(char* arr);
int main()
{
	int T, sum;
	char str[80];

	scanf_s("%d", &T);
	
	for (int i = 0; i < T; i++) {
		scanf_s("%s", str, 80);
		sum = score_func(str);
		printf("%d\n", sum);
	}
}

int score_func(char* arr)
{
	int score_sum = 0, score = 1, i = 0;
	while (i < strlen(arr)) {
		if (arr[i] == 'O') {
			score_sum += score;
			score++;
		}
		else score = 1;
		i++;
	}
	return score_sum;
}
#include<stdio.h>
#include<string.h>
char word[20001][51] = { 0, };

void merge(int start, int mid, int end) {
	int i = start, j = mid + 1, k = start;
	char temp[20001][51] = {0,};
	
	while (i <= mid && j <= end) {
		if (strlen(word[i]) > strlen(word[j])) {
			strcpy(temp[k++], word[j++]);
		}
		else if (strlen(word[i]) < strlen(word[j])) {
			strcpy(temp[k++], word[i++]);
		}
		//길이가 짧은 순으로 정렬
		else {
			//길이가 같으면 사전순으로 정렬
			if (strcmp(word[i], word[j]) == 0) {
				strcpy(temp[k++], word[i++]);
			}//두 단어가 같을 때
			else if (strcmp(word[i], word[j]) > 0) {
				strcpy(temp[k++], word[j++]);
			}//word[j]가 더 작을 때
			else {
				strcpy(temp[k++], word[i++]);
			}
		}
	}

	while (i <= mid) {
		strcpy(temp[k++], word[i++]);
	}
	while (j <= end) {
		strcpy(temp[k++], word[j++]);
	}

	for (int x = start; x <= end; x++) {
		strcpy(word[x], temp[x]);
	}
}

void mergesort(int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		mergesort(start, mid);
		mergesort(mid + 1, end);
		merge(start, mid, end);
	}
}
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%s", &word[i]);

	mergesort(0, N - 1);

	for (int i = 0; i < N; i++) {
		if (strcmp(word[i], word[i + 1]) != 0) printf("%s\n", word[i]);
	}
}
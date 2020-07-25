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
		//���̰� ª�� ������ ����
		else {
			//���̰� ������ ���������� ����
			if (strcmp(word[i], word[j]) == 0) {
				strcpy(temp[k++], word[i++]);
			}//�� �ܾ ���� ��
			else if (strcmp(word[i], word[j]) > 0) {
				strcpy(temp[k++], word[j++]);
			}//word[j]�� �� ���� ��
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
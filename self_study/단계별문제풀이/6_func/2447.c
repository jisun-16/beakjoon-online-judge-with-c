#include<stdio.h>
#define max 2200
int N;
bool arr[max][max];//0�̸� �� ���

void hole(int size, int x, int y)//size��ŭ�� ������ �մ� �Լ�
{
	if (size <1|| x+size>N || y+size>N)return;
	if (arr[x][y]) return;//�̹� �շ����� �Ѿ

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[x+i][y+j] = true;
		}
	}

	hole(size, x + 3*size, y);//�����ʿ� ���� ���� �ձ�
	hole(size, x, y + 3*size);//�Ʒ��� ���� ���� �ձ�
	hole(size / 3, x / 3, y / 3);//�� �ܰ� ���� ����
}

int main()
{
	scanf_s("%d", &N);
	hole(N/3,N/3,N/3);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j]) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
	return 0;
}
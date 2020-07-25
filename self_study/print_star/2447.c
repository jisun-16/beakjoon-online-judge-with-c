#include<stdio.h>
#define max 2200
int N;
bool arr[max][max];//0이면 별 출력

void hole(int size, int x, int y)//size만큼의 구멍을 뚫는 함수
{
	if (size <1|| x+size>N || y+size>N)return;
	if (arr[x][y]) return;//이미 뚫려있음 넘어감

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[x+i][y+j] = true;
		}
	}

	hole(size, x + 3*size, y);//오른쪽에 같은 구멍 뚫기
	hole(size, x, y + 3*size);//아래에 같은 구멍 뚫기
	hole(size / 3, x / 3, y / 3);//한 단계 작은 구멍
}

int main()
{
	scanf("%d", &N);
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
#include<stdio.h>
#include<string.h>
int main()
{
	//32
	//������ ī��Ʈ�ؼ� �ܾ��� ���� ���� ���ڿ� �������� ������ �� ���� ��츦 ����
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
#include<stdio.h>
int main()
{
	long a, b, c;
	scanf("%ld %ld %ld", &a, &b, &c);
	//a ������� b ������� c ��Ʈ���� ����

	int n = 0;

	if (c > b) {
		//c*n>a+n*b -> (c-b)*n>a -> n>a/(c-b)
		n = a / (c - b) + 1;
	}
	else n = -1;

	/*while (1) {
		n++;
		if (c <= b) {
			n = -1;
			break;
		}
		else if (c * n > a + b * n) break;
	} �ð��ʰ�*/

	printf("%d", n);
}
#include<stdio.h>
int min(int a, int b) {
	return a < b ? a : b;
}
int main()
{
	int n, arr[100001];//10의 6승이어야 하지만 VS에서 에러나서 줄임
	scanf("%d", &n);

	arr[0] = -1;
	arr[1] = 0;
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) {
			arr[i] = min(arr[i],arr[i/2]+1);
		}
		if (i % 3 == 0) {
			arr[i] = min(arr[i], arr[i / 3] + 1);
		}
	}
	printf("%d", arr[n]);
}
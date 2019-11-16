#include<stdio.h>
int main()
{
	long long N;
	scanf("%lld", &N);
	

	if (N == 1) printf("1");
	else if (N == 2) printf("2");
	else {
		int i = 0;
		while(1) {
			if ((N - 2) / 6 >= i * (i - 1) / 2 && (N - 2) / 6 < i * (i + 1) / 2) {
				i++;
				break;
			}
			i++;
		}
		printf("%d", i);
		
	}
	//1 2~7 8~19 1 6 12 18 
	//-1 0~5(0) 6~17(1,2) 18~35(3,4,5) (6,7,8,9)
	//+(n-1)
}
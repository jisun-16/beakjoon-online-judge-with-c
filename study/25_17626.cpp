#include<cstdio>
#include<cmath>

int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=1;i*i<=n;i++)
		if(i*i==n){
			printf("1\n");
			return 0;
		}
	
	for(int i=1;i*i<=n;i++)
		for(int j=i;j*j<=n;j++)
			if(i*i+j*j==n){
				printf("2\n");
				return 0;
			}
	
	for(int i=1;i*i<=n;i++)
		for(int j=i;j*j<=n;j++)
			for(int k=j;k*k<=n;k++)
				if(i*i+j*j+k*k==n){
					printf("3\n");
					return 0;
				}
	
	printf("4\n");
	return 0;
}

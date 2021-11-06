#include<cstdio>
int mod=1e9,n,a,b,c;
int main(){
	scanf("%d",&n);
	a=0,b=1;
	if(n==1) printf("0\n");
	else if(n==2) printf("1\n");
	else{
		for(int i=3;i<=n;++i){
			c=(long long)(i-1)*(a+b)%mod;
			a=b,b=c;
		}
		printf("%d\n",c);
	}
}

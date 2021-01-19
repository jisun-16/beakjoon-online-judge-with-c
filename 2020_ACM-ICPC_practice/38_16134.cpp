#include<cstdio>
//n!/r!(n-r)!
long long n,r,mod=1000000007;
long long inverse(long long a,long long b){
	if(b==0) return 1;
	if(b%2) return (a*inverse(a,b-1))%mod;
	long long c=inverse(a,b/2);
	return c*c%mod;
}
int main(){
	long long a=1,b=1;
	scanf("%d %d",&n,&r);
	if(r>n-r) r=n-r;
	for(int i=0;i<r;++i){
		a=(a*(n-i))%mod;
		b=(b*(i+1))%mod;
	}
	printf("%lld\n",a*inverse(b,mod-2)%mod);
}

#include<cstdio>
//n!/r!(n-r)!
long long m,n,r,mod=1000000007,fac[4000001];
long long inverse(long long a,long long b){
	if(b==0) return 1;
	if(b%2) return (a*inverse(a,b-1))%mod;
	long long c=inverse(a,b/2);
	return c*c%mod;
}
int main(){
	fac[0]=1,fac[1]=1;
	for(int i=1;i<=4000000;++i) fac[i+1]=(fac[i]*(i+1))%mod;
	scanf("%d",&m);
	while(m--){
		long long a,b;
		scanf("%d %d",&n,&r);
		a=fac[n],b=fac[r]*fac[n-r]%mod;
		printf("%lld\n",a*inverse(b,mod-2)%mod);
	}
	
}

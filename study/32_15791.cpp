#include<cstdio>

const long long mod=1000000007;

long long power(long long b,long long c){
	long long ret=1;
	while(c){
		if(c&1) ret=ret*b%mod;
		b=b*b%mod;
		c>>=1;
	}
	return ret;
}

int main(){
	long long n,m;
	scanf("%lld %lld",&n,&m);
	if(n-m>m) m=n-m;
	//ans=n!/m!(n-m)!=n(n-1)...(m+1)/(n-m)!
	long long a=1,b=1;
	for(long long i=1;i<=n-m;++i){
		a*=i+m;a%=mod;
		b*=i;b%=mod;
	}
	//1/b=b^(mod-2)
	printf("%lld\n",a*power(b,mod-2)%mod);
	
}

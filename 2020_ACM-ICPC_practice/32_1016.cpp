#include<cstdio>

using namespace std;

#define ll long long

int ans;
ll m,M;
bool chk[1000001],p[1000001];

int main(){
	scanf("%lld %lld",&m,&M);
	
	ans=M-m+1;
	
	for(ll i=2;i*i<=M;++i){
		if(p[i]) continue;//Á¦°ö¼öÀÇ  
		for(ll j=i;j*j<=M;j+=i) p[j]=true;
		for(ll j=((m-1)/(i*i)+1)*i*i;j<=M;j+=i*i)
			if(!chk[j-m]) chk[j-m]=true,ans--;
	}
	
	printf("%d\n",ans);
	
}

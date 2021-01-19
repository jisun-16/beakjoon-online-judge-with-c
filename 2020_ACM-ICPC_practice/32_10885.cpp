#include<cstdio>

#define ll long long

using namespace std;

const int mod=1e9+7;

int pow(int c){
	int ret=1,d=2;
	while(c){
		if(c&1) ret=(long long)ret*d%mod;
		d=(long long)d*d%mod;
		c>>=1;
	}
	return ret;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a=0,b=0,ans=-1,p=2e9; 
		for(int i=0;i<n;++i) {
			int temp;
			scanf("%d",&temp);
			if(temp==0){
				p=2e9;
				a=b=0;
				continue;
			}
			else if(temp<0){
				++b;
				if(temp==-2) ++a;
			}
			else if(temp==2)
				++a;
			if(b&1){
				if(p==2e9) p=a;
				else if(ans<a-p) ans=a-p;
			}else{
				if(ans<a) ans=a;
			}
		}
		if(ans<0) printf("0\n");
		else printf("%d\n",pow(ans));
	}
}

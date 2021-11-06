#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

typedef long long ll;

string s;
int m,n;
ll h1[1000001],h2[1000001];
ll base1[1000001],base2[1000001];
ll p1=1e9-63,p2=1e9+9,mod1=131071,mod2=100005;

bool _chk(int q,int len){
	if(len==0) return true;
	
	int a,b,c,d;
	
	a=h1[n-len];
	b=(h1[q-len]-h1[q]*base1[len])%mod1;
	b+=mod1;b%=mod1;
	
	c=h2[n-len];
	d=(h2[q-len]-h2[q]*base2[len])%mod2;
	d+=mod2;d%=mod2;
	
	return a==b&&c==d;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>s;
	
	n=s.size();
	for(int i=n-1;i>=0;i--){
		h1[i]=(s[i]+h1[i+1]*p1)%mod1;
		h2[i]=(s[i]+h2[i+1]*p2)%mod2;
	}
	base1[0]=base2[0]=1;
	base1[1]=p1;base2[1]=p2;
	for(int i=2;i<=n;i++){
		base1[i]=base1[i-1]*p1%mod1;
		base2[i]=base2[i-1]*p2%mod2;
	}
	
	cin>>m;
	for(int i=0,q;i<m;i++){
		cin>>q;
		
		int l=0,r=q,mid;
		while(l<=r){
			mid=(l+r)/2;
			
			bool chk=_chk(q,mid);
			bool chk2=_chk(q,mid+1);
			
			if(chk&&!chk2) break;
			
			if(!chk) r=mid-1;
			else l=mid+1;
		}
		
		cout<<mid<<'\n';
	}
}

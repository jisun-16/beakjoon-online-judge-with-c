#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

#define x first
#define y second

using namespace std;

const int N=200001,mod=1e9+7;

int n;
long long fen[400100],ans;
pair<int,int> p[200000];

long long _sum(int i){
	long long ret=0;
	while(i){
		ret+=fen[i];
		ret%=mod;
		i-=i&-i;
	}
	return ret;
}

void _update(int i, long long d){
	while(i<=400001){
		fen[i]+=d;
		i+=i&-i;
	}
}

bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y; 
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].x>>p[i].y;
		_update(p[i].x+N,1);
	}
	
	sort(p,p+n,cmp);
	
	int l=987654321;
	for(int i=0;i<n;i++){
		if(l!=p[i].y){
			l=p[i].y;
			for(int j=i;p[j].y==l;j++){
				_update(p[j].x+N,-1);
				if(j==n-1) break;
			}
		}
		
		int now=p[i].x+N;
		long long ll=_sum(now-1)%mod;
		long long rr=(_sum(400001)-_sum(now))%mod;
		ans+=(ll*rr)%mod;
		ans%=mod;
	}
	
	cout<<ans<<'\n';
}

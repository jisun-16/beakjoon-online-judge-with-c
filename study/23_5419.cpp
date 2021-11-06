#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

#define pii pair<int,int>
#define x first
#define y second

using namespace std;

int t,n,seg[300000],b[75000];
pii p[75001];

bool cmp(pii a, pii b){
	if(a.x==b.x) return a.y>b.y;
	return a.x<b.x;
}

int _update(int pos,int num,int idx,int x,int y){
	if(y<pos||pos<x) return seg[idx];
	if(x==y) return seg[idx]=num;
	int mid=(x+y)/2;
	return seg[idx]=_update(pos,num,idx*2,x,mid)+_update(pos,num,idx*2+1,mid+1,y);
}

int _sum(int l,int r,int idx,int x,int y){
	if(y<l||r<x) return 0;
	if(l<=x&&y<=r) return seg[idx];
	int mid=(x+y)/2;
	return _sum(l,r,idx*2,x,mid)+_sum(l,r,idx*2+1,mid+1,y);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		memset(seg,0,sizeof(seg));
		memset(b,0,sizeof(b));
		
		cin>>n;
		vector<int> v;
		for(int i=1;i<=n;i++){
			cin>>p[i].x>>p[i].y;
			v.push_back(p[i].y);
		}
		
		sort(p+1,p+n+1,cmp);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		
		long long ans=0;
		for(int i=1;i<=n;i++){
			int temp=lower_bound(v.begin(),v.end(),p[i].y)-v.begin();
			ans+=(long long)_sum(temp,n-1,1,0,n-1);
			b[temp]++;
			_update(temp,b[temp],1,0,n-1);
		}
		
		cout<<ans<<'\n';
	}
}

#include<iostream>
#include<algorithm>
using namespace std;
int n,m,p[500001],ans=1e7;
int f(int x){
	if(p[x]<0) return x;
	return p[x]=f(p[x]);
}
int u(int x,int y){
	x=f(x),y=f(y);
	if(x==y) return 0;
	if(p[x]>p[y]) swap(x,y);
	p[x]+=p[y];
	p[y]=x;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;++i) p[i]=-1;
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		int temp=u(x,y);
		if(!temp){
			cout<<i<<'\n';
			return 0;
		}
	}
	cout<<0<<'\n';	
}

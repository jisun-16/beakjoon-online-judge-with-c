#include<iostream>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
int n,chk,ans,p[100001],r[100001];
pii x[100001],y[100001],z[100001];
vector<pair<int,pair<int,int> > > edge;
int find(int u){
	if(u==p[u]) return u;
	return p[u]=find(p[u]);
}
bool merge(int a,int b){
	a=find(a);b=find(b);
	if(r[a]<r[b]) swap(a,b);
	if(p[a]==p[b]) return false;
	p[b]=a;
	if(r[a]==r[b]) ++r[a];
	return true;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		int a,b,c;
		cin>>a>>b>>c;
		x[i]={a,i};
		y[i]={b,i};
		z[i]={c,i};
		p[i]=i;
	}
	sort(x,x+n);
	sort(y,y+n);
	sort(z,z+n);
	for(int i=0;i<n-1;++i){
		edge.push_back({x[i+1].f-x[i].f,{x[i+1].s,x[i].s}});
		edge.push_back({y[i+1].f-y[i].f,{y[i+1].s,y[i].s}});
		edge.push_back({z[i+1].f-z[i].f,{z[i+1].s,z[i].s}});
	}
	sort(edge.begin(),edge.end());
	//MST
	for(int i=0;chk==n||i<edge.size();++i){
		if(merge(edge[i].s.f,edge[i].s.s)){
			ans+=edge[i].f;
			chk++;
		}
	}
	cout<<ans<<'\n';
}

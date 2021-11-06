/*https://bowbowbow.tistory.com/3 Âü°í*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int V,E,r,ord[10001],idx,ans;
bool cutv[10001];
vector<int> adj[10001];
int dfs(int u){
	ord[u]=++idx;
	int ret=ord[u],cnt=0;
	for(int i=0;i<adj[u].size();++i){
		int v=adj[u][i];
		if(!ord[v]){
			++cnt;
			int temp=dfs(v);
			if(u!=r&&temp>=ord[u]) cutv[u]=true;
			ret=min(ret,temp);
		}
		else
			ret=min(ret,ord[v]);
	}
	if(r==u)
		cutv[u]=cnt>=2;
	return ret;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>V>>E;
	while(E--){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1;i<=V;++i)
		if(!ord[i]) r=i,dfs(i);
	for(int i=1;i<=V;++i)
		if(cutv[i]) ++ans;
	cout<<ans<<'\n';
	for(int i=1;i<=V;++i)
		if(cutv[i]) cout<<i<<' ';
}

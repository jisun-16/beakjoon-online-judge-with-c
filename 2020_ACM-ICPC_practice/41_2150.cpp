//kosaraju algorithm
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int v,e,s[10001],pos;
bool visited[10001],chk[10001];
vector<int> adj[10001],rev[10001];
vector<vector<int> > ans; 
void dfs(int u){
	visited[u]=true;
	for(int i=0;i<adj[u].size();++i){
		int v=adj[u][i];
		if(!visited[v]) dfs(v);
	}
	s[pos++]=u;
}
void scc(int u){
	chk[u]=true;
	ans[ans.size()-1].push_back(u);
	for(int i=0;i<rev[u].size();++i){
		int v=rev[u][i];
		if(!chk[v]) scc(v);
	}
}
bool cmp(vector<int> a,vector<int> b){
	return a[0]<b[0];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>v>>e;
	for(int a,b,i=0;i<e;++i){
		cin>>a>>b;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	for(int i=1;i<=v;++i)
		if(!visited[i]) dfs(i);
	while(pos){
		int u=s[--pos];
		if(chk[u]) continue;
		ans.push_back(vector<int>());
		scc(u);
	}
	for(int i=0;i<ans.size();++i)
		sort(ans[i].begin(),ans[i].end());
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();++i){
		for(int j=0;j<ans[i].size();++j) cout<<ans[i][j]<<" ";
		cout<<-1<<'\n';
	}
}

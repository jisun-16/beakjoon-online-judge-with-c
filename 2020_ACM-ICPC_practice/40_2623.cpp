#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,ind[1001];
vector<int> adj[1001],ans;
void dfs(int now){
	ind[now]=-1;
	ans.push_back(now);
	for(int i=0;i<adj[now].size();++i)
		if(!(--ind[adj[now][i]])) dfs(adj[now][i]);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int temp,x,y;
		cin>>temp;
		cin>>x;
		for(int j=1;j<temp;++j){
			cin>>y;
			adj[x].push_back(y);
			ind[y]++;
			x=y;
		}
	}
	for(int i=1;i<=n;++i){
		if(!ind[i]) dfs(i);//위상정렬 		
	}
	if(ans.size()<n) cout<<0<<'\n';
	else {
		for(int i=0;i<n;++i) 
			cout<<ans[i]<<'\n';
	}
}

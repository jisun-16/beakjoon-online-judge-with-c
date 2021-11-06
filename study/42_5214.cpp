#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,k,m,cnt[101001];
queue<int> q;
vector<int> adj[101001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>m;
	for(int i=n+1;i<=n+m;++i)
		for(int temp,j=0;j<k;++j){
			cin>>temp;
			adj[i].push_back(temp);
			adj[temp].push_back(i);
		}
	cnt[1]=1;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<adj[u].size();++i){
			int v=adj[u][i];
			if(!cnt[v]){
				cnt[v]=cnt[u]+1;
				q.push(v);
			}
		}
	}
	if(cnt[n]) cout<<cnt[n]/2+1<<'\n';
	else cout<<-1<<'\n';
}

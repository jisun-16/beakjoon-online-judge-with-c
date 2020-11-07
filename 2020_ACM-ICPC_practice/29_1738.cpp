#include<cstdio>
#include<vector>
#include<queue>
#include<stack>

#define pii pair<int,int>
#define inf 987654321

using namespace std;

int n,m,dist[101],visited[101],tr[101],cycle;
vector<pii> adj[101];
vector<int> rev[101];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		adj[u].push_back({v,-w});
		rev[v].push_back(u);
	}
	
	queue<int> q;
	q.push(n);
	visited[n]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<rev[u].size();i++){
			int v=rev[u][i];
			if(!visited[v]){
				visited[v]=true;
				q.push(v);
			}
		}
	}
	
	for(int i=1;i<=n;i++)
		dist[i]=inf;
		
	dist[1]=0;
	for(int i=1;i<=n;i++)
		for(int u=1;u<=n;u++)
			for(int j=0;j<adj[u].size();j++){
				int v=adj[u][j].first,w=adj[u][j].second;
				if(dist[u]!=inf&&dist[v]>dist[u]+w){
					dist[v]=dist[u]+w;
					tr[v]=u;
					if(i==n&&visited[v]) cycle=1;
				}
			}
	
	if(cycle) printf("-1\n");
	else{
		stack<int> ans;
		int idx=n;
		while(idx){
			ans.push(idx);
			idx=tr[idx];
		}
		while(!ans.empty()){
			printf("%d ",ans.top());
			ans.pop();
		}
	}
}

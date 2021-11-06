#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

#define pii pair<int,int>
#define inf 987654321

using namespace std;

int n,s,e,m,cost[100],dist[100],chk[100];
vector<pii> adj[100];

int main(){
	scanf("%d %d %d %d",&n,&s,&e,&m);
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		adj[a].push_back({b,c});
	}
	for(int i=0;i<n;i++) {
		scanf("%d",&cost[i]);
		dist[i]=-inf;
	}
	
	dist[s]=cost[s];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<adj[j].size();k++){
				int next=adj[j][k].first,d=adj[j][k].second;
				if(dist[j]!=-inf&&dist[next]<dist[j]-d+cost[next]){
					dist[next]=dist[j]-d+cost[next];
					if(i==n-1)
						chk[j]=true;
				}
			}
	
	bool cycle=false,visited[100]={0,};
	queue<int> q;
	for(int i=0;i<n;i++)
		if(chk[i]){
			visited[i]=true;
			q.push(i);
		}
	
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(u==e){
			cycle=true;
			break;
		}
		
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i].first;
			if(!visited[v]){
				visited[v]=true;
				q.push(v);
			}
		}
	}
	
	if(dist[e]==-inf) printf("gg\n");
	else if(cycle) printf("Gee\n");
	else printf("%d\n",dist[e]);
}

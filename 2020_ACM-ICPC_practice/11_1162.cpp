#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n,m,k;
long long dist[10001][21],inf=1e18;
vector<pair<int,int> > map[10001];

void _dijkstra(){
	for(int i=0;i<10001;i++)
		for(int j=0;j<21;j++) dist[i][j]=inf;
	
	priority_queue<pair<long long,pair<int,int> >,vector<pair<long long,pair<int,int> > >,greater<pair<long long,pair<int,int> > > > pq;
	pq.push({0,{1,0}});//dist,node,포장된 도로 수 
	dist[1][0]=0;
	while(!pq.empty()){
		long long d=pq.top().first;
		int u=pq.top().second.first,kk=pq.top().second.second;
		pq.pop();
		
		if(d!=dist[u][kk]) continue;
		
		for(int i=0;i<map[u].size();i++){
			int v=map[u][i].first;
			long long nd=map[u][i].second;
			
			if(dist[v][kk]>d+nd){
				dist[v][kk]=d+nd;
				pq.push({dist[v][kk],{v,kk}});
			}
			if(kk<k){
				if(dist[v][kk+1]>d){
					dist[v][kk+1]=d;
					pq.push({d,{v,kk+1}});
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		map[a].push_back({b,c});
		map[b].push_back({a,c});
	}
	
	_dijkstra();
	
	long long ans=inf;
	for(int i=0;i<=k;i++) ans=min(ans,dist[n][i]);
	
	cout<<ans<<'\n';
}

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n,m,k;
vector<pair<int,int> > map[1001];
priority_queue<int> dist[1001];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		map[a].push_back({b,c});
	}
	
	dist[1].push(0);
	priority_queue<pair<int,int> > pq;
	pq.push({0,1});
	while(!pq.empty()){
		int d=-pq.top().first;
		int u=pq.top().second;
		pq.pop();
		
		for(int i=0;i<map[u].size();i++){
			int v=map[u][i].first,w=map[u][i].second;
			if(dist[v].size()<k||dist[v].top()>d+w){
				if(dist[v].size()==k) dist[v].pop();
				dist[v].push(d+w);
				pq.push({-(d+w),v});
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		if(dist[i].size()<k) cout<<-1<<'\n';
		else cout<<dist[i].top()<<'\n';
	}
}

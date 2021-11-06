#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int N,M,D,E;
long long dist[2][100001],ans=-1e15;
vector<int> h;
vector<pair<int,int> > adj[100001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M>>D>>E;
	for(int i=0;i<N;++i){
		int temp;
		cin>>temp;
		h.push_back(temp);
		dist[0][i]=-1;
		dist[1][i]=-1;
	}
	for(int i=0;i<M;++i){
		int a,b,c;
		cin>>a>>b>>c;
		--a;--b;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	priority_queue<pair<long long,int> > pq;
	pq.push({0,0});
	dist[0][0]=0;
	while(!pq.empty()){
		long long cost=-pq.top().first;
		int now=pq.top().second;
		pq.pop();
		if(dist[0][now]<cost) continue;
		for(int i=0;i<adj[now].size();++i){
			int next=adj[now][i].first,ncost=adj[now][i].second;
			if(h[now]<h[next]){
				if(dist[0][next]==-1||dist[0][next]>cost+ncost){
					dist[0][next]=cost+ncost;
					pq.push({-(cost+ncost),next});
				}
			}			
		}
	}
	pq.push({0,N-1});
	dist[1][N-1]=0;
	while(!pq.empty()){
		long long cost=-pq.top().first;
		int now=pq.top().second;
		pq.pop();
		if(dist[1][now]<cost) continue;
		for(int i=0;i<adj[now].size();++i){
			int next=adj[now][i].first,ncost=adj[now][i].second;
			if(h[now]<h[next]){
				if(dist[1][next]==-1||dist[1][next]>cost+ncost){
					dist[1][next]=cost+ncost;
					pq.push({-(cost+ncost),next});
				}
			}			
		}
	}
	for(int i=0;i<N;++i){
		if(dist[0][i]==-1||dist[1][i]==-1)
			continue;
		ans=max(ans,h[i]*E-(dist[0][i]+dist[1][i])*D);
	}
	if(ans==-1e15) cout<<"Impossible\n";
	else cout<<ans<<'\n';
}

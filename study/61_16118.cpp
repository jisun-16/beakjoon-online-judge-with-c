#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int N,M,ans;
long long fd[4001],wd[2][4001];
vector<pair<int,long long> > adj[4001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	while(M--){
		int a,b,c;
		cin>>a>>b>>c;
		--a,--b;
		c*=2;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	for(int i=0;i<N;++i)
		fd[i]=wd[0][i]=wd[1][i]=-1;
	priority_queue<pair<long long,int> > pq;
	pq.push({0,0});
	fd[0]=0;
	while(!pq.empty()){
		long long cost=-pq.top().first;
		int now=pq.top().second;
		pq.pop();
		if(fd[now]<cost) continue;
		for(int i=0;i<adj[now].size();++i){
			int next=adj[now][i].first;
			long long ncost=adj[now][i].second;
			if(fd[next]==-1||fd[next]>cost+ncost){
				fd[next]=cost+ncost;
				pq.push({-(cost+ncost),next});
			}
		}
	}
	priority_queue<pair<long long,pair<int,bool> > > pq2;
	pq2.push({0,{0,true}});
	wd[0][0]=0;
	while(!pq2.empty()){
		long long cost=-pq2.top().first;
		int now=pq2.top().second.first;
		bool ff=pq2.top().second.second;
		pq2.pop();
		if(wd[!ff][now]<cost) continue;
		for(int i=0;i<adj[now].size();++i){
			int next=adj[now][i].first;
			long long ncost=adj[now][i].second;
			if(ff) ncost/=2;
			else ncost*=2;
			if(wd[ff][next]==-1||wd[ff][next]>cost+ncost){
				wd[ff][next]=cost+ncost;
				pq2.push({-(cost+ncost),{next,!ff}});
			}
		}
	}
	for(int i=0;i<N;++i)
		if((fd[i]!=-1&&wd[0][i]!=-1&&fd[i]<wd[0][i])&&(fd[i]!=-1&&wd[1][i]!=-1&&fd[i]<wd[1][i]))
			++ans;
	cout<<ans<<'\n';
}

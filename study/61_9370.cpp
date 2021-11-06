#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int T;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		int n,m,t,s,g,h,dist[2001][2],cand[101];
		vector<pair<int,int>> v[2001];

		cin>>n>>m>>t;
		cin>>s>>g>>h;
		for(int i=0;i<m;++i){
			int a,b,d;
			cin>>a>>b>>d;
			v[a].push_back({b,d});
			v[b].push_back({a,d});
		}
		for(int i=0;i<t;++i)
			cin>>cand[i];
					
		for(int i=1;i<=n;++i)
			dist[i][0]=dist[i][1]=-1;
		sort(cand,cand+t);
		
		priority_queue<pair<int,int>> pq;
		pq.push({0,s});
		while(!pq.empty()){
			int cost=-pq.top().first,now=pq.top().second;
			pq.pop();
			if(dist[now][0]!=-1) continue;
			dist[now][0]=cost;
			for(int i=0;i<v[now].size();++i){
				if(dist[v[now][i].first][0]!=-1) continue;
				pq.push({-(v[now][i].second+cost),v[now][i].first});
			}
		}
		
		g=dist[g][0]>dist[h][0]?g:h;
		pq.push({0,g});
		while(!pq.empty()){
			int cost=-pq.top().first,now=pq.top().second;
			pq.pop();
			if(dist[now][1]!=-1) continue;
			dist[now][1]=cost;
			for(int i=0;i<v[now].size();++i){
				if(dist[v[now][i].first][1]!=-1) continue;
				pq.push({-(v[now][i].second+cost),v[now][i].first});
			}
		}
		
		for(int i=0;i<t;++i)
			if(dist[cand[i]][0]==dist[g][0]+dist[cand[i]][1])
				cout<<cand[i]<<" ";
		cout<<'\n';
	}
}

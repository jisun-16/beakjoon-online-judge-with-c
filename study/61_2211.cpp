#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n,m,dist[1001],pp[1001];
vector<pair<int,int>> v[1001],ans;
priority_queue<pair<int,int>> pq;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<=n;++i)
		dist[i]=987654321;
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	dist[1]=0;
	pq.push({-dist[1],1});
	while(!pq.empty()){
		int now=pq.top().second,cost=-pq.top().first;
		pq.pop();
		for(int i=0;i<v[now].size();++i){
			int next=v[now][i].first,ncost=v[now][i].second;
			if(dist[next]>cost+ncost){
				dist[next]=cost+ncost;
				pq.push({-(cost+ncost),next});
				pp[next]=now;
			}
		}
	}
	cout<<n-1<<'\n';
	for(int i=2;i<=n;++i)
		cout<<pp[i]<<" "<<i<<'\n';
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,ind[101],cnt[101][101];
vector<pair<int,int> > v[101];
queue<int> q;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int a,b,c;
		cin>>a>>b>>c;
		++ind[a];
		v[b].push_back({a,c});
	}
	for(int i=1;i<=n;++i){
		if(ind[i]==0){
			q.push(i);
			cnt[i][i]=1;
		}
	}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<v[now].size();++i){
			int a=v[now][i].first,b=v[now][i].second;
			for(int j=1;j<=n;++j)
				cnt[a][j]+=b*cnt[now][j];
			ind[a]--;
			if(ind[a]==0)
				q.push(a);
		}
	}
	for(int i=1;i<=n;++i)
		if(cnt[n][i]>0) cout<<i<<" "<<cnt[n][i]<<'\n';
}

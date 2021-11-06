#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n,m,ind[32001];
vector<int> v[32001];
priority_queue<int> q;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		ind[b]++;
		v[a].push_back(b);
	}
	for(int i=1;i<=n;++i)
		if(ind[i]==0) q.push(-i);
	while(!q.empty()){
		int x=q.top();
		q.pop();x*=-1;
		cout<<x<<' ';
		for(int i=0;i<v[x].size();++i){
			int y=v[x][i];
			--ind[y];
			if(ind[y]==0) q.push(-y);
		}
	}
}

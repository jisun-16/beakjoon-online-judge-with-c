#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n,m,c;
int s[100001],ind[100001];
bool chk[100001];
vector<pair<int,int>> adj[100001];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=0;i<c;i++){
		int a,b,x;
		cin>>a>>b>>x;
		
		adj[a].push_back({b,x});
		ind[b]++;
	}
	
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(ind[i]==0) q.push(i);
		
	for(int i=1;i<=n;i++){
		int x=q.front();
		q.pop();
		
		for(int j=0;j<adj[x].size();j++){
			pair<int,int> y=adj[x][j];
			ind[y.first]--;
			s[y.first]=max(s[y.first],s[x]+y.second);
			if(ind[y.first]==0)
				q.push(y.first);
		}
	}
	
	for(int i=1;i<=n;i++) cout<<s[i]<<'\n';
	
	return 0;
}

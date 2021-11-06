#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int t,n,r[501],m,ind[501];
bool adj[501][501];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		for(int i=0;i<=500;i++){
			for(int j=0;j<=500;j++)
				adj[i][j]=false;
			r[i]=ind[i]=0;
		}
		
		cin>>n;
		
		for(int i=0;i<n;i++) cin>>r[i];
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				adj[r[i]][r[j]]=true;
				ind[r[j]]++;
			}
		}
		
		cin>>m;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			if(!adj[a][b]){
				swap(a,b);
			}
			ind[a]++;ind[b]--;
			adj[a][b]=false;
			adj[b][a]=true;
		}
		
		vector<int> ans;
		queue<int> q;
		for(int i=1;i<=n;i++)
			if(ind[i]==0) q.push(i);
		for(int i=0;i<n;i++){
			if(q.empty()){
				ans=vector<int>();
				break;
			}
			
			int x=q.front();
			q.pop();
			
			ans.push_back(x);
			for(int y=1;y<=n;y++)
				if(adj[x][y]){
					adj[x][y]=false;
					ind[y]--;
					if(ind[y]==0) q.push(y);
				}
		}
		
		if(ans.size()){
			for(int i=0;i<ans.size();i++)
				cout<<ans[i]<<' ';
		}
		else cout<<"IMPOSSIBLE";
		
		cout<<'\n';
	}
}

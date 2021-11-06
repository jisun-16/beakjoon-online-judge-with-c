#include<iostream>
#include<stack>
#include<vector>
#include<queue>

using namespace std;

int t,n;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<1<<'\n';
			continue;
		}
		
		queue<int> q;
		vector<pair<int,int> > visited(n,{-1,-1});
		q.push(1);
		visited[1]={1,-1};
		while(!q.empty()){
			int now=q.front();
			q.pop();
			
			int x0=(now*10+0)%n;
			int x1=(now*10+1)%n;
			if(visited[x0].first==-1){
				visited[x0]={0,now};
				q.push(x0);
			}
			if(visited[x1].first==-1){
				visited[x1]={1,now};
				q.push(x1);
			}
			
			if(x0==0||x1==0) break;
		}
		
		stack<int> ans;
		for(int i=0;i!=-1;i=visited[i].second)
			ans.push(visited[i].first);
		
		if(ans.size()>100){
			cout<<"BRAK"<<'\n';
			continue;
		}
		
		while(!ans.empty()){
			cout<<ans.top();
			ans.pop();
		}
		cout<<'\n';
	}
}

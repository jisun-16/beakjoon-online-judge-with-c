#include<iostream>
#include<queue>

using namespace std;

int s;
bool visit[2001][2001];

int main(){
	cin>>s;
	
	queue<pair<int,int> > q;
	int clip=0, ans=0;
	q.push({1,0});
	
	while(!q.empty()){
		int temp=q.size();
		while(temp--){
			int x=q.front().first, y=q.front().second;
			q.pop();
			
			if(visit[x][y]) continue;
			visit[x][y]=true;
			
			if(x==s){
				cout<<ans<<'\n';
				return 0;
			}
			
			q.push({x,x});
			if(y&&x+y<2000) q.push({x+y,y});
			if(x>0) q.push({x-1,y});
		}
		ans++;
	}
}

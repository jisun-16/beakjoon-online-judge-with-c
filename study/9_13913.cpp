#include<iostream>
#include<queue>
#include<cstring>
#include<stack>

using namespace std;

int n, k, time;
int visited[200001];

int main(){
	memset(visited,-1,sizeof(visited));
	
	cin>>n>>k;
	
	queue<int> q;
	q.push(n);
	visited[n]=true;
	while(!q.empty()){
		int temp=q.size();
		while(temp--){
			int now=q.front();
			q.pop();
			
			if(now==k){
				cout<<time<<'\n';
				
				stack<int> ans;
				int tt=k;
				while(tt!=n){
					ans.push(tt);
					tt=visited[tt];
				}
				ans.push(n);
				
				while(!ans.empty()){
					cout<<ans.top()<<' ';
					ans.pop();
				}
				
				return 0;
			}
			
			if(now-1>=0&&visited[now-1]==-1){
				visited[now-1]=now;
				q.push(now-1);
			}
			if(now+1<=200000&&visited[now+1]==-1){
				visited[now+1]=now;
				q.push(now+1);
			}
			if(now*2<=200000&&visited[now*2]==-1){
				visited[now*2]=now;
				q.push(now*2);
			}
		}
		time++;
	}
}

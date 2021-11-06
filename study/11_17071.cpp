#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int n,k,ans;
int visited[500001][2]; 

bool avail(int x){ return (x>=0)&&(x<=500000); }

int main(){
	cin>>n>>k;
	
	if(n==k) {
		cout<<0<<'\n';
		return 0;
	}
	
	memset(visited,-1,sizeof(visited));
	
	queue<int> q;
	q.push(n);
	visited[n][0]=0;
	int time=1;
	while(!q.empty()){
		int temp=q.size();
		while(temp--){
			int u=q.front();
			q.pop();
			
			if(avail(u-1)&&visited[u-1][time%2]==-1){
				q.push(u-1);
				visited[u-1][time%2]=time;
			}
			if(avail(u+1)&&visited[u+1][time%2]==-1){
				q.push(u+1);
				visited[u+1][time%2]=time;
			}
			if(avail(u*2)&&visited[u*2][time%2]==-1){
				q.push(u*2);
				visited[u*2][time%2]=time;
			}
			
		}
		time++;
	}
	
	int sis=0;
	ans=500000;
	for(;k<=500000;k+=++sis){
		if(sis>=visited[k][sis%2]&&ans>sis)
			ans=sis;
	}
	
	if(ans!=500000) cout<<ans<<'\n';
	else cout<<-1<<'\n';
}

#include<iostream>
#include<queue>
#include<cstring>

#define inf 987654321

using namespace std;

int n, k;
int visit[200001];

int main(){
	
	for(int i=0;i<=200000;i++) visit[i]=inf;
	
	cin>>n>>k;
	
	queue<int> q;
	q.push(n);
	visit[n]=0;
	
	while(!q.empty()){
		int temp=q.size();
		while(temp--){
			int x=q.front();
			q.pop();
			
			if(x==k){
				cout<<visit[k]<<'\n';
				return 0;
			}
			
			if(x+1<=200000&&visit[x]+1<visit[x+1]){
				q.push(x+1);
				visit[x+1]=visit[x]+1;
			}
			if(x-1>=0&&visit[x]+1<visit[x-1]){
				q.push(x-1);
				visit[x-1]=visit[x]+1;
			}
			if(x*2<=200000&&visit[x]<visit[2*x]){
				q.push(2*x);
				visit[2*x]=visit[x];
			}
		}
	}
}

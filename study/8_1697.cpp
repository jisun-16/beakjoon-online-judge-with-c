#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n, k, ans;
bool visit[200001];

int main(){
	cin>>n>>k;
	
	if(n==k){
		cout<<0<<'\n';
		return 0;
	}
	
	queue<int> q;
	q.push(n);
	visit[n]=true;
	
	while(!q.empty()){
		int temp=q.size();
		while(temp--){
			int x=q.front();
			q.pop();
			
			if(x==k){
				cout<<ans<<'\n';
				return 0;
			}
			
			if(x+1<=200000&&!visit[x+1]) {
				q.push(x+1);
				visit[x+1]=true;
			}
			if(x-1>=0&&!visit[x-1]){
				q.push(x-1);
				visit[x-1]=true;
			}
			if(x*2<=200000&&!visit[2*x]) {
				q.push(2*x);
				visit[2*x]=true;
			}
		}
		ans++;
	}
}

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,arr[100001],cnt;
bool visited[100001],chk[100001];
void dfs(int u){
	visited[u]=true;
	int v=arr[u];
	if(!visited[v]) dfs(v);
	else if(!chk[v]){
		for(int i=v;i!=u;i=arr[i]) ++cnt;
		++cnt;
	}
	chk[u]=true;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		memset(visited,false,sizeof(visited));
		memset(chk,false,sizeof(chk));
		cnt=0;
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>arr[i];
		for(int i=1;i<=n;++i){
			if(!visited[i])
				dfs(i);
		}
		cout<<n-cnt<<'\n';
	}
}

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

int n,k,dist[1002][1002];
pair<int,int> gas[1002];
bool visited[1001];

bool _dfs(int now,int cnt,int f){
	if(dist[now][n+1]<=f) return true;
	if(cnt>k) return false;
	
	visited[now]=true;
	
	for(int i=1;i<=n;i++){
		if(visited[i]) continue;
		if(dist[now][i]>f) continue;
		
		if(_dfs(i,cnt+1,f)) return true;
	}
	
	return false;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>k;
	gas[0]={0,0};
	for(int i=1;i<=n;i++) cin>>gas[i].first>>gas[i].second;
	gas[n+1]={10000,10000};
	
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			if(i==j) dist[i][j]=1e9;
			else{
				dist[i][j]=pow(gas[i].first-gas[j].first,2)+pow(gas[i].second-gas[j].second,2);
			}
	
	int s=0,e=1000;
	while(s<e){
		memset(visited,false,sizeof(visited));
		int mid=(s+e)/2;
		
		bool chk=_dfs(0,0,mid*mid*100);
		
		if(!chk) s=mid+1;
		else e=mid;
	}
	
	cout<<e<<'\n';
}

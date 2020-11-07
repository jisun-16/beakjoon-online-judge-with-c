#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int n,m,k,l[2001],r[2001],dp[2001][2001];
vector<int> adj[2001];

int solve(int a,int b){
	int &ret=dp[a][b];
	
	if(ret!=-1) return ret;
	if(a==n||b==m) return ret=0;
	
	ret=solve(a+1,b);
	vector<int>::iterator iter=lower_bound(adj[a].begin(),adj[a].end(),b);
	if(iter!=adj[a].end())
		ret=max(solve(a+1,(*iter)+1)+1,ret);
	return ret;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int idx=0;
		scanf("%d",&idx);
		l[idx]=i;
	}
	for(int i=0;i<m;i++){
		int idx;
		scanf("%d",&idx);
		r[idx]=i;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[l[a]].push_back(r[b]);
	}
	
	for(int i=0;i<n;i++)
		sort(adj[i].begin(),adj[i].end());
		
	memset(dp,-1,sizeof(dp));
	int ans=k-solve(0,0);
	
	printf("%d\n",ans);
}

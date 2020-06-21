#include<iostream>
#include<algorithm>
#include<cstring>
#define inf 1000000000

using namespace std;

int n, m, arr[1001][1001], dp[1001][1001][3];
bool visited[1001][1001];
//dp-up,left,right에서 오는 것 따로 계산 

int _solve(int x, int y, int d){
	if(x<=0||x>n||y<=0||y>m||visited[x][y]) return -inf;

	if(x==n&&y==m) return arr[n][m];
	
	int& ret=dp[x][y][d];
	if(ret!=-inf) return ret;
	
	visited[x][y]=true;
	
	int down,rig,lef;
	down=_solve(x+1,y,0);
	rig=_solve(x,y+1,1);
	lef=_solve(x,y-1,2);
	ret=max(down,max(rig,lef))+arr[x][y];
	
	visited[x][y]=false;
	
	return ret;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){ 
		for(int j=1;j<=m;j++){		
			cin>>arr[i][j];
			dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=-inf;
		}
	}
	
	cout<<_solve(1,1,0)<<'\n';
}

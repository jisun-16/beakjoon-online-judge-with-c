#include<cstdio>
#include<queue>

#define x first
#define y second

using namespace std;

int n,home[17][17],ans;
pair<int,int> pipe[2];

void dfs(){
	if(pipe[1].x==n&&pipe[1].y==n){
		ans++;
		return;
	}
	
	if(pipe[0].x==pipe[1].x){
		if(pipe[1].y<n&&!home[pipe[1].x][pipe[1].y+1]){
			pipe[0].y++;pipe[1].y++;
			dfs();
			pipe[0].y--;pipe[1].y--;
		}
		if(pipe[1].x<n&&pipe[1].y<n&&!home[pipe[1].x][pipe[1].y+1]&&!home[pipe[1].x+1][pipe[1].y]&&!home[pipe[1].x+1][pipe[1].y+1]){
			pipe[0].y++;pipe[1].x++;pipe[1].y++;
			dfs();
			pipe[0].y--;pipe[1].x--;pipe[1].y--;
		}
	}
	else if(pipe[0].y==pipe[1].y){
		if(pipe[1].x<n&&!home[pipe[1].x+1][pipe[1].y]){
			pipe[0].x++;pipe[1].x++;
			dfs();
			pipe[0].x--;pipe[1].x--;
		}
		if(pipe[1].x<n&&pipe[1].y<n&&!home[pipe[1].x+1][pipe[1].y]&&!home[pipe[1].x][pipe[1].y+1]&&!home[pipe[1].x+1][pipe[1].y+1]){
			pipe[0].x++;pipe[1].x++;pipe[1].y++;
			dfs();
			pipe[0].x--;pipe[1].x--;pipe[1].y--;
		}
	}
	else{
		if(pipe[1].y<n&&!home[pipe[1].x][pipe[1].y+1]){
			pipe[0].x++;pipe[0].y++;pipe[1].y++;
			dfs();
			pipe[0].x--;pipe[0].y--;pipe[1].y--;
		}
		if(pipe[1].x<n&&!home[pipe[1].x+1][pipe[1].y]){
			pipe[0].x++;pipe[0].y++;pipe[1].x++;
			dfs();
			pipe[0].x--;pipe[0].y--;pipe[1].x--;
		}
		if(pipe[1].x<n&&pipe[1].y<n&&!home[pipe[1].x][pipe[1].y]&&!home[pipe[1].x+1][pipe[1].y]&&!home[pipe[1].x][pipe[1].y+1]&&!home[pipe[1].x+1][pipe[1].y+1]){
			pipe[0].x++;pipe[0].y++;pipe[1].x++;pipe[1].y++;
			dfs();
			pipe[0].x--;pipe[0].y--;pipe[1].x--;pipe[1].y--;
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&home[i][j]);
			
	pipe[0]={1,1};
	pipe[1]={1,2};
	
	dfs();
	
	printf("%d\n",ans);
}

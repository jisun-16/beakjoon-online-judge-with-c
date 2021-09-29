#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int arr[5][5];
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
vector<int> ans;
void dfs(int x,int y,int num,int cnt){
	if(cnt==5){
		ans.push_back(num);
		return;
	}
	for(int i=0;i<4;++i){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0||nx>=5||ny<0||ny>=5) continue;
		dfs(nx,ny,num*10+arr[nx][ny],cnt+1);
	}
}
int main(){
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j) scanf("%d",&arr[i][j]);
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			dfs(i,j,arr[i][j],0);
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	printf("%d",ans.size());
}

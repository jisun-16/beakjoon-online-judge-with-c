#include<iostream>
using namespace std;
int n,m,pr,pc,ans[2];
char arr[500][500];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;++i) cin>>arr[i];
	cin>>pr>>pc;
	--pr,--pc;
	for(int i=0;i<4;++i){
		bool visited[500][500][4]={0,};
		int cnt=0,dir=i,x=pr,y=pc;
		bool inf=false;
		visited[x][y][i]=true;
		while(true){
			cnt++;
			int nx=x+dx[dir],ny=y+dy[dir];
			if(nx<0||nx>=n||ny<0||ny>=m||arr[nx][ny]=='C') break;
			if(visited[nx][ny][dir]){
				inf=true;
				break;
			}
			visited[nx][ny][dir]=true;
			if(arr[nx][ny]=='/'){
				if(dir==0) dir=1;
				else if(dir==1) dir=0;
				else if(dir==2) dir=3;
				else dir=2;
			}
			else if(arr[nx][ny]=='\\'){
				if(dir==0) dir=3;
				else if(dir==1) dir=2;
				else if(dir==2) dir=1;
				else dir=0;
			}
			x=nx,y=ny;	
		}
		if(inf){
			cout<<(i==0?'U':i==1?'R':i==2?'D':'L')<<'\n';
			cout<<"Voyager";
			return 0;
		}
		else{
			if(ans[1]<cnt){
				ans[0]=i;
				ans[1]=cnt;
			}
		}
	}
	cout<<(ans[0]==0?'U':ans[0]==1?'R':ans[0]==2?'D':'L')<<'\n';
	cout<<ans[1]<<'\n';
}

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int M,N,arr[101][101],s[3],e[3];
int dx[]={0,0,0,1,-1},dy[]={0,1,-1,0,0};
int chk[101][101][5];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>M>>N;
	for(int i=1;i<=M;++i)
		for(int j=1;j<=N;++j) cin>>arr[i][j];
	cin>>s[0]>>s[1]>>s[2];
	cin>>e[0]>>e[1]>>e[2];
	
	queue<pair<pair<int,int>,int> > q;
	int ans=0;
	
	q.push({{s[0],s[1]},s[2]});
	chk[s[0]][s[1]][s[2]]=ans;
	while(!q.empty()){
		ans++;
		int temp=q.size();
		while(temp--){
			int x=q.front().first.first,y=q.front().first.second,dir=q.front().second;
			q.pop();
			
			if(x==e[0]&&y==e[1]&&dir==e[2]){
				q=queue<pair<pair<int,int>,int> >();
				break;
			}
			
			for(int i=1;i<=3;++i){
				int nx=x+dx[dir]*i,ny=y+dy[dir]*i;
				if(nx<=0||nx>M||ny<=0||ny>N) continue;
				if(arr[nx][ny]==1) break;
				if(chk[nx][ny][dir]) continue;
				q.push({{nx,ny},dir});
				chk[nx][ny][dir]=ans;
			}
			int rdir=dir==1?3:(dir==3?2:(dir==2?4:1));
			int ldir=dir==1?4:(dir==4?2:(dir==2?3:1));
			if(!chk[x][y][rdir]){
				q.push({{x,y},rdir});
				chk[x][y][rdir]=ans;
			}
			if(!chk[x][y][ldir]){
				q.push({{x,y},ldir});
				chk[x][y][ldir]=ans;
			}
		}
	}
	
	cout<<ans-1<<'\n';
}

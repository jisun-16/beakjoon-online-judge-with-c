#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int w,h,map[101][101];
pair<int,int> dest[2];
int dx[]={0,-1,0,1},dy[]={-1,0,1,0};
bool visited[101][101];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>w>>h;
	
	int cnt=0;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++){
			char temp;
			cin>>temp;
			if(temp=='*') map[i][j]=1;
			else{
				map[i][j]=0;
				if(temp=='C'){
					dest[cnt++]={i,j};
				}
			}
		}
	
	int mirror=-1;
	queue<pair<int,int> > q;
	q.push({dest[0].first,dest[0].second});
	visited[dest[0].first][dest[0].second]=true;
	while(!q.empty()){
		int temp=q.size();
		while(temp--){
			int x=q.front().first,y=q.front().second;
			q.pop();
			
			if(x==dest[1].first&&y==dest[1].second){
				cout<<mirror<<'\n';
				return 0;
			}
			
			for(int i=0;i<4;i++){
				int k=1;
				while(true){
					int nx=x+k*dx[i],ny=y+k*dy[i];
					
					if(nx<=0||nx>h||ny<=0||ny>w) break;
					if(map[nx][ny]==1) break;
					
					if(!visited[nx][ny]){
						visited[nx][ny]=true;
						q.push({nx,ny});
					}
					
					k++;
				}
			}
		}
		mirror++;
	}
}


#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int inf=987654321;
int knx[]={-2,-2,-1,-1,1,1,2,2},kny[]={-1,1,-2,2,-2,2,-1,1},bx[]={-1,-1,1,1},by[]={-1,1,-1,1},rx[]={-1,0,1,0},ry[]={0,-1,0,1};

int n,map[11][11];
pair<int,int> dist[11][11][101][3];//knight,bishop,rook
pair<int,int> piece[3];

bool avail(int x,int y){ return x>0&&x<=n&&y>0&&y<=n; }

bool operator<(pair<int,int> a,pair<int,int> b){
	if(a.first<b.first) return true;
	else if(a.first==b.first)
		if(a.second<b.second) return true;
	return false;
}

int main(){
	for(int i=0;i<11;i++)
		for(int j=0;j<11;j++)
			for(int k=0;k<101;k++)
				for(int l=0;l<3;l++)
					dist[i][j][k][l]={-1,-1};
	
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>map[i][j];
			if(map[i][j]==1){
				piece[0]=piece[1]=piece[2]={i,j};
			}
		}
	}
	
	queue<pair<pair<int,int>,pair<int,int> > > q;
	//piece.x,piece.y,check_number,piece_number
	for(int i=0;i<3;i++){
		q.push({{piece[i]},{1,i}});
		dist[piece[i].first][piece[i].second][1][i]={0,0};
	}
	
	pair<int,int> ans;
	ans.first=ans.second=inf;
	while(!q.empty()){
		int x=q.front().first.first;
		int y=q.front().first.second;
		int chk=q.front().second.first;
		int p=q.front().second.second;
		q.pop();
		
		if(chk==n*n){
			if(ans.first>dist[x][y][chk][p].first) ans=dist[x][y][chk][p];
			else if(ans.first==dist[x][y][chk][p].first&&ans.second>dist[x][y][chk][p].second) ans=dist[x][y][chk][p];
		}
		
		
		//knight
		if(p==0){
			for(int i=0;i<8;i++){
				int nx=x+knx[i],ny=y+kny[i];
				
				if(!avail(nx,ny)) continue;
				
				int nchk=chk;
				if(map[nx][ny]==chk+1) nchk++;
				
				if(dist[nx][ny][nchk][0].first==-1){
					dist[nx][ny][nchk][0]={dist[x][y][chk][p].first+1,dist[x][y][chk][p].second};
					q.push({{nx,ny},{nchk,0}});
				}
			}
		}
		//bishop
		else if(p==1){
			for(int i=0;i<4;i++){
				for(int k=1;;k++){
					int nx=x+k*bx[i],ny=y+k*by[i];
					
					if(!avail(nx,ny)) break;
					
					int nchk=chk;
					if(map[nx][ny]==chk+1) nchk++;
					
					if(dist[nx][ny][nchk][1].first==-1){
						dist[nx][ny][nchk][1]={dist[x][y][chk][p].first+1,dist[x][y][chk][p].second};
						q.push({{nx,ny},{nchk,1}});
					}
				}
			}
		}
		//rook
		else{
			for(int i=0;i<4;i++){
				for(int k=1;;k++){
					int nx=x+k*rx[i],ny=y+k*ry[i];
					
					if(!avail(nx,ny)) break;
					
					int nchk=chk;
					if(map[nx][ny]==chk+1) nchk++;
					
					if(dist[nx][ny][nchk][2].first==-1){
						dist[nx][ny][nchk][2]={dist[x][y][chk][p].first+1,dist[x][y][chk][p].second};
						q.push({{nx,ny},{nchk,2}});
					}
				}
			}
		}
		
		//가만히 있고 말을 바꿀 때 
		for(int i=0;i<3;i++){
			if(i==p) continue;
			
			if(dist[x][y][chk][i].first==-1){
				dist[x][y][chk][i]={dist[x][y][chk][p].first+1,dist[x][y][chk][p].second+1};
				q.push({{x,y},{chk,i}});
			}
		}
	}
	
	cout<<ans.first<<' '<<ans.second<<'\n';
}

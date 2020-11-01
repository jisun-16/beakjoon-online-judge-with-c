#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n,m,map[10][10],nat[10][10],bri[7][7],idx,ans=-1;
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
int cnt=0;
pair<int,int> con[15];

bool avail(int i,int j){
	return i>=0&&i<n&&j>=0&&j<m;
}

int connected(){
	int ret=0;
	bool visited[7]={0,};
	visited[1]=true;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=1;i<idx;i++){
			if(i!=now&&bri[now][i]!=987654321&&!visited[i]){
				visited[i]=true;
				q.push(i);
				ret+=bri[now][i];
			}
		}
	}
	for(int i=1;i<idx;i++)
		if(!visited[i]) return 0;
	if(ans==-1||ans>ret) ans=ret;
	return ret;
}

void dfs(int ii){
	if(!connected())
		return;
		
	for(int i=ii;i<cnt;i++){
		int temp=bri[con[i].first][con[i].second];
		bri[con[i].first][con[i].second]=987654321;
		bri[con[i].second][con[i].first]=987654321;
		dfs(i+1);
		bri[con[i].first][con[i].second]=temp;
		bri[con[i].second][con[i].first]=temp;
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&map[i][j]);
	
	idx=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(nat[i][j]||!map[i][j]) continue;
			nat[i][j]=idx;
			queue<pair<int,int> > q;
			q.push({i,j});
			while(!q.empty()){
				int x=q.front().first,y=q.front().second;
				q.pop();
				for(int d=0;d<4;d++){
					int nx=x+dx[d],ny=y+dy[d];
					if(!avail(nx,ny)) continue;
					if(!map[nx][ny]) continue;
					if(nat[nx][ny]) continue;
					nat[nx][ny]=idx;
					q.push({nx,ny});
				}
			}
			idx++;
		}
	}
	
	for(int i=1;i<idx;i++)
		for(int j=1;j<idx;j++)
			if(i!=j) bri[i][j]=987654321;
	
	for(int i=0;i<n;i++){
		int j=0;
		while(j<m){
			if(nat[i][j]>0){
				int from=nat[i][j],jj=-1;
				while(nat[i][j]==from||!map[i][j]){
					j++;
					if(jj==-1&&!map[i][j]) jj=j;
					if(jj!=-1&&nat[i][j]==from) break;
					if(j>=m) break;
				}
				if(j<m){
					int to=nat[i][j];
					if(from==to||j-jj<=1) continue;
					else{
						bri[from][to]=min(bri[from][to],j-jj);
						bri[to][from]=min(bri[to][from],j-jj);
					}
				}
			}
			else j++;
		}
	}
	
	for(int j=0;j<m;j++){
		int i=0;
		while(i<n){
			if(nat[i][j]>0){
				int from=nat[i][j],ii=-1;
				while(nat[i][j]==from||!map[i][j]){
					i++;
					if(ii==-1&&!map[i][j]) ii=i;
					if(ii!=-1&&nat[i][j]==from) break;
					if(i>=n) break;
				}
				if(i<n){
					int to=nat[i][j];
					if(to==from||i-ii<=1) continue;
					else{
						bri[from][to]=min(bri[from][to],i-ii);
						bri[to][from]=min(bri[to][from],i-ii);
					}
				}
			}
			else i++;
		}
	}
	
	for(int i=1;i<idx;i++){
		for(int j=i+1;j<idx;j++){
			if(i!=j&&bri[i][j]!=987654321)
				con[cnt++]={i,j};
		}
	}
	
	dfs(0);
	
	printf("%d\n",ans);
}

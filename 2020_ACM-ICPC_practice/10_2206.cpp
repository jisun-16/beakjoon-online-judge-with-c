#include<iostream>
#include<queue>

using namespace std;

int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int n, m, map[1001][1001], ans[1001][1001][2];


int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	
	queue<pair<pair<int,int>, int> > q;
	q.push({ {1,1},1 });
	ans[1][1][1] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop();

		if (x == n && y == m) {
			cout<<ans[x][y][block]<<'\n';
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<=0||nx>n||ny<=0||ny>m) continue;
			
			if (map[nx][ny] == 1 && block == 1) {
				ans[nx][ny][0] = ans[x][y][1] + 1;
				q.push({{nx,ny},0 });
			}
			if (map[nx][ny] == 0 && ans[nx][ny][block] == 0) {
				ans[nx][ny][block] = ans[x][y][block] + 1;
				q.push({{nx,ny},block });
			}
		}
	}
	
	cout<<-1<<'\n';
	return 0;
}

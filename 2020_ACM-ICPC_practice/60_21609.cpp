#include<iostream>
#include<queue>
using namespace std;
int n,m,arr[20][20],ans;
int auto_play(){
	int res=0;
	//find max_area
	int mx=100,my=100,ms=0,mr=0;
	bool chk[20][20]={0,};
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			if(chk[i][j]||arr[i][j]<=0||arr[i][j]==100) continue;
			chk[i][j]=true;
			int s=0,c=arr[i][j],r=0;
			bool visited[20][20]={0,};
			queue<pair<int,int> > q;
			q.push({i,j});
			visited[i][j]=true;
			++s;
			while(!q.empty()){
				int x=q.front().first,y=q.front().second;
				q.pop();
				if(x>0&&!visited[x-1][y]&&(arr[x-1][y]==c||arr[x-1][y]==0)){
					q.push({x-1,y});
					visited[x-1][y]=true;
					chk[x-1][y]=(arr[x-1][y]!=0);
					++s;
					r+=(arr[x-1][y]==0);
				}
				if(y>0&&!visited[x][y-1]&&(arr[x][y-1]==c||arr[x][y-1]==0)){
					q.push({x,y-1});
					visited[x][y-1]=true;
					chk[x][y-1]=(arr[x][y-1]!=0);
					++s;
					r+=(arr[x][y-1]==0);
				}
				if(x<n-1&&!visited[x+1][y]&&(arr[x+1][y]==c||arr[x+1][y]==0)){
					q.push({x+1,y});
					visited[x+1][y]=true;
					chk[x+1][y]=(arr[x+1][y]!=0);
					++s;
					r+=(arr[x+1][y]==0);
				}
				if(y<n-1&&!visited[x][y+1]&&(arr[x][y+1]==c||arr[x][y+1]==0)){
					q.push({x,y+1});
					visited[x][y+1]=true;
					chk[x][y+1]=(arr[x][y+1]!=0);
					++s;
					r+=(arr[x][y+1]==0);
				}
			}
			if(s<2) continue;
			if(ms<s||(ms==s&&mr<r)||(ms==s&&mr==r&&mx<i)||(ms==s&&mr==r&&mx==i&&my<j)){
				ms=s;
				mr=r;
				mx=i;
				my=j;
			}
		}
	if(ms){
		int c=arr[mx][my];
		//remove
		queue<pair<int,int> > q;
		q.push({mx,my});
		arr[mx][my]=100;
		while(!q.empty()){
			int x=q.front().first,y=q.front().second;
			q.pop();
			if(x>0&&(arr[x-1][y]==c||arr[x-1][y]==0)){
				q.push({x-1,y});
				arr[x-1][y]=100;
			}
			if(y>0&&(arr[x][y-1]==c||arr[x][y-1]==0)){
				q.push({x,y-1});
				arr[x][y-1]=100;
			}
			if(x<n-1&&(arr[x+1][y]==c||arr[x+1][y]==0)){
				q.push({x+1,y});
				arr[x+1][y]=100;
			}
			if(y<n-1&&(arr[x][y+1]==c||arr[x][y+1]==0)){
				q.push({x,y+1});
				arr[x][y+1]=100;
			}
		}
		//gravity
		for(int i=n-2;i>=0;--i)
			for(int j=0;j<n;++j){
				if(arr[i][j]==-1||arr[i][j]==100) continue;
				int k=i;
				while(k<n-1&&arr[k+1][j]==100) k++;
				if(arr[k][j]!=100) continue;
				arr[k][j]=arr[i][j];
				arr[i][j]=100;
			}
		//turn left
		int temp[20][20]={0,};
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				temp[n-1-j][i]=arr[i][j];
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				arr[i][j]=temp[i][j];
		//gravity
		for(int i=n-2;i>=0;--i)
			for(int j=0;j<n;++j){
				if(arr[i][j]==-1||arr[i][j]==100) continue;
				int k=i;
				while(k<n-1&&arr[k+1][j]==100) ++k;
				if(arr[k][j]!=100) continue;
				arr[k][j]=arr[i][j];
				arr[i][j]=100;
			}
		return ms*ms;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>arr[i][j];
	while(true){
		int res=auto_play();
		if(res==0) break;
		else ans+=res;
	}
	cout<<ans<<'\n';
}

#include<iostream>
#include<queue>
using namespace std;
int R,C,arr[100][100],N,h;
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
void dd(){
	int idx=0,visited[100][100]={0,};
	queue<pair<int,int> > q;
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j){
			if(!arr[i][j]||visited[i][j]) continue;
			int l=j,r=j,mh=i;
			visited[i][j]=++idx;
			q.push({i,j});
			while(!q.empty()){
				int x=q.front().first,y=q.front().second;
				q.pop();
				for(int d=0;d<4;++d){
					int nx=x+dx[d],ny=y+dy[d];
					if(nx<0||nx>=R||ny<0||ny>=C) continue;
					if(!arr[nx][ny]||visited[nx][ny]) continue;
					l=ny<l?ny:l;r=ny>r?ny:r;
					mh=nx>mh?nx:mh;
					visited[nx][ny]=idx;
					q.push({nx,ny});
				}
			}
			if(mh!=R-1){
				int m=mh+1;
				bool chk=true;
				for(;m<R;++m){
					for(int n=l;n<=r;++n)
						if(arr[m][n]+arr[mh][n]>1){
							chk=false;
							break;
						}
					if(!chk) break;
				}
				int k=m-1;
				if(k==mh) return;
				for(m=k;m>0;--m){
					for(int n=l;n<=r;++n){
						if(m-k+mh<0) arr[m][n]=0;
						else{
							arr[m][n]=arr[m][n]+arr[m-k+mh][n];
							arr[m-k+mh][n]=0;
						}
					}
				}
				return;
			}
		}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>R>>C;
	for(int i=0;i<R;++i){
		string s;
		cin>>s;
		for(int j=0;j<C;++j){
			arr[i][j]=(s[j]=='.'?0:1);
		}
	}
	cin>>N;
	for(int n=0;n<N;++n){
		cin>>h;
		h=R-h;
		int j=0;
		if(n%2==0){
			while(j<C&&!arr[h][j]) ++j;
		}
		else{
			j=C-1;
			while(j>=0&&!arr[h][j]) --j;
		}
		arr[h][j]=0;
		dd();
	}
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j) cout<<(arr[i][j]?'x':'.');
		cout<<'\n';
	}
}

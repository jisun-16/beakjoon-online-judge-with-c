#include<iostream>
#include<algorithm>
using namespace std;
int dice[6],arr[21][21],u=0,f=1,l=2;
int dx[]={0,0,0,-1,1},dy[]={0,1,-1,0,0};
void mov(int dir){
	int nu,nf,nl;
	switch(dir){
		case 1:{
			nu=l,nf=f,nl=5-u;
			break;
		}
		case 2:{
			nu=5-l,nf=f,nl=u;
			break;
		}
		case 3:{
			nu=f,nl=l,nf=5-u;
			break;
		}
		case 4:{
			nu=5-f,nl=l,nf=u;
			break;
		}
	}
	u=nu;f=nf;l=nl;
}
int main(){
	int m,n,x,y,k;
	cin>>m>>n>>x>>y>>k;
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j) cin>>arr[i][j];
	while(k--){
		int d;
		cin>>d;
		int nx=x+dx[d],ny=y+dy[d];
		if(nx<0||nx>=m||ny<0||ny>=n) continue;
		x=nx;y=ny;
		mov(d);
		if(arr[x][y]){
			dice[5-u]=arr[x][y];
			arr[x][y]=0;
		}
		else{
			arr[x][y]=dice[5-u];
		}
		cout<<dice[u]<<'\n';
	}
}

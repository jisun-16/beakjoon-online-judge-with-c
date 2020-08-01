#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

const int inf=2000000000; 
int n,m,l;
int up[3000],down[3000];
int path[3000][3000];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m>>l;
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>up[cnt];
		cnt++;
	}
	cnt=0;
	for(int i=0;i<m;i++){
		cin>>down[cnt];
		cnt++;
	}
	
	cnt=0;
	for(int i=0;i<n-1;i++){
		path[i][cnt]=pow(abs(up[i]-down[cnt]),2)+l*l;
		while(abs(up[i]-down[cnt])<abs(up[i+1]-down[cnt])){
			cnt++;
			path[i][cnt]=pow(abs(up[i]-down[cnt]),2)+l*l;
		}
	}
	for(int j=cnt;j<m;j++){
		path[n-1][j]=pow(abs(up[n-1]-down[j]),2)+l*l;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cout<<path[i][j]<<' ';
		cout<<'\n';
	}
}

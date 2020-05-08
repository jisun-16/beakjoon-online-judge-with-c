#include<iostream>
#include<algorithm>

using namespace std;

int n, m, num[501][501], ans = 0;
pair<int, int> matrix[19][3]={
{{0,1},{1,0},{1,1}},
{{0,1},{0,2},{0,3}},
{{1,0},{2,0},{3,0}},
{{0,1},{0,2},{1,0}},{{0,1},{0,2},{1,2}},{{1,0},{1,1},{1,2}},{{0,1},{1,1},{1,2}},{{0,1},{0,2},{1,1}},
{{0,1},{0,2},{-1,1}},{{0,1},{-1,1},{-1,2}},{{0,1},{0,2},{-1,2}},
{{0,1},{1,0},{2,0}},{{0,1},{1,1},{2,1}},{{1,0},{2,0},{2,1}},{{1,0},{1,1},{2,1}},{{1,0},{2,0},{1,1}},
{{1,0},{2,0},{2,-1}},{{1,0},{1,-1},{2,-1}},{{1,0},{2,0},{1,-1}}};
/*
0o  0ooo  0  0oo  ooo  0o  o0
oo ,    , o, ooo, 0oo, oo, oo
		  o			   oo  oo
		  o
*/
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>num[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<19;k++){
				int sum=num[i][j];
				int d=0;
				for(d=0;d<3;d++){
					int nx=i+matrix[k][d].first, ny=j+matrix[k][d].second;
					if(nx<0||nx>=n||ny<0|ny>=m) break;
					sum+=num[nx][ny];
				}
				if(d==3&&sum>ans) ans=sum;
			}
		}
	}
	
	cout<<ans<<'\n';
}

#include<iostream>
using namespace std;
int n,m,office[8][8],cctv[8][2],dir[8],cnt,ans;
void solve(int chk_idx){
	if(chk_idx==cnt){
		bool arr[8][8]={0,};
		for(int i=0;i<cnt;++i){
			int temp=office[cctv[i][0]][cctv[i][1]];
			switch(temp){
				
			}
		}
		return;
	}
	int num=office[cctv[chk_idx][0]][cctv[chk_idx][1]];
	switch(num){
		case 1:{
			for(int i=0;i<4;++i){
				dir[chk_idx]=i;
				solve(chk_idx+1);
			}
			break;
		}
		case 2:{
			for(int i=0;i<2;++i){
				dir[chk_idx]=i;
				solve(chk_idx+1);
			}
			break;
		}
		case 3:{
			for(int i=0;i<4;++i){
				dir[chk_idx]=i;
				solve(chk_idx+1);
			}
			break;
		}
		case 4:{
			for(int i=0;i<4;++i){
				dir[chk_idx]=i;
				solve(chk_idx+1);
			}
			break;
		}
		case 5:{
			solve(chk_idx+1);
			break;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>office[i][j];
			if(office&&office!=6){
				cctv[cnt][0]=i;
				cctv[cnt++][1]=j;
			}
		}
	}
	solve(0);
	cout<<ans<<'\n';
}

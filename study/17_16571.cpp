#include<iostream>
#include<algorithm>

using namespace std;

int b[3][3],dp[20000];

int b_num(){
	int ret=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			ret*=3;
			ret+=b[i][j];
		}
	return ret;
}

bool _chk(int t){
	//가로 
	for(int i=0;i<3;i++){
		if(b[i][0]==t&&b[i][0]==b[i][1]&&b[i][1]==b[i][2])
			return true;
	}
	//세로 
	for(int i=0;i<3;i++){
		if(b[0][i]==t&&b[0][i]==b[1][i]&&b[1][i]==b[2][i])
			return true;
	}
	//대각선 
	if(b[0][0]==t&&b[0][0]==b[1][1]&&b[1][1]==b[2][2])
		return true;
	
	if(b[0][2]==t&&b[0][2]==b[1][1]&&b[1][1]==b[2][0])
		return true;
	
	return false;
}

int _solve(int t){
	if(_chk(3-t)) return -1;
	
	int &ret=dp[b_num()];
	if(ret!=-2) return ret;
	
	int m=2;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(b[i][j]==0){
				b[i][j]=t;
				m=min(m,_solve(3-t));
				b[i][j]=0;
			}
	
	return (m==2||m==0)?(ret=0):(ret=-m);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int cnt=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			cin>>b[i][j];
			if(b[i][j]) cnt++;
		}
	
	for(int i=0;i<20000;i++) dp[i]=-2;
	
	int temp=_solve(cnt%2+1);
	char ans=(temp==1)?'W':(temp==0?'D':'L');
	cout<<ans<<'\n';
}

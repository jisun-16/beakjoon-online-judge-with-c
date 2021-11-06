#include<iostream>
#include<vector>

typedef long long ll;
using namespace std;

const int mod=1000000007;
int n;
vector<vector<ll> > map,ans;

vector<vector<ll> > _mul(vector<vector<ll> > a, vector<vector<ll> > b){
	vector<vector<ll> > ret(8,vector<ll>(8));
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			for(int k=0;k<8;k++){
				ret[i][j]+=a[i][k]*b[k][j];
				ret[i][j]%=mod;
			}
	
	return ret;
}

int main(){
	cin>>n;	
	
	map=ans=vector<vector<ll> >(8,vector<ll>(8));
	map[0][1]=map[0][2]=1;
	map[1][0]=map[1][2]=map[1][4]=1;
	map[2][0]=map[2][1]=map[2][3]=map[2][4]=1;
	map[3][2]=map[3][4]=map[3][5]=map[3][6]=1;
	map[4][1]=map[4][2]=map[4][3]=map[4][6]=1;
	map[5][3]=map[5][7]=1;
	map[6][3]=map[6][4]=map[6][7]=1;
	map[7][5]=map[7][6]=1;
	/*map={
		{0,1,1,0,0,0,0,0},
		{1,0,1,0,1,0,0,0},
		{1,1,0,1,1,0,0,0},
		{0,0,1,0,1,1,1,0},
		{0,1,1,1,0,0,1,0},
		{0,0,0,1,0,0,0,1},
		{0,0,0,1,1,0,0,1},
		{0,0,0,0,0,1,1,0}
	};*/
	for(int i=0;i<8;i++) ans[i][i]=1;
	
	while(n){
		if(n%2) ans=_mul(ans,map);
		map=_mul(map,map);
		n/=2;
	}
	
	cout<<ans[0][0]<<'\n';
}

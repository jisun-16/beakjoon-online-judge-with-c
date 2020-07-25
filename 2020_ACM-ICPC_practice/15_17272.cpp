#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll> > mat;

const long long mod=1000000007;
//dp??? dp[n]=dp[n-1]+dp[n-m]
//За·Д dp
ll n; 
int m;

mat operator*(const mat& a,const mat& b){
	mat res(m,vector<ll>(m,0));
	
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			for(int k=0;k<m;k++){
				res[i][j]+=(a[i][k]*b[k][j])%mod;
				res[i][j]%=mod;
			}
	
	return res;
}

int main(){
	cin>>n>>m;
	
	mat ans(m,vector<ll>(m,0));
	mat p(m,vector<ll>(m,0));
	
	for(int i=0;i<m;i++) ans[i][i]=1;
	p[0][0]=1;p[0][m-1]=1;
	for(int i=1;i<m;i++) p[i][i-1]=1;
	
	while(n){
		if(n%2) ans=ans*p;
		p=p*p;
		n/=2;
	}
	
	cout<<ans[0][0]<<'\n';
}

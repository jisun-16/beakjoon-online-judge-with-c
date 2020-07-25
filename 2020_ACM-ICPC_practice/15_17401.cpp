#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll> > mat;

const long long mod=1000000007;
int t,n,d;

mat operator*(const mat& a, const mat& b){
	mat res(n,vector<ll>(n,0));
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++){
				res[i][j]+=(a[i][k]*b[k][j])%mod;
				res[i][j]%=mod;
			}
	
	return res;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>t>>n>>d;
	vector<mat> adj(t,mat(n,vector<ll>(n,0)));
	for(int i=0;i<t;i++){
		int temp;
		cin>>temp;
		while(temp--){
			int a,b,c;
			cin>>a>>b>>c;
			adj[i][a-1][b-1]=c;
		}
	}
	
	mat ans(n,vector<ll>(n,0));
	mat p(n,vector<ll>(n,0));
	for(int i=0;i<n;i++){
		ans[i][i]=p[i][i]=1;
	}
	
	for(int i=0;i<t;i++) p=p*adj[i];
	int nn=d/t;//аж╠Б 
	while(nn){
		if(nn%2) ans=ans*p;
		p=p*p;
		nn/=2;
	}
	for(int i=0;i<d%t;i++) ans=ans*adj[i];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout<<ans[i][j]<<' ';
		cout<<'\n';
	}
}


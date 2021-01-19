#include<iostream>
#include<vector>
#define mat vector<vector<long long> >
using namespace std;
int n,m,k,mod=1e9+7;
mat operator *(mat const& a,mat const& b){
	mat ret(a.size(),vector<long long>(b[0].size()));
	for(int i=0;i<a.size();++i)
		for(int j=0;j<b.size();++j)
			for(int k=0;k<b[0].size();++k)
				ret[i][j]=(ret[i][j]+a[i][k]*b[k][j])%mod;
	return ret;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	mat arr(n,vector<long long>(n)),ans(n,vector<long long>(n));
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		--a;--b;
		arr[a][b]=arr[b][a]=1;
	}
	cin>>k;
	for(int i=0;i<n;++i) ans[i][i]=1;
	while(k>0){
		if(k&1) ans=ans*arr;
		k/=2;
		arr=arr*arr;
	}
	cout<<ans[0][0]<<'\n';
}

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int n, R, G, B;
long long dp[11][101][101][101], fac[11];
//level n, 남은 장난감의 개수 (R,G,B) 

long long _solve(int nn, int rr, int gg, int bb){
	if(rr<0||bb<0||gg<0) return 0;
	if(nn<=0) return 1;
	
	long long& ret=dp[nn][rr][gg][bb];
	if(ret!=-1) return ret;
	
	ret=0;
	
	//1-color
	ret+=_solve(nn-1,rr-nn,gg,bb);
	ret+=_solve(nn-1,rr,gg-nn,bb);
	ret+=_solve(nn-1,rr,gg,bb-nn);
	
	//2-color
	if(nn%2==0){
		long long mul=fac[nn]/pow(fac[nn/2],2);
		ret+=mul*_solve(nn-1,rr-nn/2,gg-nn/2,bb);
		ret+=mul*_solve(nn-1,rr-nn/2,gg,bb-nn/2);
		ret+=mul*_solve(nn-1,rr,gg-nn/2,bb-nn/2);
	}
	
	//3-color
	if(nn%3==0){
		long long mul=fac[nn]/pow(fac[nn/3],3);
		ret+=mul*_solve(nn-1,rr-nn/3,gg-nn/3,bb-nn/3);
	}
	
	return ret;
} 

int main(){
	fac[0]=1;
	for(int i=1;i<=10;i++){
		fac[i]=i*fac[i-1];
	}
	
	cin>>n>>R>>G>>B;
	
	if(R+G+B<(n*(n+1))/2){
		cout<<0<<'\n';
		return 0;
	}
	
	memset(dp,-1,sizeof(dp));
	
	cout<<_solve(n,R,G,B)<<'\n';
}

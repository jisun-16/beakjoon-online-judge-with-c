#include<cstdio>

const int mod=10007;

int main(){
	int n,nCr[53][53];
	
	nCr[0][0]=1;
	for(int i=1;i<=52;i++){
		nCr[i][0]=1;
		for(int j=1;j<i;j++)
			nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%mod;
		nCr[i][i]=1;
	}
	
	scanf("%d",&n);
	
	int ans=0,sign=1;
	for(int i=1;i<=n/4;i++){
		ans+=sign*nCr[13][i]*nCr[52-4*i][n-4*i];
		while(ans<0) ans+=mod;
		ans%=mod;
		sign*=-1;
	}
	
	printf("%d\n",ans);
}

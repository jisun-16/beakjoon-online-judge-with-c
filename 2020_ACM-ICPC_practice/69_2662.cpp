#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,p[301][21],dp[2][301][21],ans[21];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		int temp;
		scanf("%d",&temp);
		for(int j=0;j<m;++j)
			scanf("%d",&p[temp][j]);
	}
	int t=0;
	for(int i=0;i<m;++i,t=!t)
		for(int j=0;j<=n;++j)
			for(int k=j;k<=n;++k)
				if(dp[!t][k][m]<dp[t][k-j][m]+p[j][i]){
					for(int l=0;l<i;++l)
						dp[!t][k][l]=dp[t][k-j][l];
					dp[!t][k][i]=j;
					dp[!t][k][m]=dp[t][k-j][m]+p[j][i];
				}
	printf("%d\n",dp[t][n][m]);
	for(int i=0;i<m;++i)
		printf("%d ",dp[t][n][i]);
}

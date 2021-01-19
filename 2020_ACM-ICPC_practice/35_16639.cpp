#include<cstdio>

#define inf 987654321

int n,mx[10][10],mn[10][10];
char exp[20];

int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}

int main(){
	scanf("%d ",&n);
	for(int i=0;i<n;++i) scanf("%1c",&exp[i]);
	
	for(int i=0;i<=n/2;++i)
		for(int j=0;j<=n/2;++j) 
			mx[i][j]=-inf,mn[i][j]=inf;
		
	for(int i=0;i<=n/2;++i) 
		mx[i][i]=mn[i][i]=exp[i*2]-'0';
	
	for(int k=1;k<=n/2;++k)
		for(int i=0;i<=n/2-k;++i)
			for(int j=i;j<i+k;++j){
				char op=exp[2*j+1];
				if(op=='+'){
					mx[i][i+k]=max(mx[i][i+k],mx[i][j]+mx[j+1][i+k]);
					mn[i][i+k]=min(mn[i][i+k],mn[i][j]+mn[j+1][i+k]);
				}
				else if(op=='-'){
					mx[i][i+k]=max(mx[i][i+k],mx[i][j]-mn[j+1][i+k]);
					mn[i][i+k]=min(mn[i][i+k],mn[i][j]-mx[j+1][i+k]);
				}
				else{
					//max
					mx[i][i+k]=max(mx[i][i+k],mx[i][j]*mx[j+1][i+k]);
					mx[i][i+k]=max(mx[i][i+k],mx[i][j]*mn[j+1][i+k]);
					mx[i][i+k]=max(mx[i][i+k],mn[i][j]*mx[j+1][i+k]);
					mx[i][i+k]=max(mx[i][i+k],mn[i][j]*mn[j+1][i+k]);
					//min
					mn[i][i+k]=min(mn[i][i+k],mx[i][j]*mx[j+1][i+k]);
					mn[i][i+k]=min(mn[i][i+k],mx[i][j]*mn[j+1][i+k]);
					mn[i][i+k]=min(mn[i][i+k],mn[i][j]*mx[j+1][i+k]);
					mn[i][i+k]=min(mn[i][i+k],mn[i][j]*mn[j+1][i+k]);
				}
			}
	
	printf("%d\n",mx[0][n/2]);
}

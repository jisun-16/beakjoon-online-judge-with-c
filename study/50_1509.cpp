#include<stdio.h>
#include<cstring>
int main(){
	char s[2502];
	int dp[2501]={0,},p[2501]={0,};
	scanf("%s",s+1);
	int l=strlen(s+1);
	for(int i=1;i<=l;++i){
		dp[i]=2500;
		for(int j=1;j<=i;++j){
			if(s[j]==s[i]&&(i-j<=1||p[j+1])){
				p[j]=1;
				dp[i]=dp[i]<dp[j-1]+1?dp[i]:dp[j-1]+1;
			}
			else p[j]=0;
		}
	}
	printf("%d\n",dp[l]);
}

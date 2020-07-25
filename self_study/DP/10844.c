#include<stdio.h>
#define mod 1000000000
int main(){
    int N,i,j,sum=0;
    int s[101][10]={0,};
    scanf("%d",&N);
    for(i=0;i<10;i++) s[1][i]=1;
    for(i=2;i<=N;i++){
        for(j=0;j<10;j++){
            if(j==0) s[i][0]=s[i-1][1]%mod;
            else if(j==9) s[i][9]=s[i-1][8]%mod;
            else s[i][j]=(s[i-1][j-1]+s[i-1][j+1])%mod;
        }
    }
    for(i=1;i<10;i++) sum=(sum+s[N][i])%mod;
    printf("%d",sum%mod);
    return 0;
}
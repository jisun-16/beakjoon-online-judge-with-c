#include<stdio.h>
int main(){
    int n, tyle[1001];
    scanf("%d",&n);
    tyle[0]=1;
    tyle[1]=1;
    tyle[2]=3;
    for(int i=3;i<=n;i++){
        tyle[i]=(tyle[i-1]+2*tyle[i-2])%10007;
    }
    printf("%d",tyle[n]);
    return 0;
}
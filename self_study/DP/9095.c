#include<stdio.h>
int main(){
    int T, arr[11], i, n;
    scanf("%d",&T);
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(i=4;i<11;i++) arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    while(T){
        T--;
        scanf("%d",&n);
        printf("%d\n",arr[n]);
    }
    return 0;
}
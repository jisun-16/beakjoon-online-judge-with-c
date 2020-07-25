#include<stdio.h>
int main(){
    int N, i, cnt;
    scanf("%d",&N);
    cnt=N;
    while(cnt){
        for(i=0;i<N-cnt;i++)printf(" ");
        for(i=0;i<cnt;i++)printf("*");
        printf("\n");
        cnt--;
    }
    return 0;
}
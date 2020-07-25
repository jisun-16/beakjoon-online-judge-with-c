#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int cnt=0;
    while(cnt<N){
        for(int i=0;i<cnt;i++) printf(" ");
        for(int i=0;i<(N-cnt)*2-1;i++) printf("*");
        printf("\n");
        cnt++;
    }
    return 0;
}
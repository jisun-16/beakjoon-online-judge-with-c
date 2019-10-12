#include<stdio.h>
int main(){
    int N, i;
    scanf("%d",&N);
    while(N){
        for(i=0;i<N;i++) printf("*");
        printf("\n");
        N--;
    }
    return 0;
}
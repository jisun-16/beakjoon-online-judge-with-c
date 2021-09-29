#include<cstdio>	
int num,chk[1<<20];
int main(){
	while(scanf("%d",&num)!=-1){
		int a=num/32,b=num%32;
		if(!(chk[a]&(1<<b))){
			chk[a]|=1<<b;
			printf("%d ",num);
		}
	}
}

#include<stdio.h>

int main(){
	int n,prev,now;
	long long w,coin;
	
	scanf("%d %d",&n,&w);
	scanf("%d",&prev);
	for(int i=1;i<n;i++){
		scanf("%d",&now);
		if(prev<now){
			coin=w/prev;
			w+=(now-prev)*coin;
		}
		prev=now;
	}
	
	printf("%lld\n",w);
	
	return 0;
}

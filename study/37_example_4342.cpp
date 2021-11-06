#include<cstdio>
#define swap(a,b){int t;t=a;a=b;b=t;}

int main(){
	while(true){
		int a,b,cnt=0;
		scanf("%d %d",&a,&b);
		
		if(a==0&&b==0) break;
		
		while(a&&b){
			++cnt;
			
			if(a<b) swap(a,b);
			
			if(a/b==1)
				a=a-b;
			else{
				if(a%b==0)
					a=0;
				else break;
			}
		}
		
		if(cnt%2) printf("A wins\n");
		else printf("B wins\n");
	}
}

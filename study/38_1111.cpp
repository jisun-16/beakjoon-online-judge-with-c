#include<cstdio>
int n,arr[50],i;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;++i) scanf("%d",&arr[i]);
	if(n==1) printf("A\n");
	else if(n==2){
		if(arr[0]==arr[1]) printf("%d\n",arr[0]);
		else printf("A\n");
	}
	else{
		if(arr[0]==arr[1]){
			for(i=2;i<n;++i)
				if(arr[i]!=arr[0]) break;
			if(i!=n) printf("B\n");
			else printf("%d\n",arr[0]);
		}
		else{
			if((arr[2]-arr[1])%(arr[1]-arr[0])==0){
				int a=(arr[2]-arr[1])/(arr[1]-arr[0]);
				int b=arr[1]-arr[0]*a;
				for(i=2;i<n;++i)
					if(arr[i]!=arr[i-1]*a+b) break;
				if(i!=n) printf("B\n");
				else printf("%d\n",arr[n-1]*a+b);
			}
			else printf("B\n");
		}
	}
}

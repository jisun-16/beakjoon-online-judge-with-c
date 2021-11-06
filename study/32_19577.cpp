#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n,ans=-1,d[1400]={0,},idx=0;
	scanf("%d",&n);
	if(n==1){
		printf("1\n");
		return 0;
	}
	for(int i=1;i*i<=n;++i) 
		if(n%i==0) d[idx++]=i,d[idx++]=n/i;
	sort(d,d+idx);
	for(int i=0;i<idx;++i){
		int p=d[i],temp=d[i];
		for(int j=1;j<idx;++j){
			if(temp<d[j]) break;
			if(temp%d[j]==0){
				p=p/d[j]*(d[j]-1);
				while(temp%d[j]==0) temp/=d[j];
			}
		}
		if(d[i]*p==n){
			ans=d[i];
			break;
		}
	}
	printf("%d\n",ans);
}

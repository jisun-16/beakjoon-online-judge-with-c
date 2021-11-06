#include<stdio.h>
int main(){
	int n,a[1001]={0,},ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	for(int temp,i=0;i<n;++i) scanf("%d",&temp),a[i]-=temp;
	for(int i=0;i<n;++i){
		while(a[i]>0){
			for(int j=i;a[j]>0;++j) --a[j];
			++ans;
		}
		while(a[i]<0){
			for(int j=i;a[j]<0;++j) ++a[j];
			++ans;
		}
	}
	printf("%d\n",ans);
}

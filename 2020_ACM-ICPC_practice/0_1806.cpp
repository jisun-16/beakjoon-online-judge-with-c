#include<cstdio>
int n,s,arr[100000],l,r,ans=1e9,sum,len;
int main(){
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;++i) scanf("%d",&arr[i]);
	while(true){
		if(sum>=s){
			if(ans>len) ans=len;
			sum-=arr[l];
			l++;
			len--;
		}
		else{
			if(r==n) break;
			sum+=arr[r];
			r++;
			len++;
		}
	}
	printf("%d\n",ans==1e9?0:ans);
}

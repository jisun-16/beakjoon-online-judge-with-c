#include<stdio.h>
#define abs(n) (n>0?n:-n)
#define min(a,b) (a<b?a:b)
int n,ans=987654321;
int r[20],c[20],s[20][20];
void calc(int cnt,int idx,int diff){
	if(cnt==n/2){
		ans=min(ans,abs(diff));
		return;
	}
	if(idx==n) return;
	calc(cnt+1,idx+1,diff-r[idx]-c[idx]);
	calc(cnt,idx+1,diff);
}
int main(){
	scanf("%d",&n);
	int total=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			scanf("%d",&s[i][j]);
			r[i]+=s[i][j];
			c[j]+=s[i][j];
			total+=s[i][j];
		}
	calc(1,1,total-r[0]-c[0]);
	printf("%d\n",ans);
}

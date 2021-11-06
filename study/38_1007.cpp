#include<cstdio>
#include<cmath>
#define inf 1e10
using namespace std;
int t,n,x[20],y[20],tx,ty;
double ans;
void combi(int cnt,int idx,int sx,int sy){
	if(cnt==0){
		double temp=sqrt(pow(tx-2*sx,2)+pow(ty-2*sy,2));
		if(temp<ans) ans=temp;
		return;
	}
	for(int i=idx;i<=n-cnt;++i){
		combi(cnt-1,i+1,sx+x[i],sy+y[i]);
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		ans=inf;tx=0;ty=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d %d",x+i,y+i);
			tx+=x[i];
			ty+=y[i];
		}
		combi(n/2-1,1,x[0],y[0]);
		printf("%.9lf\n",ans);
	}
}

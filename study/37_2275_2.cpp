#include<cstdio>
#include<queue>

using namespace std;

int n,h,p[10001],d[10001],ind[10001],val[10001],ans;
queue<int> q;

int main(){
	scanf("%d %d",&n,&h);
	for(int i=1;i<=n;++i){
		scanf("%d %d",&p[i],&d[i]);
		val[i]=2e9;
		if(p[i]!=0) ++ind[p[i]];
	}
	for(int i=1;i<=n;++i)
		if(ind[i]==0) q.push(i),val[i]=h;
	while(!q.empty()){
		int now=q.front(),next=p[now];
		q.pop();
		if(next==0) break;
		ans+=max(d[now]-val[now],0);
		val[next]=min(max(val[now]-d[now],0),val[next]);
		if(--ind[next]==0) q.push(next);
	}
	printf("%d\n",ans);
}

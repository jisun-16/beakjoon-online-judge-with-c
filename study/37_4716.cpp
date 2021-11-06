#include<cstdio>
#include<algorithm>
#define pii pair<int,int>
#define a first
#define b second
using namespace std;
int n,an,bn,am[1000],idx[1000],ans;
pii d[1000];
bool cmp(int i,int j){return abs(d[i].a-d[i].b)>abs(d[j].a-d[j].b);}
int main(){
	while(true){
		ans=0;
		scanf("%d %d %d",&n,&an,&bn);
		if(n==0) break;
		for(int i=0;i<n;++i) {
			scanf("%d %d %d",&am[i],&d[i].a,&d[i].b);
			idx[i]=i;
		}
		sort(idx,idx+n,cmp);
		for(int k=0;k<n;++k){ 
			int i=idx[k];
			if(d[i].a<d[i].b){
				if(an>=am[i]){
					ans+=am[i]*d[i].a;
					an-=am[i];
				}
				else{
					ans+=(an*d[i].a+(am[i]-an)*d[i].b);
					bn-=(am[i]-an);
					an=0;
				}
			}
			else{
				if(bn>=am[i]){
					ans+=am[i]*d[i].b;
					bn-=am[i];
				}
				else{
					ans+=(bn*d[i].b+(am[i]-bn)*d[i].a);
					an-=(am[i]-bn);
					bn=0;
				}
			}
		}
		printf("%d\n",ans);	
	}
}

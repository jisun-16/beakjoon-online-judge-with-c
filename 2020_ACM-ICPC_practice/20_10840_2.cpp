#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int nl,ml;
char N[1502],M[1502];
unsigned long long pN[1501],pM[1501],p[26]={1};

int main(){
	scanf("%s %s",N+1,M+1);
	
	nl=strlen(N+1);ml=strlen(M+1);
	for(int i=1;i<26;i++) p[i]=p[i-1]*1523;
	for(int i=1;i<=nl;i++) pN[i]=pN[i-1]+p[N[i]-'a'];
	for(int i=1;i<=ml;i++) pM[i]=pM[i-1]+p[M[i]-'a'];
	
	int l=min(nl,ml),ans=0;
	for(int len=l;len>=1&&!ans;len--){
		unsigned long long v[1501]={0,};
		int idx=0;
		
		for(int j=len;j<=ml;j++) 
			v[idx++]=pM[j]-pM[j-len];
		
		sort(v,v+idx);
		
		for(int j=len;j<=nl;j++)
			if(binary_search(v,v+idx,pN[j]-pN[j-len]))
				ans=len;
	}
	
	printf("%d\n",ans);
}

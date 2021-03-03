#include<cstdio>
using namespace std;
int main(){
	int q,mod,arr[200001]={0,},s=0,e=0,cnt=0,chk[101];
	scanf("%d %d",&q,&mod);
	while(q--){
		int a,b;
		scanf("%d",&a);
		if(a==1){
			scanf("%d",&arr[e]);
			arr[e]%=mod;
			if(!chk[arr[e++]]++) ++cnt;
			while(cnt==mod&&s<e&&chk[arr[s]]>1) 
				--chk[arr[s++]];
		}
		else if(a==2){
			if(e!=0){
				if(!--chk[arr[--e]]) --cnt;
				while(cnt!=mod&&s>0) cnt+=!chk[arr[--s]]++;
			}
		}
		else{
			printf("%d\n",cnt==mod?e-s:-1);
		}
	}
}

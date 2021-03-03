#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int q,mod,arr[200001]={0,},idx=0;
	vector<int> chk[101];
	scanf("%d %d",&q,&mod);
	while(q--){
		int a,b;
		scanf("%d",&a);
		if(a==1){
			scanf("%d",&b);
			arr[++idx]=b%mod;
			chk[b%mod].push_back(idx);
		}
		else if(a==2){
			if(idx>0) {
				chk[arr[idx--]].pop_back();
				
			}
		}
		else{
			int i,ans=200000;
			for(i=0;i<mod;++i){
				if(chk[i].size()==0) break;
				if(ans>chk[i][chk[i].size()-1]) ans=chk[i][chk[i].size()-1];
			}
			if(i!=mod) printf("-1\n");
			else printf("%d\n",idx-ans+1);
		}
	}
}

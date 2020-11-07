#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int T, N, S[500];
vector<int>::iterator it;

int main(){
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int ans=0;
		
		scanf("%d",&N);		
		for(int i=0;i<N;i++) scanf("%d",&S[i]);
		
		for(int i=0;i<N;i++){
			vector<int> v;
			for(int j=i;j<N;j++){
				if(v.empty()||v.back()<S[j])
					v.push_back(S[j]);
				else{
					it=lower_bound(v.begin(),v.end(),S[j]);	
					*it=S[j];
				}
				ans+=v.size();
			}
		}
		
		printf("Case #%d: %d\n",t,ans);
	}
}

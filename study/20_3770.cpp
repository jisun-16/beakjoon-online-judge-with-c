#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int T,N,M,K;

int main(){
	scanf("%d",&T);
	
	for(int tt=1;tt<=T;tt++){
		long long ans=0;
		int fen[1000]={0};
		vector<pair<int,int> > road;
		
		scanf("%d %d %d",&N,&M,&K);
		for(int kk=0;kk<K;kk++){
			int e,w;
			scanf("%d %d",&e,&w);
			road.push_back({e,w});
		}
		
		sort(road.begin(),road.end());
		
		for(int i=road.size()-1;i>=0;i--){
			long long temp=0;
			int j=road[i].second-1;
			while(j){
				temp+=fen[j];
				j-=(j&-j);
			}
			
			ans+=temp;
			
			j=road[i].second;
			while(j<=M){
				fen[j]+=1;
				j+=(j&-j);
			}
		}
		
		printf("Test case %d: %lld\n",tt,ans);
	}
}

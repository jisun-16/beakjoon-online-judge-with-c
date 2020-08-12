#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T,n,loc[2][100001],fen[100001];

void _update(int i,int num){
	while(i<=n){
		fen[i]+=num;
		i+=(i&-i);
	}
}

int _sum(int i){
	int ret=0;
	while(i){
		ret+=fen[i];
		i-=(i&-i);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin>>T;
	while(T--){
		for(int i=0;i<100001;i++) fen[i]=0;
		
		cin>>n;
		for(int i=1;i<=n;i++){
			int temp;
			cin>>temp;
			loc[0][temp]=i;
		}
		for(int i=1;i<=n;i++){
			int temp;
			cin>>temp;
			loc[1][i]=loc[0][temp];
		}
					
		long long ans=0;
		for(int i=n;i>=1;i--){
			ans+=(long long)_sum(loc[1][i]-1);
			_update(loc[1][i],1);
		}
		
		cout<<ans<<'\n';
	}
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int t, coin[100];
long long price;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	
	for(int i=1;i<100;i++) {
		coin[i]=i;
		if(i>=25) 
			coin[i]=min(coin[i],coin[i-25]+1);
		if(i>=10)
			coin[i]=min(coin[i],coin[i-10]+1);
	}
	
	cin>>t;
	while(t--){
		int ans=0;
		cin>>price;
		
		while(price){
			ans+=coin[price%100];
			price/=100;
		}
		
		cout<<ans<<'\n';
	}
}

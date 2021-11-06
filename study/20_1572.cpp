#include<iostream>
#include<algorithm>

using namespace std;

int n,k,m=65536;
long long ans=0;
int arr[250001],fen[65537];

int _sum(int i){
	int ret=0;
	while(i){
		ret+=fen[i];
		i-=(i&-i);
	}
	return ret;
}

void _update(int i,int num){
	while(i<=m){
		fen[i]+=num;
		i+=(i&-i);
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>arr[i];
	
	for(int i=0;i<k;i++){
		_update(arr[i]+1,1);
	}
	for(int i=k;i<=n;i++){
		int s=0,e=1<<16;
		while(s<e){
			int mid=(s+e)/2;
			int temp=_sum(mid);
			if(temp>=(k+1)/2) e=mid;
			else s=mid+1;
		}
		
		ans+=s-1;
		
		if(i==n) break;
		
		_update(arr[i]+1,1);
		_update(arr[i-k]+1,-1);
	}
	
	cout<<ans<<'\n';
}

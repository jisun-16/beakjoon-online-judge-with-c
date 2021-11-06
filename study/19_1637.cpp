#include<iostream>

using namespace std;

unsigned int n,arr[20001][3];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	
	unsigned int s=0,e=2147483647,ans=-1;
	while(s<=e){
		unsigned int mid=(s+e)/2;
		
		unsigned int temp=0;
		for(int i=0;i<n;i++){
			if(mid<arr[i][0]) continue;
			
			unsigned int t=min(mid,arr[i][1]);
			temp+=(t-arr[i][0])/arr[i][2]+1;
		}
		
		if(temp%2==0) s=mid+1;
		else{
			e=mid-1;
			ans=mid;
		}
	}
	
	if(ans!=-1){
		cout<<ans<<' ';
		int cnt=0;
		for(int i=0;i<n;i++) 
			cnt+=(ans>=arr[i][0]&&ans<=arr[i][1]&&(ans-arr[i][0])%arr[i][2]==0);
		cout<<cnt<<'\n';
	}
	else{
		cout<<"NOTHING\n";
	}
}


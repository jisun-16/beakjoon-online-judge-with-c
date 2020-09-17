#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

int n,k,arr[1000001];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>arr[i];
	
	sort(arr,arr+n);
	
	deque<int> dq;
	int ans=987654321;
	k=n-k;//k개 제거 -> k개 선택 
	for(int i=0,j=1;i+k<=n;i++){
		if(!dq.empty()&&dq.front()<=i)
			dq.pop_front();
		
		for(;j<i+k;j++){
			//arr[j]-arr[j-1]이 최대 
			while(!dq.empty()&&arr[j]-arr[j-1]<=arr[dq.back()]-arr[dq.back()-1])
				dq.pop_back();
			dq.push_back(j);
		}
		
		int temp=(arr[i+k-1]-arr[i])+(arr[dq.front()]-arr[dq.front()-1]);
		ans=min(ans,temp);
	}
	
	cout<<ans<<'\n';
}

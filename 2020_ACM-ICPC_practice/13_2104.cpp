#include<iostream>
#include<stack>

using namespace std;

int n, arr[100002];
long long ans,arr_sum[100002];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	arr_sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		arr_sum[i]=arr_sum[i-1]+arr[i];
	}
	arr[n+1]=-1;
	
	stack<pair<int,int> > s;
	for(int i=1;i<=n+1;i++){
		int left=i;
		while(!s.empty()&&s.top().second>arr[i]){
			ans=max(ans,(arr_sum[i-1]-arr_sum[s.top().first-1])*s.top().second);
			left=s.top().first;
			s.pop();
		}
		s.push({left,arr[i]});
	}
	
	cout<<ans<<'\n';
}

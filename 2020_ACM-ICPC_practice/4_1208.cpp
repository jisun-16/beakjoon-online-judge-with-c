#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, s, arr[41];
long long ans;
vector<int> suma, sumb;

void a_sum(int start, int sum){
	sum+=arr[start];
	if(start>=n/2) return;
	if(sum==s)
		ans++;
	
	suma.push_back(sum);
	a_sum(start+1, sum-arr[start]);
	a_sum(start+1, sum);
}

void b_sum(int start, int sum){
	sum+=arr[start];
	if(start>=n) return;
	if(sum==s)
		ans++;
	
	sumb.push_back(sum);
	b_sum(start+1, sum-arr[start]);
	b_sum(start+1, sum);
}

int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	a_sum(0,0);
	b_sum(n/2,0);
	
	sort(suma.begin(),suma.end());
	sort(sumb.begin(),sumb.end());
	
	for(int i=0;i<suma.size();i++){
		ans+=upper_bound(sumb.begin(),sumb.end(),s-suma[i])-lower_bound(sumb.begin(),sumb.end(),s-suma[i]);
	}
	
	cout<<ans<<'\n';
}

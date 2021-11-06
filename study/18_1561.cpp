#include<iostream>
#include<algorithm>

using namespace std;

long long n;
int m, t[10001],t_cnt[31];


int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		cin>>t[i];
		t_cnt[t[i]]++;
	}
	
	if(n<=m){
		cout<<n<<'\n';
		return 0;
	}
	
	long long s=0,e=60000000000,ti=0,cnt;
	while(s<=e){
		long long mid=(s+e)/2;
		cnt=m;
		for(int i=1;i<=30;i++)
			cnt+=(mid/i)*t_cnt[i];
		if(cnt<n) s=mid+1;
		else {
			e=mid-1;
			ti=mid;
		}
	}
	
	cnt=m;
	for(int i=0;i<m;i++) cnt+=(ti-1)/t[i];
	
	int ans;
	for(ans=0;ans<m;ans++){
		if(ti%t[ans]==0) cnt++;
		if(cnt==n) break;
	}
	
	cout<<ans+1<<'\n';
}

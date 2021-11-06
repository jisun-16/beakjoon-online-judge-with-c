#include<iostream>
#include<algorithm>

using namespace std;

int n,time[100001];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>time[i];
	
	sort(time,time+n);
	
	long long s,e,mid;
	s=1;e=time[n-1];
	while(s<e){
		mid=(s+e)/2;
		
		int cnt=0;
		for(int i=0;i<n;i++)
			cnt+=1-(time[i]-1)/mid;
		
		if(cnt<=0) s=mid+1;
		else e=mid;
	}
	
	cout<<e<<'\n';
}

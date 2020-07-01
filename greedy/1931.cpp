#include<iostream>
#include<algorithm>

using namespace std;

#define pii pair<int,int>

int n, cnt[100001];
pii time[100001];

bool cmp(pii a, pii b){
	if(a.second==b.second) return a.first<b.first;
	return a.second<b.second;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>time[i].first>>time[i].second;
	}
	
	sort(time,time+n,cmp);
	
	int ans=0;
	int temp=0;
	for(int i=0;i<n;i++){
		if(time[i].first>=temp){
			ans++;
			temp=time[i].second;
		}
	}
	
	cout<<ans<<'\n';
}

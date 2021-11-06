#include<iostream>
using namespace std;
int n,s[8],w[8],ans;
void sol(int idx,int cnt){
	ans=ans>cnt?ans:cnt;
	if(idx==n)
		return;
	if(s[idx]<=0){
		sol(idx+1,cnt);
		return;
	}
	for(int i=0;i<n;++i){
		if(i==idx||s[i]<=0) continue;
		s[idx]-=w[i];
		s[i]-=w[idx];
		sol(idx+1,cnt+(s[idx]<=0)+(s[i]<=0));
		s[idx]+=w[i];
		s[i]+=w[idx];
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i) cin>>s[i]>>w[i];
	sol(0,0);
	cout<<ans<<'\n';
}

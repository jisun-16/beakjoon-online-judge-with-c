#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int> pi[100001];
long long n,ans,d,md;
// 사용계획->남은기한 기준 정렬 
bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.second==b.second) return a.first<b.first;
	return a.second<b.second;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i) cin>>pi[i].first;
	for(int i=0;i<n;++i) cin>>pi[i].second;
	sort(pi,pi+n,cmp);
	if(pi[0].first<pi[0].second){
		//기한연장 
		ans+=(pi[0].second-pi[0].first+29)/30;
		d=pi[0].first+ans*30;
	}
	else d=pi[0].first;
	for(int i=1;i<n;++i){
		if(pi[i].second!=pi[i-1].second) md=d;
		if((pi[i].second>md?pi[i].second:md)>pi[i].first){
			//기간연장 
			long long temp=((pi[i].second>md?pi[i].second:md)-pi[i].first+29)/30;
			ans+=temp;
			d=max(d,md);
			d=max(d,pi[i].first+temp*30);
		}
		else d=d>pi[i].first?d:pi[i].first;
	}
	cout<<ans<<'\n';
}

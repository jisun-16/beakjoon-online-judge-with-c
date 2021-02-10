#include<iostream>
#include<stack>
using namespace std;
int n,h;
long long ans;
stack<pair<int,int> > s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		int cnt=1;
		cin>>h;
		while(!s.empty()&&s.top().first<h){
			ans+=s.top().second;
			s.pop();
		}
		if(!s.empty()&&s.top().first==h){
			cnt+=s.top().second;
			ans+=s.top().second;
			s.pop();
		}
		if(!s.empty()) ++ans;
		s.push({h,cnt});
	}
	cout<<ans<<'\n';
}

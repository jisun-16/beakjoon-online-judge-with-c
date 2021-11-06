#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int n, T[100001];
long long ans=0;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>T[i];
	T[n]=-1;
	
	stack<pair<int,int> > s;
	for(int i=0;i<=n;i++){
		int left=i;
		while(!s.empty()&&s.top().second>T[i]){
			ans=max(ans,((long long)i-s.top().first)*s.top().second);
			left=s.top().first;
			s.pop();
		}
		s.push({left,T[i]});
	}
	
	cout<<ans<<'\n';
}

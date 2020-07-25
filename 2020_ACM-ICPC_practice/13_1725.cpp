#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int n,hei[100001],ans;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin>>n;
	for(int i=0;i<n;i++)
		cin>>hei[i];
	hei[n]=-1;
	
	stack<pair<int,int> > s;
	for(int i=0;i<=n;i++){
		int left=i;
		while(!s.empty()&&s.top().second>hei[i]){
			ans=max(ans,(i-s.top().first)*s.top().second);
			left=s.top().first;
			s.pop();
		}
		s.push({left,hei[i]});
	}
	
	cout<<ans<<'\n';
}

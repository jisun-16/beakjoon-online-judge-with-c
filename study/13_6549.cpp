#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	while(true){
		int n=0;
		cin>>n;
		
		if(n==0) break;
		
		long long ans=0,one=1;
		stack<pair<int,int> > s;
		for(int i=0;i<=n;i++){
			int h=0;
			if(i<n) cin>>h;
			else h=-1;
			
			int left=i;
			while(!s.empty()&&s.top().second>h){
				int x=s.top().first,y=s.top().second;
				s.pop();
				
				ans=max(ans,one*(i-x)*y);
				left=x;
			}
			
			s.push({left,h});
		}
		
		cout<<ans<<'\n';
	}
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,arr[100000][2],d,p=-1e8,ans;
vector<int> s,e;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i) {
		int a,b;
		cin>>a>>b;
		if(a<b) arr[i][0]=a,arr[i][1]=b;
		else arr[i][0]=b,arr[i][1]=a;
	}
	cin>>d;
	for(int i=0;i<n;++i){
		if(arr[i][1]-arr[i][0]>d) continue;
		s.push_back(arr[i][0]);
		e.push_back(arr[i][1]);
	}
	sort(s.begin(),s.end());
	sort(e.begin(),e.end());
	for(int i=0;i<s.size();++i){
		if(s[i]==p) continue;
		p=s[i];
		int temp=s.end()-lower_bound(s.begin(),s.end(),p)+upper_bound(e.begin(),e.end(),p+d)-e.begin();
		temp-=s.size();
		if(ans<temp) ans=temp;		
	}
	cout<<ans<<'\n';
}

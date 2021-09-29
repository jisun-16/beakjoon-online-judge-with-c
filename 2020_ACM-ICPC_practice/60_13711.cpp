#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,a[100001],b[100001],c[100001],ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		int temp;
		cin>>temp;
		a[temp]=i;
	}
	for(int i=0;i<n;++i){
		cin>>b[i];
		c[i]=a[b[i]];
	}
	vector<int> v;
	v.push_back(c[0]);
	for(int i=1;i<n;++i){
		if(c[i]>v[ans]) 
			v.push_back(c[i]),++ans;
		else{
			int temp=upper_bound(v.begin(),v.end(),c[i])-v.begin();
			v[temp]=c[i];
		}
	}
	cout<<ans+1<<'\n';
}

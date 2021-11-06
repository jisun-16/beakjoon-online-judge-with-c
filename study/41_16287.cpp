#include<iostream>
#include<algorithm>
using namespace std;
int w,n,a[5000],wei[800000];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>w>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	/*for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			if(a[i]+a[j]<w) wei[a[i]+a[j]]=true;
	*/
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			if(a[i]+a[j]>w) continue;
			if(wei[w-a[i]-a[j]]){
				cout<<"YES\n";
				return 0;
			}
		}
		for(int j=0;j<i;++j) 
			if(a[i]+a[j]<w) wei[a[i]+a[j]]=true;
	}
	cout<<"NO\n";
}

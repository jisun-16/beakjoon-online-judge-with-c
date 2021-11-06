#include<iostream>
using namespace std;
int n,arr[1000001],s[1000001],top;
long long ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i) cin>>arr[i];
	s[top++]=1e9+1;
	for(int i=0;i<n;){
		if(arr[i]<s[top-1]){
			s[top++]=arr[i++];
		}
		else{
			if(s[top-2]>arr[i]){
				ans+=arr[i];
				s[top-1]=arr[i++];
			}
			else{
				ans+=s[top-2];
				top--;
			}
		}
	}
	for(int i=top-1;i>1;--i) ans+=s[i-1];
	cout<<ans<<'\n';
}


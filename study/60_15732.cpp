#include<iostream>
#include<algorithm>
using namespace std;
int n,k,d,a[10000],b[10000],c[10000];
long long ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>d;
	for(int i=0;i<k;++i)
		cin>>a[i]>>b[i]>>c[i];
	int s=0,e=n;
	while(s<=e){
		int m=(s+e)/2;
		long long chk=0;
		for(int i=0;i<k;++i){
			if(m<a[i]) continue;
			if(m<b[i]) chk+=((m-a[i])/c[i])+1;
			else chk+=((b[i]-a[i])/c[i])+1;
		}
		if(chk>=(long long)d){
			ans=m;
			e=m-1;
		}
		else 
			s=m+1;
	}
	cout<<ans<<'\n';
}

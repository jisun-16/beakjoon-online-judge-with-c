#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int inf=987654321;
long long n,arr[5000],ans[3]={inf,inf,inf};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i) cin>>arr[i];
	sort(arr,arr+n);
		for(int i=0;i<n;++i){
			int l=i+1,r=n-1;
			while(l<r){
				long long sum=arr[i]+arr[l]+arr[r];
				if(abs(sum)<abs(ans[0]+ans[1]+ans[2])){
					ans[0]=arr[i],ans[1]=arr[l],ans[2]=arr[r];
				}
				if(sum<0) ++l;
				else if(sum>0) --r;
				else {
					i=n;
					break;
				}
			}
		}
		cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<'\n';
}

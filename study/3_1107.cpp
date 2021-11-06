#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n, m, ans;
bool broken[10];

int _avail(int k){
	int ret=0;
	
	if(k==0) {
		if(broken[0]) return 0;
		else return 1;
	}
	
	while(k){
		if(broken[k%10]){
			return 0;
		}
		k/=10;
		ret++;
	}
	
	return ret;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		int temp;
		cin>>temp;
		broken[temp]=true;	
	}
	
	if(n==100){
		cout<<0<<'\n';
		return 0;
	}
	
	ans=abs(n-100);
	for(int i=0;i<=1000000;i++){
		int temp=_avail(i);
		if(temp!=0){
			temp=temp+abs(n-i);
			ans=min(ans,temp);
		}
	}
	
	cout<<ans<<'\n';
}

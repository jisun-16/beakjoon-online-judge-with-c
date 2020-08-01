#include<iostream>
#include<algorithm>

using namespace std;

int n,m,k;

int main(){
	cin>>n>>m>>k;
	
	while(k>0){
		if(n>2*m) n--;
		else m--;
		k--;
	}
	
	int ans=min(n/2,m);
	cout<<ans<<'\n';
}

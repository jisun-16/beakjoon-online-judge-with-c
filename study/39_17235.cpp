#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,x,y,a=-2e9,b=2e9,c=-2e9,d=2e9;
	cin>>n;
	while(n--){
		cin>>x>>y;
		if(x+y>a) a=x+y;
		if(x+y<b) b=x+y;
		if(y-x>c) c=y-x;
		if(y-x<d) d=y-x;
	}
	unsigned long long ab=(long long)a-b,cd=(long long)c-d;
	unsigned long long ans=ab>cd?ab*ab:cd*cd;
	if(ans%2) cout<<ans/2<<".5\n";
	else cout<<ans/2<<'\n';
}

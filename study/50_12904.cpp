#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a,b;
int ans;
int main(){
	cin>>a>>b;
	while(true){
		if(a.length()==b.length()){
			if (a==b) ans=1;
			break;
		}
		if(b[b.length()-1]=='A')
			b.pop_back();
		else 
			b.pop_back(),reverse(b.begin(),b.end());
	}
	cout<<ans<<'\n';
}

#include<iostream>

using namespace std;

int t,dh,ds,hd,hs,sd,sh;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>dh>>ds>>hd>>hs>>sd>>sh;
		
		if(hd>hs||sd>sh||sd*hd>(hs-hd)*(sh-sd)) cout<<"GOD\n";
		else cout<<"KDH\n";
	}	
}

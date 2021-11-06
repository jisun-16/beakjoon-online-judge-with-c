#include<iostream>
#include<algorithm>

using namespace std;

int n, B[51], ans=0;

int  main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>B[i];
	}
	
	while(1){
		bool _zero=true, div=true;
		for(int i=0;i<n;i++){
			if(B[i]%2==1){
				ans++;
				B[i]-=1;
			}
		}
		
		for(int i=0;i<n;i++){
			if(B[i]!=0) {
				_zero=false;
				break;
			}
		}
		
		if(_zero) break;
		
		for(int i=0;i<n;i++) B[i]/=2;
		ans++;
	}
	
	cout<<ans<<'\n';
}

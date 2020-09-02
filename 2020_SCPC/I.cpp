#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

#define Max 100000000
int phi[Max];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n;
	cin>>n;
	
	for(int i=(int)sqrt(n);i<=n;i++){
		if(n%i!=0) continue;
		
		int p=i,nn=i;
		
		if(i<Max&&phi[i]!=0) p=phi[i];
		else{
			for(int j=2;j*j<=nn;j++){
				if(nn%j!=0) continue;
				while(nn%j==0) nn/=j;
				p*=j-1;
				p/=j;
			}
	
			if(nn!=1){
				p*=nn-1;
				p/=nn;
			}
	
			phi[i]=p;
		}
		
		if(i*p==n){
			cout<<i<<'\n';
			return 0;
		}
	}
	
	cout<<-1<<'\n';
	
	return 0;
}

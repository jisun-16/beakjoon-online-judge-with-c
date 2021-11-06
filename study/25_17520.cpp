#include<iostream>

using namespace std;

const int mod=16769023;
int n,two[50001];

int main(){
	cin>>n;
	two[0]=1;
	for(int i=1;i<=(n+1)/2;i++){
		two[i]=two[i-1]*2;
		two[i]%=mod;
	}
	cout<<two[(n+1)/2]<<'\n';
}

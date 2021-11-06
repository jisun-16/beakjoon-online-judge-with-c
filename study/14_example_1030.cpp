#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

int S,N,K,R1,R2,C1,C2;

int _solve(int s,int x,int y){
	if(s==0) return 0;
	
	int p=(int)pow(N,s-1);
	if(x>=p*(N-K)/2&&x<p*(N+K)/2&&y>=p*(N-K)/2&&y<p*(N+K)/2) return 1;
	
	x=x%p;
	y=y%p;
	
	return _solve(s-1,x,y);
}

int main(){
	cin>>S>>N>>K>>R1>>R2>>C1>>C2;
	for(int i=R1;i<=R2;i++){
		for(int j=C1;j<=C2;j++) cout<<_solve(S,i,j);
		cout<<'\n';
	}
}

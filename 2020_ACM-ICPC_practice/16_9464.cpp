#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>

using namespace std;

int T,L;
int v[2100];

int _gcd(int a,int b){
	if(b==0) return a;
	return _gcd(b,a%b);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int cnt=0;
	for(int i=2;i<=100;i++)
		for(int j=i-1;j>0;j-=2)
			if(_gcd(i,j)==1){
				int a=2*i*j,b=i*i-j*j;
				if(_gcd(a,b)==1)
					v[cnt++]=2*(a+b);
			}
	sort(v,v+cnt);
	
	int sum=0;
	for(int i=0;i<cnt;i++){
		sum+=v[i];
		cout<<i<<"+"<<v[i]<<"="<<sum<<'\n';
	}
	cin>>T;
	while(T--){
		int ans=0;
		cin>>L;
		
		int i=0;
		while(L>=v[i]){
			L-=v[i++];
			ans++;
		}
		
		cout<<ans<<'\n';
	}
}

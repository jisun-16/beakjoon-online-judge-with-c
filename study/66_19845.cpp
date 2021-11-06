#include<iostream>
using namespace std;
int N,Q,num[250001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>Q;
	for(int i=1;i<=N;++i)
		cin>>num[i];
	while(Q--){
		int x,y;
		cin>>x>>y;
		if(num[y]<x){
			cout<<0<<'\n';
			continue;
		}
		int l=y,r=N;
		while(l<r){
			int mid=(l+r+1)/2;
			if(num[mid]>=x) l=mid;
			else r=mid-1;
		}
		cout<<(num[y]-x+1+l-y)<<'\n';
	}
}

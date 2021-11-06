#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,deg[200001]={0,},leaf=0;
	cin>>n;
	for(int i=0;i<n-1;++i){
		int a,b;
		cin>>a>>b;
		deg[a]++;
		deg[b]++;
	}
	for(int i=0;i<n;++i) 
		if(deg[i]==1) leaf++;
	cout<<(leaf/2+leaf%2)<<'\n';
}

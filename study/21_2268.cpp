#include<iostream>
#include<algorithm>

using namespace std;

long long n,m,arr[1000001],fen[1000001];

long long _sum(int i){
	long long ret=0;
	while(i){
		ret+=fen[i];
		i-=-i&i;
	}
	
	return ret;
}

void _modify(int i,long long num){
	while(i<=n){
		fen[i]+=num;
		i+=-i&i;
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		
		
		if(a==0){
			if(b>c) swap(b,c);
			cout<<_sum(c)-_sum(b-1)<<'\n';
		}
		else{
			_modify(b,c-arr[b]);
			arr[b]=c;
		}
	}
}

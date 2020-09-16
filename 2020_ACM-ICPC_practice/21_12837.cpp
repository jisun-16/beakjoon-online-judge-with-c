#include<iostream>
#include<algorithm>

using namespace std;

int n,q;
long long fen[1000001];

long long _sum(int i){
	long long ret=0;
	while(i){
		ret+=fen[i];
		i-=-i&i;
	}
	
	return ret;
}

void _update(int i,long long num){
	while(i<=n){
		fen[i]+=num;
		i+=-i&i;
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	for(int i=0;i<q;i++){
		int a,b,c;
		cin>>a>>b>>c;
		
		if(a==1)
			_update(b,c);
		else
			cout<<_sum(c)-_sum(b-1)<<'\n';
	}
}

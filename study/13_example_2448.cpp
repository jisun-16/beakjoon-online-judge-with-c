#include<iostream>
#include<algorithm>

using namespace std;

int n;
int map[3072][10000];

void _solve(int x,int y,int t){
	int s=t-1,e=t-1;
	for(int i=0;i<t;i++){
		for(int j=0;j<t*2;j++){
			if(j>=s&&j<=e) map[x+i][y+j]=1;	
			else map[x+i][y+j]=0;
		}
		s--;e++;
	}
	if(t>3){
		_solve(x,y+t/2,t/2);
		_solve(x+t/2,y,t/2);
		_solve(x+t/2,y+t,t/2);
	}
	else if(t==3){
		map[x+1][y+2]=0;
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	_solve(0,0,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n*2+1;j++){
			if(map[i][j]) cout<<"*";
			else cout<<" ";
		}
		cout<<'\n';
	}
}

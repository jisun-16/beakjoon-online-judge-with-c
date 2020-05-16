#include<iostream>
#include<algorithm>

using namespace std;

int n, m, paper[4][4], ans=0;
bool rowcol[4][4] ={false}; //true - 세로 false-가로 

int _sum(){
	int temp=0;
	for(int i=0;i<n;i++){
		int p=1;//10^n
		for(int j=m-1;j>=0;j--){
			if(!rowcol[i][j]){
				temp+=paper[i][j]*p;
				p*=10;
			}
			else p=1;
		}
	}
	
	for(int j=0;j<m;j++){
		int p=1;//10^n
		for(int i=n-1;i>=0;i--){
			if(rowcol[i][j]){
				temp+=paper[i][j]*p;
				p*=10;
			}
			else p=1;
		}
	}
	
	return temp;
}

void _dfs(int pt){
	if(pt<=n*m){
		int temp=_sum();
		ans=max(temp,ans);
	}
	for(int i=pt;i<n*m;i++){
		rowcol[i/m][i%m]=true;
		_dfs(i+1);
		rowcol[i/m][i%m]=false;
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) scanf("%1d",&paper[i][j]);
	}
	
	_dfs(0);
	
	cout<<ans<<'\n';
}

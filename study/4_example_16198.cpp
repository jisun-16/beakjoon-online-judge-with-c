#include<iostream>
#include<algorithm>

using namespace std;

int n, ans=0, wei[11]={0};
bool ex[11]={0};

void _energy(int cnt, int sum){
	if(cnt==2){
		ans=max(ans,sum);
		return;
	}
	
	pair<int,int> temp[11];
	int x=0;
	
	for(int j=0;j<n;j++){
		if(!ex[j]){
			temp[x].first=wei[j];
			temp[x++].second=j;
		}
	}
	
	for(int i=1;i<cnt-1;i++){
		ex[temp[i].second]=true;
		_energy(cnt-1,sum+temp[i-1].first*temp[i+1].first);
		ex[temp[i].second]=false;
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>wei[i];
	_energy(n,0);
	cout<<ans<<'\n';
}

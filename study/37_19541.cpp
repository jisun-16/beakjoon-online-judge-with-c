#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,m;
vector<vector<int> > v;
bool init[100001],fin[100001];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int k,i=0;i<m;++i){
		cin>>k;
		vector<int> arr(k);
		for(int j=0;j<k;++j) cin>>arr[j];
		v.push_back(arr);
	}
	for(int i=1;i<=n;++i) cin>>fin[i],init[i]=fin[i];
	
	for(int i=m-1;i>=0;--i){
		bool chk=false;
		//비감염자가 있다면 감염집단 아님 
		for(int j=0;j<v[i].size();++j)
			if(!init[v[i][j]]){
				chk=true;
				break;
			} 
		if(chk){
			for(int j=0;j<v[i].size();++j)
				init[v[i][j]]=false;
		}
	}
	
	bool arr[100001]={0,};
	for(int i=1;i<=n;++i) arr[i]=init[i];
	
	for(int i=0;i<m;++i){
		bool chk=false;
		for(int j=0;j<v[i].size();++j)
			if(arr[v[i][j]]) {
				chk=true;
				break;
			}
		if(chk){
			for(int j=0;j<v[i].size();++j)
				arr[v[i][j]]=true;
		}
	}
	
	bool yes=true;
	for(int i=1;i<=n;++i) 
		if(arr[i]!=fin[i]) {
			yes=false;
			break;
		}
	
	if(yes){
		cout<<"YES\n";
		for(int i=1;i<=n;++i) cout<<init[i]<<' ';
	}
	else
		cout<<"NO\n";
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n,m;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m;
	
	vector<vector<int> > meeting(m);
	vector<int> befo(n),after(n),ans(n);
	for(int i=0;i<m;i++){
		int k;
		cin>>k;
		while(k--){
			int temp;
			cin>>temp;
			meeting[i].push_back(--temp);
		}
	}
	
	for(int i=0;i<n;i++) {
		cin>>after[i];
	}
	befo=after;
	
	for(int i=m-1;i>=0;i--){
		int s=meeting[i].size();
		bool chk=false;
		for(int j=0;j<s;j++)
			if(!befo[meeting[i][j]]){
				chk=true;
				break;
			}
		
		if(chk){
			for(int j=0;j<s;j++){
				befo[meeting[i][j]]=0;
			}
		}
	}
	
	ans=befo;
	
	for(int i=0;i<m;i++){
		int s=meeting[i].size();
		bool chk=false;
		for(int j=0;j<s;j++)
			if(befo[meeting[i][j]]){
				chk=true;
				break;
			}
		
		if(chk){
			for(int j=0;j<s;j++){
				befo[meeting[i][j]]=1;
			}
		}
	}
	
	int i;
	for(i=0;i<n;i++) {
		if(after[i]!=befo[i]) break;
	}
	
	if(i==n){
		cout<<"YES\n";
		for(int j=0;j<n;j++) cout<<ans[j]<<' ';
		cout<<'\n';
	}
	else cout<<"NO\n";
}

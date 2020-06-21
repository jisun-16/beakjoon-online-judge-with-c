#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		bool avail=true;
		int n,m;
		
		cin>>n>>m;
		
		set<int> sunny;
		vector<int> ans(m+1,-1);
		vector<int> index(m+1,-1);
				
		for(int i=1;i<=m;i++){
			int rain;
			cin>>rain;
			
			if(!avail) continue;
			
			if(!rain){
				ans[i]=0;
				sunny.insert(i);
			}
			else{
				set<int>::iterator x=sunny.upper_bound(index[rain]);
				if(x==sunny.end()){
					avail=false;
					continue;
				}
				
				ans[*x]=rain;
				index[rain]=i;
				sunny.erase(x);
			}
		}
		
		if(avail){
			cout<<"YES"<<'\n';
			for(int i=1;i<=m;i++) 
				if(ans[i]!=-1)
					cout<<ans[i]<<' ';
			cout<<'\n';
		}
		else
			cout<<"NO"<<'\n';
	}
}

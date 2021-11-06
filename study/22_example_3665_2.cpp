#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		int n,m;
		int r[501]={0,},chg[501]={0,};
		
		cin>>n;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			r[a]=i;
		}
		cin>>m;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			if(r[a]>r[b]){
				swap(a,b);
			}
			chg[a]++;chg[b]--;
		}
		
		for(int i=1;i<=n;i++)
			r[i]+=chg[i];
		
		bool chk=false;
		for(int i=1;i<=n;i++){
			chk=false;
			for(int j=1;j<=n;j++)
				if(r[j]==i){
					chk=true;
					break;
				}
			if(!chk) {
				cout<<"IMPOSSIBLE";
				break;
			}
		}
		
		if(chk){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)
					if(r[j]==i){
						cout<<j<<' ';
						break;
					}
			}
		}
		
		cout<<'\n';
	}
}

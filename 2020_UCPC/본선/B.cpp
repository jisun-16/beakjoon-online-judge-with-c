#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int n,m,k;
string row[26],map;
long long ans;

int main(){
	
	cin>>n>>m>>k;
	for(int i=0;i<k;i++) cin>>row[i];
	cin>>map;

	int s=0,e=m-1;
	int now=map[n-1]-'A';
	for(int i=m-2;i>=0;i--)
		if(row[now][i]=='U'){
			s=i+1;
			break;
		}
	
	ans+=(long long)e-s+1;
	
	for(int i=n-2;i>=0;i--){
		//cout<<s<<' '<<e<<'\n';
		bool chk=false;
		now=map[i]-'A';
		for(int j=e;j>=s;j--)
			if(row[now][j]=='U'){
				chk=true;
				e=j;
				break;
			}
		
		if(!chk) break;
		
		for(int j=s-1;j>=0;j--)
			if(row[now][j]=='U'){
				chk=false;
				s=j+1;
				break;
			}
		if(chk) s=0;
		
		ans+=(long long)e-s+1;
	}
	
	cout<<ans<<'\n';
}

#include<iostream>
#include<algorithm>

using namespace std;

int n;
pair<int,int> p[600001];
int x[300001],y[300001];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		p[i]={x[i],-1};//시작점 
		p[i+n]={y[i],1};//끝 
	}
	
	sort(p,p+2*n);
	
	int ans=0,temp=0,chk=0;
	for(int i=0;i<2*n;i++){
		if(p[i].second<0) temp++;
		else temp--;
		
		if(ans<temp){
			ans=temp;
			chk=p[i].first;
		}
	}
	
	cout<<ans<<'\n';
	for(int i=0;i<n;i++) 
		if(x[i]<=chk&&chk<=y[i]) cout<<i+1<<' ';
	cout<<'\n';
}

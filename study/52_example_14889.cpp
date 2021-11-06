#include<iostream>
#include<cmath>
using namespace std;
int n,s[21][21],ans=987654321;
bool teamA[21];
void calc(){
	int sumA=0,sumB=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(teamA[i]&&teamA[j]) sumA+=s[i][j];
			else if(!teamA[i]&&!teamA[j]) sumB+=s[i][j];
	if(abs(sumA-sumB)<ans) ans=abs(sumA-sumB);
}
void perm(int cnt,int idx){
	if(cnt==n/2) {
		calc();
		return;
	}
	for(int i=idx+1;i<=n;++i){
		if(teamA[i]) continue;
		teamA[i]=true;
		perm(cnt+1,i);
		teamA[i]=false;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j) cin>>s[i][j];
	perm(0,0);
	cout<<ans<<'\n';
}

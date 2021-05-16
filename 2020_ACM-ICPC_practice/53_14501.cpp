#include<iostream>
#include<algorithm>
using namespace std;
int n,T[16],P[16],ans;
bool chk[16];
void dfs(int now,int sum){
	if(now>n+1) return;
	if(ans<sum) ans=sum;
	for(int i=now;i<=n;++i){
		dfs(i+T[i],sum+P[i]);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>T[i]>>P[i];
	dfs(1,0);
	cout<<ans<<'\n';
}

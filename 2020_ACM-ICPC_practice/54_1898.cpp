#include<iostream>
#include<algorithm>
using namespace std;
int n,S[50001],ans[50001];
bool chk[50001],fin;
void dfs(int idx){
	if(fin) return;
	if(idx==n){
		for(int i=0;i<n;++i) cout<<ans[i]<<'\n';
		fin=true;
		return;
	}
	if(S[idx]!=1&&!chk[S[idx]-1]){
		ans[idx]=S[idx]-1;
		chk[S[idx]-1]=true;
		dfs(idx+1);
		chk[S[idx]-1]=false;
	}
	if(!chk[S[idx]]){
		ans[idx]=S[idx];
		chk[S[idx]]=true;
		dfs(idx+1);
		chk[S[idx]]=false;
	}
	if(S[idx]!=n&&!chk[S[idx]+1]){
		ans[idx]=S[idx]+1;
		chk[S[idx]+1]=true;
		dfs(idx+1);
		chk[S[idx]+1]=false;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i) cin>>S[i];
	dfs(0);
}

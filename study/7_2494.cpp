#include<iostream>
#include<algorithm>
#include<cstring>

#define inf 2100000000

using namespace std;

int n, now[10001], des[10001], dp[10001][10], ans[10001][10];

int _solve(int idx, int tt){
	if(idx==n) return 0;
	
	int& ret=dp[idx][tt];
	if(ret!=-1) return ret;
	
	int cur=(now[idx]+tt)%10;
	
	//left
	int ll=(des[idx]-cur+10)%10;
	int c1=_solve(idx+1,(tt+ll)%10)+ll;
	
	//right
	int rr=(cur-des[idx]+10)%10;
	int c2=_solve(idx+1,tt)+rr;
	
	if(c1<c2){
		ret=c1;
		ans[idx][tt]=ll;
	}
	else{
		ret=c2;
		ans[idx][tt]=-rr;
	}
	
	return ret;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++) scanf("%1d",&now[i]);
	for(int i=0;i<n;i++) scanf("%1d",&des[i]);
	
	memset(dp,-1,sizeof(dp));
	
	cout<<_solve(0,0)<<'\n';
	
	int k=0;
	for(int i=0;i<n;i++){
		cout<<i+1<<' '<<ans[i][k]<<'\n';
		if(ans[i][k]>0) k=(k+ans[i][k]+10)%10;
	}
}

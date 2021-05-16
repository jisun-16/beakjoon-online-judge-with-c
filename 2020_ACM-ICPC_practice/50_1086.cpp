#include<iostream>
#include<algorithm>
#include<string>
typedef long long ll;
using namespace std;
ll dp[1<<15][100],u,d=1;
int n,k,len[15],mod[15],tmod[51];
string num[15];
ll gcd(ll a,ll b){
	if(a<b) swap(a,b);
	return b==0?a:gcd(b,a%b);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>num[i];
		len[i]=num[i].length();
		d*=(i+1);
	}
	cin>>k;
	//숫자의 모듈러 연산 
	for(int i=0;i<n;++i)
		for(int j=0;j<len[i];++j)
			mod[i]=(mod[i]*10+(num[i][j]-'0'))%k;
	//10^n의 모듈러 연산 
	for(int i=0;i<=50;++i){
		if(i==0) tmod[i]=1;
		else tmod[i]=(tmod[i-1]*10)%k;
	}
	//dp-bitmask
	dp[0][0]=1;
	for(int i=0;i<(1<<n);++i)
		for(int j=0;j<n;++j){
			if(i&(1<<j)) continue;
			int temp=i|(1<<j);
			for(int l=0;l<k;++l)
				dp[temp][((l*tmod[len[j]])%k+mod[j])%k]+=dp[i][l];
		}
	u=dp[(1<<n)-1][0];
	ll g=gcd(d,u);
	cout<<(u/g)<<"/"<<(d/g)<<'\n';
}

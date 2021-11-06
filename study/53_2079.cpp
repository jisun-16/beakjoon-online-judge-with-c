#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s;
int dp[2001],L;
bool pal[2001][2001];
int main(){
	cin>>s;
	L=s.length();
	for(int i=0;i<L;++i) pal[i][i]=true;
	for(int i=0;i<L-1;++i)
		if(s[i]==s[i+1]) 
			pal[i][i+1]=true;
	for(int l=2;l<L;++l)
		for(int i=0;i<L-l;++i)
			if(s[i]==s[i+l]&&pal[i+1][i+l-1])
				pal[i][i+l]=true;
	dp[0]=1;
	for(int i=1;i<L;++i){
		dp[i]=pal[0][i]?1:dp[i-1]+1;
		for(int j=1;j<=i;++j){
			if(pal[j][i])
				dp[i]=min(dp[i],dp[j-1]+1);
		}
	}
	cout<<dp[L-1]<<'\n';
}

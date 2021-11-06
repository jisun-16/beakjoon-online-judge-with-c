#include<iostream>
#define mod 1000000007

using namespace std;

int n, l, r;
long long dp[101][101][101];

int main(){
	cin>>n>>l>>r;
	
	//���� ���� �ǹ��� ����/������/�߰��� �߰��Ѵ� 
	dp[1][1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=l;j++){
			for(int k=1;k<=r;k++){
				dp[i][j][k]=dp[i-1][j-1][k]+dp[i-1][j][k-1]+(i-2)*dp[i-1][j][k];
				dp[i][j][k]%=mod;
			}
		}
	}
	
	cout<<dp[n][l][r]<<'\n';
}

#include<iostream>
#include<algorithm>
#include<vector>

typedef long long ll;
using namespace std;

const int mod=1000000007;
int n;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	vector<int> sco(n);
	for(int i=0;i<n;i++) cin>>sco[i];
	
	sort(sco.begin(),sco.end());
	
	vector<ll> pow(n);
	pow[0]=1;
	for(int i=1;i<n;i++)
		pow[i]=2*pow[i-1]%mod;
	
	long long ans=0;
	//i번째 지수가 최댓값인 경우+최솟값인 경우
	//2^(i) - 2^(n-i-1) * sco[i]
	for(int i=0;i<n;i++){
		ans=(ans+(pow[i]-pow[n-i-1]+mod)%mod*sco[i])%mod;
	}
	
	cout<<ans<<'\n';
}

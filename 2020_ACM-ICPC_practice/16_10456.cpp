#include<iostream>
#include<cstring>
#include<algorithm> 

using namespace std;

int T,N;
int tr[10060],dp[10060];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>T;
	while(T--){
		for(int i=0;i<10060;i++) dp[i]=0;
		
		int tr7=0,tr30=0;
		
		cin>>N;
		for(int i=30;i<=N+60;i++){
			int a,b;
			if(i<N+30) cin>>a>>b;
			else a=b=0;
			
			tr[i]=b;
			tr7-=2*tr[i-7];
			tr7+=2*b;
			
			tr30=0;
			int chk=0,chk2=0;
			for(int j=i-29;j<=i;j++){
				if(tr[j]>3){
					tr30+=6;
					chk++;
					if(chk%7==0) chk2++;
				}
				else{
					tr30+=2*tr[j];
					chk=0;
				}
			}
			tr30-=6*chk2;
			
			//1일권,7일권,30일권을 구매할때의 최소값 
			dp[i]=dp[i-1]+min(a+2*b,min(3+2*b,6));
			dp[i]=min(dp[i],min(dp[i-7]+18+tr7,dp[i-7]+36));
			dp[i]=min(dp[i],min(dp[i-30]+45+tr30,dp[i-30]+90));
		}
		
		cout<<dp[N+30-1]<<'\n';
	}
}

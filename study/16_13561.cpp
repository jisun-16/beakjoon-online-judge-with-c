#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int inf=2000000000;

int k,n,chk[100001],cnt;
pair<int,int> loc[1000000];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>k>>n;
	for(int i=0;i<n;i++){
		int ll,kk;
		cin>>ll>>kk;
		loc[i]={ll,kk};
	}
	sort(loc,loc+n);
	
	int s=0,e=0,ans=inf,d=inf;
	while(e<n){
		if(chk[loc[e].second]==0) cnt++;
		chk[loc[e].second]++;
		
		while(cnt==k){
			int temp=loc[e].first-loc[s].first+1;
			if(temp<0) temp=temp/2-1;
			else temp/=2;
			
			if(temp<d){
				d=temp;
				ans=loc[e].first-temp;
			}
			
			chk[loc[s].second]--;
			if(chk[loc[s].second]==0) cnt--;
			s++;
		}
		
		e++;
	}
	
	cout<<ans<<'\n';
}

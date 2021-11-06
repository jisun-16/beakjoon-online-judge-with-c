#include<iostream>
#include<algorithm>

using namespace std;

int n, k, elec[101], e_cnt[101], cnt, ans;
bool plu[101];

int main(){
	cin>>n>>k;
	for(int i=0;i<k;i++){
		cin>>elec[i];
		e_cnt[elec[i]]++;
	}
	
	for(int i=0;i<k;i++){
		if(plu[elec[i]]){
			e_cnt[elec[i]]--;
			continue;
		}//이미 꽂혀있는 경우 
		
		if(cnt<n){
			plu[elec[i]]=true;
			e_cnt[elec[i]]--;
			cnt++;
			continue;
		}//빈 플러그가 있는 경우
		
		int p=-1;
		for(int j=0;j<i;j++){
			if(plu[elec[j]]&&!e_cnt[elec[j]])
				p=j;
		}//다 쓴 기기가 있는 경우 
		
		if(p<0){
			int last[101]={0};
			for(int j=i;j<k;j++){
				if(!last[elec[j]]){
					last[elec[j]]=j;
				}
			}
			
			for(int j=0;j<k;j++){
				if(plu[elec[j]])
					p=max(p,last[elec[j]]);
			}
		}
		
		ans++;
		plu[elec[p]]=false;
		plu[elec[i]]=true;
		e_cnt[elec[i]]--;
	}
	
	cout<<ans<<'\n';
}

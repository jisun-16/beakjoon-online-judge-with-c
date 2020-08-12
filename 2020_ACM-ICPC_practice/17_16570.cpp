#include<iostream>
#include<algorithm>

using namespace std;

int n,arr[1000001],cnt[1000001];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	
	int len=0;
	for(int i=n-2;i>=0;i--){
		int temp=0;
		int l=i,r=n-1;
		while(arr[l]==arr[r]){
			l--;r--;
			temp++;
			if(l<0) break;
		}
		if(temp>len){
			len=temp;
			cnt[len]++;
		}
		else if(temp==len)
			cnt[len]++;
	}
	
	if(len==0) cout<<-1<<'\n';
	else cout<<len<<' '<<cnt[len]<<'\n';
	
	return 0;
}

#include<iostream>
#include<algorithm>

using namespace std;

int n,lis[100001],tr[500001];
bool chk[500001];
pair<int,int> arr[100001];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
	sort(arr,arr+n);
	
	int cnt=0;
	for(int i=0;i<n;i++){
		int x=lower_bound(lis,lis+cnt,arr[i].second)-lis;
		if(x==cnt) cnt++;
		lis[x]=arr[i].second;
		tr[lis[x]]=x?lis[x-1]:0;
	}
	
	int i=lis[cnt-1];
	while(i){
		chk[i]=true;
		i=tr[i];
	}
	
	cout<<n-cnt<<'\n';
	for(int i=0;i<n;i++)
		if(!chk[arr[i].second]) cout<<arr[i].first<<'\n';
}

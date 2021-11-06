#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,arr[2001],ans=1;
vector<int> arr2;
bool chk[2001][2001];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	
	int du=arr[0],cnt=1;
	arr2.push_back(arr[0]);
	for(int i=1;i<n;i++){
		if(arr[i]==du) cnt++;
		else{
			du=arr[i];
			cnt=1;
			arr2.push_back(arr[i]);
		}
		ans=max(ans,cnt);
	}
	
	for(int i=0;i<arr2.size();i++){
		for(int j=i+1;j<arr2.size();j++){
			if(chk[i][j]) continue;
			
			chk[i][j]=true;
			
			int cnt=2;
			int diff=arr2[j]-arr2[i];
			int val=arr2[j]+diff;
			int bef=j;
			while(true){
				int idx=lower_bound(arr2.begin(),arr2.end(),val)-arr2.begin();
				if(arr2[idx]!=val) break;
				
				cnt++;
				val+=diff;
				chk[bef][idx]=true;
				bef=idx;
			}
			
			ans=max(ans,cnt);
		}
	}
	
	cout<<ans<<'\n';
}

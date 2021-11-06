#include<iostream>
#include<vector>
using namespace std;

int n,arr[1000001],tr[1000001]={1},ans[1000001];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	vector<int> v;
	v.push_back(arr[0]);
	for(int i=1;i<n;i++){
		if(v[v.size()-1]<arr[i]){
			v.push_back(arr[i]);
			tr[i]=v.size();
		}
		else{
			int temp=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
			v[temp]=arr[i];
			tr[i]=temp+1;
		}
	}
	
	cout<<v.size()<<'\n';
	int idx=v.size();
	for(int i=n-1;i>=0;i--){
		if(tr[i]==idx) ans[--idx]=arr[i];
	}
	for(int i=0;i<v.size();i++) cout<<ans[i]<<' ';
}

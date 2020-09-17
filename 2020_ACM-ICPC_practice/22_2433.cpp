#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>

using namespace std;

int n,m,c;
int arr[1000001]={0,};
vector<int> ans;
deque<pair<int,int>> mx,mn;
	
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++) cin>>arr[i];
	
	for(int i=1;i<=m-1;i++){
		while(!mx.empty()&&mx.front().first<arr[i])
			mx.pop_front();
		while(!mx.empty()&&mx.back().first<arr[i])
			mx.pop_back();
		mx.push_back({arr[i],i});
		
		while(!mn.empty()&&mn.front().first>arr[i])
			mn.pop_front();
		while(!mn.empty()&&mn.back().first>arr[i])
			mn.pop_back();
		mn.push_back({arr[i],i});
	}
	
	if(n<m&&mx.front().first-mn.front().first<=c)
		ans.push_back(1);
	
	for(int i=m;i<=n;i++){
		while(!mx.empty()&&(mx.front().first<arr[i]||mx.front().second<i-m+1))
			mx.pop_front();
		while(!mx.empty()&&mx.back().first<arr[i])
			mx.pop_back();
		mx.push_back({arr[i],i});
		
		while(!mn.empty()&&(mn.front().first>arr[i]||mn.front().second<i-m+1))
			mn.pop_front();
		while(!mn.empty()&&mn.back().first>arr[i])
			mn.pop_back();
		mn.push_back({arr[i],i});
		
		if(mx.front().first-mn.front().first<=c) 
			ans.push_back(i-m+1);
	}
	
	if(ans.size()==0) cout<<"NONE"<<'\n';
	else {
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<'\n';
	}
}

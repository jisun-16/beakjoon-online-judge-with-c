#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<pair<int,int> > arr;
vector<int> ans;

bool cmp(const pair<int,int> a, const pair<int,int> b){
	if(a.first==b.first) return a.second>b.second;
	return a.first<b.first;
}

bool cmp2(const int a,const int b){
	return a>=b;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		arr.push_back({b,c});
	}
	
	sort(arr.begin(),arr.end(),cmp);
	arr.erase(unique(arr.begin(),arr.end()),arr.end());
	
	ans.push_back(arr[0].second);
	for(int i=1;i<arr.size();i++){
		int now=arr[i].second;
		auto it=lower_bound(ans.begin(),ans.end(),now,cmp2);
		if(it==ans.end()) ans.push_back(now);
		else *it=now;
	}
	
	cout<<ans.size()<<'\n';
}

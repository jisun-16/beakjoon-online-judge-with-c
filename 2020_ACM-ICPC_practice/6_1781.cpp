#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n;
pair<int, int> cup[200001];

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.first<b.first) return true;
	else if(a.first==b.first) return a.second>b.second;
	
	return false;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cup[i].first>>cup[i].second;
	}
	
	sort(cup,cup+n,cmp);
	
	priority_queue<int> pq;
	int ans=0;
	for(int i=0;i<n;i++){
		pq.push(-cup[i].second);
		while(cup[i].first<pq.size()) pq.pop();
	}
	while(!pq.empty()){
		ans-=pq.top();
		pq.pop();
	}
	
	cout<<ans<<'\n';
}

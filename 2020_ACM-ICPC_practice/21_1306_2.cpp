#include<iostream>
#include<deque>

using namespace std;

int n,m,arr[1000001];
deque<pair<int,int> > dq;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>arr[i];
	
	for(int i=0;i<2*m-2;i++){
		while(!dq.empty()&&dq.front().first<arr[i])
			dq.pop_front();
		while(!dq.empty()&&dq.back().first<arr[i])
			dq.pop_back();
		dq.push_back({arr[i],i});
	}
	
	for(int i=2*m-2;i<n;i++){
		while(!dq.empty()&&(dq.front().first<arr[i]||dq.front().second<i-m*2+2))
			dq.pop_front();
		while(!dq.empty()&&dq.back().first<arr[i])
			dq.pop_back();
		dq.push_back({arr[i],i});
		cout<<dq.front().first<<' ';
	}
}

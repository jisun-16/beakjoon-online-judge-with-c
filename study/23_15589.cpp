#include<iostream>
#include<algorithm>
#include<vector>

#define x first
#define y second

using namespace std;

int main(){
	ios::sync_with_stdio(0);cout.tie(0);cout.tie(0);
	
	int n;
	cin>>n;
	
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
	
	v.push_back({-1,-1});
	v.push_back({1000000001,1000000001});
	sort(v.begin(),v.end());
	
	int all=0;
	int s=v[1].x,e=v[1].y;
	for(int i=2;i<=n;i++){
		if(v[i].x<=e)
			e=max(e,v[i].y);
		else{
			all+=e-s;
			s=v[i].x;
			e=v[i].y;
		}
	}
	all+=e-s;
	
	int min_covered=1000000001,max_r=-1;
	for(int i=1;i<=n;i++){
		if(v[i].y<=max_r){
			min_covered=0;
			break;
		}
		int l=max(v[i-1].y,v[i].x);
		int r=min(v[i].y,v[i+1].x);
		int area=max(0,r-l);
		min_covered=min(min_covered,area);
		max_r=max(max_r,v[i].y);
	}
	
	cout<<all-min_covered<<'\n';
}

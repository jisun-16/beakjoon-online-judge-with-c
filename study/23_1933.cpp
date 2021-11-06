#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

#define x first
#define y second

int n;
vector<pair<int,int>> v;
multiset<int> s;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin>>n;
	for(int i=0;i<n;i++) {
		int l,r,hei;
		cin>>l>>hei>>r;
		v.push_back({l,hei});
		v.push_back({r,-hei});
	}
	
	sort(v.begin(),v.end());
	
	s.insert(0);
	int px=v[0].x,py=-1;
	int i=0;
	while(i<n*2){
		while(px==v[i].x){
			int x=v[i].x,h=v[i].y;
			if(h<0) s.erase(s.find(-h));
			else s.insert(h);
			i++;
		}
		
		int val=*prev(s.end());
		if(val!=py){
			cout<<px<<' '<<*prev(s.end())<<' ';
			py=val;
		}
		px=v[i].x;
	}
}

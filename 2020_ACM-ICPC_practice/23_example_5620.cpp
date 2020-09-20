#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>

#define x first
#define y second

using namespace std;

const int inf=1<<30;
int n;
pair<int,int> coor[100001];
set<pair<int,int>> s;

double dist(pair<int,int> a,pair<int,int> b){
	return (double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){
	ios::sync_with_stdio(0);cout.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>coor[i].x>>coor[i].y;
	
	sort(coor,coor+n);
	s.insert({coor[0].y,coor[0].x});
	s.insert({coor[1].y,coor[1].x});
	
	double ans=dist(coor[0],coor[1]);
	int idx=0;
	for(int i=2;i<n;i++){
		while(idx<i){
			int d=coor[i].x-coor[idx].x;
			if(d*d<=ans) break;
			else{
				s.erase({coor[idx].y,coor[idx].x});
				idx++;
			}
		}
		
		double limit=sqrt(ans);
		auto end=s.upper_bound({coor[i].y+limit,inf});
		for(auto it=s.lower_bound({coor[i].y-limit,-inf});it!=end;++it)
			ans=min(ans,dist({it->y,it->x},coor[i]));
		s.insert({coor[i].y,coor[i].x});
	}
	
	cout<<(int)ans<<'\n';
}

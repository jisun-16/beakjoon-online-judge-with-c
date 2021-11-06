#include<iostream>
#include<algorithm>
#include<queue>

#define x first
#define y second

using namespace std;

int n,h_cnt,v_cnt,ans;
pair<int,int> s,l,h[50001],v[50001];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n;
	
	cin>>s.x>>s.y;
	l=s;
	
	for(int i=1;i<n;i++){
		pair<int,int> now;
		cin>>now.x>>now.y;
		
		if(l.x==now.x) h[h_cnt++]={min(l.y,now.y),max(l.y,now.y)};
		else v[v_cnt++]={min(l.x,now.x),max(l.x,now.x)};
		
		l=now;	
	}
	
	if(l.x==s.x) h[h_cnt++]={min(l.y,s.y),max(l.y,s.y)};
	else v[v_cnt++]={min(l.x,s.x),max(l.x,s.x)};
	
	sort(h,h+h_cnt);
	sort(v,v+v_cnt);
	
	priority_queue<int> pq;
	for(int i=0;i<h_cnt;i++){
		pair<int,int> now=h[i];
		while(!pq.empty()&&(-pq.top()<=now.x))
			pq.pop();
		pq.push(-now.y);
		
		ans=max(ans,(int)pq.size());
	}
	
	pq=priority_queue<int>();
	for(int i=0;i<v_cnt;i++){
		pair<int,int> now=v[i];
		while(!pq.empty()&&(-pq.top()<=now.x))
			pq.pop();
		pq.push(-now.y);
		
		ans=max(ans,(int)pq.size());
	}
	
	cout<<ans<<'\n';
}

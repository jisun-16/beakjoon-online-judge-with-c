#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int n,r,bx,by,bvx,bvy,ans=0;
	cin>>n>>r>>bx>>by>>bvx>>bvy;
	
	pair<double,double> p[50000];
	int cnt=0;
	for(int i=0;i<n;i++){
		int x,y,vx,vy;
		cin>>x>>y>>vx>>vy;
		
		int dvx=vx-bvx,dvy=vy-bvy,dx=x-bx,dy=y-by;
		int a=dvx*dvx+dvy*dvy;
		int b=2*(dvx*dx+dvy*dy);
		int c=dx*dx+dy*dy-r*r;
		
		if(a==0){
			if(b==0) ans+=(c<=0);
			else if((long long)b*c>=0) p[cnt++]={0.0,-1.0*c/b};
		}
		else{
			long long d=(long long)b*b-(long long)4*a*c;
			if(d>=0){
				double t1=(-b-sqrt(d))/2/a,t2=(-b+sqrt(d))/2/a;
				if(t2>=0) p[cnt++]={max(0.0,t1),t2};
			}
		}
	}
	
	sort(p,p+cnt);
	
	int res=0;
	priority_queue<double,vector<double>,greater<double>> pq;
	for(int i=0;i<cnt;i++){
		pq.push(p[i].second);
		while(!pq.empty()&&pq.top()<p[i].first)
			pq.pop();
		res=max(res,(int)pq.size());
	}
	ans+=res;
	
	cout<<ans<<'\n';
}

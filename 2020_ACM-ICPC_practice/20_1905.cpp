#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct B{
	int x1,y1,x2,y2,h;
	B(int x1,int y1,int x2,int y2,int h):x1(x1),y1(y1),x2(x2),y2(y2),h(h){}
	bool operator<(const B &cmp){
		return h<cmp.h;
	}
};

int Lx,Ly,n,ans;
vector<B> box;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>Lx>>Ly>>n;
	for(int i=0;i<n;i++){
		int lx,ly,h,px,py;
		cin>>lx>>ly>>h>>px>>py;
		B temp=B(px,py,px+lx,py+ly,h);
		
		for(int j=i-1;j>=0;j--){
			if(temp.x1>=box[j].x2) continue;
			if(temp.y1>=box[j].y2) continue;
			if(temp.x2<=box[j].x1) continue;
			if(temp.y2<=box[j].y1) continue;
			
			temp.h+=box[j].h;
			break;
		}
		ans=max(ans,temp.h);
		
		box.insert(lower_bound(box.begin(),box.end(),temp),temp);
	}
	
	cout<<ans<<'\n';
}

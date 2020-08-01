#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node{
	int x1,y1,x2,y2;
	bool hori;
	node(){}
	node(int x1,int y1,int x2,int y2):x1(x1),y1(y1),x2(x2),y2(y2){
		if(x1==x2) hori=true;
		if(y1==y2) hori=false;
	}
};

const int inf=2e9;

int l,n;
int dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};//→↑←↓ 
pair<int,int> dir[1001];
vector<node> chk;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>l;
	cin>>n;
	
	if(n==0){
		cout<<l+1<<'\n';
		return 0;
	}
	
	for(int i=0;i<n;i++){
		char temp;
		cin>>dir[i].first>>temp;
		if(temp=='L') dir[i].second=1;
		else dir[i].second=-1;
	}
	dir[n]={inf,-1};
	
	chk.push_back(node(-l-1,-l-1,-l-1,l+1));
	chk.push_back(node(l+1,-l-1,l+1,l+1));
	chk.push_back(node(-l-1,-l-1,l+1,-l-1));
	chk.push_back(node(-l-1,l+1,l+1,l+1));
	
	int x=0,y=0,d=0;
	long long ans=0;
	for(int i=0;i<=n;i++){
		int temp=inf;
		//최대로 직진할 수 있는 시간  구하기 
		for(int j=0;j<chk.size();j++){
			if(chk[j].hori){
				if(d==0)
					if(x==chk[j].x1&&y<chk[j].y1)
						temp=min(temp,chk[j].y1-y);
				if(d==1)
					if(x>chk[j].x1&&y>=chk[j].y1&&y<=chk[j].y2)
						temp=min(temp,x-chk[j].x1);
				if(d==2)
					if(x==chk[j].x1&&y>chk[j].y2)
						temp=min(temp,y-chk[j].y2);
				if(d==3)
					if(x<chk[j].x1&&y>=chk[j].y1&&y<=chk[j].y2)
						temp=min(temp,chk[j].x1-x);
			}
			else{
				if(d==0)
					if(y<chk[j].y1&&x>=chk[j].x1&&x<=chk[j].x2)
						temp=min(temp,chk[j].y1-y);
				if(d==1)
					if(y==chk[j].y1&&x>chk[j].x2)
						temp=min(temp,x-chk[j].x2);
				if(d==2)
					if(y>chk[j].y1&&x>=chk[j].x1&&x<=chk[j].x2)
						temp=min(temp,y-chk[j].y1);
				if(d==3)
					if(y==chk[j].y1&&x<chk[j].x1)
						temp=min(temp,chk[j].x1-x);
			}
		}
		
		if(dir[i].first>=temp) {
			ans+=temp;
			break;
		}
		
		ans+=dir[i].first;
		int nx=x+dx[d]*dir[i].first,ny=y+dy[d]*dir[i].first;
		d+=dir[i].second+4;d%=4;
		
		chk.push_back(node(min(x,nx),min(y,ny),max(x,nx),max(y,ny)));
		
		x=nx;y=ny;
	}
	
	cout<<ans<<'\n';
}

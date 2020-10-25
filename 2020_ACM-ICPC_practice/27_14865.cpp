#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

#define x first
#define y second
#define pii pair<int,int>

using namespace std;

int n;
pii coor[1000000];
vector<pii> v;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>coor[i].x>>coor[i].y;
	
	int idx=1,state=0;
	for(int k=0;;k++){
		if(coor[k%n].y<0&&coor[(k+1)%n].y>0){
			for(int j=0;j<n;j++){
				int i=(k+j)%n;
				if((long long)coor[i].y*coor[(i+1)%n].y<0){
					v.push_back({coor[i].x,idx});
					state++;
					if(state%2==0)
						idx++;
				}
			}
			
			break;
		}
	}
	
	sort(v.begin(),v.end());
	
	int outm=0,inm=0;
	stack<pii> s;
	for(int i=0;i<v.size();i++){
		if(s.empty()){
			outm++;
			s.push({v[i].y,0});
		}
		else{
			if(s.top().x==v[i].y){
				if(s.top().y==0)
					inm++;
				s.pop();
			}
			else{
				s.top().y=1;
				s.push({v[i].y,0});
			}
		}
	}
	
	cout<<outm<<" "<<inm<<'\n';
}

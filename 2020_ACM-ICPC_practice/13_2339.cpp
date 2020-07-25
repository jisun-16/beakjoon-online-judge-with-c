#include<iostream>
#include<vector>
#include<algorithm> 

using namespace std;

int n,slate[21][21],ans;//0빈공간, 1불순물, 2보석 

int _solve(int x1,int y1,int x2,int y2,bool dir){
	int ret=0,imp=0,jem=0;
	
	for(int i=x1;i<=x2;i++){
		for(int j=y1;j<=y2;j++){
			if(slate[i][j]==1){
				imp++;
				if(dir)//가로 
					ret+=_solve(x1,y1,i-1,y2,!dir)*_solve(i+1,y1,x2,y2,!dir);
				else//세로 
					ret+=_solve(x1,y1,x2,j-1,!dir)*_solve(x1,j+1,x2,y2,!dir);
			}
			else if(slate[i][j]==2) jem++;
		}
	}
	
	if(imp==0) return (jem==1)?1:0;
	return ret;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>slate[i][j];
		}
	
	int x1=0,y1=0,x2=n-1,y2=n-1;
	int ans=_solve(x1,y1,x2,y2,true)+_solve(x1,y1,x2,y2,false);
	
	if(ans==0) cout<<-1<<'\n';
	else cout<<ans<<'\n';
}

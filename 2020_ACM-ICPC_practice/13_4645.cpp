#include<iostream>
#include<algorithm>

using namespace std;

int _solve(int n,int x1,int x2,int y,bool hori){
	if(x1>=x2||y==0||y==1<<n) return 0;
	
	int ret=0,N=1<<n,H=1<<(n-1);
	
	if(hori){
		if(n==1) return (x1==0)+(x2==2);
		if(y==H) return (x1==0)+(x2==N);
		
		if(x1<H&&x2>H){//양쪽에 걸쳐있음 
			if(y>H){//up
				if(H-x1>x2-H){//left>right
					ret+=_solve(n-1,x2-H,H-x1,y-H,false);
					ret+=2*_solve(n-1,0,x2-H,y-H,false);
				}
				else{//left<right
					ret+=_solve(n-1,H-x1,x2-H,N-y,false);
					ret+=2*_solve(n-1,0,H-x1,N-y,false);
				}
			}
			else{//down
				if(H-x1>x2-H){//left>right
					ret+=_solve(n-1,x1,N-x2,y,true);
					ret+=2*_solve(n-1,N-x2,H,y,true);
				}
				else{//left<right
					ret+=_solve(n-1,H-x1,x2-H,y,true);
					ret+=2*_solve(n-1,0,H-x1,y,true);
				}
			}
		}
		else{//한쪽으로 치우쳐있음
			if(y>H){//up
				if(x1<H)//left 
					ret+=_solve(n-1,H-x2,H-x1,y-H,false);
				else//right
					ret+=_solve(n-1,x1-H,x2-H,N-y,false);
			} 
			else{//down
				if(x1<H)//left
					ret+=_solve(n-1,x1,x2,y,true);
				else//right
					ret+=_solve(n-1,x1-H,x2-H,y,true);
			}
		} 
	}
	else{
		if(n==1) return (x1==0&&x2>=1);
		if(y==H) return (x1<H);
		
		//left
		if(y<H){
			if(x2>H)//up
				ret+=_solve(n-1,max(x1-H,0),x2-H,H-y,true);
			if(x1<H)//down
				ret+=_solve(n-1,x1,min(H,x2),y,false);
		}
		//right
		else{
			if(x2>H)//up
				ret+=_solve(n-1,N-x2,min(H,N-x1),y-H,true);
			if(x1<H)//down
				ret+=_solve(n-1,x1,min(H,x2),y-H,false);
		}
	}
	
	return ret;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	while(true){
		int n,x1,x2,y;
		cin>>n;
		if(n==0) break;
		cin>>x1>>x2>>y;
		cout<<_solve(n,x1,x2,y,true)<<'\n';
	}
}

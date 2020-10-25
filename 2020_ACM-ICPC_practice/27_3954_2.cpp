#include<bits/stdc++.h>

using namespace std;

int t,sm,sc,si,m,i,n;
unsigned char mem[100000];
string code, input;

int _solve(int x,int l){
	int y,a,num=0;
	
	if(l){
		y=x-1,a=1;
		while(a){
			y++;
			if(code[y]==']') a--;
			else if(code[y]=='[') a++;
		}
		
		if(!mem[m]){
			n=2;
			return y;
		}
	}
	else y=sc,num--;
	
	do{
		for(a=x,num++;a<y;a++,num++){
			switch(code[a]){
				case '-':{
					mem[m]--;
					break;
				}
				case '+':{
					mem[m]++;
					break;
				}
				case '<':{
					m=m?m-1:sm-1;
					break;
				}
				case '>':{
					m=m<sm-1?m+1:0;
					break;
				}
				case '[':{
					a=_solve(a+1,l+1);
					num+=n-1;
					break;
				}	
				case ',':{
					mem[m]=i<si?input[i++]:255;
					break;
				}
			}
			
			if(a<0) return -1;
		}
		
		if(num++>50000000){
			cout<<"Loops "<<x-1<<" "<<y<<'\n';
			return -1;
		}
	}while(l&&mem[m]);
	
	n=num;
	return y;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		cin>>sm>>sc>>si;
		cin>>code>>input;
		for(int i=0;i<sm;i++) mem[i]=0;
		m=i=0;
		n=_solve(0,0);
		if(n>0)
			cout<<"Terminates\n";
	}
}

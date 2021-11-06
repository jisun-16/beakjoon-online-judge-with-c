#include<iostream>

using namespace std;

int d[30][30001];
int R, C, N;
char b[30000][31];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>R>>C;
	for(int i=0;i<R;++i) cin>>b[i];
	
	cin>>N;
	while(N--){
		int q;
		cin>>q;
		--q;
		
		int r=0, c=q, tmp;
		int &size=d[q][0];
		while(1){
			if(!size)
				break;
			c=d[q][size]&31, r=d[q][size]>>5;
			size--;
			if(b[r][c]=='.')
				break;
		}
		
		while(1){
			d[q][++size]=(r<<5)+c;
			
			if(r==R-1 || b[r+1][c]=='X')
				break;
				
			else if(b[r+1][c]=='O'){
				if(c>0 && b[r][c-1]=='.' && b[r+1][c-1]=='.')
					c--;
				else if(c<C-1 && b[r][c+1]=='.' && b[r+1][c+1]=='.')
					++c;
				else break;
			}
			++r;
		}
		
		b[r][c]='O';
		size--;
	}
	
	for(int i=0;i<R;++i)
		cout<<b[i]<<"\n";
}

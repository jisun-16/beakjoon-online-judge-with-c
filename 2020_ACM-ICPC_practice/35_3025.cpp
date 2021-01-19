#include<cstdio>
#include<set>

#define pii pair<int,int>

using namespace std;

int r,c,z,idx[31];
char b[30002][32];
set<int> ob[31];
pii chk[30001][31];

void mov(int row,int col,int st){
	int i=*(ob[col].upper_bound(row));//가장 먼저 만나는 장애물의 높이 
	if(b[i][col]=='X'){
		//벽 
		b[i-1][col]='O';
		ob[col].erase(i);
		ob[col].insert(i-1);
	}
	else{
		//돌 
		if(b[i][col-1]=='.'&&b[i-1][col-1]=='.'){
			//왼쪽 
			chk[idx[st]][st]={i-1,col};
			idx[st]++;
			mov(i-1,col-1,st);
		}
		else if(b[i][col+1]=='.'&&b[i-1][col+1]=='.'){
			//오른쪽 
			chk[idx[st]][st]={i-1,col};
			idx[st]++;
			mov(i-1,col+1,st);
		}
		else{
			//멈춤 
			b[i-1][col]='O';
			ob[col].erase(i);
			ob[col].insert(i-1);
		}
	}
}

int main(){
	scanf("%d %d",&r,&c);
	
	for(int i=1;i<=r;++i){
		char temp[31];
		scanf("%s",temp);
		for(int j=1;j<=c;++j){
			b[i][j]=temp[j-1];
			if(b[i][j]=='X') 
				ob[j].insert(i);
		}
	}
	for(int i=1;i<=c;++i)
		ob[i].insert(r+1);
	
	scanf("%d",&z);
	while(z--){
		int st;
		scanf("%d",&st);
		
		int x,y;
		while(idx[st]){
			x=chk[idx[st]-1][st].first;
			y=chk[idx[st]-1][st].second;
			if(b[x][y]!='.') --idx[st];
			else break;
		}
		
		if(idx[st]==0)
			mov(1,st,st);
		else
			mov(x,y,st);
	}
	
	for(int i=1;i<=r;++i)
		printf("%s\n",b[i]+1);
}

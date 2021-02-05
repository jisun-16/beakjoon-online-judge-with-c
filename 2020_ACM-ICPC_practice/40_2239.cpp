#include<iostream>
#include<algorithm>
using namespace std;
int s[9][9],col[9][10],row[9][10],sq[9][10],fin;
void dfs(int cnt){
	if(fin) return;
	if(cnt==81){
		fin=true;
		for(int i=0;i<9;++i){
			for(int j=0;j<9;++j) cout<<s[i][j];
			cout<<'\n';
		}
		return;
	}
	int x=cnt/9,y=cnt%9;
	if(s[x][y]!=0) dfs(cnt+1);
	else{
		for(int i=1;i<=9;++i){
			if(row[x][i]) continue;
			if(col[y][i]) continue;
			if(sq[(x/3)*3+y/3][i]) continue;
			s[x][y]=i;
			row[x][i]=true;col[y][i]=true;sq[(x/3)*3+y/3][i]=true;
			dfs(cnt+1);
			s[x][y]=0;
			row[x][i]=false;col[y][i]=false;sq[(x/3)*3+y/3][i]=false;			
		}
	}
}
int main(){
	for(int i=0;i<9;++i)
		for(int j=0;j<9;++j) {
			scanf("%1d",&s[i][j]);
			if(s[i][j]!=0){
				row[i][s[i][j]]=true;
				col[j][s[i][j]]=true;
				sq[(i/3)*3+j/3][s[i][j]]=true; //0 1 2 | 3 4 5 | 6 7 8 
			}
		}
	dfs(0);
}

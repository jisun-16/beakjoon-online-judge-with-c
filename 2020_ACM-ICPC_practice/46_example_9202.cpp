#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int w,b,score[9]={0,0,0,1,1,2,3,5,11},dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
string word[300000],board[4];
bool visited[4][4],chk;
void dfs(string s,int idx,int x,int y){
	if(idx==s.length()||chk){
		chk=true;
		return;
	}
	if(s[idx]!=board[x][y]) return;
	if(visited[x][y]) return;
	visited[x][y]=true;
	for(int i=0;i<8;++i){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0||nx>=4||ny<0||ny>=4) continue;
		dfs(s,idx+1,nx,ny);
	}
}
bool find(string s){
	bool ret=false;
	for(int i=0;i<4&&!ret;++i)
		for(int j=0;j<4&&!ret;++j){
			memset(visited,false,sizeof(visited));
			chk=false;
			dfs(s,0,i,j);
			ret=chk;
		}
	return ret;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>w;
	for(int i=0;i<w;++i) cin>>word[i];
	sort(word,word+w);
	cin>>b;
	while(b--){
		int s=0,cnt=0;
		string l="";
		for(int i=0;i<4;++i) cin>>board[i];
		for(int i=0;i<w;++i){
			chk=false;
			for(int r=0;r<4;++r)
				for(int c=0;c<4;++c) visited[r][c]=false;
			bool chk=find(word[i]);
			if(chk){
				cnt++;
				s+=score[word[i].length()];
				if(l.length()<word[i].length()) l=word[i];
			}
		}
		cout<<s<<" "<<l<<" "<<cnt<<'\n';
	}
}

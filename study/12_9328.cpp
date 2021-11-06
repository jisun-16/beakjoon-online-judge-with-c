#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

const int dx[]={-1,0,1,0},dy[]={0,-1,0,1};

int t,h,w;
bool key[26],visited[102][102];
char map[102][102];

bool avail(int x,int y){
	return x>=0&&x<=h+1&&y>=0&&y<=w+1&&map[x][y]!='*'&&!visited[x][y];
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>t;
	while(t--){
		memset(map,0,sizeof(map));
		memset(key,false,sizeof(key));
		memset(visited,false,sizeof(visited));
		
		cin>>h>>w;
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++){
				char temp;
				cin>>temp;
				if(temp!='.') map[i][j]=temp;
			}
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0') break;
			key[s[i]-'a']=true;
		}
		
		queue<pair<int,int> > q;
		queue<pair<int,int> > door[26];
		q.push({0,0});
		visited[0][0]=true;
		
		int ans=0;
		while(!q.empty()){
			int x=q.front().first,y=q.front().second;
			q.pop();
			
			for(int i=0;i<4;i++){
				int nx=x+dx[i],ny=y+dy[i];
				
				if(!avail(nx,ny)) continue;
				
				if(map[nx][ny]>='A'&&map[nx][ny]<='Z'){
					if(!key[map[nx][ny]-'A']){
						door[map[nx][ny]-'A'].push({nx,ny});
						continue;
					}
				}//열 수 없는 문을 만났을 때 
				else if(map[nx][ny]>='a'&&map[nx][ny]<='z'){
					if(!key[map[nx][ny]-'a']){
						int k=map[nx][ny]-'a';
						key[k]=true;
						while(!door[k].empty()){
							q.push({door[k].front()});
							door[k].pop();
						}
					}
				}//새로운 열쇠를 찾았을 때 
				else if(map[nx][ny]=='$') ans++;
				
				visited[nx][ny]=true;
				q.push({nx,ny});
			}
			
		}
		
		cout<<ans<<'\n';
	}
}

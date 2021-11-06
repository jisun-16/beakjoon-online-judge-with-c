#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<algorithm>

using namespace std;

const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
string target="123456780";

int main(){
	string s="";
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			char temp=0;
			cin>>temp;
			s=s+temp;
		}
	
	queue<pair<string,int> > q;
	set<string> visited;
	q.push({s,0});
	visited.insert(s);
	
	while(!q.empty()){
		string u=q.front().first;
		int d=q.front().second;
		q.pop();
		
		if(u==target) {
			cout<<d<<'\n';
			return 0;
		}
		
		int i=u.find('0');
		int x=i/3;
		int y=i%3;
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			
			if(nx<0||nx>=3||ny<0||ny>=3) continue;
			
			string v=u;
			swap(v[x*3+y],v[nx*3+ny]);
			
			if(visited.find(v)==visited.end()){
				visited.insert(v);
				q.push({v,d+1});
			}
		}
	}
	
	cout<<-1<<'\n';
}

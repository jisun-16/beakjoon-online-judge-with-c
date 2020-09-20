#include<iostream>
#include<algorithm>

using namespace std;

bool adj[26][26],alp[26];
int ind[26];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		for(int i=0;i<26;i++){
			alp[i]=false;
			ind[i]=0;
			for(int j=0;j<26;j++) 
				adj[i][j]=true;
		}
		
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			char a,b;
			cin>>a>>b;
			adj[a-'a'][b-'a']=false;
			alp[a]=true;
			alp[b]=true;
		}
		
		int cnt=0;
		queue<int> q;
		for(int i=0;i<26;i++){
			if(!alp[i]) continue;
			cnt++;
			for(int j=0;j<26;j++){
				if(alp[j]&&adj[j][i]) ind[i]++;
			}
			if(ind[i]==0) q.push(i);
		}
		
		for(int i=0;i<cnt;i++){
			if(q.empty()){
				break;
			}
			
			int x=q.front();
			q.pop();
			for(int y=0;y<26;y++){
				if(alp[y]&&adj[x][y]) ind[y]--;
				if(ind[y]==0) q.push(y);
			}
		}
		
		
	}
}

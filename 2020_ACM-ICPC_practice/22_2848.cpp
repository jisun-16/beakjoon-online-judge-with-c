#include<iostream>
#include<string>

using namespace std;

int n,ind[26];
char ans[26];
string word[101];
bool adj[26][26],alp[26];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>word[i];
		for(int j=0;j<word[i].length();j++)
			alp[word[i][j]-'a']=true;
	}
	
	int idx=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=0;k<word[i].length();k++){
				if(k>=word[j].length()){
					idx=-1;
					break;
				}
				
				int a=word[i][k]-'a',b=word[j][k]-'a';
				if(a==b) continue;
				
				if(!adj[a][b]){
					adj[a][b]=true;
					ind[b]++;
					
					if(adj[b][a])
						idx=-1;
				}
				
				break;
			}
		}
	}
	
	if(idx==-1) {
		cout<<"!"<<'\n';
		return 0;
	}
	
	while(true){
		int now=-1,cnt=0;
		for(int i=0;i<26;i++)
			if(alp[i]&&ind[i]==0){
				now=i; 
				cnt++;
			}
		
		if(cnt>1){
			idx=-1;
			break;
		}
		if(cnt==0) break;
		
		alp[now]=false;
		ans[idx++]=now+'a';
		
		for(int i=0;i<26;i++)
			if(adj[now][i]){
				adj[now][i]=false;
				ind[i]--;
			}
	}
	
	if(idx==-1) cout<<"?"<<'\n';
	else if(idx==0) cout<<"!"<<'\n';
	else{
		for(int i=0;i<idx;i++)
			cout<<ans[i];
		cout<<'\n';
	}
}

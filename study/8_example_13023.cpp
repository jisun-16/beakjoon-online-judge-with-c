#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, cnt;
bool chk[2001], ans;
vector<vector<int> > fnd;

void _dfs(int u){
	if(ans) return;
	
	if(cnt==5) {
		ans=true;
		return;
	}
	
	for(int i=0;i<fnd[u].size();i++){
		if(chk[fnd[u][i]]) continue;
		chk[fnd[u][i]]=true;
		cnt++;
		_dfs(fnd[u][i]);
		cnt--;
		chk[fnd[u][i]]=false;
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m;
	fnd.resize(n);
	
	for(int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		fnd[a].push_back(b);
		fnd[b].push_back(a);
	}
	
	for(int i=0;i<n;i++) {
		if(ans) break;
		cnt=1;
		chk[i]=true;
		_dfs(i);
		chk[i]=false;
	}
	
	if(ans) cout<<1<<'\n';
	else cout<<0<<'\n';
}

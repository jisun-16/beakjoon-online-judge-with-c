#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n,m;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	
	vector<vector<int> > v(n);
	vector<int> cnt(n);
	for(int i=0;i<n;i++){
		while(true){
			int temp;
			cin>>temp;
			if(temp==0) break;
			temp--;
			v[i].push_back(temp);
		}
	}
	
	vector<int> ans(n,-1);
	queue<int> q;
	
	cin>>m;
	while(m--){
		int temp;
		cin>>temp;
		temp--;
		q.push(temp);
		
		ans[temp]=0;
	}
	
	int t=0;
	while(!q.empty()){
		int temp=q.size();
		while(temp--){
			int now=q.front();
			q.pop();
			
			for(int i=0;i<v[now].size();i++) 
				cnt[v[now][i]]++;
			
			for(int i=0;i<v[now].size();i++){
				int next=v[now][i];
				
				if(ans[next]!=-1) continue;
				if(cnt[next]*2<v[next].size())continue;
				
				ans[next]=ans[now]+1;
				
				q.push(next);
			}
		}
		t++;
	}
	
	for(int i=0;i<n;i++) cout<<ans[i]<<' ';
	cout<<'\n';
}

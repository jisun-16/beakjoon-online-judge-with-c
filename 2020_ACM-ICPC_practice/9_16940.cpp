#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n, BFS[100001], ord[100001];
vector<int> graph[100001];
int visited[100001];

bool cmp(int a, int b){
	return ord[a]<ord[b];
}

int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	for(int i=0;i<n;i++){
		cin>>BFS[i];
		ord[BFS[i]]=i;
	}
	
	if(BFS[0]!=1){
		cout<<0<<'\n';
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		sort(graph[i].begin(),graph[i].end(),cmp);
	}
	
	queue<int> q;
	
	q.push(1);
	int temp[100001], cnt=0;
	visited[1]=true;
	
	while(!q.empty()){
		int now=q.front();
		q.pop();
		temp[cnt++]=now;
		
		for(int i=0;i<graph[now].size();i++){
			int next=graph[now][i];
			if(visited[next]) continue;
			visited[next]=true;
			q.push(next);
		}
	}
	
	int avail=true;
	for(int i=0;i<n;i++){
		if(temp[i]!=BFS[i]){
			avail=false;
			break;
		}
	}
	
	if(avail) cout<<1<<'\n';
	else cout<<0<<'\n';
}

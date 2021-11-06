#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int chk[3001];//
int n, dist[3001];
vector<int> graph[3001];

int _check(int now, int before){
	if(chk[now]) return now;
	
	chk[now]=1;
	
	for(int i=0;i<graph[now].size();i++){
		int next=graph[now][i];
		
		if(next==before) continue;//�ڷ� ������ ���� 
		
		int ret=_check(next,now);
		
		if(ret==-2) return -2;//����Ŭ�� ���ԵǾ� ���� ���� ��� 
		if(ret>=0){
			chk[now]=2;//����Ŭ 
			if(ret==now) return -2;//������ 
			else return ret;//����Ŭ������ �������� �ƴ� 
		}
	}
	
	return -1;//������� 
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int a, b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	_check(1,-1);
	
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(chk[i]==2){
			dist[i]=0;
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int u=q.front();
		q.pop();
		
		for(int i=0;i<graph[u].size();i++){
			int v=graph[u][i];
			if(chk[v]==2) continue;
			chk[v]=2;
			dist[v]=dist[u]+1;
			q.push(v);
		}
	}
	
	for(int i=1;i<=n;i++) cout<<dist[i]<<' ';
	cout<<'\n';
	
	return 0;
}

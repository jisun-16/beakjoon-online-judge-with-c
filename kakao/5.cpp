#include <string>
#include <vector>
#include<iostream>
#include<queue>

using namespace std;

int n,s_or_w[20],m_cnt;
vector<int> adj[20];
bool chk[20];
void perm(int idx){
    if(idx==n){
        bool visited[20]={0,};
        queue<int> q;
        int s_cnt=0,w_cnt=0;
        visited[0]=true;
        q.push(0);
        s_cnt++;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=0;i<adj[x].size();++i){
                int nx=adj[x][i];
                if(!visited[nx]){
                    visited[nx]=true;
                    q.push(nx);
                    if(s_or_w[nx]==0) s_cnt++;
                    else w_cnt++;
                }
            }
        }
        for(int i=1;i<n;++i){
            if(chk[i]&&!visited[i]) return;
        }
        if(s_cnt>w_cnt) m_cnt=m_cnt>=s_cnt?m_cnt:s_cnt;
        return;
    }
    chk[idx]=true;
    perm(idx+1);
    chk[idx]=false;
    perm(idx+1);
}
int main(){
	cin>>n;
	for(int i=0;i<n;++i) cin>>s_or_w[i];
	for(int i=0;i<n-1;++i){
		int a,b;
		cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
	}
    int answer = 0;
    chk[0]=true;
    perm(1);
    answer=m_cnt;
    cout<<answer;
}

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n, m, s, e;
int adj[502][502];
int dp[502];
void dijkstra() {
    memset(dp, -1, sizeof(dp));
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,s });
    while (pq.size()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dp[here] != -1) continue;
        dp[here] = cost;
        for (int i = 0; i < n; i++) {
            if (adj[here][i] == -1) continue;
            if (dp[i] != -1) continue;
            pq.push({ -cost - adj[here][i],i });
        }
    }
}
void eraseEdge() {
    queue<int> q;
    q.push(e);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (adj[i][x] != -1 && dp[x] == dp[i] + adj[i][x]) {
                adj[i][x] = -1;
                q.push(i);
            }    
        }
    }
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
    while (1) {
	    cin>>n>>m;
	    if(n==0&&m==0) break;
	    
        cin>>s>>e;
        memset(adj, -1, sizeof(adj));
        for (int i = 0; i < m; i++) {
        	int x,y,z;
            cin>>x>>y>>z;
            adj[x][y] = z;
        }
        
        dijkstra();
        eraseEdge();
        dijkstra();
        
        cout<<dp[e]<<'\n';
    }
    return 0;
}

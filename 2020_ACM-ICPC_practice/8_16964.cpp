#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, arr[100001], cnt=1, ans;
vector<int> tree[100001];
bool visit[100001];

void _dfs(int x, int now){
	if(cnt==n){
		ans=1;
		return;
	}
	
    if (visit[now])
        return;
    visit[now] = true;
    
    for (int i=0;i<tree[now].size();i++) {
    	int next=tree[now][i];
    	
        if (!visit[next] && next==arr[cnt]) {
            cnt++;
            _dfs(x+1,next);
            i=-1;
        }
    }
}
  
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin>>n;
	for(int i=1;i<n;i++) {
		int a, b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for(int i=0;i<n;i++) cin>>arr[i];
	
	if(arr[0]!=1){
		cout<<0<<'\n';
		return 0;
	}
	
	_dfs(0,1);
	
	cout<<ans<<'\n';
}

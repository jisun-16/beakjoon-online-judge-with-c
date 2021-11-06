#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, arr[100001], cnt=1,order[100001],ans;
vector<int> tree[100001];
bool visit[100001];

bool cmp(int a,int b){
	return order[a]<order[b];
}

void _dfs(int now, vector<int>& compare){
    if (visit[now])
        return;
    compare.push_back(now);
    visit[now] = true;
    for(int next:tree[now])
    	if(!visit[next]) _dfs(next,compare);
}
  
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin>>n;
	for(int i=0;i<n-1;i++) {
		int a, b;
		cin>>a>>b;
		a--;b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		arr[i]--;
		order[arr[i]]=i;
	}
	
	for(int i=0;i<n;i++){
		sort(tree[i].begin(),tree[i].end(),cmp);
	}
	
	vector<int> compare;
	_dfs(0,compare);
	
	for(int i=0;i<compare.size();i++){
		if(arr[i]!=compare[i]){
			cout<<0<<'\n';
			return 0;
		}
	}
	
	cout<<1<<'\n';
	
	return 0;
}
